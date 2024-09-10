MODULE=mux241
UDT_FILE=v

#sim verilator build分别为三个步骤。
#waves则为运行.vcd文件查看波形
.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: ./obj_dir/V$(MODULE)

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE) #实质并没有作任何工作，下面一步已生成.vcd文件
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2

./obj_dir/V$(MODULE): .stamp.verilate #通过make编译.c文件.h文件tb.cpp文件形成可执行文件
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(MODULE).$(UDT_FILE) tb_$(MODULE).cpp #通过verilator转化.v到.c文件并处理tb文件
	@echo
	@echo "### VERILATING ###"
	verilator -Wall --trace --x-assign unique --x-initial unique -cc $(MODULE).$(UDT_FILE) --exe tb_$(MODULE).cpp
	@touch .stamp.verilate

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd

