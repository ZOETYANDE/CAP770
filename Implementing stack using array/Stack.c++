# include <iostream>

# define SIZE 20
using namespace std;

int stack[SIZE];
int top = -1;

//void getElement(int n, int arr[]);
void push(int);
int pop();
void display();
bool isEmpty();
bool isFull();


int main(){
    int choice;
    int num1 = 0, num2 = 0;
    do{
        cout<<"Select an opartion to do[1-4]:"<<endl;
        cout<<"[1]Push an element into the stack"<<endl;
        cout<<"[2]Pop out an element from the stack"<<endl;
        cout<<"[3]Display the stack elements"<<endl;
        cout<<"[4]Exit"<<endl;

        if(choice == 1){
            cin>>num1;
            push(num1);
        }
        else if(choice == 2){
            num2 = pop();
        }
        else if(choice == 3){
            display();
        }
        else{
            exit(1);
        }
    }while(choice != 4);
}

// int getElements(int stack){
//     for(int i = 0; i < arr.length(); i++){
//         cin>>arr[i];
//     }
// }

// Push function
void push(int n){
    if(isFull()){
        cout<<"Stack is overloaded"<<endl;
        exit(1);
    }
    top += 1;
    stack[top] = n;
    cout<<"\nInsertion Successfull"
}

// Pop function
int pop() {
    if(isEmpty()){
        cout<<"Stack is empty";
        exit(1);
    }

    return stack[top--];
}

void display(stack){
    if(isEmpty())
        cout<<"\nStack is empty!!!";
    else{
        int i;
        for(i = top; i > 0; i--){
            cout<<stack[i];
        }
    }
}

bool isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}

bool isFull(){
    if(top == SIZE - 1)
        return true;
    else
        return false;
}