#include<stdio.h>

struct test{
int data;
};

int j;
int add(int x, int y)
{

		int test[x];
    return printf("%*c%*c",  x, ' ',  y, ' ');
}

extern int xyz;
int main(){
int j;
    //xyz=143;
    //printf("%d",add(0,0));
    //printf("%d\n", fun(10,10,23));
    //printf("%d\n",xyz);

	struct test asd[5];

	int i=0;

printf("j %d\n",j);

	for(i=0;i<5;i++)
		asd[i].data=i;

	struct test* ptr=asd;


	for(i=0;i<5;i++){
		printf("%d\n", ptr->data);		
		ptr++;

	}
    return 0;

}

int fun()
{
   return 100;
}
