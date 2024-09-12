`include "pre_encode83.v"
`include "nixie_decode47.v"

module top(
        input [7:0]x,
        input en,
        output reg t,
        output reg [6:0]y
);
        wire [2:0]numb;

        pre_encode83 u_pre_encode83(
                .x(x),
                .en(en),
                .t(t),
                .y(numb)
        );
        nixie_decode47 u_nixie_decode47(
                .x({1'b0, numb}),
                .y(y)
        );

endmodule
