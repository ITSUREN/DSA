#include "./modules/Evaluation_Methods.c"
#define MAXLENGTH 50 // Maximum characters that may be processed

void PrefixEval() {
    char prefix[MAXLENGTH], character;
    int Operand1, Operand2, Result,value;

    printf("Enter a Valid Prefix Expression: ");
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
    displayresults();
}

void InfixEval() {
    char infix[MAXLENGTH], character;
    int Operand1, Operand2, Result,value,numberofbraces=0;
    char Operator;

    printf("Enter a Valid Infix Expression: ");
    scanf("%s",infix);

    for (int i=0; i<strlen(infix);i++) {
        character=infix[i];
        if(isalpha(character)) {
            printf("\n Enter the value of %c: ",character);
            scanf("%d",&value);
            pushv(value);
        }
        else {
            if (character=='('){
                pusho(character);
            } else if (character==')') {
                while ((Operator=popo())!='(') {
                    Operand2=popv();Operand1=popv();
                    pushv(EvaluateOperator(Operand1,Operator,Operand2));
                }
                //popo();//to remove the bracket but NO NEED because the next call removes it
            }
            else if (precedenceOperator()<=precedence(character)) {
                pusho(character);            }
            else {
                Operand2=popv();Operand1=popv();
                Operator=popo();
                pusho(character);
                pushv(EvaluateOperator(Operand1,Operator,Operand2));
            }
        }
    }
    while (!OStackisEmpty()) {
        Operand2=popv();Operand1=popv();
        Operator=popo();
        pushv(EvaluateOperator(Operand1,Operator,Operand2));
    }
    displayresults();
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
    displayresults();
}