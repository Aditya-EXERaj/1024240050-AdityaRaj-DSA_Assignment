#include <iostream>
using namespace std ;
int main (){
  //bubble sorting
  int arr[]={64,34,25,12,22,11,90};
  int n = sizeof(arr)/sizeof(int);
  
  for (int i=0 ; i <= n-1 ; i++){
      bool sorted = true;
       for (int j=0 ; j<=n-1-i ;j++){
        //now we do swap 
           if (arr[j]>arr[j+1]){
            int temp =arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp ;
            sorted = false ;
           }  
       }
       if(sorted == true){
        break ;
       }
  }

  for ( int k=0 ; k<=n-1 ; k++){
    cout<< arr[k]<<" ";
  }
  return 0 ;
}