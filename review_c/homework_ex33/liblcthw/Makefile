CC = gcc
CFLAGS = -g -Wall -O2 -I./src/lcthw -I./src/lcthw/test # 添加 -I./test，确保 minunit.h 能被找到
TARGET = minunit
SOURCES = src/lcthw/test/minunit.c src/lcthw/list_algos.c src/lcthw/list.c   
OBJECTS = $(SOURCES:.c=.o)

# 默认目标
all: $(TARGET)

# 编译目标文件
$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# 链接目标文件生成可执行文件
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# 清理目标文件
clean:
	rm -f $(OBJECTS) $(TARGET)
