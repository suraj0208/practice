#include <iostream>
#include <queue>

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

void printLevel(node* root,int level){
    if(level==1){
        cout<<root->data<<" ";
    }

    if(root->left)
        printLevel(root->left,level-1);

    if(root->right)
        printLevel(root->right,level-1);
}

void bfs_recurr(node* root){
    int h = height(root);

    for(int i=1;i<=h;i++){
        printLevel(root,i);
        cout<<endl;
    }
    cout<<endl;
}


void bfs(node* root){
    queue<node*> q;

    if(root)
        q.push(root);

    while(q.size()!=0){
        root=q.front();
        cout<<root->data<<" ";

        if(root->left)
            q.push(root->left);

        if(root->right)
            q.push(root->right);

        q.pop();
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

    bfs(root);
    bfs_recurr(root);

    return 0;
}
