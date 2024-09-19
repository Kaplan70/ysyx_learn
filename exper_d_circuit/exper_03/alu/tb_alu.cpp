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
#include "dbg.h"

#define MAX_SIM_TIME 200 
#define VERIF_START_TIME 7
#define VDUT Valu
vluint64_t sim_time = 1;

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);//用于随机设置初始值
	VDUT *dut = new VDUT;

	/*用于初始化传输波形*/
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace, 5);
	m_trace->open("waveform.vcd");
	
	while (sim_time <= MAX_SIM_TIME) {
                //dut->clk ^= 1;

                /*测试向量产生部分*/
                //注意如何判断溢出问题：
                //1,对于8位数，仅有同号运算会出现溢出。
                //2,运算正数过大溢出，8位超过127则溢出。
                //3,运算负数过小溢出，负数过小看不太出来。两负数可根据c标志，进位则溢出。
                if(sim_time % 8 == 0) {
                	dut->a = dut->b =  rand() % 16;
                        dut->select = 7;
                }
                else if(sim_time % 7 == 0){
                	dut->a = rand() % 16;
                        dut->b = rand() % 16;
                        dut->select = 6;
                }
                else if(sim_time % 6 == 0){
                	dut->a = 8;
                        dut->b = 15;
                        dut->select = 5;
                }
                else if(sim_time % 5 == 0){
                	dut->a = 10;
                        dut->b = 5;
                        dut->select = 4;
                }
                else if(sim_time % 4 == 0){
                	dut->a = 10;
                        dut->b = 5;
                        dut->select = 3;
                }
                else if(sim_time % 3 == 0){
                	dut->a = 10;
                        dut->select = 2;
                }
                else if(sim_time % 2 == 0){
                	dut->a = rand() % 16;
                        dut->b = rand() % 16;
                        dut->select = 1;
                }
                else if(sim_time % 1 == 0){
                	dut->a = rand() % 16;
                        dut->b = rand() % 16;
                        dut->select = 0;
                }

                dut->eval();

                /*结果测试部分*/
                if(sim_time % 1 == 0) {
                        log_info("a = %d, b = %d, select = %d, result = %d, sim_time = %d, overflow = %d", \
                                        dut->a, dut->b, dut->select, dut->result, sim_time, dut->overflow);
                }
                if(sim_time % 7 == 0) {
                        if(dut->a != dut->b) {
                                if((dut->a > 7 && dut->b > 7) || (dut->a < 8 && dut->b < 8)) {
                                        if((dut->a < dut->b) != dut->result) log_info("error");
                                }
                                else if(dut->a < 8 && dut->b > 7) if(dut->result) log_info("error");
                                else if(dut->a > 7 && dut->b < 8) if(!(dut->result)) log_info("error");
                        }
                }
		m_trace->dump(sim_time);//传输波形
		sim_time++;
	}
	m_trace->close();
	delete dut;
	exit(EXIT_SUCCESS);
}

