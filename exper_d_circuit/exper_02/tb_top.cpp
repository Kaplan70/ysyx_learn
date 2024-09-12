/*c标准头文件*/
#include <stdio.h>
#include <stdlib.h>
/*输入输出流文件*/
#include <iostream>
/*verilator标准头文件*/
#include <verilated.h>
/*verilator生成波形标准头文件*/
#include <verilated_vcd_c.h>
/*由dut文件生成标准.h*/
#include <Vtop.h> 
/*.h
 *特别要求转化到cpp文件的数据类型 
 */

#define MAX_SIM_TIME 200 
#define VERIF_START_TIME 7
#define VDUT Vtop 
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

/*输入测试向量类*/
class DutInTx {
        //例如用uint32_t来初始化32位变量
        public:
                uint8_t x;
                uint8_t en;
};

/*输出结果向量类*/
class DutOutTx {
        public:
                uint8_t y;
};

//scoreboard
class DutScb {
	private:
	std::deque<DutInTx*> in_q;

	public:
	// Input interface monitor port
	void writeIn(DutInTx *tx){
		// Push the received transaction item into a queue for later
		in_q.push_back(tx);
	}

	// Output interface monitor port
	void writeOut(DutOutTx* tx){
		// We should never get any data from the output interface
		// before an input gets driven to the input interface
		if(in_q.empty()){
			std::cout <<"Fatal Error in DutScb: empty DutInTx queue" << std::endl;
			exit(1);
		}

		// Grab the transaction item from the front of the input item queue
		DutInTx* in;
		in = in_q.front();
		in_q.pop_front();

		/*核心部分：
		 *01,scoreboard获取输入值后，如何用c++编写功能实现
		 *02,对于用c++实现的输出与tx，即dut输出作比较
		 *03,若结果有异，输出错误信息
		 */
                if(in->en) {
                        if(in->x > 127) if(tx->y != 7) std::cout << "erro" << std::endl;
                        else if(in->x > 63) if(tx->y != 125) std::cout << "erro" << std::endl; 
                        else if(in->x > 31) if(tx->y != 109) std::cout << "erro" << std::endl; 
                        else if(in->x > 15) if(tx->y != 102) std::cout << "erro" << std::endl;
                        else if(in->x > 7) if(tx->y != 79) std::cout << "erro" << std::endl; 
                        else if(in->x > 3) if(tx->y != 91) std::cout << "erro" << std::endl;
                        else if(in->x > 1) if(tx->y != 6) std::cout << "erro" << std::endl; 
                        else if(tx->y != 63) std::cout << "erro" << std::endl;
                }
                else if(tx->y != 63) std::cout << "erro" << std::endl;

		
		// As the transaction items were allocated on the heap, it's important
		// to free the memory after they have been used
		delete in;
		delete tx;
	}
};

/*产生测试向量函数*/
DutInTx* rndDutInTx(int sim_time){
	/*i参数的传入实参为posedge_cnt，
	 *其中posedge_cnt为rst信号有效后开始计数，
	 *即在rst后，每5个edge产生一个测试向量
	 */
	if((sim_time % 5) == 0){
		DutInTx *tx = new DutInTx();

		/*在这里对测试向量加上随机值！*/
                tx->x = rand() % 256;
                tx->en = rand() % 2;

		return tx;
	} else {
		return NULL;
	}
}

/*输入驱动模块类*/
class DutInDrv {
	private:
		VDUT *dut;
	public:
		DutInDrv(VDUT *dut){
			this->dut = dut;
		}

		void drive(DutInTx *tx){
			// Don't drive anything if a transaction item doesn't exist
			if(tx != NULL){
				
				/*在这里将测试向量的值传给dut的输入接口！*/
                                dut->x = tx->x;
                                dut->en = tx->en;

				// Release the memory by deleting the tx item
				// after it has been consumed
				delete tx;
			}
		}
};

/*输入监测模块类*/
class DutInMon {
	private:
		VDUT *dut;
		DutScb *scb;
	public:
		DutInMon(VDUT *dut, DutScb *scb){
			this->dut = dut;
			this->scb = scb;
		}

		void monitor(int sim_time){
                        if(sim_time % 5 == 0) {
                                // If there is valid data at the input interface,
                                // create a new AluInTx transaction item and populate
                                // it with data observed at the interface pins
                                DutInTx *tx = new DutInTx();
                                /*将dut输入接口处的值反传给新的tx！*/
                                tx->x = dut->x;
                                tx->en = dut->en;

                                // then pass the transaction item to the scoreboard
                                scb->writeIn(tx);
                        }
		}
};

/*输出监测模块类*/
class DutOutMon {
	private:
		VDUT *dut;
		DutScb *scb;
	public:
		DutOutMon(VDUT *dut, DutScb *scb){
			this->dut = dut;
			this->scb = scb;
		}

		void monitor(int sim_time){
                        if(sim_time % 5 == 0) {
                                // If there is valid data at the output interface,
                                // create a new AluOutTx transaction item and populate
                                // it with result observed at the interface pins
                                DutOutTx *tx = new DutOutTx();
                                /*将输出端口的值传给新的tx,注：此处的tx为输出结果向量*/
                                tx->y = dut->y;

                                // then pass the transaction item to the scoreboard
                                scb->writeOut(tx);
                        }
		}
};

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);//用于随机设置初始值
	VDUT *dut = new VDUT;

	/*用于初始化传输波形*/
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace, 5);
	m_trace->open("waveform.vcd");
	
	DutInTx *tx;
	
	// Here we create the driver, scoreboard, input and output monitor blocks
	DutInDrv  *drv    = new DutInDrv(dut);
	DutScb    *scb    = new DutScb();
	DutInMon  *inMon  = new DutInMon(dut, scb);
	DutOutMon *outMon = new DutOutMon(dut, scb);

	while (sim_time < MAX_SIM_TIME) {
                // Generate a randomized transaction item of type AluInTx
                // 注意：此处引入sim_time为了特定时间产生测试向量
                tx = rndDutInTx(sim_time);

                // Pass the transaction item to the ALU input interface driver,
                // which drives the input interface based on the info in the
                // transaction item
                // 驱动并无引入sim_time是其中有通过tx非NULL判断
                drv->drive(tx);

                // Monitor the input interface
                inMon->monitor(sim_time);

                dut->eval();

                // Monitor the output interface
                outMon->monitor(sim_time);
                
                //注：这里sim_tiom参数是波形本身需要
		m_trace->dump(sim_time);//传输波形
		sim_time++;
	}
	m_trace->close();
	delete dut;
	delete outMon;
	delete inMon;
	delete scb;
	delete drv;
	exit(EXIT_SUCCESS);
	return 0;
}

