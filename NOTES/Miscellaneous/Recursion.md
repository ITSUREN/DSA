# ♻ Recursions (Under Work)
- The [CODE:📑](../Miscellaneous/Recursion.md).
- Process by which a function calls itself repeatedly until some specific conditions are met ( a.k.a. base condition).

### 🛑 Conditions to satisfy
- Each function call should bring itself closer to the solution.
- Must include a stopping condition.

### 🌿 Types of Recursions:
- Categorized into 5 Types as:
    1. ### Direct Recursion:
    - The Recursion where a _Single_ Function calls itself repeatedly until a base condition is satisfied
    - It is inferred that there is some calculation within the recursive stage
    - exempli gratia:
    ```c
    int fact(int n) {
        if (num == 0) 
            return 1;
        else
            return n * fact(n-1); // Calculation within the redursive stage
    }
    ```
    2. ### Inirect Recursion:
    - The Recursion where a _Multiple_ Function call themselves making a chaing until the last one calls the first one. 
    - That is f() -> f1() -> f2() -> ... -> fn() -> f().
    - It is inferred that there is some calculation within the recursive stage
    - exempli gratia:
    ```c
    int fun1(int x) {
        if (x == 0) 
            return 1;
        else
            return x * fun2(x); // Calculation within the redursive stage
    }
    int fun2(int y) {
        return fun1(y-1); // No calculation withing the recursive stage
    }
    ```
    3. ### Tail Recursion:
    - The Recursion where a there are no calculations in the recursive stage and only returns value.
    ```c
    int fact(int n, int accumulator) {
        if (num == 0) 
            return accumultor;
        else
            return fact(n-1, n*accumulator); // Calculation within the redursive stage
    }
    ```
    4. Linear Recursion
    5. Tree Recursion

&nbsp;
# 🧰 Applications
- Some Programs using Recursion.
    1. ### [Tower Of Hanoi](./Tower_of_Hanoi.md)
    2. ### [Fibonacci](./Fibonacci.md)
    3. ### [Greatest Common Divisor](./GCD.md)
