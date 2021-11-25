#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

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

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    } else {
        printf("Duplicate Value!\n");
    }
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

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    } else {
        printf("Cannot Find the Value!\n");
    }
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

int main () {
    BST myBST;
    bst_init(&myBST);
    int length, input, panjang, value;
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &input);
        bst_insert(&myBST, input);
    }
    char string[101];
    scanf("%d", &panjang);
    for (int i = 0; i < panjang; i++) {
        scanf("%s", string);
        if (strcmp(string, "insert")==0) {
            scanf("%d", &value);
                bst_insert(&myBST, value);
        }
        else if (strcmp(string, "remove")==0) {
            scanf("%d", &value);
                bst_remove(&myBST, value);
        }
        else if (strcmp(string, "inorder")==0) {
            bst_inorder(&myBST); 
            printf("\n");  
        }
        else if (strcmp(string, "preorder")==0) {
            bst_preorder(&myBST); 
            printf("\n");    
        }
        else if (strcmp(string, "postorder")==0) {
            bst_postorder(&myBST); 
            printf("\n");    
        }
    }
}

// 8
// 8 10 14 3 6 7 1 4