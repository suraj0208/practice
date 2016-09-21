#include <iostream>

#define null NULL

struct node{
    int data;
    node* left;
    node* right;
};


using namespace std;

int getIndex(int inorder[],int start,int n,int data){
    for(int i=start;i<n;i++){

        if(inorder[i]==data)
            return i;

    }
    return -1;
}

node* construct(int pre[],int in[],int instart,int inend,int *preindex){

    if(instart==inend){
        return null;
    }

    int data = pre[*preindex];

    (*preindex)++;

    int inindex = getIndex(in,instart,inend,data);

    node* temp = new node;

    temp->data=data;

    temp->left=construct(pre,in,instart,inindex,preindex);
    temp->right=construct(pre,in,inindex+1,inend,preindex);

    return temp;
}

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    int in[] = {4,2,5,1,6,3};
    int pre[] = {1,2,4,5,3,6};

    int preindex=0;
    node* root =construct(pre,in,0,6,&preindex);

    inorder(root);
    cout<<endl;

    return 0;
}
