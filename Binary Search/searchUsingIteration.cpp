#include <iostream>

using namespace std;


int binarySearch(int arr[], int x, int low, int high){

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }

    return -1;

}
int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = n - 1;
    int x = 4;

    int result = binarySearch(arr, x, low, high);

    if(result != -1){
        cout<<"Item found: "<<arr[result]<<" at ["<<result<<"] Position"<<endl;
    }

    else{
        cout<<"Item not found"<<endl;
    }
    
    // cout<<"Enter the value to search: ";
    // cin>>x

    return 0;
}