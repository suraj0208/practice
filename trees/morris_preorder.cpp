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

void morris_preorder(node* root){
    if(!root)
        return;

    node* prev;
    node* current=root;

    while(current){

        if(current->left==null){
            cout<<current->data<<" ";
            current=current->right;
        }else{

            prev=current->left;

            while(prev->right && prev->right!=current){
                prev=prev->right;
            }

            if(prev->right==null){
                cout<<current->data<<" ";
                prev->right=current;
                current=current->left;
            }else{
                prev->right=null;
                current=current->right;
            }

        }

    }
    cout<<endl;

}


int main(){
    int in[] = {4,2,5,1,3};
    int pre[] = {1,2,4,5,3};

    int preindex=0;
    node* root = construct(pre,in,0,5,&preindex);


    inorder(root);
    cout<<endl;

    morris_preorder(root);


    return 0;
}
