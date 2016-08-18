#include <iostream>
using namespace std;

struct stack{
    int *arr;
    int top;
    int capacity;
};

void create(stack** st,int capacity){
    *st=new stack;
    (*st)->top=-1;
    (*st)->arr=new int[capacity];
    (*st)->capacity=capacity;
}

void push(stack *st,int data){
    st->arr[++(st->top)]=data;
}

int pop(stack* st){
    return st->arr[st->top--];
}

int top(stack* st){
    return st->arr[st->top];
}

bool isFull(stack* st){
    return (st->top)+1==st->capacity? true:false;
}

bool isEmpty(stack* st){
    return (st->top)==-1? true:false;
}

void stockspan(int arr[],int n){
    stack* st;
    create(&st,n);
    push(st,0);

    int stocks[n];
    stocks[0]=1;

    for(int i=1;i<n;i++){

        while(!isEmpty(st) && arr[top(st)]<arr[i])
            pop(st);

        stocks[i]=isEmpty(st)? (i+1): i-top(st);

        push(st,i);
    }

    for(int i=0;i<n;i++)
        cout<<stocks[i]<<" ";

    cout<<endl;
}

void insertatbottom(stack *st,int data){
    if(isEmpty(st))
        push(st,data);
    else{
        int temp=pop(st);
        insertatbottom(st,data);
        push(st,temp);
    }
}

void sortedInsert(stack* st, int temp){
    if(isEmpty(st) || top(st)<temp){
        push(st,temp);
        return;
    }

    int another = pop(st);
    sortedInsert(st,temp);
    push(st,another);

}

void sortstack(stack* st){
    if(isEmpty(st))
        return;

    int temp=pop(st);
    sortstack(st);
    sortedInsert(st,temp);
}



void reverse(stack* st){
    if(isEmpty(st))
        return;

    int temp=pop(st);
    reverse(st);
    insertatbottom(st,temp);
}

int main(){
    int data[]={100, 80, 60, 70, 61, 75, 85};

    stack *st;
    create(&st,7);

    for(int i=0;i<7;i++)
        push(st,data[i]);

    //while(!isEmpty(st))
    //    cout<<pop(st)<<" ";

    //reverse(st);

    sortstack(st);
    cout<<endl;
    //stockspan(data,7);

    while(!isEmpty(st))
        cout<<pop(st)<<" ";

    cout<<endl;
    return 0;
}
