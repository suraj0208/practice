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

int remove_nodes(node* root,int sum,int k){
    if(!root)
        return sum;

    if(root->left==null && root->right==null){
        return sum+root->data;

    }

    int leftsum=remove_nodes(root->left,root->data+sum,k);
    int rightsum=remove_nodes(root->right,root->data+sum,k);

    if(leftsum<k)
        root->left=null;

    if(rightsum<k)
        root->right=null;

    return fmax(leftsum,rightsum);

}

int main(){
    int in[] = {8,4,13,9,15,14,2,12,5,1,6,3,10,11,7};
    int pre[] ={1,2,4,8,9,13,14,15,5,12,3,6,7,10,11};


    int preindex=0;
    node* root =construct(pre,in,0,15,&preindex);

    inorder(root);
    cout<<endl;

    remove_nodes(root,0,20);

    inorder(root);
    cout<<endl;

    return 0;
}
