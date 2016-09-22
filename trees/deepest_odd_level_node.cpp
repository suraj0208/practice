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

int deepest_odd_level(node* root,int level){
    static int deepest=0;
    if(root==null)
        return 0;

    if(root->left==null && root->right == null){

        if(deepest==0 && level&1)
            deepest=level;
        else if( level&1 && level>deepest)
            deepest=level;

        return deepest;

    }

    return fmax(deepest_odd_level(root->left,level+1),deepest_odd_level(root->right,level+1));

}

int main(){
    int in[] = {4,2,1,5,9,7,3,6,8,11,10};
    int pre[] = {1,2,4,3,5,7,9,6,8,10,11};

    int preindex=0;
    node* root =construct(pre,in,0,11,&preindex);

    inorder(root);
    cout<<endl;

    cout<<deepest_odd_level(root,1)<<endl;

    return 0;
}
