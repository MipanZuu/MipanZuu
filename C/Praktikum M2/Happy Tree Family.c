//
//  main.c
//  Praktikum M2
//
//  Created by Denta Bramasta Hidayat on 12/04/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct bstnode_t {
    int key;
      struct bstnode_t *left, *right;
}     BSTNode;

typedef struct bst_t {
      BSTNode *_root;
      unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
  BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
  newNode->key = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
  if (root == NULL)
    return __bst__createNode(value);

  if (value < root->key)
    root->left = __bst__insert(root->left, value);
  
  else if (value > root->key)
      root->right = __bst__insert(root->right, value);
  
  return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
  while (root != NULL) {
    if (value < root->key)
      root = root->left;
    else if (value > root->key)
      root = root->right;
    else
      return root;
  }
  return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

bool bst_find(BST *bst, int value) {
      BSTNode *temp = __bst__search(bst->_root, value);
      if (temp == NULL)
        return false;
  
      if (temp->key == value)
        return true;
      else
        return false;
}
 
void Parent(BSTNode *root, int num, int parent){
    if(root == NULL)
        return;
    
    if(root->key == num){
        printf("%d ", parent);
    }
    else {
        Parent(root->left, num, root->key);
        Parent(root->right, num,root->key);
    }
}

void FindParent (BST *bst, int X){
    Parent(bst->_root, X, -1);
}

void FindChild(BST *bst, int num){
    if (!bst_find(bst, num)){
        printf("404 Not Found\n");
    }
    else {
        BSTNode *temp =  __bst__search(bst->_root, num);
     
        if(temp != NULL){
            if(temp->left != NULL)
            printf("%d ", temp->left->key);
            
            if(temp->right != NULL)
            printf("%d ", temp->right->key);
        
            printf("\n");
        }
        else
            return;
    }
}

void bst_init(BST *bst) {
      bst->_root = NULL;
      bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
      return bst->_root == NULL;
}
void bst_insert(BST *bst, int value) {
      if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
  }
}

int main()
{
    BST Family;
    bst_init(&Family);
    int N, n, X, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &N);
        bst_insert(&Family, N);
    }
    
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
        scanf("%d", &X);
        FindParent(&Family, X);
        FindChild(&Family, X);
    }
    
  return 0;
}
