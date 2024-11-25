#include <stdio.h>

int main() {
    int value = 0x64655a; // 假设整数表示字符 'Z', 'e', 'd'
    char *name = (char *)&value;

    printf("name from integer: %c%c%c%c\n", name[0], name[1], name[2], name[3]);

    return 0;
}

