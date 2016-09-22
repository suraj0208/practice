#include <iostream>
#include "build.h"
#include <cmath>

using namespace std;

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void left_view(node* root,int level){
    static int deepest=0;

    if(root==null)
        return;

    if(level>deepest)
        cout<<root->data<<endl;

    if(root->left==null && root->right == null){
        if(level>deepest)
            deepest=level;
    }

    left_view(root->left,level+1);
    left_view(root->right,level+1);


}

int main(){
    int in[] = {4,2,1,5,9,7,3,6,8,11,10};
    int pre[] = {1,2,4,3,5,7,9,6,8,10,11};

    int preindex=0;
    node* root =construct(pre,in,0,11,&preindex);

    inorder(root);
    cout<<endl;

    left_view(root,1);

    return 0;
}
