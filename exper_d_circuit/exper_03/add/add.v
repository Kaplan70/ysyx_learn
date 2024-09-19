/*32位加法器*/
//注意：此处a和b不区分为补码or原码
//仅对其进行加法运算处理。
//例如对于补码：
//1,异号运算后，out_flower始终为0,而out_c则可能0或1
//2,同正号运算，out_flower可能为1,而out_c则始终为0
//3,同负号运算，out_flower可能为1,而out_c则始终为1
module add #(n = 8)(
        input [n-1:0] a,
        input [n-1:0] b,
        output [n-1:0] result,
        output carry,
        output overflow,
        output zero
);
        assign {carry, result} = a + b;
        assign overflow = (a[n-1] == b[n-1]) && (result[n-1] != a[n-1]);
        assign zero = ~(|result);

endmodule
