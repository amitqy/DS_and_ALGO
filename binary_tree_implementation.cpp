#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *left, *right;
};

Node *newNode(int val)
{
    Node *n = new Node;
    n->data = val;
    n->left = n->right = NULL;
    return n;
}
void insert(Node *root, int val)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if (n->left != NULL)
        {
            q.push(n->left);
        }
        else
        {
            n->left = newNode(val);
            break;
        }
        if (n->right != NULL)
        {
            q.push(n->left);
        }
        else
        {
            n->right = newNode(val);
            break;
        }
        
    }
}

void levelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();
        cout << n->data <<" ";
        if(n->left != NULL)
          q.push(n->left);
        if(n->right != NULL)
          q.push(n->right);
    }
    
}
void inOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(root == NULL){
            root = newNode(val);
        }
        else
        {
            insert(root,val);
        }
        
    }
    inOrder(root);
    cout << endl;
    levelOrder(root);
    return 0;
}

