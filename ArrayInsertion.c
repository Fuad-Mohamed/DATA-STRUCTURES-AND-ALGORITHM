#include<stdio.h>
void main()
{
    int arr[6] = {1,2,3,4,0};
    int n = 4;
    int element = 5;

    /*Arrays Before Insertion */
    printf("ARRAY BEFORE INSERTION \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    /*Shifting Arrays To the right*/
    for(int i = n - 1; i >= 0; i--){
      arr[i + 1] = arr[i];
    }
    printf("\n");

    arr[0] = element;

        printf("ARRAY AFTER INSERTION \n");
      for( int i = 0; i <= n; i++){
        printf("%d ", arr[i]);
      }

}
