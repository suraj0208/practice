#include <iostream>
#include "build.h"
#include <climits>

using namespace std;

void find_min_max(node* root, int level,int* min, int* max){
    if(!root)
        return;

    if(level<*min)
        *min=level;
    else if(level>*min)
        *max=level;

    find_min_max(root->left,level-1,min,max);
    find_min_max(root->right,level+1,min,max);

}

void print_line(node* root, int level,int line){
    if(!root)
        return;

    if(line==level)
        cout<<root->data<<" ";

    print_line(root->left,level-1,line);
    print_line(root->right,level+1,line);

}

void vertical_order(node* root){
    int max=INT_MIN;
    int min=INT_MAX;

    find_min_max(root,0,&min,&max);

    for(int i=min;i<=max;i++){
        print_line(root,0,i);
        cout<<endl;
    }

}


int main(){
    int in[] = { 4,2,5,1,6,8,3,7,9 };
    int pre[] ={ 1,2,4,5,3,6,8,7,9 };

    int preindex=0;
    node* root =construct(pre,in,0,9,&preindex);

    vertical_order(root);

    return 0;
}
