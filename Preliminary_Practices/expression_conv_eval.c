#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "./modules/precedence.c"
#include "./modules/debug_stack.c"

#define MAX_Length 50 // Maximum characters that may be processed

void display(char stacks[MAX_Length], int length, int rev) {
    printf("\n[RES] The Result is: ");
    switch (rev)
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

void InfixtoPostfix(){
    char infix[MAX_Length], PostStack[MAX_Length], OpStack[MAX_Length];
    int otos=-1,ptos=-1,length, debugvar=0;
    printf("Enter the Infix Word: ");
    scanf("%s",infix);
    length = strlen(infix);
    for (int i=0;i<=length;i++){
        debug_print(&debugvar,length,PostStack,ptos,OpStack,otos);
        if (infix[i]=='(') { // starting open braces
            OpStack[++otos]=infix[i];
        }
        else if(isalpha(infix[i])) { // alphabets
            PostStack[++ptos]=infix[i];
        }
        else if(infix[i]==')') { 
            while (OpStack[otos]!='('){ // ending open braces
                PostStack[++ptos] = OpStack[otos--];
            }
            otos--; //to remove the ')'
        }
        else {//Operators 
            while (otos != -1 && precedence(OpStack[otos]) >= precedence(infix[i])) {
                PostStack[++ptos] = OpStack[otos--];
            }
            OpStack[++otos] = infix[i];
        }
    }
    while (otos!=-1){
        PostStack[++ptos]=OpStack[otos];
        otos--;
    }
    display(PostStack,ptos,0);
}

void InfixtoPrefix(){
    char infix[MAX_Length], PreStack[MAX_Length], OpStack[MAX_Length];
    int otos=-1,ptos=-1, length,debugvar=0;
    printf("Enter the Infix word: ");
    scanf("%s",infix);
    length=strlen(infix);
    for (int i=length;i>=0;i--) {
        debug_print(&debugvar,length,PreStack,ptos,OpStack,otos);
        if(infix[i]==')') {
            OpStack[++otos]=infix[i];
        }
        else if (isalpha(infix[i])){
            PreStack[++ptos]=infix[i];
        }
        else if (infix[i]=='(') {
            while (OpStack[otos]!=')') {
                PreStack[++ptos]=OpStack[otos--];
            }
            otos--; //to discard '(' from OpStack
        }
        else {
            while (otos != -1 && precedence(OpStack[otos]) > precedence(infix[i])) {
                PreStack[++ptos] = OpStack[otos--];
            }
            OpStack[++otos] = infix[i];
        }
    }
    while(otos!=-1) {
        PreStack[++ptos]=OpStack[otos--];
    }
    display(PreStack,ptos,1);
}

void PostfixtoInfix() {
    // todo
}

void PrefixtoInfix(){
    // todo
}

void PrefixEval() {
    //todo
}

void InfixEval() {
    //todo
}

void PostfixEval() {
    //todo
}

void menu_conv() {
    int choice;
    system("clear");
    printf("\nMENU: Conversion\n\n1. prefix->infix\n2. infix->prefix\n3. infix->postfix\n4. postfix->infix\n\n=> ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            PrefixtoInfix();
            break;
        case 2:
            InfixtoPrefix();
            break;
        case 3:
            InfixtoPostfix();
            break;
        case 4:
            PostfixtoInfix();
            break;
        default:
            printf("\n[ERR 02]: Invalid Input.\n"); 
    }
}

void menu_eval() {
    int choice;
    system("clear");
    printf("\nMENU: Evaulations\n\n1. prefix\n2. infix\n3. postfix\n\n=> ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            PrefixEval();
            break;
        case 2:
            InfixEval();
            break;
        case 3:
            PostfixEval();
            break;
        default:
            printf("\n[ERR 03]: Invalid Input.\n");
    }
}


void menu() {
    int choice;
    system("clear");
    printf("\nMENU: \n\n1. Expresion Conversions\n2. Expression Evaluations\n\n=> ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            menu_conv();
            break;
        case 2:
            menu_eval();
            break;
        default:
            printf("\n[ERR 01]: Invalid Input\n");
    }
}

int main(){
   menu(); 
}