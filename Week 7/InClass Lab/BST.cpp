#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  // if(root->left == NULL && root->right == NULL ){
  //   cout << root->key;
  // }
  // else{
  //   traverseInOrder(root->left);
  //   cout << root->key;
  //   traverseInOrder(root->right);
  // }
  if(root == NULL){
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key){
  if(node == NULL){
    struct node *node = new struct node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
  }
  else {
    if(key<=node->key){
      node->left = insertNode(node->left,key);
      return node;
    }
    else{
      node->right = insertNode(node->right, key);
      return node;
    }
  }
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root == NULL){
    return root;
  }
  else{
    if(key < root->key){
      root-> left = deleteNode(root->left, key);
      return root;
    }
    else if(key > root->key){
      root->right = deleteNode(root->right, key);
      return root;
    }
    else{
      if(root->left == NULL && root->right == NULL){
        delete root;
        root = NULL;
        return root;
      }
      else if (root-> left == NULL){
        struct node *temporary = root;
        root = root->right;
        delete temporary;
        return root;
      }
      else if (root->right == NULL){
        struct node *temporary = root;
        root = root->left;
        delete temporary;
        return root;
      }
      else{
        struct node *temporary = root->right;
        while(temporary != NULL && temporary->left != NULL){
          temporary = temporary->left;
        }
        root->key = temporary->key;
        root->right = deleteNode(root->right, temporary->key);
        return root;
      }
    }
  }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}