# 🎲 Expression Evaluations
- Converions Include:
    1. **[Prefix Evaluation](#1️⃣-prefix-evaluations)**
    2. **[Infix Evaluation](#2️⃣-infix-evaluations)**
    3. **[Postfix Evaluation](#3️⃣-postfix-evaluations)**

&nbsp;
# 🌿 Evaluations
## 1️⃣ Prefix Evaluations
### Algorithm
1. Scan one character from Right to Left.
```c
for (int i=strlen(prefix); i>=0;i--) {
}
```
2. Repeat until the string is completely read:
    1. If scanned character is an operand push it to Value Stack.
    ```c
    if(isalpha(character)) {
        printf("\n Enter the value of %c: ",character);
        scanf("%d",&value);
        pushv(value);
    }
    ```
    2. If scanned character is an operator then 
        1. Pop two operands and an operator
        2. Evaluate the expression with the operator then push to the Value Stack
    ```c
    else {
        Operand1=popv();Operand2=popv();
        pushv(EvaluateOperator(Operand1,character,Operand2));
    }
    ```
3. Pop and display the result that remains in the Value Stack
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Data_Structures/expression_operations.c) and not the below file.
- **The Code: [Prefix Evaluation](../Data_Structures/expression_evaluation.c#L4)**.
- **Referenced Modules: [Evaluation_Methods](../Data_Structures/modules/Evaluation_Methods.c)**, [debug_stack](../Data_Structures/modules/stringfunc.c) (optional).
### Example:
- **Input**: +A-/B$CD*E+F-/GHI where A=1, B=2.//3 2 1 5 9 3 2 
- **Output**: "[RES] The result is: -5"

## 2️⃣ Infix Evaluations
### Algorithm
1. Scan one character from Left to Right
2. Repeat until the string is completely read:
    1. If the scanned character is an operand push it to Value Stack.
    2. If the scanned character is an operator and 
        1. If it's precedence is lower than the precedence of the stack then pop two operands and operators, evalutate them and push them to the Value Stack
        2. push the character to the Operator Stack
        ```c
        else if (precedenceOperator()<=precedence(character)) {
            pusho(character);            }
        else {
            Operand2=popv();Operand1=popv();
            Operator=popo();
            pusho(character);
            pushv(EvaluateOperator(Operand1,Operator,Operand2));
        }
        ```
    3. If the scanned character is '(' then push it to Operator Stack but if the scanned character is ')' then evaluate the expression until the '(' is reached.
    ```c
    if (character=='('){
        pusho(character);
    } else if (character==')') {
        while ((Operator=popo())!='(') {
            Operand2=popv();Operand1=popv();
            pushv(EvaluateOperator(Operand1,Operator,Operand2));
        }
    }
    ```
3. Emtpy the Operator Stack if it isn't empty.
```c
while (!OStackisEmpty()) {
    Operand2=popv();Operand1=popv();
    Operator=popo();
    pushv(EvaluateOperator(Operand1,Operator,Operand2));
}
```
4. Pop and display the result that remains in the Value Stack
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Data_Structures/expression_operations.c) and not the below file.
- **The Code: [Infix Evaluation](../Data_Structures/expression_evaluation.c#L26)**.
- **Referenced Modules: [Evaluation_Methods](../Data_Structures/modules/Evaluation_Methods.c)**, [debug_stack](../Data_Structures/modules/stringfunc.c) (optional), [Precedence](../Data_Structures/modules/precedence.c).
### Example:
- **Input**: (A+B)*C where A=10,//5 2
- **Output**: "[RES] The result is: 30"

## 3️⃣ Postfix Evaluations
### Algorithm
1. Scan one character from Left to Right
```c
for (int i=0; i<=(strlen(postfix)-1);i++) {
}
```
2. Repeat until the string is completely read:
    1. If scanned character is an operand push it to Value Stack.
    ```c
    if(isalpha(character)) {
        printf("\n Enter the value of %c: ",character);
        scanf("%d",&value);
        pushv(value);
    }
    ```
    2. If scanned character is an operator then 
        1. Pop two operands and an operator
        2. Evaluate the expression with the operator then push to the Value Stack
    ```c
    else {
        Operand1=popv();Operand2=popv();
        pushv(EvaluateOperator(Operand1,character,Operand2));
    }
    ```
3. Pop and display the result that remains in the Value Stack
### Code Details:
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Data_Structures/expression_operations.c) and not the below file.
- **The Code: [Postfix Evaluation](../Data_Structures/expression_evaluation.c#L69)**.
- **Referenced Modules: [Evaluation_Methods](../Data_Structures/modules/Evaluation_Methods.c)**, [debug_stack](../Data_Structures/modules/stringfunc.c) (optional).
### Example:
- **Input**: ABC*+ where A=3,// 4 5 
- **Output**: "[RES] The result is: 23"
