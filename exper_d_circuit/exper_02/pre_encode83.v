module pre_encode83(
        input [7:0]x,
        input en,
        output reg t,
        output reg [2:0]y
);
        always @(x or en) begin
                if(en) begin
                        casez(x)
                                8'b0000_0001: begin
                                        y = 3'b000; 
                                        t = 1'b1;
                                end
                                8'b0000_001?: begin
                                        y = 3'b001; 
                                        t = 1'b1;
                                end
                                8'b0000_01??: begin
                                        y = 3'b010; 
                                        t = 1'b1;
                                end
                                8'b0000_1???: begin
                                        y = 3'b011; 
                                        t = 1'b1;
                                end
                                8'b0001_????: begin
                                        y = 3'b100; 
                                        t = 1'b1;
                                end
                                8'b001?_????: begin
                                        y = 3'b101; 
                                        t = 1'b1;
                                end
                                8'b01??_????: begin
                                        y = 3'b110; 
                                        t = 1'b1;
                                end
                                8'b1???_????: begin
                                        y = 3'b111; 
                                        t = 1'b1;
                                end
                                default: begin
                                        y = 3'b000; 
                                        t = 1'b0;
                                end
                        endcase
                end
                else begin
                        y = 3'b000; 
                        t = 1'b0;
                end
        end

endmodule
