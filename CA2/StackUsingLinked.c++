#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value);//Function Prototype
int pop();
int Display();
bool isEmpty();

int main(){
    int ch, number, poppedElement;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            cout<<"Enter the number to be added: "<<endl;
            cin>>number;
            push(number);
            break;
            case 2:
            poppedElement = pop();
            break;
            case 3:
            cout<<Display()<<endl;
            break;
            case 4:
            exit(1);
            default:
            cout<<"Incorrect choice \n";
        }
    }
}

Node* createNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void push(int value){
    Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    Node* temp = top;
    int data = temp->data;
    top = top->next;
    delete temp;
    return data;
}

int Display(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }

    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}