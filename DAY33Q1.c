#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main(){
    char infix[100], c;

    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++){
        
        c = infix[i];

        if(isalnum(c)){      // operand
            printf("%c", c);
        }
        else if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while(stack[top] != '(')
                printf("%c", pop());
            pop(); // remove '('
        }
        else{ // operator
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}