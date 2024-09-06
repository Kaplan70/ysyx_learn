#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#define MAXDATA 32
#define MAXROW 5

//数据库流程
//如何写入数据到文件？连接文件-置入数据-写入数据到文件。
//如何删除文件中数据？连接文件（并加载数据）-删除存储空间数据-写入数据到文件。
//如何打印单条信息？接通文件-加载数据-得到数据（内调用打印单条数据）。
//如何列出数据在显示屏上？连接文件（并加载数据从文件到存储空间）-打印罗列数据。

struct address{
        int id;
        int set;
        char name[MAXDATA];  //为了提前定义出空间
        char email[MAXDATA];
};

struct database{
        struct address row[MAXROW];
};

//注意这定义嵌套结构体很有意思，为什么有时候嵌套的是指针？
//有时候却直接是数据？例如为什么connect要嵌套指针？
struct connect{
        FILE *file;
        struct database *db;
};

//终结程序
void die(const char *message)
{
        printf("ERROR:%s\n", message);
        exit(1);
}

void database_load(struct connect *conn)
{
        //注意，大部分系统函数在完成功能的同时均会返回值，通过返回值可判断
        //函数完成的情况。
        int rc = fread(conn->db, sizeof(struct database), 1, conn->file);
        if(!rc) die("load data error");
}

struct connect* database_open(const char *filename, char mode)
{
        struct connect *conn = malloc(sizeof(struct connect));
        //错误检查(此处为打印错误，实际可写一个错误处理程序)
        if(!conn) die("conn memery error");
        //注意此处为什么创建两次空间？因为connect结构体是保存
        //指针的，即里面数据体的首地址，因此并不包含数据体的空间。
        conn->db = malloc(sizeof(struct database));
        //错误检查
        if(!conn->db) die("conn->db memery error");

        if(mode == 'c') conn->file = fopen(filename, "w");//创建新空文件
        else {
                conn->file = fopen(filename, "r+");//其他情况接通文件
                if(conn->file) database_load(conn);//如果地址有效，则先加载文件内容
        }
        if(!conn->file) die("return conn->file error");
        return conn;
}

void database_creat(struct connect *conn)
{
        int i = 0;
        for(i = 0; i < MAXROW; i++) {
                struct address addr = {.id = i, .set = 0};
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
        if(!rc) die("write error");
        //刷新缓冲区什么意思？
        
}

void database_set(struct connect *conn, int id, const char *name, const char *email)
{
        struct address *addr = &conn->db->row[id];
        addr->set = 1;
        //为什么字符串不能通过直接的赋值来传递值？
        //而要通过一个用来传递字符的函数？
        char *res = strncpy(addr->name, name, MAXDATA);
        if(!res) die("faild to copy name");
        res = strncpy(addr->email, email, MAXDATA);
        if(!res) die("faild to copy email");
}

void address_printf(struct address *addr)
{
        printf("id-%d; name-%s; email-%s;\n", addr->id, addr->name, addr->email);
}

void database_get(struct connect *conn, int id)
{
        //这里很重要，注意这个取指没？
        //更简洁写法= conn->db->row + i
        //这个写法省去了取指符号
        struct address *addr = &conn->db->row[id];
        if(addr->set) address_printf(addr);
        else printf("this id is not set\n");
}

void database_list(struct connect *conn)
{
        struct address *addr;
        int i = 0;
        for(i = 0; i < MAXROW; i++) {
                addr = &conn->db->row[i];
                if(addr->set) address_printf(addr);
        }
}

void database_delete(struct connect* conn, int id)
{
        //更简洁写法conn->db->row + i
        struct address *addr = &conn->db->row[id];
        addr->set = 0;
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
        int id = 0;
        if(argc > 3) id = atoi(argv[3]);

        struct connect *conn;
        conn = database_open(file, mode);

        switch(mode) {
                case 'c':
                        database_creat(conn);
                        database_write(conn);
                        break;
                case 's':
                        if(argc != 6) die("need name and email\n");
                        database_set(conn, id, argv[4], argv[5]);
                        database_write(conn);
                        break;
                case 'g':
                        if(argc != 4) printf("get need id\n");
                        database_get(conn, id);
                        break;
                case 'd':
                        if(argc != 4) printf("delete need id\n");
                        database_delete(conn, id);
                        database_write(conn);
                        break;
                case 'l':
                        database_list(conn);
                        break;

                default:
                        die("input of mode error");

        }
        database_close(conn);
        return 0;
}
