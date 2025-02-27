#include <stdio.h>
#include <stdint.h>

// 位域结构体
typedef union {
    struct {
        uint8_t a : 4;
        uint8_t b : 4;
    } bits;
    uint8_t byte;
} BitField;

// 检查端序的联合体
typedef union {
    uint16_t value;
    uint8_t bytes[2];
} EndianTest;

int main() {
    // 测试位域排列
    BitField bf;
    bf.byte = 0x12;  // 0001 0010
    printf("位域测试:\n");
    printf("完整字节: 0x%02x\n", bf.byte);
    printf("低4位(a): 0x%x\n", bf.bits.a);
    printf("高4位(b): 0x%x\n", bf.bits.b);

    // 测试端序
    EndianTest et;
    et.value = 0x1234;
    printf("\n端序测试:\n");
    printf("完整数值: 0x%04x\n", et.value);
    printf("第一个字节: 0x%02x\n", et.bytes[0]);
    printf("第二个字节: 0x%02x\n", et.bytes[1]);

    return 0;
}
