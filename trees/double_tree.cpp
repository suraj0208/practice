#include <iostream>
#include "build.h"

using namespace std;

void double_tree(node* root){
    if(!root)
        return;

    node* temp = new node;
    temp->data = root->data;
    temp->left=root->left;
    root->left=temp;

    double_tree(temp->left);

    double_tree(root->right);

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

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    int in[] = {4,2,5,1,3};
    int pre[] = {1,2,4,5,3};

    int preindex=0;
    node* root =construct(pre,in,0,5,&preindex);

    inorder(root);
    cout<<endl;
    double_tree(root);
    inorder(root);
    cout<<endl;

    return 0;
}
