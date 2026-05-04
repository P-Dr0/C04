#include<iostream>
using namespace std;
struct node{
  int data;
  struct node * left;
  struct node * right;
};

void insert(node * & current, int data){
  if(current == NULL){
    current = new node;
    current->data = data;
    current->left = NULL;
    current->right = NULL;
  } else if(data < current->data){
    insert(current->left, data);
  } else {
    insert(current->right, data);
  }
}

node * search(node * current, int data){
  if(current == NULL){
    return NULL;
  } else if(data == current->data){
     return current;
  } else {
    if(data < current->data){
      return search(current->left, data);
    } else {
      return search(current->right, data);
    }
  }
}

int main(){
  node * root = NULL;

  insert(root, 34);
  insert(root, 56);
  insert(root, 9);
  insert(root, 12);
  insert(root, 8);

  node * result = search(root, 56);
  if(result == NULL){
    cout << "Element not found" << endl;
  } else {
    cout << "Element " << result->data << " found" << endl;
  }

  result = search(root, 13);
  if(result == NULL){
    cout << "Element not found" << endl;
  } else {
    cout << "Element " << result->data << " found" << endl;
  }

  return 0;
}