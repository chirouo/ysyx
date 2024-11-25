#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;

    // 打印原始 argv 和 states
    printf("Original arguments:\n");
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    printf("\nOriginal states:\n");
    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    // 1. 将 states[0] 的值赋给 argv[1]
    if (argc > 1) { // 确保 argv[1] 存在
        argv[1] = states[0]; // 将 "California" 赋值给 argv[1]
    }

    // 2. 将 argv[1] 的值赋给 states[1]
    if (argc > 1) { // 确保 argv[1] 存在
        states[1] = argv[1]; // 将 argv[1] 赋值给 states[1]
    }

    // 打印修改后的 argv 和 states
    printf("\nModified arguments:\n");
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    printf("\nModified states:\n");
    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

