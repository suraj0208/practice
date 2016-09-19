#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

bool isEqual(node* root,node* subtree){
    if(root==null && subtree==null)
        return true;

    if(root==null || subtree == null)
        return false;

    return root->data==subtree->data && isEqual(root->left,subtree->left) && isEqual(root->right,subtree->right);

}

bool isSubtree(node* root,node* subtree){
    if(root==null && subtree==null)
        return true;

    if(root==null || subtree == null)
        return false;

    if(root->data==subtree->data)
        return isEqual(root,subtree);

    return isSubtree(root->left,subtree) || isSubtree(root->right,subtree);

}

int main(){
    int subdata[] = { 5,4,1,6,8,7,9,10,3};

    int data[] = { 25,5,4,1,6,8,7,9,10,3};

    node* subtree = null;
    node* root = null;

    int ns = sizeof(subdata)/sizeof(subdata[0]);

    for(int i=0;i<ns;i++){
        subtree=create(subtree,subdata[i]);
    }

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    cout<<isSubtree(root,subtree)<<endl;


    return 0;
}
