#include <stdio.h>
void main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    SEQUENTIAL TRAVERSAL
    for(int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); */

     REVERSE TRAVERSAL
        for(int i = n -1; i >= 0; i--){
            printf("%d ", arr[i]);
        }
    printf("\n");


}
