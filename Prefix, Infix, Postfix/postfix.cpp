#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Value{
    
    int value;

    Value *above;
    Value *below;
} *top = NULL;

Value *createValue(int value){

    Value *newValue = (Value*)calloc(1, sizeof(Value));

    newValue->value = value;

    return newValue;
}

int pop(){
    
    int value = top->value;
    top = top->below;
    free(top->above);
    top->above = NULL;

    return value;
}

void push(int value){

    Value *newValue = createValue(value);

    if(top == NULL){
        top = newValue;
        return;
    }

    top->above = newValue;
    newValue->below = top;
    top = top->above;
}

int postfixOperation(char expression[]){

    // printf("%d\n", strlen(expression));

    for(int index = 0; index < strlen(expression); index++){

        // If character is a number, push to stack
        if(expression[index] >= 48 && expression[index] <= 57){
            push(expression[index] - '0');
            // printf("%d\n", top->value);
        }
        
        // printf("%c\n", expression[index]);
        int A = pop();
        int B = pop();
        int value;

        if(expression[index] == '+'){
            value = B + A;
        }

        if(expression[index] == '-'){
            value = B - A;
        }

        if(expression[index] == '*'){
            value = B * A;
        }

        if(expression[index] == '/'){
            value = B / A;
        }
        printf("%d\n", value);
        push(value);
    }

    return top->value;
}

void printStack(){

    Value *cursor = top;
    while(cursor){
        printf("%d", cursor->value);
        cursor = cursor->below;
    }
}


int main(){

    char expression[12] = "2536+**5/2-";

    int answer = postfixOperation(expression);

    printf("%d", answer);

    return 0;
}