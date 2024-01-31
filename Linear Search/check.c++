#include <iostream>

using namespace std;

int main() {
    int arr[5] = {4, 7, 2, 1, 9};
    int n;

    cout<<"Which value are looking for? ";
    cin>>n;
    for(int i = 0 ; i < 5; i++){
        if(n == arr[i]){
            cout<<"Number found"<<endl;
            break;
        }
        else{
            cout<<"Number not found";
        }
    }
    return 1;
}