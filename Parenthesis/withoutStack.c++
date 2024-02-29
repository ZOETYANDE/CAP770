#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
char expression[50]; // declaration of char type array
int x=0, i=0; // declaration of two integer type variables
cout<<"\nEnter an expression: ";
scanf("%[^\n]s", expression);
// Scanning the expression until we reach the end of the expression.
while(expression[i]!= '\0')
{
    // Condition to check the symbol is '(' or '{' or '['
    if(expression[i]=='(' || expression[i] == '{' || expression[i] == '[')
    {
        x++; // incrementing 'x' variable
    }
    // condition to check the symbol is ')' or '}' or ']' 
    else if(expression[i]==')' || expression[i] == '}' || expression[i] == ']')
    {
        x--; // decrementing 'x' variable
        if(x<0)
        break;
    }
    i++; // incrementing 'i' variable.
}
// Condition to check whether x is equal to 0 or not.
if(x==0)
{
    cout<<"Expression is balanced"<<endl;
}

else
{
    cout<<"Expression is unbalanced"<<endl;
}
return 0;
}