#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";
    int hex_number = 255;
    int oct_number = 64;
    int neg_number = -12345;
    char empty_string[] = "";

    // 基础打印
    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

    // 打印空字符串
    printf("An empty string: \"%s\"\n", empty_string);

    // 八进制和十六进制打印
    printf("Hexadecimal (255 in hex): %x\n", hex_number);
    printf("Hexadecimal with uppercase letters (255 in HEX): %X\n", hex_number);
    printf("Octal (64 in octal): %o\n", oct_number);

    // 打印带符号的数字
    printf("Signed number (negative): %d\n", neg_number);
    printf("Unsigned number (negative interpreted as unsigned): %u\n", neg_number);

    // 指定宽度和对齐
    printf("Right-aligned (width 10): %10d\n", distance);
    printf("Left-aligned (width 10): %-10d|\n", distance);

    // 打印浮点数的多种格式
    printf("Scientific notation: %e\n", power);
    printf("Fixed-point notation: %f\n", power);
    printf("Shortest representation (auto scientific or fixed): %g\n", power);

    return 0;
}

