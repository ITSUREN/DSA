# Introduction
- Converions Include:
    1. [Infix_to_Postfix](#infix-to-postfix)
    2. [Infix_to_Prefix](#infix-to-prefix)
    3. [Prefix_to_Infix](#prefix-to-infix)
    4. [Postfix_to_Infix](#postfix-to-infix)

## Infix to Postfix
- follow the Algorithm below:
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

## Infix to Prefix 
- follow the Algorithm below:
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
    
## Prefix to Infix

## Postfix to Infix