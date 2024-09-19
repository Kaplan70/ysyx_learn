/*32位加法器*/
//注意：此处a和b不区分为补码or原码
//仅对其进行加法运算处理。
//例如对于补码：
//1,异号运算后，out_flower始终为0,而out_c则可能0或1
//2,同正号运算，out_flower可能为1,而out_c则始终为0
//3,同负号运算，out_flower可能为1,而out_c则始终为1
module add8(
        input [31:0] a,
        input [31:0] b,
        output reg [31:0] out,
        output reg out_c,
        output reg out_flower
);
        {out_c, out} = a + b;
        out_flower = (a[31] == b[31]) && (out[31] != a[31]);

endmodule
