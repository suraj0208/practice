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
        (*head)->next=null;
    }else{
        node* temp=new node;
        temp->data=data;
        temp->next=*head;
        *head=temp;
    }
}

void print(node* head){
    if(head==null)
    {
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    print(head->next);

}

void deletenode(node** head,int data){
    if(*head==null)
        return;

    node* first=*head;
    node* prev=null;

    while(first && first->data!=data){
        prev=first;
        first=first->next;
    }

    if(!first)
        return;

    if(first==*head){
        *head=(*head)->next;
        delete first;
    }else{
        prev->next=first->next;
        delete first;
    }

}

void deletenode_at_pos(node** head, int pos){
    node* first=*head;
    node* prev=null;

    if(!first)
        return;

    int count=0;

    while(first && count<pos){
        prev=first;
        first=first->next;
        count++;
    }

    if(!first)
        return;

    if(pos==0){
        prev=(*head);
        (*head)=(*head)->next;
        delete prev;
    }else{
        prev->next=first->next;
        delete first;
    }

}

void swap_nodes(node** head,int x,int y){
    node* first=*head;

    if(!first)
        return;

    node *prevx=null,*prevy=null,*currx=first,*curry=first;

    while(currx && currx->data!=x){
        prevx=currx;
        currx=currx->next;
    }

    while(curry && curry->data!=y){
        prevy=curry;
        curry=curry->next;
    }

    if(!(currx && curry))
        return;


    if(prevx==null)
        (*head)=curry;
    else
        prevx->next=curry;

    if(prevy==null)
        (*head)=currx;
    else
        prevy->next=currx;

    node* temp=currx->next;
    currx->next=curry->next;
    curry->next=temp;
}

void reverse_iterative(node** head){
    node *prev=null,*current=*head,*next=null;

    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

void reverse_recursize(node** head){
    node* first=*head;

    if(first==null)
        return;

    node* rest=(*head)->next;

    if(rest==null)
        return;

    reverse_recursize(&rest);
    first->next->next=first;
    first->next=null;

    (*head)=rest;
}

node* sortedmerge_iterative(node* head1,node* head2){
    node dummy;

    node* tail=&dummy;

    while(true){
        if(head1==null){
            tail->next=head2;
            break;
        }

        if(head2==null){
            tail->next=head1;
            break;
        }

        if(head1->data<=head2->data){
            tail->next=head1;
            head1=head1->next;
        }else{
            tail->next=head2;
            head2=head2->next;
        }

        tail=tail->next;
    }
    return dummy.next;
}

node* sortedmerge_recursive(node* head1,node*head2){
    if(head1==null)
        return head2;

    if(head2==null)
        return head1;

    if(head1->data<=head2->data){
        head1->next=sortedmerge_recursive(head1->next,head2);
        return head1;
    }
    head2->next=sortedmerge_recursive(head1,head2->next);
    return head2;
}

node* reverse(node* head, int k){


    node *current=head,*next=null,*prev=null;
    int count=0;

    while(current && count<k){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }

    if(next)
        head->next=reverse(next,k);

    return prev;

}

int main(){

    node* head=null;
    node* head1=null;
    node* res=null;

    insert(&head,10);
    insert(&head,9);
    insert(&head,8);
    insert(&head,7);
    insert(&head,6);
    insert(&head,5);
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);

    insert(&head1,15);
    insert(&head1,14);
    insert(&head1,13);
    insert(&head1,12);
    insert(&head1,11);

    print(head);
    //print(head1);
    //res=sortedmerge_recursive(head,head1);
    //print(res);

    head=reverse(head,3);

    print(head);


    return 0;
}
