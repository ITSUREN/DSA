int precedence(char ch){
    switch(ch) {
        case '^':
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

int isOperator(char ch) {
    return (ch == '^' || ch == '$' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}