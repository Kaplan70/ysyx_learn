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
#include <Vadd_sub.h> 
#include "dbg.h"

#define MAX_SIM_TIME 50 
#define VERIF_START_TIME 7
#define VDUT Vadd_sub
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
                if(sim_time % 2 == 0) {
                	dut->a = rand() % 256;
                        dut->b = rand() % 256;
                        dut->select = 0;
                }else {
                	dut->a = rand() % 128;
                        dut->b = rand() % 128;
                        dut->select = 1;
                }

                dut->eval();

                /*结果测试部分*/
                if(sim_time % 2 == 0){
                        log_info("a = %d, b = %d, select = %d, result = %d, overflow = %d, carry = %d, sim_time = %d", \
                                        dut->a, dut->b, dut->select, dut->result, dut->overflow, dut->carry, sim_time);
                        if(dut->overflow == 1) {
                                log_info("[error]:value is overflow!");
                        }
                        else {
                                if(dut->result != dut->a + dut->b) log_info("[error]:comput error!");
                        }
                }else {
                        log_info("a = %d, b = %d, select = %d, result = %d, overflow = %d, carry = %d, sim_time = %d", \
                                        dut->a, dut->b, dut->select, dut->result, dut->overflow, dut->carry, sim_time);
                        if(dut->overflow == 1) {
                                log_info("[error]:value is overflow!");
                        }
                        else {
                                if(dut->result != dut->a - dut->b) log_info("[error]:comput error!");
                        }
                }

		m_trace->dump(sim_time);//传输波形
		sim_time++;
	}
	m_trace->close();
	delete dut;
	exit(EXIT_SUCCESS);
}

