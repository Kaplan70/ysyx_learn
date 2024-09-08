#-makefile头部-#
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS) #什么叫做用于构建库的其他东西？ 
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c) #搜索所有的.c文件作为源文件。
OBJECTS=$(patsubst %.c,%.o,$(SOURCES)) #转换.c文件作为.o文件生成目标文件。

TEST_SRC=$(wildcard tests/*_tests.c) #寻找测试文件，问题是什么是用于单元测试的测试文件？
TESTS=$(patsubst %.c,%,$(TEST_SRC)) #转换测试文件为对应的可执行文件-目标文件。

TARGET=build/libYOUR_LIBRARY.a #目标为一个库，没太看懂？难道最后制作成一个库用于使用？
SO_TARGET=$(patsubst %.a,%.so,$(TARGET)) #为什么需要转化目标.a为.so？
#--#

# The Target Build
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC #此处为了能够提前修改参数
$(TARGET): build $(OBJECTS) #TARGET需要build & OBJECTS来构建库。以下是如何构建。
       ar rcs $@ $(OBJECTS)
       ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
       $(CC) -shared -o $@ $(OBJECTS)

build: #此处仅仅是创建目录，/build & /bin
       @mkdir -p build
       @mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET) #显然，此处用来增添一些选项。在此处，他链接了我们构建的TARGET库。
tests: $(TESTS)
       sh ./tests/runtests.sh #虽然难以置信，但上行已经是make通过以存在的方式产生了测试文件，
                              #而此行是直接运行已经写好的shell文件，用来调用产生的测试文件。

valgrind:
       VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
       rm -rf build $(OBJECTS) $(TESTS)
       rm -f tests/tests.log
       find . -name "*.gc*" -exec rm {} \;
       rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
       install -d $(DESTDIR)/$(PREFIX)/lib/
       install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
       @echo Files with potentially dangerous functions.
       @egrep $(BADFUNCS) $(SOURCES) || true
