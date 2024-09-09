#include <stdio.h>
#include <dlfcn.h>
#include "dbg.h"

typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[])
{
        check(argc == 4, "example: ./main c_29_lib.so function data");

        //获取对应参数
        char *lib_file = argv[1];
        char *func_torun = argv[2];
        char *data = argv[3]; 

        //打开库
        void *lib = dlopen(lib_file, RTLD_NOW); //此函数会返回句柄，待后面使用
        check(lib, "faild open lib %s:%s.", lib_file, dlerror());

        //获取库函数
        lib_function func = dlsym(lib, func_torun);
        check(func, "faild fund function %s:%s", func_torun, dlerror());

        //使用函数
        int rc;
        rc = func(data);
        check(rc == 0, "function %s return %d", func_torun, rc);
        
        //关闭库
        rc = dlclose(lib);
        check(rc == 0, "faild to close %s", lib_file);

        return 0;

error:
        return 1;
}
