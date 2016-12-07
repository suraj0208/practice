#include <iostream>
#include <set>
#include "build.h"

using namespace std;

void preorderutil(node* root,set<int> &s,int root_data ){
    if (!root)
        return;

    int rem = root_data-root->data;

    if(s.find(rem)!=s.end()){
        cout<<rem<<" "<<root->data<<endl;
    }

    s.insert(root->data);

    preorderutil(root->left,s,root_data);
    preorderutil(root->right,s,root_data);

    s.erase(root->data);

}

void preorder(node* root){
    set<int> s;

    preorderutil(root->left,s,root->data);
    preorderutil(root->right,s,root->data);

}

int main(){
    int in[] = {9,5,1,7,2,12,8,4,3,11};
    int pre[] = {8,5,9,7,1,12,2,4,11,3};

    int preindex=0;
    node* root =construct(pre,in,0,10,&preindex);

    preorder(root);



}
