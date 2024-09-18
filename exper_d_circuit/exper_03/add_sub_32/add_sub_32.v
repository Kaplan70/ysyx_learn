/*32位加减运算器*/
//注意：此处以a与b为原码
`include "add32.v"

module add_sub_32(
        input [31:0] a,
        input [31:0] b,
        input select,
        output [31:0] result,
        output c,
        output overflow,
        output zero
);
        wire [31:0] bs;
        assign bs = select ? (~b + 32'b1) : b;
        wire [31:0]resultb;
        add32 u_add32(
                .a(a),
                .b(bs),
                .out(resultb),
                .out_c(c),
                .out_flower(overflow)
        );
        assign zero = ~(|result);
        assign result = resultb[31] ? (~resultb + 32'b1) : resultb;

endmodule
