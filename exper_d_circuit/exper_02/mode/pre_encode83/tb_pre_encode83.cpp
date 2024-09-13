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
#include "dbg.h"

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

                /*测试向量产生部分*/
                if(sim_time % 5 == 0) {
                	dut->x = rand() % 256;
                } else if(sim_time % 4) {
                        dut->x = rand() % 64;
                } else if(sim_time % 3) {
                        dut->x = rand() % 16;
                } else if(sim_time % 2) {
                        dut->x = rand() % 4;
                }
                dut->en = 1;

                dut->eval();

                /*结果测试部分*/
                if(sim_time % 1 == 0){
                        if(dut->en) {
                                if(dut->x > 127) {
                                        check(dut->y == 7, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else if(dut->x > 63) {
                                        check(dut->y == 6, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else if(dut->x > 31) {
                                        check(dut->y == 5, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else if(dut->x > 15) {
                                        check(dut->y == 4, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else if(dut->x > 7) {
                                        check(dut->y == 3, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else if(dut->x > 3) {
                                        check(dut->y == 2, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else if(dut->x > 1) {
                                        check(dut->y == 1, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
                                else {
                                        check(dut->y == 0, "error: x = %d, y = %d", dut->x, dut->y);
                                        log_info("x = %d, y = %d\n", dut->x, dut->y);
                                }
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

