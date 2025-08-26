/*3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1 
distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array 
(a) Linear time 
(b) Using binary search. */
// i am letting n=10 ;

#include<iostream>
using namespace std ;
int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int n=sizeof(arr)/sizeof(int) ;// i can also take it from user
  // a part 
  int target  ;
  cout<<"Enter the target elemnt from 1 to 10 :";
  cin>>target;
  for (int i=0 ;i<n ;i++){
      if(arr[i]==target){
        cout<<"Target found roaming at index :"<<i;
          break ;
      }
  }
  return 0 ;
}