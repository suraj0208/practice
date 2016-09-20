#include <iostream>

using namespace std;

#define null NULL

struct node{
    int data;
    node* left;
    node* right;
    node* insucc;
};

node* create(node* root,int data){
   if(root==null){
       root = new node;
       root->data=data;
       root->left=null;
       root->right=null;
       return root;
   }

   if(data<root->data){
       root->left = create(root->left,data);
   }else{
       root->right = create(root->right,data);
   }
   return root;
}

void populate_succ(node* root){
    if(!root)
        return;

    static node* succ=null;

    populate_succ(root->right);

    root->insucc=succ;

    succ=root;

    populate_succ(root->left);
}

int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    populate_succ(root);

    while(root->left)
        root=root->left;

    while (root) {
        cout<<root->data<<" ";
        root=root->insucc;
    }

    cout<<endl;

    return 0;
}
