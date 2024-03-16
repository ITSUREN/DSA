#define MAXLENGTH 50 // Maximum characters that may be processed

void debug_stack(char Stack[MAXLENGTH],int length){
    printf("[ ");
    for (int i=0; i<length; i++){
        printf("%c,",Stack[i]);
    }
    printf("\b ]");
}

void debug_print(int *debugvar,int length, char PostStack[MAXLENGTH], int ptos, char OpStack[MAXLENGTH], int otos) {
    printf("\n >[DEBUG] Array ran: %2d , len= %d with PostStack=", ++(*debugvar),length);
    debug_stack(PostStack,ptos+1);
    printf(" and OpStack=");
    debug_stack(OpStack,otos+1);
}