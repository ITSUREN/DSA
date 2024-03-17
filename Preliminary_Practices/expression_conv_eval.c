#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "./modules/Log.c"
#include "expression_conversion.c"
#include "expression_evaluation.c"

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