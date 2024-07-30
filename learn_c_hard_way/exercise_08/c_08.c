#include <stdio.h>

int main(void)
{
    int sum[] = {1, 2, 3};
    char str0[] = "abc";
    char *str1 = "def";

    //测试数组
    printf("size of int : %ld\n", sizeof(int));
    printf("size of long int : %ld\n", sizeof(long int));
    
    printf("size of sum : %ld\n", sizeof(sum));
    printf("&sum[0] = %p, use sum, not &sum[0]\n", sum);

    //测试字符串
    printf("size of char : %ld\n", sizeof(char));
    printf("str0 is %s\n", str0);
    printf("size of str0 : %ld, as sizeof(str0)\n", sizeof(str0));
    printf("str1 is %s\n", str1);
    printf("size of str1 : %ld, as siceof(str1)\n", sizeof(str1));

    printf("str0 = %s\n", str0);
    printf("&str0[0] = %p, use str0, not &str0[0]\n", str0);
    printf("str1 = %s\n", str1);
    printf("&str1[0] = %p, use str1, not &str1[0]\n", str1);


    //练习9实验附加题
    //str1[0] = 1;
    //printf("str1[0] as int = %d\n", str1[0]);
    int *p = (int *)str0;
    *p = 1;
    printf("str0-4byte as int = %d\n", *p);



    return 0;
}
