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

node* find_lca(node* root,int a,int b){
    if(root==null)
        return null;

    if(root->data==a || root->data == b)
        return root;

    node* left=find_lca(root->left,a,b);
    node* right=find_lca(root->right,a,b);

    if(left && right)
        return root;

    if(left)
        return left;

    if(right)
        return right;

    return null;
}




int main(){
    int in[] = {8,4,9,2,10,5,11,1,6,7,3};
    int pre[] = {1,2,4,8,9,5,10,11,3,6,7};

    int preindex=0;
    node* root =construct(pre,in,0,sizeof(in)/sizeof(in[0]),&preindex);

    node* lca=find_lca(root,8,10);

    cout<<(lca!=null ? lca->data:-1)<<endl;

    return 0;
}
