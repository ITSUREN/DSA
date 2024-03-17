#include <math.h>
//#include "./precedence.c"
#define MAXLENGTH 50 // Maximum characters that may be processed

int ValueStack[MAXLENGTH], OperatorStack[MAXLENGTH];
int VTopofStack=-1,OTopofStack=-1;

void pushv(int value) {
    ValueStack[++VTopofStack]=value;
}

int popv() {
    return ValueStack[VTopofStack--];
}

void pusho(int value) {
    OperatorStack[++OTopofStack]=value;
}

int popo() {
    return OperatorStack[OTopofStack--];
}

int precedenceOperator(){
    return precedence(OperatorStack[OTopofStack]);
}

int EvaluateOperator(int Operand1,char Operator,int Operand2) {
    switch(Operator) {
        case '$':
        case '^':
            return powers(Operand1,Operand2);
        case '+':
            return (Operand1+Operand2);
        case '-':
            return (Operand1-Operand2);
        case '/':
            return (Operand1/Operand2);
        case '%':// Not used in conversion 
            return ((int)Operand1%(int)Operand2);
        case '*':
            return (Operand1*Operand2);
        default:
            printf("\n[ERR 01] Invlid Operator\n");
    }
}
