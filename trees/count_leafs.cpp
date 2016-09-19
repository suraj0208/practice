#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

int getLeaf(node* root){
    if(root==null)
        return 0;

    if(root->left==null && root->right==null)
        return 1;

    return getLeaf(root->left)+getLeaf(root->right);

}

int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }


    cout<<getLeaf(root)<<endl;

    return 0;
}
