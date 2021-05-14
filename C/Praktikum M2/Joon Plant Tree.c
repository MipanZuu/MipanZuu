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

BSTNode* BalanceARRtoBST(int arr[], int start, int end)
{
    if (start > end)
      return NULL;
  
    int mid = (start + end+1)/2;
    BSTNode *root = __bst__createNode(arr[mid]);
  
   root->left =  BalanceARRtoBST(arr, start, mid-1);
   root->right = BalanceARRtoBST(arr, mid+1, end);
  
    return root;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void bubbleSort(int arr[], int size){
    int i,j;
    for(i = 0; i< size-1;i++){
        for(j = 0; j < size -i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void bst_init(BST *bst) {
      bst->_root = NULL;
      bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
      return bst->_root == NULL;
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

void bst_insert(BST *bst, int value) {
      if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
  }
}

void __bst__preorder(BSTNode* node){
    if (node == NULL)
        return;
    printf("%d ", node->key);
    __bst__preorder(node->left);
    __bst__preorder(node->right);
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

int main()
{
    int joon;
    scanf("%d", &joon);
    int arr[joon];
    for (int i = 0; i < joon; i++) {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    BSTNode *root = BalanceARRtoBST(arr, 0, size-1);
    
    __bst__preorder(root);
    printf("\n");
    __bst__inorder(root);
    printf("\n");
    __bst__postorder(root);
    printf("\n");
  return 0;
}
