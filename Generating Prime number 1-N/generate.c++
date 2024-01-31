#include <iostream>

using namespace std;

int main(){
    int n;
    cout<<"Please provide the range: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    for(int i=1;i<n;i++){
        if(arr[i]!=0){
            for(int j=i+1;j<n;j++){
                if(arr[j]%arr[i]==0){
                    arr[j]=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(arr[i]!=0){
            cout<<arr[i]<<" ";
        }
    }
}