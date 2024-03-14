# Introduction
- Converions Include:
    1. [Infix_to_Postfix](#infix-to-postfix)
    2. [Infix_to_Prefix](#infix-to-prefix)
    3. [Prefix_to_Infix](#prefix-to-infix)
    4. [Postfix_to_Infix](#postfix-to-infix)

## Infix to Postfix
- follow the Algorith below:
    1. Start
    2. Scan one character at a time of an infix expression from right to left (when given)
    ```c
     for (int i=0;i<=length;i++){
        printf("%c",infix[i]);
    }
    ```
    3. Initialize Operand Stack (OpStack) with its corresponding top of stack (otos) and Posfix Stack (PostStack) and its top of stack (ptos):
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
        - if scanned character is an Alphabet then push it to Pos Stack:
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
                PostStack[++ptos] = OpStack[otos];
                otos--;
            }
            otos--;
        }
        ```
        - if scanned character is an operator and the last operator in the OpStack has higher precedence than the character then push the top Operator of OpStack to Postfix Stack and replace the top Operand of Opstack with the operator else just push to OpStack:
        ```c
        else {
            if (precedency(OpStack[otos])>=precedency(infix[i])){
                PostStack[++ptos]=OpStack[otos--];
                OpStack[++otos]=infix[i];
            } else {
                OpStack[++otos]=infix[i];
            }
        }
        ```
    5. Dump the contents of Opstack to PostStack:
    ```c
    while (otos!=1){
        PostStack[++ptos]=OpStack[otos];
        otos--;
    }
    ```

## Infix to Prefix 

## Prefix to Infix

## Postfix to Infix