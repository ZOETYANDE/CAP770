#include<iostream>

using namespace std;

int main() {

    int arr[5] = {4, 7, 2, 1, 9};

    int i = 0, min = arr[0], max = arr[0];

    cout<<"The value of your array is: "
    while(i < 5){
        cout<<arr[i]<<" ";
        if(min > arr[i+1]){
            min = arr[i+1];
        }
        if(max < arr[i+1]){
            max = arr[i+1];
        }
        i++;
    }
    cout<<"The maximum value is: "<<max<<"\n";
    cout<<"The minimum value is: "<<min<<"\n";

    return 1;
}