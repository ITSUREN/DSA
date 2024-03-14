int precedence(char ch){
    switch(ch) {
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