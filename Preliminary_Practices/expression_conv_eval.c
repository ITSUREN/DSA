#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_Length 50 // Maximum characters that may be processed

int precedence(char); // Function Protyping

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

/*
void debug_stack(char Stack[MAX_Length],int length){
    printf("[ ");
    for (int i=0; i<length; i++){
        printf("%c,",Stack[i]);
    }
    printf("\b ]");
}
*/

void InfixtoPostfix(){
    //int debugvar=0;
    char infix[MAX_Length], PostStack[MAX_Length], OpStack[MAX_Length];
    int otos=-1,ptos=-1,length;
    printf("Enter the Infix Word: ");
    scanf("%s",infix);
    length = strlen(infix);
    //printf("\n >[DEBUG] Variable length=%d",length);
    for (int i=0;i<=length;i++){
        /*
        printf("\n >[DEBUG] Array ran: %d , len= %d with PostStack=", ++debugvar,length);
        debug_stack(PostStack,ptos+1);
        printf(" and OptStack=");
        debug_stack(OpStack,otos+1);
        printf(" | otos=%d and ptos=%d", otos,ptos);
        */
        if (infix[i]=='(') { // starting open braces
            OpStack[++otos]=infix[i];
            //printf("\n >[DEBUG] Triggerd starting curly braces push to opstack\n");
        }
        else if(isalpha(infix[i])) { // alphabets
            PostStack[++ptos]=infix[i];
            //printf("\n >[DEBUG] Triggered Alphabetic push to post\n");
        }
        else if(infix[i]==')') { 
            while (OpStack[otos]!='('){ // ending open braces
                PostStack[++ptos] = OpStack[otos--];
            }
            otos--; //to skip
            //printf("\n> [DEBUG] Triggerd ending curly braces push to opstack\n");
        }
        else {//Operators 
            while (otos != -1 && precedence(OpStack[otos]) >= precedence(infix[i])) {
                PostStack[++ptos] = OpStack[otos--];
            }
            OpStack[++otos] = infix[i];
            //printf("\n >[DEBUG] Triggered operator push to post and opstack\n"); 
        }
    }
    while (otos!=-1){
        PostStack[++ptos]=OpStack[otos];
        otos--;
    }
    display(PostStack,ptos,0);
}

void InfixtoPrefix(){
    //int debugvar=0;
    char infix[MAX_Length], PreStack[MAX_Length], OpStack[MAX_Length];
    int otos=-1,ptos=-1, length;
    printf("Enter the Infix word: ");
    scanf("%s",infix);
    //reverseString(infix); //strrev didn't work on linux becuase non standard 
    length=strlen(infix);
    for (int i=length;i>=0;i--) {
        /*
        printf("\n >[DEBUG] Array ran: %d , length= %d with PreStack=", ++debugvar,length);
        debug_stack(PreStack,ptos+1);
        printf(" and OptStack=");
        debug_stack(OpStack,otos+1);
        printf(" | otos=%d and ptos=%d", otos,ptos);
        */
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

int precedence(char ch){
    switch(ch) {
        case '$': // exponent
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 1;
    }
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