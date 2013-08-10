/* Paras Narang
 *
 * LIS using DP
 */
#include<iostream>

using namespace std;

int lis(int arr[], int n ){
    int *lis, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    for(int i = 0; i < n; i++ )
      lis[i] = 1;

    for(int i = 1; i < n; i++ )
        for(int j = 0; j < i; j++ )
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for(int i = 0; i < n; i++ )
        if(max < lis[i] )
            max = lis[i];

   free( lis );
   return max;
}

int main(){
    int arr[] = { 5, 15, 3, 32, 12, 42, 13, 80, 99 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Length of LIS : " << lis( arr, n ) << endl;
    return 0;
}
