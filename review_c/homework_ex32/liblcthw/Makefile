CC = gcc
CFLAGS = -g -Wall -O2 -I./src/lcthw  # 添加 -I./test，确保 minunit.h 能被找到
TARGET = minunit
SOURCES = src/lcthw/list.c src/lcthw/test/minunit.c
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
