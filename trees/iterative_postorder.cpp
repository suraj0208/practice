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

void postOrderIterative(struct node* root)
{
    // Check for empty tree
    if (root == NULL)
        return;

    stack<node*> stack;
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                stack.push(root->right);

            stack.push(root);

            // Set root as root's left child
            root = root->left;
        }

        // Pop an item from stack and set it as root
        root = stack.top();
        stack.pop();

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && stack.top() == root->right)
        {
            stack.pop();  // remove right child from stack
            stack.push(root);  // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            cout<<root->data<<" ";
            root = NULL;
        }
    } while (!stack.empty());
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

        if(root->right && st.top()==root->right){
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

    postOrderIterative(root);


    return 0;
}
