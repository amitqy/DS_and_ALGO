/*
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}


only contains the function


*/




void levelOrder(Node* root)
{
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
      Node *curr = q.front();
      q.pop();
      if(curr != NULL){
          cout << curr->data << " ";
      if(curr->left!=NULL){
           q.push(curr->left);
      }
      if(curr->right!=NULL){
           q.push(curr->right);
      }
      }
      else{
          if(q.size() ==0){
              break;
          }
          else{
          q.push(NULL);
           cout << endl;
          }
      }
  }
}
