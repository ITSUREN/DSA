#define MAX_Lengths 50

void debug_stack(char Stack[MAX_Lengths],int length){
    printf("[ ");
    for (int i=0; i<length; i++){
        printf("%c,",Stack[i]);
    }
    printf("\b ]");
}

void debug_print(int *debugvar,int length, char PostStack[MAX_Lengths], int ptos, char OpStack[MAX_Lengths], int otos) {
    printf("\n >[DEBUG] Array ran: %2d , len= %d with PostStack=", ++(*debugvar),length);
    debug_stack(PostStack,ptos+1);
    printf(" and OpStack=");
    debug_stack(OpStack,otos+1);
}