#include <iostream>
#include <stack>

using namespace std;

#define null NULL

struct node{
    int data;
    node* left=NULL;
    node* right=NULL;
};

node* create(node* root,int data){
    if(root==null){
        root=new node;
        root->data=data;
        return root;
    }

    if(data<=root->data){
        root->left=create(root->left,data);
    }else{
        root->right=create(root->right,data);
    }

    return root;
}

bool inorder(node* root){
    stack<node*> mystack;

    int prev=0;

    while(root!=null){
        mystack.push(root);
        root=root->left;
    }


    while(!mystack.empty()){
        root=mystack.top();

        if(!(prev<=root->data))
            return false;

        prev=root->data;

        cout<<root->data<<" ";
        mystack.pop();

        root=root->right;

        while(root!=null){
            mystack.push(root);
            root=root->left;
        }

    }
    return true;
}

void in_succ(node* root,int data){

    node* root_bak=root;
    node* successor=null;
    while(root!=null){

        if(root->data==data)
            break;

        if(data<root->data)
            root=root->left;
        else
            root=root->right;

    }

    if(root==null)
        return;

    if(root->right!=null){
        root=root->right;

        while(root->left!=null)
            root=root->left;

        cout<<root->data<<endl;
    }else{
        root=root_bak;

        while(root->data!=data){
            if(data<root->data){
                successor=root;
                root=root->left;
            }else
                root=root->right;
        }
        if(successor)
            cout<<successor->data;
    }



}

void preorder(node* root){
    stack<node*> mystack;

    while(root!=null){
        mystack.push(root);
        cout<<root->data<<" ";
        root=root->left;
    }

    while(!mystack.empty()){
        root=mystack.top();
        mystack.pop();

        root=root->right;

        while(root!=null){
            mystack.push(root);
            cout<<root->data<<" ";
            root=root->left;
        }

    }

}

int main(){
    node* root=null;

    int data[]={5,2,4,1,3,7,6,9,8};

    int n=sizeof(data)/sizeof(int);

    for(int i=0;i<n;i++)
        root=create(root,data[i]);


    in_succ(root,3);
    cout<<endl;

    return 0;
}
