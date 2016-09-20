#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

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

int convertToSumTree(node* root){
    if(root==null)
        return 0;

    if(root->left==null && root->right ==null){
        int temp =root->data;
        root->data=0;
        return temp;
    }

    int left=0;

    if(root->left)
        left=convertToSumTree(root->left);

    int right=0;

    if(root->right)
        right=convertToSumTree(root->right);

    int temp = root->data;

    root->data=left+right;

    return temp+root->data;


}

int main(){
    int in[] = {8,-2,-4,10,7,6,5};
    int pre[] = {10,-2,8,-4,6,7,5};

    int preindex=0;
    node* root = construct(pre,in,0,7,&preindex);

    inorder(root);
    cout<<endl;

    convertToSumTree(root);

    inorder(root);
    cout<<endl;

    return 0;
}
