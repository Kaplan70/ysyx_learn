#include <stdio.h>
#include <dlfcn.h>
#include "dbg.h"

#define LIB_FILE "build/lib_c29.so"

typedef int (*lib_function)(const char *data);

int main()
{

        //获取对应参数
        char *data = "Data is She";

        //打开库
        void *lib = dlopen(LIB_FILE, RTLD_LAZY); //此函数会返回句柄，待后面使用
        check(lib, "faild open lib %s:%s.", LIB_FILE, dlerror());

        //测试库函数01
        char *func_torun01 = "printf_message";
        lib_function func01 = dlsym(lib, func_torun01);
        check(func01, "faild fund function %s:%s", func_torun01, dlerror());
        //使用函数
        int rc;
        rc = func01(data);
        check(rc == 0, "function %s return %d", func_torun01, rc);

        //测试02
        char *func_torun02 = "uppercase";
        lib_function func02 = dlsym(lib, func_torun02);
        check(func02, "faild fund function %s:%s", func_torun02, dlerror());
        //使用函数
        rc = func02(data);
        check(rc == 0, "function %s return %d", func_torun02, rc);

        //测试03
        char *func_torun03 = "lowercase";
        lib_function func03 = dlsym(lib, func_torun03);
        check(func03, "faild fund function %s:%s", func_torun03, dlerror());
        //使用函数
        rc = func03(data);
        check(rc == 0, "function %s return %d", func_torun02, rc);
        
        //关闭库
        rc = dlclose(lib);
        check(rc == 0, "faild to close %s", LIB_FILE);

        return 0;

error:
        return 1;
}
