#include <iostream>
#include <queue>

#include "build.h"

using namespace std;

bool isIdentical(node* root1, node* root2){
    if(root1 == null && root2 == null)
        return true;

    if( root1 == null || root2 == null)
        return false;

    bool d = root1->data == root2->data;

    bool sub = isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);

    return d&&sub;
}


int main(){

    int data1[] = { 5,4,1,6,8,9,10,3};
    int data2[] = { 5,4,1,6,8,9,10,3};

    node* root1 = null;
    node* root2 = null;

    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);

    for(int i=0;i<n1;i++){
        root1=create(root1,data1[i]);
    }

    for(int i=0;i<n2;i++){
        root2=create(root2,data2[i]);
    }

    cout<<isIdentical(root1,root2)<<endl;

    return 0;
}
