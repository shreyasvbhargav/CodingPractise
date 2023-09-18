#include<iostream>
#include <unistd.h>
using namespace std;

typedef struct tree{
    int val;
    struct tree *left, *right;
}tree;

tree* newNode(int val){
    tree *node = new tree();
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

tree* newTree(){
    tree *root = newNode(20);
    
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->left->right->left = newNode(12);
    root->left->right->right = newNode(18);

    root->right = newNode(30);
    root->right->right = newNode(40);

    return root;
}


void inorder(tree *root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->val<<", ";
    inorder(root->right);
}

int diameter(tree *root, int &entire){
    if(root == NULL)
        return 0;

    int left = diameter(root->left, entire);
    int right = diameter(root->right, entire);

    int onepath = max(left, right)+1;
    entire = max(entire, left+right+1);

    return onepath;
}


int main(){
    int entire = 0;
    int diam = 0;

    tree *root = newNode(50);
    root->right = newNode(100);
    root->right->right = newNode(120);
    root->left = newTree();
    inorder(root);
    cout<<endl;
    int tmp = diameter(root, entire);
    diam = max(entire, tmp);
    cout<<diam<<endl;
}