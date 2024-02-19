# include <iostream>
# include <string>

using namespace std;

int linearSearch(string str, string substring, int index);

int main(){

    string str, sub;
    cout<<"Enter the main string: ";
    getline(cin, str);
    cout<<"Enter the substring to be looked for: ";
    getline(cin, sub);

    string found = (linearSearch(str, sub, 0))? "Found":"Not Found";

    cout<<found;
    return 0;
}

int linearSearch(string str, string substring, int index){
    if(substring.empty()){
        return 1;
    }
    if(index >= str.length()){
        return 0;
    }
    if(str[index] == substring[0]){
        return linearSearch(str, substring.substr(1), index + 1);
    }
    else {
        return linearSearch(str, substring, index + 1);
    }
}