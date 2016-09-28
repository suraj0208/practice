#include <stdio.h>

int main(){
    char *str = "12 14";

    int i=0;
    int j=0;

    sscanf(str,"%d%d",&i,&j);

    printf("%d %d\n",i,j);

    return 0;
}
