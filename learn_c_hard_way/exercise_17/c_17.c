#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#define MAXDATA 32
#define MAXROW 5

struct address{
        int id;
        int set;
        char name[MAXDATA];  //为了提前定义出空间
        char email[MAXDATA];
}

struct database{
        struct address row[MAXROW];
}

//注意这定义嵌套结构体很有意思，为什么有时候嵌套的是指针？
//有时候却直接是数据？例如为什么connect要嵌套指针？
struct connect{
        FILE *file;
        struct database *db;
}

void database_load(struct connect *conn)
{
        //注意，大部分系统函数在完成功能的同时均会返回值，通过返回值可判断
        //函数完成的情况。
        int rc = fread(conn->db, sizeof(struct database), 1,conn->file);
        if(!rc) printf("function of fread error\n");
}

void database_open(const char *filename, char mode)
{
        struct connect *conn = malloc(sizeof(struct connect));
        //错误检查(此处为打印错误，实际可写一个错误处理程序)
        if(!conn) printf("conn memery error\n");
        //注意此处为什么创建两次空间？因为connect结构体是保存
        //指针的，即里面数据体的首地址，因此并不包含数据体的空间。
        conn->db = malloc(sizeof(struct database));}
        //错误检查
        if(!conn->db) printf("conn->db memery error\n");

        if(mode == 'c') conn->file = fopen(filename, "w");//创建新空文件
        else {
                conn->file = fopen(filename, "r+");//其他情况接通文件
                if(conn->file) database_load(conn);//如果地址有效，则先加载文件内容
        }

void database_creat(struct connect *conn)
{
        int i = 0;
        for(i = 0; i < MAXROW; i++) {
                struct address *addr = {.id = i, .set = 0};
                //每一步都很妙，如果你是指针而不是数据本体，那访问通过->.
                conn->db->row[i] = addr;
        }
}

void database_write(struct connect *conn)
{
        //此处为什么要调整读写指针？
        //是否是我们的读取操作会改变指针位置？
        //由于write操作是每类操作最后必经历的，
        //因此需要调整。
        rewind(conn->file);
        int rc = fwrite(conn->db, sizeof(struct database), 1, conn->file);
        if(!rc) printf("write error\n");
        //刷新缓冲区什么意思？
        
}

void database_close(struct connect *conn)
{
        //总是可以看出来，他们写的程序总是比较严谨，
        //对于这里，我或许直接就释放内存，他们还考虑
        //了空间是否存在？file流是否关闭？db是否分配了内存？
        if(conn) {
                if(conn->file) fclose(conn->file);
                if(conn->db) free(conn->db);
                free(conn->db);
        }
}

int main(int argc, char *argv[])
{
        char *file = argv[1];
        char mode = argv[2][0];
        database_open(file, mode);

        switch(mode) {
                case 'c':
                        break;
                case 's':
                        break;

        }
        return 0;
}
