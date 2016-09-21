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

void morris_inorder(node* root){
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
                prev->right=current;
                current=current->left;
            }else{
                prev->right=null;
                cout<<current->data<<" ";
                current=current->right;
            }

        }

    }
    cout<<endl;

}


int main(){


    /*int in[] = {4,2,5,1,3};
    int pre[] = {1,2,4,5,3};

    int preindex=0;
    node* root = construct(pre,in,0,5,&preindex);*/

    node *root = new node;
    root->data=1;

    root->left        = new node;
    root->left->data=2;

    root->right       = new node;
    root->right->data=3;

    root->left->left  = new node;
    root->left->left->data=4;

    root->left->right = new node;
    root->left->right->data=5;


    inorder(root);
    cout<<endl;

    morris_inorder(root);


    return 0;
}
