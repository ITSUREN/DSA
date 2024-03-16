# Introduction
- Converions Include:
    1. [Infix_to_Postfix](#infix-to-postfix)
    2. [Infix_to_Prefix](#infix-to-prefix)
    3. [Prefix_to_Infix](#prefix-to-infix)
    4. [Postfix_to_Infix](#postfix-to-infix)

## Infix to Postfix
### Algorithm
1. Start
2. Scan one character at a time of an infix expression from left to Right (when infix word is given)
```c
    for (int i=0;i<=length;i++){
    printf("%c",infix[i]);
}
```
3. Initialize Operand Stack (OpStack) with its corresponding top of stack (otos) and Postfix Stack (PostStack) and its top of stack (ptos):
```c
char PostStack[MAX_Length], OpStack[MAX_Length];
int otos=-1,ptos=-1;
```
4. Repeat till there is data in infix stack
    - If scanned character is '(' push it to Opstack
    ```c
    if (infix[i]=='(') { 
        OpStack[++otos]=infix[i];
        len++;
    }
    ```
    - if scanned character is an Alphabet then push it to PostStack:
    ```c
    else if(isalpha(infix[i])) {
        PostStack[++ptos]=infix[i];
    }
    ```
    - if scanned character is ')' then dump the contents of Operand Stack to Postfix Stack.
    ```c
    else if(infix[i]==')') { 
        len++;
        while (OpStack[otos]!='('){ 
            PostStack[++ptos] = OpStack[otos--];
        }
        otos--;
    }
    ```
    - if scanned character is an operator and the last operator in the OpStack has higher precedence than the character then push the top Operator of OpStack to Postfix Stack and replace the top Operand of Opstack with the operator else just push to OpStack, repeat to resolve the precedence:
    ```c
    else {
        while (otos != -1 && precedence(OpStack[otos]) >= precedence(infix[i])) {
            PostStack[++ptos] = OpStack[otos--];
        }
        OpStack[++otos] = infix[i];
    }
    ```
5. Dump the contents of Opstack to PostStack:
```c
while (otos!=1){
    PostStack[++ptos]=OpStack[otos];
    otos--;
}
```
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Preliminary_Practices/expression_conv_eval.c) and not the below file.
- **The Code: [Infix to Postfix Conversion](../Preliminary_Practices/expression_conversion.c#L4)**.
- **Referenced Modules: [precedence](../Preliminary_Practices/modules/precedence.c)**, [debug_stack](../Preliminary_Practices/modules/stringfunc.c) (optional).
### Example:
- **Input**: (A+B*C^D)/((E+F-G)*H)^I/J
- **Output**: ABCD^*+EF+G-H*I^/J/


## Infix to Prefix 
### Algorithm
1. Start
2. Scan one character at a time of an infix expression from Right to Left (when infix word is given)
```c
    for (int i=0;i<=length;i++){
    printf("%c",infix[i]);
}
```
3. Initialize Operand Stack (OpStack) with its corresponding top of stack (otos) and Prefix Stack (PreStack) and its top of stack (ptos):
```c
char PreStack[MAX_Length], OpStack[MAX_Length];
int otos=-1,ptos=-1;
```
4. Repeat till there is data in infix stack
    - If scanned character is '(' push it to Opstack
    ```c
    if (infix[i]==')') { 
        OpStack[++otos]=infix[i];
        len++;
    }
    ```
    - if scanned character is an Alphabet then push it to PreStack:
    ```c
    else if(isalpha(infix[i])) {
        PreStack[++ptos]=infix[i];
    }
    ```
    - if scanned character is ')' then dump the contents of Operand Stack to Prefix Stack.
    ```c
    else if(infix[i]=='()') { 
        len++;
        while (OpStack[otos]!=')'){ 
            PreStack[++ptos] = OpStack[otos--];
        }
        otos--;
    }
    ```
    - if scanned character is an operator and the last operator in the OpStack has higher precedence than the character then push the top Operator of OpStack to Prefix Stack and replace the top Operand of Opstack with the operator else just push to OpStack, repeat to resolve the precedence:
    ```c
    else {
        while (otos != -1 && precedence(OpStack[otos]) >= precedence(infix[i])) {
            PreStack[++ptos] = OpStack[otos--];
        }
        OpStack[++otos] = infix[i];
    }
    ```
5. Dump the contents of Opstack to PostStack:
```c
while (otos!=1){
    PreStack[++ptos]=OpStack[otos];
    otos--;
}
```
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Preliminary_Practices/expression_conv_eval.c) and not the below file.
- **The Code: [Infix to Prefix Conversion](../Preliminary_Practices/expression_conversion.c#L38)**.
- **Referenced Modules: [precedence](../Preliminary_Practices/modules/precedence.c)**, [debug_stack](../Preliminary_Practices/modules/stringfunc.c) (optional).
### Example:
- **Input**: (A+B*C$D)/((E+F-G)*H)$I/J
- **Output**: //+A*B$CD$*-+EFGHIJ

    
## Prefix to Infix
### Algorithm
1. Read the prefix expression from Right to Left.
```c
for (int i=(strlen(prefix)-1);i>=0;i--) {
}
```
2. Repeat till above condition is reached:
    1. If scanned character is alphabet then Push to the Operand Stack 
    ```c
    if (isalpha(character)) {
        operand0[0]=character; operand0[1]='\0';
        PushOperand(operand0); 
    }
    ```
    2. But if scanned character is an operator pop last two operands from the stack, add a symbol between it and push it back to the stack.
    ```c
    else {
        char Buffer[MAX_Length];
        strcpy(operand2,PopOperand());
        strcpy(operand1,PopOperand());
        strcpy(Buffer,"(");
        strcat(Buffer,operand1);
        operator1[0]=character;operator1[1]='\0';
        strcat(Buffer,operator1);
        strcat(Buffer,operand2);
        strcat(Buffer,")\0");
        PushOperand(Buffer);
        operandcount--;
    }
    ```
3. Print the reverse of the output string.
```c
printf("\n\n The Infix Expression is: %s\n",strreverse(displaystringstack()));
```
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Preliminary_Practices/expression_conv_eval.c) and not the below file.
- **The Code: [Prefix to Infix Conversion](../Preliminary_Practices/expression_conversion.c#L106)**.
- **Referenced Modules: [Conversion_Methods](../Preliminary_Practices/modules/Conversion_Methods.c)**, [stringfunction](../Preliminary_Practices/modules/stringfunc.c).
### Example:
- **Input**: //+A*B^CD^*-+EFGHIJ
- **Output**: (((A+(B*(C^D)))/((((E+F)-G)*H)^I))/J)


## Postfix to Infix
### Algorithm
1. Read the postfix expression from Left to Right.
```c
for (int i=(strlen(postfix)-1);i>=0;i--) {
}
```
2. Repeat till above condition is reached:
    1. If scanned character is alphabet then Push to the Operand Stack 
    ```c
    if (isalpha(character)) {
        operand0[0]=character; operand0[1]='\0';
        PushOperand(operand0); 
    }
    ```
    2. But if scanned character is an operator pop last two operands from the stack, add a symbol between it and push it back to the stack.
    ```c
    else {
        char Buffer[MAX_Length];
        strcpy(operand2,PopOperand());
        strcpy(operand1,PopOperand());
        strcpy(Buffer,"(");
        strcat(Buffer,operand1);
        operator1[0]=character;operator1[1]='\0';
        strcat(Buffer,operator1);
        strcat(Buffer,operand2);
        strcat(Buffer,")\0");
        PushOperand(Buffer);
        operandcount--;
    }
    ```
3. Print the reverse of the output string.
```c
printf("\n\n The Infix Expression is: %s\n",strreverse(displaystringstack()));
```
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Preliminary_Practices/expression_conv_eval.c) and not the below file.
- **The Code: [Postfix to Infix Conversion](../Preliminary_Practices/expression_conversion.c#L71)**.
- **Referenced Modules: [Conversion_Methods](../Preliminary_Practices/modules/Conversion_Methods.c)**.
### Example:
- **Input**: ABCD^*+EF+G-H*I^/J/
- **Output**: (((A+(B*(C^D)))/((((E+F)-G)*H)^I))/J)