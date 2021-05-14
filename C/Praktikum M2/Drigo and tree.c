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

bool bst_find(BST *bst, int value) {
      BSTNode *temp = __bst__search(bst->_root, value);
      if (temp == NULL)
        return false;
  
      if (temp->key == value)
        return true;
      else
        return false;
}


void bst_init(BST *bst) {
      bst->_root = NULL;
      bst->_size = 0u;
}

void bst_insert(BST *bst, int value) {
      if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
  }
}
void printKthNode(BSTNode* root, int N)
{
   if(root == NULL)
       return;

   static int index = 0; //These will initialize to zero only once as its static

   //For every Node go to the right of that node first.
   printKthNode(root->right, N);


   //Right has returned and now current node will be greatest
   if(++index == N)
   {
    printf("%d", root->key);
    return;
   }

   //And at last go to the left
   printKthNode(root->left, N);
}

void print (BST *bst, int k)
{
    printKthNode(bst->_root, k);
}


//void largest(BSTNode *root, int K)
//{
//    int c = 0;
//    while (root != NULL && root->right != NULL)
//    {
//        largest(root->right, K);
//        c++;
//        if (c == K) {
////            root = root->right;
////            root = root->left;
//            printf("%d", root->key);
//            return;
//        }
//    }
//}
//
//void BSTLarge(BST *bst, int K)
//{
//    largest(bst->_root, K);
//}

//void kthLargestUtil(BSTNode *root, int k, int *c)
//{
//    if (root == NULL || *c >= k)
//        return;
//
//    kthLargestUtil(root->right, k, c);
//    c++;
////    root = root->right;
//    if (*c == k)
//    {
//        root = root->right;
//        root = root->left;
//        printf("%d", root->key);
//        return;
//    }
//    kthLargestUtil(root->left, k, c);
//}
//
//void kthLargest(BST *bst, int k)
//{
//    int c = 0;
//    kthLargestUtil(bst->_root, k, &c);
//}

int main()
{
      BST Bakery;
      int chef, K, drigo[100];
      bst_init(&Bakery);

    scanf("%d %d", &chef, &K);
    for (int i = 0; i < chef; i++) {
        scanf("%d", &drigo[i]);
        bst_insert(&Bakery, drigo[i]);
    }
    print(&Bakery, K);
//    BSTLarge(&Bakery, K);
//    kthLargest(&Bakery, K);
    
  return 0;
}
