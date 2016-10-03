#include <iostream>
#include <queue>
#include "build.h"

using namespace std;

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void bfs(node* root,int low,int high){

    node* marker = new node;
    queue<node*> q;

    q.push(root);
    q.push(marker);

    int level =0;

    while(!q.empty()){
        node* n = q.front();
        q.pop();

        if(n==marker){
            level++;

            if(level>high)
                break;

            q.push(marker);

            if(level>low)
                cout<<endl;
            continue;
        }

        if(level>=low){
            cout<<n->data<<" ";
        }

        if(n->left)
            q.push(n->left);

        if(n->right)
            q.push(n->right);

    }


}

int main(){
    int in[] = { 4,8,10,12,14,20,22 };
    int pre[] ={ 20,8,4,12,10,14,22 };

    int preindex=0;
    node* root =construct(pre,in,0,sizeof(in)/sizeof(in[0]),&preindex);

    bfs(root,1,3);
    cout<<endl;

    return 0;
}
