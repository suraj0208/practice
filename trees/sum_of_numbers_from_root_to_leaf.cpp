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

void sum_root_to_leaf(node* root, int* sum, int current){
    if(!root)
        return;

    if(root->right==null && root->left == null){
        *sum=*sum+root->data + current*10;
        return;
    }

    sum_root_to_leaf(root->left,sum,current*10+root->data);
    sum_root_to_leaf(root->right,sum,current*10+root->data);

}

int main(){
    int in[] = {2,3,7,5,4,6,5,4};
    int pre[] = {6,3,2,5,7,4,5,4};

    int preindex=0;
    node* root =construct(pre,in,0,8,&preindex);

    int sum=0;

    sum_root_to_leaf(root,&sum,0);

    cout<<sum<<endl;

    return 0;
}
