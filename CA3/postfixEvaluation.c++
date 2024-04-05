#include <iostream>

#define MAX 100

using namespace std;

// Function Definition
void initialize(struct Stack *);
void push(struct Stack *, int);
int pop(struct Stack *);
int is_operator(char);
int evaluate_postfix(char *);

struct Stack {
    int items[MAX];
    int top;
};


int main() {
    char postfix_expression[MAX];

    cout<<"Enter postfix expression separated by spaces: ";
    fgets(postfix_expression, MAX, stdin);

    int result = evaluate_postfix(postfix_expression);
    cout<<"Result: "<<result;

    return 0;
}

void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    return s->items[(s->top)--];
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluate_postfix(char *expression) {
    struct Stack stack;
    initialize(&stack);

    while (*expression) {
        if (isdigit(*expression)) {
            push(&stack, *expression - '0');
        } else if (is_operator(*expression)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (*expression) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
        expression++;
    }

    return pop(&stack);
}
