#include<iostream>
#include<stack>
#include <queue>
using namespace std;

typedef 
struct node{
    int v;
    struct node *left;
    struct node *mid;
    struct node *right;
}node;

node * newnode(int val){
    node *n = (node *)malloc(sizeof(node));
    n->v = val;
    n->left = n->mid = n->right = NULL;
    return n;
}

void level(node *root){
    queue<node *> q;
    node *curr = NULL;

    cout<<root->v<<", ";

    q.push(root->left);
    q.push(root->mid);
    q.push(root->right);

    while(!q.empty()){
        curr = q.front();
        q.pop();

        cout<<curr->v<<", ";
        if(curr->left)
            q.push(curr->left);
        if(curr->mid)
            q.push(curr->mid);
        if(curr->right)
            q.push(curr->right);
    }
    cout<<endl;
}

void inorder(node *root){
    stack<node *> s;
    node *curr = NULL;

    if(root == NULL)
        return;

    s.push(root);
    curr = root->left;

    while(!s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        while(curr == NULL && !s.empty()){
            curr = s.top();
            //curr = curr->mid;
            inorder(curr->mid);
            cout<<curr->v<<", ";
            s.pop();
            curr = curr->right;
            inorder(curr);
            curr=NULL;
            //curr = s.top()->mid;
        }
    }
    cout<<endl;
}

void preorder(node *root){
    if(root == NULL)
        return;
    
    cout<<root->v<<", ";

    preorder(root->left);
    preorder(root->mid);
    preorder(root->right);
}

void postorder(node *root){
    if(root == NULL)
        return;
    
    
}

int main(){
    node * root = newnode(1);
    root->left = newnode(2);
    root->mid = newnode(3);
    root->right = newnode(4);
#if 1
    root->left->left = newnode(5);
    root->left->left->left = newnode(10);
#endif
    root->left->right = newnode(6);
    root->left->right->left = newnode(11);
    root->left->right->mid = newnode(12);
    root->left->right->right = newnode(13);
#if 1
    root->right->left = newnode(7);
    root->right->mid = newnode(8);
    root->right->right = newnode(9);
#endif
    //level-order
    level(root);

    //inorder
    inorder(root);

    //preorder
    preorder(root);
}