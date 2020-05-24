

/*
https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
*/

Node* lca(Node* root ,int n1 ,int n2 )
{
   if(root == NULL){
       return NULL;
   }
   if(root->data == n1 || root->data == n2){
       return root;
   } 
   Node *a = lca(root->left,n1,n2);
   Node *b = lca(root->right,n1,n2);
   if(b == NULL && a != NULL){
       return a;
   }
   if(a == NULL && b== NULL){
       return NULL;
   }
   if(a != NULL && b != NULL){
       return root;
   }
}