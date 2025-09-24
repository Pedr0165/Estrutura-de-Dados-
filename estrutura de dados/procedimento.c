
#include <stdio.h>

void linha(void){
    printf("-------------\n");
}
int main(void){
    printf("antes da linha\n");
    linha();
    printf("depois da linha\n");
    return 0;
    
}
