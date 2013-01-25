/* Paras Narang 
 * Kadane's Algorithm
 * Maximum Contiguous Subsequence
 * */
#include <iostream>
using namespace std;

int kadane(int *arr, int size){
  int current_max=0, max=0;
  int current_start_index=0, max_start_index=0, max_end_index=0;
  for(int current_end_index=0; current_end_index<size; current_end_index++){
    current_max = current_max + arr[current_end_index];
    if(current_max<0){
      current_max = 0;
      current_start_index = current_end_index + 1;
    }
    if(current_max>max){
      max = current_max;
      max_start_index = current_start_index;
      max_end_index = current_end_index;
    }
  }
  //cout<<"Start : "<<max_start_index<<endl;
  //cout<<"End : "<<max_end_index<<endl;
  //cout<<"Max Sum : "<<max<<endl;
  return max;
}

int main(){
    int a[] = {-1, 5, 7, -2, 9, -8, -1, 8, -15, 4, 3, 10};
    int max_sum = kadane(a,12);
    cout<<"Max Sum : "<<max_sum<<endl;
    return 0;
}
