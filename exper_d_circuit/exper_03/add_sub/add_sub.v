/*32位加减运算器*/
//注意：此处以a与b为原码
`include "add.v"

module add_sub #(n = 8)(
        input [n-1:0] a,
        input [n-1:0] b,
        input select,
        output [n-1:0] result,
        output carry,
        output overflow,
        output zero
);
        wire [n-1:0] bs;
        assign bs = select ? (~b + 1) : b;

        add #(8)u_add ( 
                .a(a),
                .b(bs),
                .result(result),
                .carry(carry),
                .overflow(overflow),
                .zero(zero)
        );

endmodule
