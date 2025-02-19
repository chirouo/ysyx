# 编译器设置
CC = gcc
CFLAGS = -Wall -Werror

# 目标文件
TARGET = yemu
SRC = yemu.c

# 默认目标
all: $(TARGET)

# 编译规则
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 清理目标文件和可执行文件
clean:
	rm -f $(TARGET)

.PHONY: all run clean
