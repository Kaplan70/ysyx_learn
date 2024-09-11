module nixie_decode38(
        input [2:0]x,
        output [6:0]y
);
        always @(x) begin
                case(x)
                        3'000: y = 7'011_1111;
                        3'001: y = 7'000_0110;
                        3'010: y = 7'101_1011;
                        3'011: y = 7'100_1111;
                        3'100: y = 7'110_0110;
                        3'101: y = 7'110_1101;
                        3'110: y = 7'111_1101;
                        default: y = 7'111_1111;
                endcase
        end

endmodule
