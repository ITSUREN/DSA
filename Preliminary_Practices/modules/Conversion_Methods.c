#include <string.h>
#include <ctype.h>

#define MAXLENGTH 50 // Maximum characters that may be processed

char OperandsStack[MAXLENGTH][MAXLENGTH], Result[MAXLENGTH],Operand[2];
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

void display(char stacks[MAXLENGTH], int length, int reverse) {
    printf("\n[RES] The Resultant Expression is: ");
    switch (reverse)
    {
    case 0:
        for (int i=0;i<length;i++) {
            printf("%c", stacks[i]);
        }
        break;
    case 1:
        for (int i=length-1;i>=0;i--) {
            printf("%c",stacks[i]);
        }
        break;
    default:
        printf("\n[ERR 01] (Internal) Unexpected value for rev state passed");
        break;
    } 
    printf("\n");
}