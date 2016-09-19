#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

int height(node* root){
    if(root==null)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh>rh)
        return 1+lh;

    return 1+rh;

}

void printLevel(node* root, int level,bool bit){
    if(level==1){
        cout<<root->data<<" ";
    }

    if(bit){
        if(root->left)
            printLevel(root->left,level-1,bit);

        if(root->right)
            printLevel(root->right,level-1,bit);
    }else{

        if(root->right)
            printLevel(root->right,level-1,bit);

        if(root->left)
            printLevel(root->left,level-1,bit);
    }

}

void levelOrder(node* root){
    int h=height(root);

    bool bit=true;
    for(int i=1;i<=h;i++){
        printLevel(root,i,bit);
        bit=!bit;
    }
    cout<<endl;
}

int main(){
    int data[] = { 5,4,1,6,8,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    levelOrder(root);


    return 0;
}
