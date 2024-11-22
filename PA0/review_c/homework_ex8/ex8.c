#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
         ' ', 'A', '.', ' ',
         'S', 'h', 'a', 'w'
    };

    // 打印初始值
    printf("Initial values:\n");
    printf("areas[0]: %d\n", areas[0]);
    printf("name: %s\n", name);
    printf("full_name: %s\n", full_name);

    // 1. 修改 areas 的值
    areas[0] = 100;
    areas[2] = 200;
    printf("\nAfter modifying areas:\n");
    printf("areas[0]: %d\n", areas[0]);
    printf("areas[2]: %d\n", areas[2]);

    // 2. 修改 name 和 full_name 的值
    name[0] = 'J';
    name[1] = 'o';
    name[2] = 'e';  // 修改字符串内容
    full_name[4] = 'B'; // 修改 full_name 中的 'A'
    full_name[5] = '!'; // 修改 full_name 中的 '.'
    printf("\nAfter modifying name and full_name:\n");
    printf("name: %s\n", name);
    printf("full_name: %s\n", full_name);

    // 3. 将 name 中的字符赋值给 areas 的元素
    areas[4] = name[0]; // 将 name[0] 的字符 'J' 的 ASCII 值赋给 areas[4]
    printf("\nAfter assigning name[0] to areas[4]:\n");
    printf("areas[4]: %d (ASCII of '%c')\n", areas[4], areas[4]);

    // 查看最终值
    printf("\nFinal values:\n");
    printf("areas: %d, %d, %d, %d, %d\n", areas[0], areas[1], areas[2], areas[3], areas[4]);
    printf("name: %s\n", name);
    printf("full_name: %s\n", full_name);

    return 0;
}

