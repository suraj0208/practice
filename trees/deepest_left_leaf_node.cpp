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

int deepest_leaf_node(node* root,int level,bool lorr){
    static int deepest=0;
    static int data;

    if(!root)
        return deepest;

    if(root->left==null && root->right==null){
        if(level>deepest  && lorr){
            deepest=level;
            data=root->data;
        }
        return data;
    }

    deepest_leaf_node(root->left,level+1,true);
    deepest_leaf_node(root->right,level+1,false);

    return data;
}

int main(){
    int in[] = {4,2,1,5,9,7,3,6,8,10};
    int pre[] = {1,2,4,3,5,7,9,6,8,10};

    int preindex=0;
    node* root =construct(pre,in,0,10,&preindex);

    inorder(root);
    cout<<endl;

    cout<<deepest_leaf_node(root,1,true);

    cout<<endl;

    return 0;
}
