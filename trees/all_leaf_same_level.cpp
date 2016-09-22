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

bool all_leaf_same_level(node* root,int level){
    static int leftmost=0;

    if(root==null)
        return true;

    if(root->left==null && root->right == null){

        if(leftmost==0){
            leftmost=level;
            return true;
        }else if(level==leftmost)
            return true;
        else
            return false;

    }

    return all_leaf_same_level(root->left,level+1)&&all_leaf_same_level(root->right,level+1);

}

int main(){
    int in[] = {3,5,12,7,1};
    int pre[] = {12,5,3,7,1};

    int preindex=0;
    node* root =construct(pre,in,0,5,&preindex);

    inorder(root);
    cout<<endl;

    cout<<all_leaf_same_level(root,1)<<endl;

    return 0;
}
