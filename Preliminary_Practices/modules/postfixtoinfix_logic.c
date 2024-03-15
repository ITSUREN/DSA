#include <string.h>
#include <ctype.h>

#define MAXLENGTHS 50

char OperandsStack[MAXLENGTHS][MAXLENGTHS], OperatorsStack[MAXLENGTHS];
int TopOperand=-1, TopOperators=-1;

void PushOperand(char *Operand){ // Identifies as void function
    strcpy(OperandsStack[++TopOperand],Operand);
    printf("\n Operand Pushed Current val: %d Operand:%s",TopOperand,Operand);
}

char *PopOperand() {
    return (OperandsStack[TopOperand--]);
    printf("\n Operand Popped Current val: %d",TopOperand);
}

void PushOperator(char Operator) {
    OperatorsStack[++TopOperators]=Operator;
}

char PopOperator() {
    return (OperatorsStack[TopOperators--]);
}

int isEmpty(int t) {
    return !t;
}

displaystringstack() {
    char c;
    for (int i=0;i<TopOperand+1;i++) {
        int j=0;
        while (((c=OperandsStack[i][j])!='\0')||(j<=5)) {
            //printf("\n Triggered display",i+j);
            printf("%c",OperandsStack[i][j++]);
        }
        if (j>=5) {
            //printf("\n [ERR 01]: Couldn't terminate substring withing 20 characters");
        }
    }
}