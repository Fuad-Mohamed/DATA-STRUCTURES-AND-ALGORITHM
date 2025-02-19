#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int current_length = 5;
    int position;

    printf("Original Array: ");
    for (int i = 0; i < current_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter deletion position (0-%d): ", current_length - 1);
    scanf("%d", &position);

    if (position < 0 || position >= current_length) {
        printf("Error: Invalid position!\n");
        return 1;
    }

    for (int i = position; i < current_length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    current_length--;

    printf("Array after deletion: ");
    for (int i = 0; i < current_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
