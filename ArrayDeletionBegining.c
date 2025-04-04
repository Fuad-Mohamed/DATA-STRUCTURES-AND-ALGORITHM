#include<stdio.h>
int  main()
{

    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/ sizeof(arr[0]);

    /*ARAAY BEFORE DELETION*/
    printf("ARRAY BEFORE DELETION\n");
    for(int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }

    /*ARAAY DURING DELETION*/
    for(int i = 1; i < n;i++){
        arr[i - 1] = arr[i];
    }

    n--;

    /*ARAAY AFTER DELETION*/
        printf("\nARRAY AFTER DELETION\n");
    for(int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }
}
