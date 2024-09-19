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

#define MAX_SIM_TIME 10 
#define VERIF_START_TIME 7
#define VDUT Vadd_sub
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
                /*
                if(sim_time % 3 == 0) {
                	dut->a = rand() % 256;
                        dut->b = rand() % 256;
                        dut->select = rand() % 2;
                }
                else if(sim_time % 2 == 0){
                	dut->a = rand() % 128;
                        dut->b = rand() % 128;
                        dut->select = rand() % 2;
                }
                else if(sim_time % 1 == 0){
                	dut->a = rand() % 64;
                        dut->b = rand() % 64;
                        dut->select = rand() % 2;
                }
                */
                dut->a = 64;
                dut->b = 128;
                dut->select = 0;
                //测试两正数补码64+64=128-溢出-无进位。
                //测试两负数补码-128+(-128)=-256-溢出-有进位。
                //测试正负数补码64-(-64)=128-溢出-无进位。
                //测试正负数补码-128-(128)=-256-溢出-有进位。
                /*
                if(sim_time % 5 == 0) {
                        dut->a = 64;
                        dut->b = 64;
                        dut->select = 0;
                }
                else if(sim_time % 4 == 0) {
                        dut->a = -128;
                        dut->b = -128;
                        dut->select = 0;
                }
                else if(sim_time % 3 == 0) {
                        dut->a = 64;
                        dut->b = -64;
                        dut->select = 1;
                }
                else if(sim_time % 2 == 0) {
                        dut->a = -128;
                        dut->b = 128;
                        dut->select = 1;
                }
                else if(sim_time % 1 == 0) {
                        dut->a = 64;
                        dut->b = 63;
                        dut->select = 0;
                }
                */

                dut->eval();

                /*结果测试部分*/
                if(sim_time % 1 == 0){
                        log_info("a = %d, b = %d, select = %d, result = %d, overflow = %d, carry = %d, sim_time = %d", \
                                        dut->a, dut->b, dut->select, dut->result, dut->overflow, dut->carry, sim_time);
                        if(dut->select == 0) {
                                if(dut->overflow == 1) {
                                        log_info("[error]:value is overflow!");
                                }
                        }
                        else {
                                if(dut->overflow == 1) {
                                        log_info("[error]:value is overflow!");
                                }
                        }
                }
		m_trace->dump(sim_time);//传输波形
		sim_time++;
	}
	m_trace->close();
	delete dut;
	exit(EXIT_SUCCESS);
}

