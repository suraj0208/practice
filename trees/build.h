#define null NULL

struct node{
    int data;
    node* left;
    node* right;
};

node* create(node* root,int data){
   if(root==null){
       root = new node;
       root->data=data;
       root->left=null;
       root->right=null;
       return root;
   }

   if(data<root->data){
       root->left = create(root->left,data);
   }else{
       root->right = create(root->right,data);
   }
   return root;
}
