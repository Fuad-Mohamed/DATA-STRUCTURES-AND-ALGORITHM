#include<stdio.h>
int main()
{
    int arr[] = {1,2,3,4,0};
    int element = 5;
    int n = 4;


    /*BEFORE INSERTION*/
    printf("BEFORE INSERTION AT THE END \n");
    for(int i = 0;i < n;i++){
        printf("%d ", arr[i]);
    }

    arr[n] = element;

    /*AFTER INSERTION*/
    printf("\nAFTER INSERTION AT THE END \n");
     for(int i = 0;i <= n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
