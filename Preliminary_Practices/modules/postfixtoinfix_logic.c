#include <string.h>
#include <ctype.h>

#define MAXLENGTHS 50

char OperandsStack[MAXLENGTHS][MAXLENGTHS], OperatorsStack[MAXLENGTHS], RES[MAXLENGTHS],OP[2];
int TopOperand=-1, TopOperators=-1;

void PushOperand(char *Operand){ // Identifies as void function
    strcpy(OperandsStack[++TopOperand],Operand);
    //printf("\n[Debug] Operand Pushed Current val: %d Operand:%s",TopOperand,Operand);
}

char *PopOperand() {
    return (OperandsStack[TopOperand--]);
    //printf("\n[Debug] Operand Popped Current val: %d",TopOperand);
}

/*
void PushOperator(char Operator) {
    OperatorsStack[++TopOperators]=Operator;
}

char PopOperator() {
    return (OperatorsStack[TopOperators--]);
}

int isEmpty(int t) {
    return !t;
}
*/

char *displaystringstack() {
    char c;
    strcpy(RES,"");
    //writeLog("\n Display String Triggered.\n");
    for (int i=0;i<=TopOperand;i++) {
        int j=0;
        while ((OperandsStack[i][j]!='\0')) {
            //writeLog("\n > i=%d, j=%d and char=%c",i,j,OperandsStack[i][j]);
            OP[0]=OperandsStack[i][j++];OP[1]='\0';
            strcat(RES,OP);
            //printf("%c",OperandsStack[i][j++]);
        }
    }
    return RES;
}