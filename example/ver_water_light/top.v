module top(
	input clk,
	input rst,
	output reg [2:0] led,
	output reg [1:0] count
);
	//reg [1:0] count;
	always @(posedge clk) begin
		if (rst) begin led <= 3'b001; count <= 2'b00; end
		else begin
			if (count == 2'b00) led <= {led[1:0], led[2]};
			count <= (count >= 2'b10 ? 2'b00 : count + 1);
		end
	end
endmodule

