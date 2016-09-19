#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

void printLeft(node* root){
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            printLeft(root->left);
        }else if (root->right){
            cout<<root->data<<" ";
            printLeft(root->right);
        }
    }
}

void printLeaves(node* root){
    if(!root)
        return;

    if(root->left == null && root->right==null)
    {
        cout<<root->data<<" ";
    }

    printLeaves(root->left);
    printLeaves(root->right);

}

void printRight(node* root){
    if(root){
        if(root->right){
            printRight(root->right);
            cout<<root->data<<" ";
        }else if(root->left){
            printRight(root->left);
            cout<<root->data<<" ";
        }
    }
}

void printBoundary(node* root){
    if(root){
        cout<<root->data<<" ";

        printLeft(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printRight(root->right);

    }
}

int main(){
    int data[] = {5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    printBoundary(root);
    cout<<endl;

    return 0;
}
