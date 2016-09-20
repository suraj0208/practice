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

int checkSumTreeUtil(node* root,bool* bit){

    if(root->left==null && root->right==null)
        return root->data;

    int left = 0;

    if(root->left)
        left=checkSumTreeUtil(root->left,bit);

    int right = 0;

    if(root->right)
        right=checkSumTreeUtil(root->right,bit);

    if(root->data!=(left+right)){
        *bit=false;
    }

    return root->data+left+right;

}

bool checkSumTree(node* root){
    if(root==null)
        return true;

    bool bit=true;

    checkSumTreeUtil(root,&bit);
    return bit;
}

int main(){
    int in[] = {4,10,6,26,3,3};
    int pre[] = {26,10,4,6,3,3};

    int preindex=0;
    node* root =construct(pre,in,0,6,&preindex);

    inorder(root);
    cout<<endl;

    cout<<checkSumTree(root)<<endl;

    return 0;
}
