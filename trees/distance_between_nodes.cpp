#include <iostream>
#include "build.h"

using namespace std;

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

node* findLCA(node* root,int a, int b){
    if(root==null)
        return null;

    if(root->data==a || root->data==b)
        return root;

    node* left = findLCA(root->left,a,b);
    node* right = findLCA(root->right,a,b);

    if(left && right)
        return root;

    if(left)
        return left;

    if(right)
        return right;


    return null;
}

int getLevel(node* root,int data,int level){
    if(root==null)
        return -1;

    if(root->data==data)
        return level;

    int l = getLevel(root->left,data,level+1);
    int r = getLevel(root->right,data,level+1);

    if(l!=-1)
        return l;

    if(r!=-1)
        return r;

    return -1;
}

int main(){
    int in[] = {8,4,9,2,10,5,11,1,6,7,3};
    int pre[] = {1,2,4,8,9,5,10,11,3,6,7};

    int preindex=0;
    node* root =construct(pre,in,0,sizeof(in)/sizeof(in[0]),&preindex);

    node* lca=findLCA(root,8,11);
    int a = getLevel(root,8,0);
    int b = getLevel(root,10,0);
    int r = getLevel(root,lca->data,0);

    cout<<a+b-2*r<<endl;



    return 0;
}
