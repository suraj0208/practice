#include <iostream>
#include "build.h"

using namespace std;

void printkdistanceroot(node* root,int k){
    if(root==null)
        return;

    if(k<0)
        return;

    if(k==0)
        cout<<root->data<<endl;

    printkdistanceroot(root->left,k-1);
    printkdistanceroot(root->right,k-1);
}

int kdistance(node* root,int x,int k){

    if(root==null)
        return -1;

    if(root->data==x){
        printkdistanceroot(root,k);
        return k;
    }

    int left = kdistance(root->left,x,k);
    int right = kdistance(root->right,x,k);

    if(left==1)
        cout<<root->data<<endl;
    else if(right==1)
        cout<<root->data<<endl;

    if(left>0){
        printkdistanceroot(root->right,left-2);
        return left-1;
    }else if (right>0){
        printkdistanceroot(root->left,right-2);
        return right-1;
    }

}

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    int in[] = {16,8,17,4,18,9,19,2,10,5,11,1,12,6,13,3,14,7,15};
    int pre[]= {1,2,4,8,16,17,9,18,19,5,10,11,3,6,12,13,7,14,15};

    node* root = null;

    int n = sizeof(in)/sizeof(in[0]);

    int preindex=0;

    root=construct(pre,in,0,n,&preindex);

    //inorder(root);

    kdistance(root,15,2);




    return 0;
}
