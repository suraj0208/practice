#include <iostream>
#define null NULL

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* create(node* root,int data){
    if(root==null){
        root=new node;
        root->data=data;
        root->left=null;
        root->right=null;
        return root;
    }
    if(data<root->data){
        root->left=create(root->left,data);
    }else
        root->right=create(root->right,data);

    return root;
}

void inorder(node* root){
    if(root==null)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int height(node* root){
    if(root==null)
        return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    if(lh>rh)
        return 1+lh;

    return 1+rh;
}

void printLevel(node* root,int level){
    if(root==null)
        return;

    if(level==1)
        cout<<root->data<<" ";
    else{
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }

}

int getLevelWidth(node* root,int level){
    if(root==null)
        return 0;

    if(level==1)
        return 1;

    return getLevelWidth(root->left,level-1)+getLevelWidth(root->right,level-1);
}

int getWidth(node* root){
    int ht=height(root);
    int width=0;

    for(int i=1;i<=ht;i++){
        int curr=getLevelWidth(root,i);
        if(width<curr)
            width=curr;
    }
    return width;
}

void getLevel(node* root){
    int ht=height(root);

    for(int i=1;i<=ht;i++){
        printLevel(root,i);
    }
}

int find(int inor[],int data,int beg,int n){
    for(int i=beg;i<=n;i++)
        if(inor[i]==data)
            return i;
    return -1;
}
node* buildTree(int inor[],int pre[], int instr,int inend){
    static int startIndex=0;

    if(instr>inend)
        return null;

    node* root=new node;
    root->left=null;
    root->right=null;
    root->data=pre[startIndex++];

    if(instr==inend)
        return root;

    int rootIndex=find(inor,root->data,instr,inend);

    root->left=buildTree(inor,pre,instr,rootIndex-1);
    root->right=buildTree(inor,pre,rootIndex+1,inend);

    return root;
}


int main(){
    int preor[]={5,4,3,2,1,6,7,8,9};
    int inor[]={1,2,3,4,5,6,7,8,9};
    int data[]={5,4,6,3,7,2,8,1,9};
    int len=9;

    node* root=null;

    for(int i=0;i<len;i++)
        root=create(root,data[i]);

    //root=buildTree(inor,preor,0,9);
    //getLevel(root);

    inorder(root);
    cout<<endl;
    getLevel(root);
    cout<<endl;
    cout<<getWidth(root)<<endl;

}
