#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

#include <verilated.h>
#include <verilated_vcd_c.h>
#include <Vtop.h>


#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);
	Vtop *top = new Vtop;

	Verilated::traceEverOn(true);
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	top->trace(m_trace, 5);
	m_trace->open("waveform.vcd");
    
	while (sim_time < MAX_SIM_TIME) {
	
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
		
		top->eval();
		
		assert(top->f == (a ^ b));
		
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		
		m_trace->dump(sim_time);
		
		sim_time++;
	}
	m_trace->close();
	delete top;
	exit(EXIT_SUCCESS);
	return 0;
}

