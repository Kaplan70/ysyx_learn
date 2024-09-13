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
#include <Vnixie_decode47.h> 
#include "dbg.h"


#define MAX_SIM_TIME 200 
#define VERIF_START_TIME 7
#define VDUT Vnixie_decode47 
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
                /*产生测试向量*/
                //dut->clk ^= 1;
                if(sim_time % 5 == 0) {
                        dut->x = rand() % 8;
                }

                dut->eval();

                /*验证输出数据*/
                if(sim_time % 5 == 0) {
                        switch(dut->x) {
                                case 0: check(dut->y == 63, "error:x = %d, y = %d", dut->x, dut->y);
                                case 1: check(dut->y == 6, "error:x = %d, y = %d", dut->x, dut->y);
                                case 2: check(dut->y == 91, "error:x = %d, y = %d", dut->x, dut->y);
                                case 3: check(dut->y == 79, "error:x = %d, y = %d", dut->x, dut->y);
                                case 4: check(dut->y == 102, "error:x = %d, y = %d", dut->x, dut->y);
                                case 5: check(dut->y == 109, "error:x = %d, y = %d", dut->x, dut->y);
                                case 6: check(dut->y == 125, "error:x = %d, y = %d", dut->x, dut->y);
                                case 7: check(dut->y == 7, "error:x = %d, y = %d", dut->x, dut->y);
                        }
                }


		m_trace->dump(sim_time);//传输波形
		sim_time++;
	}
	m_trace->close();
	delete dut;
	exit(EXIT_SUCCESS);

error:
	return 0;
}

