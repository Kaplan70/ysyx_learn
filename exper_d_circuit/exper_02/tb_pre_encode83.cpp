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
#include <Vpre_encode83.h> 


#define MAX_SIM_TIME 200 
#define VERIF_START_TIME 7
#define VDUT Vpre_encode83
vluint64_t sim_time = 0;

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);//用于随机设置初始值
	VDUT *dut = new VDUT;

	/*用于初始化传输波形*/
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace, 5);
	m_trace->open("waveform.vcd");
	

	while (sim_time < MAX_SIM_TIME) {
                //dut->clk ^= 1;
                //给信号赋值
                if(sim_time % 5 == 0) {
                	dut->x = rand() % 256;
                	dut->en = rand() % 2;
                }
                dut->eval();
                if(dut->en) {
                	if(dut->x > 127) if(dut->y != 7) std::cout << "error:x="<< dut->x << "y=" << dut->y << std::endl;
                	else if(dut->x > 63) if(dut->y != 6) std::cout << "error:x=" << dut->x << "y=" << dut->y << std::endl;
                }

		m_trace->dump(sim_time);//传输波形
		sim_time++;
	}
	m_trace->close();
	delete dut;
	exit(EXIT_SUCCESS);
	return 0;
}

