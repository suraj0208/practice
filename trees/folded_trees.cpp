#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

bool ismirror(node* root1,node*root2){
    if(root1 == null && root2 == null)
        return true;

    if(root1 == null || root2 == null)
        return false;

    return ismirror(root1->left, root2->right) && ismirror(root1->right,root2->left);
}

bool isFolded(node* root){
    return ismirror(root->left,root->right);
}


int main(){
    //int in[] = {9,7,10,10,12,15};
    //int pre[] = {10,7,9,10,15,12};


    int in[] = {7,9,10,11,15};
    int pre[] = {10,7,9,15,11};

    int preindex=0;
    node* root = construct(pre,in,0,5,&preindex);

    inorder(root);
    cout<<endl;

    cout<<isFolded(root)<<endl;


    return 0;
}
