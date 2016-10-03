#include <iostream>
#include "build.h"

using namespace std;

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int get_level(node* root,int data,int level){
    if(root==null)
        return -1;

    if(root->data==data)
        return level;

    int left = get_level(root->left,data,level+1);
    int right = get_level(root->right,data,level+1);

    return (left != -1 ? left:right);
}

bool check_siblings(node* root,int d1,int d2){
    if(root==null)
        return false;

    if(root->left && root->right){

        if((root->left->data == d1 || root->left->data==d2) && (root->right->data==d1 || root->right->data==d2))
            return true;

    }

    return check_siblings(root->left,d1,d2)||check_siblings(root->right,d1,d2);

}

bool check_cosins(node* root,int d1,int d2){

    int l1 = get_level(root,d1,0);
    int l2 = get_level(root,d2,0);


    return (l1==l2 && !check_siblings(root,d1,d2));


}

int main(){
    int in[] = { 7,2,8,6,1,5,3 };
    int pre[] ={ 6,2,7,8,5,1,3 };

    int preindex=0;
    node* root =construct(pre,in,0,sizeof(in)/sizeof(in[0]),&preindex);

    cout<<check_cosins(root,7,3)<<endl;

    return 0;
}
