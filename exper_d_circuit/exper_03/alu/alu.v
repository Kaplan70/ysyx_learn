module alu #(n = 4)(
        input [n-1:0]a,
        input [n-1:0]b,
        input [2:0]select,
        output reg [n-1:0]result,
        output overflow
);
        //详细说明比较大小如何比较？
        //01overflow。02out。
        wire [n-1:0]out;
        assign out = a - b;

        wire [n-1:0]bs;
        assign bs = ({4{1'b1}} ^ b) + 1;
        //wire overflow;
        assign overflow = (a[n-1] == bs[n-1]) && (a[n-1] != out[n-1]);

        wire zero;
        assign zero = ~(|(a - b));

        always @(*) begin
                case(select)
                        3'b000:result = a + b;
                        3'b001:result = a - b;
                        3'b010:result = {4{1'b1}} ^ a;
                        3'b011:result = a & b;
                        3'b100:result = a | b;
                        3'b101:result = a ^ b;
                        3'b110:result = {{3{1'b0}}, {out[n-1] ^ overflow}};
                        3'b111:result = zero ? 4'b1 : 4'b0;
                endcase
        end

endmodule
