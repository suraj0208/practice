#define null NULL

#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* create(node* root,int data){
   if(root==null){
       root = new node;
       root->data=data;
       root->left=null;
       root->right=null;
       return root;
   }

   if(data<root->data){
       root->left = create(root->left,data);
   }else{
       root->right = create(root->right,data);
   }
   return root;
}

int getIndex(int inorder[],int start,int n,int data){
    for(int i=start;i<n;i++){

        if(inorder[i]==data)
            return i;

    }
    return -1;
}

node* construct(int pre[],int in[],int instart,int inend,int *preindex){

    if(instart==inend){
        return null;
    }

    int data = pre[*preindex];

    (*preindex)++;

    int inindex = getIndex(in,instart,inend,data);

    node* temp = new node;

    temp->data=data;

    temp->left=construct(pre,in,instart,inindex,preindex);
    temp->right=construct(pre,in,inindex+1,inend,preindex);

    return temp;
}


