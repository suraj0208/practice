#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

void inorder(node *root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void iterative_postorder(node* root){
    stack<node*> st;

    do{
        while(root){
            if(root->right)
                st.push(root->right);

            st.push(root);
            root=root->left;
        }

        root=st.top();
        st.pop();

        if(root->right && st.top()==(root->right)){
            st.pop();
            st.push(root);
            root=root->right;
        }else{
            cout<<root->data<<" ";
            root=null;
        }

    }while(!st.empty());

}


int main(){
    //int in[] = {9,7,10,10,12,15};
    //int pre[] = {10,7,9,10,15,12};


    int in[] = {7,9,10,11,15};
    int pre[] = {10,7,9,15,11};

    int preindex=0;
    node* root = construct(pre,in,0,5,&preindex);

    inorder(root);
    cout<<endl;

    iterative_postorder(root);


    return 0;
}
