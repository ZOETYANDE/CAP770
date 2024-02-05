#include <iostream>

using namespace std;

int  main(){
    int arr[100];
    int location, n, data;    

    cout<<"How many numbers do you want: "<<endl;
    cin>>n;

    cout<<"Provide the array elements: ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the data to be inserted: ";
    cin>>data;
    cout<<"Enter insertion position: ";
    cin>>location;
    n = n + 1;
    for(int i = n-1; i >= location; i--)
        arr[i] = arr[i-1];
    
    arr[location - 1] = data;

    cout<<"The new array is: ";

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
};