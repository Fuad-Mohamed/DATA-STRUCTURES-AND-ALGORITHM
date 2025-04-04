#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *size, int pos, int value) {
    if (*size >= MAX_SIZE || pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*size)++;
}

void delete(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

int search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void sort(int arr[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void reverse(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void display(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], size = 0, choice, pos, value;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Sort Ascending\n5. Sort Descending\n6. Reverse\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0-based) and value: ");
                scanf("%d %d", &pos, &value);
                insert(arr, &size, pos, value);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &size, pos);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(arr, size, value);
                if (pos != -1) printf("Value found at index %d\n", pos);
                else printf("Value not found!\n");
                break;
            case 4:
                sort(arr, size, 1);
                printf("Array sorted in ascending order.\n");
                break;
            case 5:
                sort(arr, size, 0);
                printf("Array sorted in descending order.\n");
                break;
            case 6:
                reverse(arr, size);
                printf("Array reversed.\n");
                break;
            case 7:
                display(arr, size);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
