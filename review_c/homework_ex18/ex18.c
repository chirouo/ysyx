#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);
typedef int *(*sort_function)(int *numbers, int count, compare_cb cmp);


/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, sort_function sort, compare_cb cmp) {
    int i = 0;
    int *sorted = sort(numbers, count, cmp);

    if (!sorted) die("Failed to sort as requested.");

    printf("Sorted: ");
    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
}


// 快速排序实现
int *quick_sort(int *numbers, int count, compare_cb cmp) {
    if (count < 2) return numbers;

    int pivot = numbers[count / 2];
    int i, j = 0, k = 0;

    int *left = malloc(count * sizeof(int));
    int *right = malloc(count * sizeof(int));
    int *result = malloc(count * sizeof(int));

    if (!left || !right || !result) {
        free(left);
        free(right);
        free(result);
        return NULL;
    }

    for (i = 0; i < count; i++) {
        if (i == count / 2) continue;
        if (cmp(numbers[i], pivot) < 0) {
            left[j++] = numbers[i];
        } else {
            right[k++] = numbers[i];
        }
    }

    int *sorted_left = quick_sort(left, j, cmp);
    int *sorted_right = quick_sort(right, k, cmp);

    memcpy(result, sorted_left, j * sizeof(int));
    result[j] = pivot;
    memcpy(result + j + 1, sorted_right, k * sizeof(int));

    free(left);
    free(right);
    return result;
}

int main(int argc, char **argv)
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }
    printf("Testing Bubble Sort :\n");
    test_sorting(numbers, count, bubble_sort, sorted_order);
    printf("Testing Quick Sort :\n");
    test_sorting(numbers, count, quick_sort, sorted_order);
    printf("Testing Bubble Sort :\n");
    test_sorting(numbers, count, bubble_sort, reverse_order);
    printf("Testing Quick Sort :\n");
    test_sorting(numbers, count, quick_sort, reverse_order);
    printf("Testing Bubble Sort :\n");
    test_sorting(numbers, count, bubble_sort, strange_order);
    printf("Testing Quick Sort :\n");
    test_sorting(numbers, count, quick_sort, strange_order);


    free(numbers);

    return 0;
}
