#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(int);
    int target;
    
    cout << "Enter the target element from 1 to 9: ";
    cin >> target;

    int hi = n - 1;
    int lo = 0;
    int ans = -1;   
    bool found = false;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) {
            ans = mid;
            found = true;
            break;   
        } 
        else if (arr[mid] > target) {
            hi = mid - 1;
        } 
        else {
            lo = mid + 1;
        }
    }

    if (found) {
        cout << "Target found at index: " << ans;
    } else {
        cout << "Element not found, brother";
    }

    return 0;
}
