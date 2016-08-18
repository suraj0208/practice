#include <iostream>
using namespace std;

#define null NULL

struct node{
    int data;
    node* next;
};

void insert(node** head,int data){
    if(*head==null){
        *head=new node;
        (*head)->data=data;
        return;
    }

    node* front = *head;
    while(front->next!=null){
        front=front->next;
    }

    front->next=new node;
    front->next->data=data;
}

int add1(node* head){
    if(head->next==null){
        int sum = head->data+1;
        head->data=sum%10;
        return sum/10;
    }

    int carry = add1(head->next);

    int sum =head->data+carry;

    head->data=sum%10;

    return sum/10;
}

void add1Util(node** head){
    int carry = add1(*head);

    if(carry!=0){
        node* temp = new node;
        temp->data = carry;
        temp->next=*head;
        *head=temp;
    }
}
void print(node* head){
    if(head==null){
        cout<<endl;
        return;
    }

    cout<<head->data<<" ";
    print(head->next);

}
int main(){
    node* head=null;

    insert(&head,9);
    insert(&head,9);
    insert(&head,8);
    //insert(&head,9);

    int carry=0;
    print(head);
    add1Util(&head);
    print(head);
    return 0;
}
