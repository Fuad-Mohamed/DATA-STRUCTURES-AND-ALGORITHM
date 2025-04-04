#include<stdio.h>
int main()
{
    int arr[6] = {1,2,3,4,0};
    int n = 4;
    int position = 3;
    int element = 50;

    /*BEORE INSERTION*/

    printf("BEFORE INSERTION \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    /*DURING INSERTION*/
    for(int i = n; i >= position; i--){
        arr[i] =arr[i - 1];
    }

     arr[position - 1] = element;
    /*AFTER INSERTION*/
    printf("\n AFTER INSERTION \n");
    for(int i = 0; i <= n; i++){
        printf("%d ", arr[i]);
    }

}
