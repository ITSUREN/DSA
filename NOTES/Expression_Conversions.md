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
- follow the algorithm below:
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

## Postfix to Infix
- follow the algorithm below:
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