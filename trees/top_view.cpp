#include <iostream>
#include "build.h"

using namespace std;

void top_view(node* root,int* min,int *max){

    if(root==null)
        return;

    top_view(root->left);

}

int main(){
    int in[] = {4,2,5,1,3};
    int pre[] = {1,2,4,5,3};

    int preindex=0;
    node* root =construct(pre,in,0,5,&preindex);

    inorder(root);
    cout<<endl;
    double_tree(root);
    inorder(root);
    cout<<endl;

    return 0;
}
