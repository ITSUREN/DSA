#include <string.h>
#include <ctype.h>

#define MAXLENGTHS 50

char OperandsStack[MAXLENGTHS][MAXLENGTHS], Result[MAXLENGTHS],Operand[2];
int TopOperand=-1;

void PushOperand(char *Operand){ 
    strcpy(OperandsStack[++TopOperand],Operand);
}

char *PopOperand() {
    return (OperandsStack[TopOperand--]);
}

char *displaystringstack() {
    char c;
    strcpy(Result,"");
    for (int i=0;i<=TopOperand;i++) {
        for (int j=0;OperandsStack[i][j]!='\0';j++) {
            //writeLog("\n > i=%d, j=%d and char=%c",i,j,OperandsStack[i][j]);
            Operand[0]=OperandsStack[i][j];Operand[1]='\0'; //conversion to string
            strcat(Result,Operand);
        }
    }
    return Result;
}