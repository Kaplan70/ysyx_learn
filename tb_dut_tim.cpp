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
#include <Valu.h> 
/*.h
 *特别要求转化到cpp文件的数据类型 
 */
#include "Valu___024unit.h"


#define MAX_SIM_TIME 200 
#define VERIF_START_TIME 7
#define VDUT Valu 
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;


/*reset信号初始化*/
void dut_reset(VDUT *dut, vluint64_t &sim_time){
	dut->rst = 0;
	if(sim_time >= 3 && sim_time < 6) dut->rst = 1; 
}

/*输入测试向量类*/
class DutInTx {
        public:

};

/*输出结果向量类*/
class DutOutTx {
        public:

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
		
		// As the transaction items were allocated on the heap, it's important
		// to free the memory after they have been used
		delete in;
		delete tx;
	}
};

/*产生测试向量函数*/
DutInTx* rndDutInTx(int i){
	/*i参数的传入实参为posedge_cnt，
	 *其中posedge_cnt为rst信号有效后开始计数，
	 *即在rst后，每5个edge产生一个测试向量
	 */
	if((i % 5) == 0){
		DutInTx *tx = new DutInTx();

		/*在这里对测试向量加上随机值！*/

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
			// we always start with in_valid set to 0, and set it to
			// 1 later only if necessary
			dut->in_valid = 0;

			// Don't drive anything if a transaction item doesn't exist
			if(tx != NULL){
				
				/*在这里将测试向量的值传给dut的输入接口！*/
				
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

		void monitor(){
			if (dut->in_valid == 1) {
				// If there is valid data at the input interface,
				// create a new AluInTx transaction item and populate
				// it with data observed at the interface pins
				DutInTx *tx = new DutInTx();
				/*将dut输入接口处的值反传给新的tx！*/

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

		void monitor(){
			if (dut->out_valid == 1) {
				// If there is valid data at the output interface,
				// create a new AluOutTx transaction item and populate
				// it with result observed at the interface pins
				DutOutTx *tx = new DutOutTx();
				/*将输出端口的值传给新的tx,注：此处的tx为输出结果向量*/

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
		dut_reset(dut, sim_time);
	
		dut->clk ^= 1;
		dut->eval();
		
		/*作为检查的判断条件*/
		if(dut->clk == 1){
			if (sim_time >= VERIF_START_TIME) {
				// Generate a randomized transaction item of type AluInTx
				tx = rndDutInTx(posedge_cnt);

				// Pass the transaction item to the ALU input interface driver,
				// which drives the input interface based on the info in the
				// transaction item
				drv->drive(tx);

				// Monitor the input interface
				inMon->monitor();

				// Monitor the output interface
				outMon->monitor();
				
				posedge_cnt++;
            		}
		}

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

