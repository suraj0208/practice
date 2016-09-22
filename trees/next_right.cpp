#include <iostream>
#include "build.h"

using namespace std;

int height(node* root){
    if(!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh>rh)
        return 1+lh;

    return 1+rh;
}

bool printLevel(node* root, int level,int data,node** right){
    if(root==null)
        return false;

    if(level==1){
        if(root->data==data){
            if(*right)
                cout<<(*right)->data;
            else
                cout<<"null";
            return true;
        }
        (*right)=root;

        return false;
    }

    return  printLevel(root->right,level-1,data,right)
            || printLevel(root->left,level-1,data,right);

}

void level_order(node* root,int data){
    int h = height(root);

    for(int i=1;i<=h;i++){
        node* right=null;

        if(printLevel(root,i,data,&right))
            break;

    }
}

int main(){
    int in[] = {8,2,4,10,6,5};
    int pre[] = {10,2,8,4,6,5};

    int preindex=0;
    node* root =construct(pre,in,0,6,&preindex);

    for(int i=0;i<6;i++){
        cout<<in[i]<<" ";
        level_order(root,in[i]);
        cout<<endl;
    }

    return 0;
}
