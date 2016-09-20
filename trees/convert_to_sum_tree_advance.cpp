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

void increment(node* root,int diff){
    if(root->left){
        root->left->data = root->left->data+diff;
        increment(root->left,diff);
    }else if(root->right){
        root->right->data=root->right->data+diff;
        increment(root->right,diff);
    }
}

void convertToSumTree(node* root){
    if(root==null)
        return;

    if(root->left==null && root->right ==null)
        return;

    convertToSumTree(root->left);
    convertToSumTree(root->right);

    int left=0;

    if(root->left)
        left=root->left->data;


    int right=0;

    if(root->right)
        right=root->right->data;


    int diff = left+right-root->data;

    if(diff>0)
        root->data=root->data+diff;

    if(diff<0)
        increment(root,-diff);

}

int main(){
    int in[] = {3,7,5,50,1,2,30};
    int pre[] = {50,7,3,5,2,1,30};

    int preindex=0;
    node* root = construct(pre,in,0,7,&preindex);

    inorder(root);
    cout<<endl;

    convertToSumTree(root);

    inorder(root);
    cout<<endl;

    return 0;
}
