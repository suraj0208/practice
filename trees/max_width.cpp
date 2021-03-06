#include <iostream>
#include "build.h"

using namespace std;

int height(node* root){
    if(root==null)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh>rh)
        return 1+lh;

    return 1+rh;
}

int printLevel(node* root,int level){
    if(!root)
        return 0;

    if(level==1){
        return 1;
    }


    return printLevel(root->left,level-1) + printLevel(root->right,level-1);

}

int maxwidth(node* root){
    int h = height(root);

    int max=0;
    for(int i=1;i<=h;i++){
        int temp=printLevel(root,i);

        if(max<temp)
            max=temp;
    }
    return max;
}

int main(){
    int in[] = {4,2,5,1,7,3,8};
    int pre[] = {1,2,4,5,3,7,8};

    int preindex=0;
    node* root =construct(pre,in,0,7,&preindex);

    cout<<maxwidth(root)<<endl;


    return 0;
}
