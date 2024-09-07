#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//关键是定义通用模板的函数指针
typedef int (*arith)(int a, int b);

int sum_a(int a, int b)
{
       return a + b; 
}

int mul_a(int a, int b)
{
       return a * b;
}

int setdata(int *data, int count, arith posedata)
{
        int result = 1;
        int i;
        //强行传递指针，但作用数据空间不同
        //即，通过传递的指针所指的数据重新
        //开辟一块空间来储存。
        int *dataset = malloc(count * sizeof(int));
        memcpy(dataset, data, count * sizeof(int));

        for(i = 0; i < count; i++) {
                result = posedata(result, dataset[i]);
        }
        //注意，开辟了空间就需要释放
        free(dataset);
        return result; 
}


int main(int argc, char *argv[])
{
        //生成数据
        int i = 0;
        int count = argc - 1;
        int *data = malloc(count * sizeof(int));
        for(i = 0; i < count; i++) {
                data[i] = atoi(argv[i+1]);
        }
        
        //处理数据
        //通过传递函数指针，来执行不同的操作。
        int sum_data = setdata(data, count, sum_a);
        int mul_data = setdata(data, count, mul_a);
        printf("sum = %d; mul = %d\n", sum_data, mul_data);
        free(data);
}
