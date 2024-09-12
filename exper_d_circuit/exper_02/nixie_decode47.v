module nixie_decode47(
        input [3:0]x,
        output reg [6:0]y
);
        always @(x) begin
                case(x)
                        4'b0000: y = 7'b011_1111;//0
                        4'b0001: y = 7'b000_0110;
                        4'b0010: y = 7'b101_1011;
                        4'b0011: y = 7'b100_1111;//3
                        4'b0100: y = 7'b110_0110;
                        4'b0101: y = 7'b110_1101;
                        4'b0110: y = 7'b111_1101;//6
                        4'b0111: y = 7'b000_0111;
                        default: y = 7'b111_1111;
                endcase
        end

endmodule
