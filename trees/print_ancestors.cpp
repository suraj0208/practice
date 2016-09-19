#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

bool printAncestors(node* root,int data){
    if(root==null)
        return false;

    if(root->data==data)
        return true;

    bool l=printAncestors(root->left,data);
    bool r=printAncestors(root->right,data);

    if(l||r){
        cout<<root->data<<" ";
        return true;
    }
    return false;

}


int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    printAncestors(root,3);
    cout<<endl;

    return 0;
}
