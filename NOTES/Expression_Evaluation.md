# Introduction
- Converions Include:
    1. [Prefix](#prefix-evaluations)
    2. [Infix](#infix-evaluations)
    3. [Postfix](#postfix-evaluations)

## Prefix Evaluations
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
- <span style="color:orange"> **Warning:**</span> Run the code from the [main code file](../Preliminary_Practices/expression_conv_eval.c) and not the below file.
- **The Code: [Prefix Evaluation](../Preliminary_Practices/expression_evaluation.c#L4)**.
- **Referenced Modules: [Evaluation_Methods](../Preliminary_Practices/modules/Evaluation_Methods.c)**, [debug_stack](../Preliminary_Practices/modules/stringfunc.c) (optional).
### Example:
- **Input**: +A-/B$CD*E+F-/GHI where A=1, B=2.//3 2 1 5 9 3 2 
- **Output**: "[RES] The result is: -5"

