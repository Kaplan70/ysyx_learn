module pre_encode83(
        input [7:0]x,
        input en,
        output reg t,
        output reg [2:0]y
);
        always @(x or en) begin
                if(en) begin
                        casez(x)
                                8'b0000_0001: y = 3'b000; c = 1'b1;
                                8'b0000_001?: y = 3'b001; c = 1'b1;
                                8'b0000_01??: y = 3'b010; c = 1'b1;
                                8'b0000_1???: y = 3'b011; c = 1'b1;
                                8'b0001_????: y = 3'b100; c = 1'b1;
                                8'b001?_????: y = 3'b101; c = 1'b1;
                                8'b01??_????: y = 3'b110; c = 1'b1;
                                8'b1???_????: y = 3'b111; c = 1'b1;
                                default: y = 3'b000; c = 1'b0;
                        endcase
                end
                else y = 3'b000; c = 1'b0;
        end

endmodule
