#include "./debug_stack.c"
//#include "./precedence.c" //somehow already got it from the conversion side
#include <math.h>

#define MAXLENGTH 50 // Maximum characters that may be processed

int ValueStack[MAXLENGTH],VTopofStack=-1,OTopofStack=-1;
char OperatorStack[MAXLENGTH];

// Value Stack Operations
void pushv(int value) {
    ValueStack[++VTopofStack]=value;
}

int popv() {
    return ValueStack[VTopofStack--];
}

void DebugVStack() {
    debug_stack_int(ValueStack,VTopofStack);
}


// Operator Stack Operations
void pusho(char value) {
    OperatorStack[++OTopofStack]=value;
}

char popo() {
    return OperatorStack[OTopofStack--];
}

void DebugOperatorStack() {
    debug_stack(OperatorStack,OTopofStack);
}

int precedenceOperator(){
    return precedence(OperatorStack[OTopofStack]);
}

int OStackisEmpty(){
    if (OTopofStack<0) {
        return 1;
    }
    else return 0;
}

// Inputs and Outputs
void displayresult() {
    printf("\n\n[RES] The result is: %d\n",popv());
}

// Oerator Evaluation
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
        case '%':// Not used in conversion side of things 
            return ((int)Operand1%(int)Operand2);
        case '*':
            return (Operand1*Operand2);
        default:
            printf("\n[ERR 01] Invalid Operator\n");
            exit(1); //Same as Exit Failure
    }
}

