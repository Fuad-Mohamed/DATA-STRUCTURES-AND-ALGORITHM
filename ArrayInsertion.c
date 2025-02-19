#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int current_length = 5;
    int new_element, position;

    printf("Original Array: ");
    for (int i = 0; i < current_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter element to insert: ");
    scanf("%d", &new_element);
    printf("Enter insertion position (0-%d): ", current_length);
    scanf("%d", &position);

    if (position < 0 || position > current_length) {
        printf("Error: Invalid position!\n");
        return 1;
    }

    if (current_length >= MAX_SIZE) {
        printf("Error: Array is full!\n");
        return 1;
    }

    for (int i = current_length; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = new_element;
    current_length++;

    printf("Array after insertion: ");
    for (int i = 0; i < current_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
