#include <iostream>

using namespace std;

int  main(){
    int arr[100];
    int location, n, data, int t;    

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
    for(int i = location; i < n; i++) {
        arr[location] = arr[i];
        location++;
    }
    n = n + 1;

    for(int i = 0; i < n; i++){
        cout<<arr[i];
    }


    return 0;
};