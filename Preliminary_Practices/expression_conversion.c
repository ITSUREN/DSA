#include "./modules/Conversion_Methods.c"
#define MAXLENGTH 50 // Maximum characters that may be processed

void InfixtoPostfix(){
    char infix[MAXLENGTH], PostStack[MAXLENGTH], OpStack[MAXLENGTH];
    int otos=-1,ptos=-1,length, debugvar=0;
    printf("Enter the Infix Word: ");
    scanf("%s",infix);
    length = strlen(infix);
    for (int i=0;i<=length;i++){
        //debug_print(&debugvar,length,PostStack,ptos,OpStack,otos);
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
    char infix[MAXLENGTH], PreStack[MAXLENGTH], OpStack[MAXLENGTH];
    int otos=-1,ptos=-1, length,debugvar=0;
    printf("Enter the Infix word: ");
    scanf("%s",infix);
    length=strlen(infix);
    for (int i=length;i>=0;i--) {
        //debug_print(&debugvar,length,PreStack,ptos,OpStack,otos);
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
    char postfix[MAXLENGTH],operand1[MAXLENGTH],operand2[MAXLENGTH],operator0[2],operand0[2],character;
    int operandcount=0;

    printf("Enter the Postfix Expression: ");
    scanf("%s",postfix);
    for (int i=0;i<strlen(postfix);i++) {
        character=postfix[i];
          if (isalpha(character)) {
            operand0[0]=character; operand0[1]='\0'; //conversion to string
            PushOperand(operand0); 
        }
        else {
            char Buffer[MAXLENGTH];
            // Pop Two values
            strcpy(operand2,PopOperand());
            strcpy(operand1,PopOperand());

            //formatting
            strcpy(Buffer,"(");
            strcat(Buffer,operand1);

            operator0[0]=character;operator0[1]='\0'; //conversion to string
            strcat(Buffer,operator0);

            strcat(Buffer,operand2);
            strcat(Buffer,")\0");

            PushOperand(Buffer);
            operandcount--;
        }
    }
    printf("\n\n[RES] The Resultant Expression is: %s\n",displaystringstack());
}

void PrefixtoInfix(){
    char prefix[MAXLENGTH],operand1[MAXLENGTH],operand2[MAXLENGTH],operator0[2],operand0[2],character;
    int operandcount=0;

    printf("Enter the Prefix Expression: ");
    scanf("%s",prefix);
    for (int i=(strlen(prefix)-1);i>=0;i--) {
        character=prefix[i];
          if (isalpha(character)) {
            operand0[0]=character; operand0[1]='\0';
            PushOperand(operand0); 
        }
        else {
            char Buffer[MAXLENGTH];

            strcpy(operand2,PopOperand());
            strcpy(operand1,PopOperand());

            strcpy(Buffer,"(");
            strcat(Buffer,operand1);

            operator0[0]=character;operator0[1]='\0';
            strcat(Buffer,operator0);

            strcat(Buffer,operand2);
            strcat(Buffer,")\0");

            PushOperand(Buffer);
            operandcount--;
        }
    }
    printf("\n\n[RES] The Resultant Expression is: %s\n",strreverse(displaystringstack()));
}