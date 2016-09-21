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

void printPostorder(int pre[],int in[], int instart,int inend,int *preindex){
    if(instart==inend){
        return;
    }

   int data=pre[*preindex];

   (*preindex)++;

   int inindex=getIndex(in,instart,inend,data);

   printPostorder(pre,in,instart,inindex,preindex);
   printPostorder(pre,in,inindex+1,inend,preindex);
   cout<<data<<" ";

}

int main(){

    int in[] = {4,2,5,1,3,6};
    int pre[] = {1,2,4,5,3,6};

    int preindex=0;

    printPostorder(pre,in,0,6,&preindex);
    cout<<endl;

    return 0;
}
