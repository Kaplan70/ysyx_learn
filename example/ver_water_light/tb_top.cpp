#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <verilated.h>
#include <verilated_vcd_c.h>
#include <Vtop.h> 
//#include "Vtop___024unit.h"


#define MAX_SIM_TIME 100 
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;


/*reset信号初始化*/
void dut_reset(Vtop *dut, vluint64_t &sim_time){
	dut->rst = 0;
	if(sim_time >= 3 && sim_time < 6) dut->rst = 1; 
}

/* 检查函数：
 * 01通过C语言计算期望值，02将期望值与实际值比较，03若不相等则输出错误。
*/
void check_out_void(Vtop *dut, vluint64_t &sim_time){
	static int led = 0;
	static int led_list[3] = {1, 4, 2};
	static int i = 0;
	
	if(sim_time >= VERIF_START_TIME){
		led = led_list[i];
		if(led != dut->led) std::cout << "erroe" << std::endl;
		if(i == 2) i = 0; else i++;
	}
}

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);//用于随机设置初始值
	Vtop *dut = new Vtop;

	/*用于初始化传输波形*/
	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	dut->trace(m_trace, 5);
	m_trace->open("waveform.vcd");

	while (sim_time < MAX_SIM_TIME) {
		dut_reset(dut, sim_time);
	
		dut->clk ^= 1;
		dut->eval();
		
		/*作为检查的判断条件*/
		if(dut->clk == 1 && !((posedge_cnt - 1) % 3)){
			posedge_cnt++;
			check_out_void(dut, sim_time);
		}
		
		printf("clk = %d  rst = %d  led = %d\n", dut->clk, dut->rst, dut->led);
		m_trace->dump(sim_time);//传输波形
		
		sim_time++;
	}
	m_trace->close();
	delete dut;
	exit(EXIT_SUCCESS);
	return 0;
}

