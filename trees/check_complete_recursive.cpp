#include <iostream>
#include <queue>

#include "build.h"

using namespace std;

int get_total_nodes(node* root){
    if(root==null)
        return 0;

    return 1+get_total_nodes(root->left)+get_total_nodes(root->right);
}

bool check_complete_recursive(node* root,int index,int n){
    if(root==null)
        return true;

    if(index>=n)
        return false;

    return check_complete_recursive(root->left,2*index+1,n) && check_complete_recursive(root->right,2*index+2,n);
}

int main(){
    int in[] = {4,2,5,1,6,3,7};
    int pre[] = {1,2,4,5,3,6,7};

    int preindex=0;
    node* root =construct(pre,in,0,6,&preindex);

    int n=get_total_nodes(root);
    cout<<check_complete_recursive(root,0,n)<<endl;

    return 0;
}
