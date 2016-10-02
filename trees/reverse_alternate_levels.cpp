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

void preorder(node* root1,node* root2,int level){
    if(!root1 || !root2)
        return;

    if(level%2==0){
        int temp = root1->data;
        root1->data=root2->data;
        root2->data=temp;
    }

    preorder(root1->left,root2->right,level+1);
    preorder(root1->right,root2->left,level+1);

}

void reverse_alternate(node* root){
    preorder(root->left,root->right,0);
}

int main(){
    int in[] = {8,4,9,2,10,5,11,1,12,6,13,3,14,7,15};
    int pre[] ={1,2,4,8,9,5,10,11,3,6,12,13,7,14,15};

    int preindex=0;
    node* root =construct(pre,in,0,sizeof(in)/sizeof(in[0]),&preindex);

    reverse_alternate(root);

    inorder(root);

    cout<<endl;

    return 0;
}
