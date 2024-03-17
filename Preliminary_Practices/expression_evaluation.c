#include "./modules/Evaluation_Methods.c"
//#include "./modules/debug_stack.c"
#define MAXLENGTH 50 // Maximum characters that may be processed

void PrefixEval() {
    char prefix[MAXLENGTH], character;
    int Operand1, Operand2, Result,value;

    printf("Enter a Valid Postfix Expression: ");
    scanf("%s",prefix);

    for (int i=strlen(prefix); i>=0;i--) {
        character=prefix[i];
        if(isalpha(character)) {
            printf("\n Enter the value of %c: ",character);
            scanf("%d",&value);
            pushv(value);
        }
        else {
            Operand1=popv();Operand2=popv();
            pushv(EvaluateOperator(Operand1,character,Operand2));
        }
    }
    printf("\n\n[RES] The result is: %d\n",popv());
}

void InfixEval() {
    
}

void PostfixEval() {
    char postfix[MAXLENGTH], character;
    int Operand1, Operand2, Result,value;

    printf("Enter a Valid Postfix Expression: ");
    scanf("%s",postfix);

    for (int i=0; i<=(strlen(postfix)-1);i++) {
        character=postfix[i];
        if(isalpha(character)) {
            printf("\n Enter the value of %c: ",character);
            scanf("%d",&value);
            pushv(value);
        }
        else {
            Operand2=popv();Operand1=popv();
            pushv(EvaluateOperator(Operand1,character,Operand2));
        }
    }
    printf("\n\n[RES] The result is: %d\n",popv());
}