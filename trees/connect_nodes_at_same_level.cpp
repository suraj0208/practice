#include <iostream>
#include <queue>

using namespace std;

#define null NULL

struct node{
    int data;
    node* left;
    node* right;
    node* next;
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

int height(node* root){
    if(!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh>rh)
        return 1+lh;

    return 1+rh;
}

void traverse_level(node* root,int level, node** succ /* here double pointer is only option */){
    if(root==null)
        return;

    if(level==1){
        root->next=*succ;
        *succ=root;
    }

    if(root->right)
        traverse_level(root->right,level-1,succ);

    if(root->left)
        traverse_level(root->left,level-1,succ);

}

int connect_level_nodes(node* root){
    int h=height(root);

    for(int i=1;i<=h;i++){
        node* succ=null;
        traverse_level(root,i,&succ);
    }

}

void preorder(node* root){
    if(!root)
        return;

    cout<<root->data<<"-->";

    if(root->next)
        cout<<root->next->data<<endl;
    else
        cout<<"null"<<endl;

    preorder(root->left);
    preorder(root->right);

}

int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    connect_level_nodes(root);

    preorder(root);


    return 0;
}
