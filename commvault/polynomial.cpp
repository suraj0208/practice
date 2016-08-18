#include <iostream>

using namespace std;

struct node {
    int val;
    int coe;
    node* next;
};

void insert(node** head,int val,int coe){
    if((*head)==NULL){
        (*head)=new node;
        (*head)->val=val;
        (*head)->coe=coe;
        (*head)->next=NULL;
        return;
    }

    node* temp=(*head);

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node;
    temp=temp->next;
    temp->val=val;
    temp->coe=coe;
    temp->next=NULL;
}

void print(node* head){
    if(head==NULL){
        cout<<endl;
        return;
    }

    cout<<"( "<<head->val<<", "<<head->coe<<" ) ";
    print(head->next);
}

void add(node* h1,node* h2){
    if(h1==NULL){
        print(h2);
        return;
    }else if(h2==NULL){
        print(h1);
        return;
    }

    node* h=NULL;

    while(h1!=NULL && h2!=NULL){
        if(h1->coe>h2->coe){
            insert(&h,h1->val,h1->coe);
            h1=h1->next;
        }
        else if(h1->coe<h2->coe){
            insert(&h,h2->val,h2->coe);
            h2=h2->next;
        }else{
            insert(&h,(h1->val+h2->val),(h1->coe));
            h1=h1->next;
            h2=h2->next;
        }


    }
    print(h);

}

int main(){
    node* h1=NULL;
    node* h2=NULL;

    insert(&h1,5,3);
    insert(&h1,2,2);
    insert(&h1,3,1);
    insert(&h1,4,0);

    print(h1);

    insert(&h2,2,2);
    insert(&h2,3,1);
    insert(&h2,1,0);

    print(h2);

    add(h1,h2);


    return 0;
}
