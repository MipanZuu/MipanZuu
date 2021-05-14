//
//  main.c
//  Hall of Murderer
//
//  Created by Denta Bramasta Hidayat on 11/04/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>

/**
 * Node structure and
 * uniqueBST structure
 */

#define NAME_SIZE 100

typedef struct bstnode_t {
    bool killed;
    int kill_count;
    char name[NAME_SIZE];
    
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions,
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(char *name) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->left = newNode->right = NULL;
    
    strcpy(newNode->name,name);
    newNode->kill_count = 0;
    newNode->killed = false;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, char *name) {
   if (root == NULL)
        return __bst__createNode(name);

    if (strcmp(name,root->name)<0)
        root->left = __bst__insert(root->left, name);
    else if (strcmp(name, root->name)>0)
        root->right = __bst__insert(root->right, name);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, char *name) {
    while (root != NULL) {
        if (strcmp(name,root->name)<0)
            root = root->left;
        else if (strcmp(name,root->name)>0)
            root = root->right;
        else
            return root;
    }
    return root;
}

void __bst__preorder(BSTNode *root) {
    if(root){
    
        if (!root->killed) {
            printf("%s %d\n", root->name,root->kill_count);
        }
            __bst__preorder(root->left);
            __bst__preorder(root->right);
        
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_findAsMurderer(BST *bst, char *name) {
    BSTNode *temp = __bst__search(bst->_root, name);
    if (temp == NULL)
        return false;
    
    if (strcmp(temp->name,name)==0){
        temp->kill_count++;
        return true;
    }
    else
        return false;
}

bool bst_findAsVictim(BST *bst, char *name) {
    BSTNode *temp = __bst__search(bst->_root, name);
    if (temp == NULL)
        return false;
    
    if (strcmp(temp->name,name)==0){
    
        temp->killed = true;
        
        return true;
    }
    else
        return false;
}

bool bst_find(BST *bst, char *name) {
    BSTNode *temp = __bst__search(bst->_root, name);
    if (temp == NULL)
        return false;
    
    if (strcmp(temp->name,name)==0)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, char *murdererName,char *victimName) {
    if (!bst_find(bst, murdererName)) {
        bst->_root = __bst__insert(bst->_root, murdererName);
        bst->_size++;
    }
    bst_findAsMurderer(bst,murdererName);
    bst_findAsVictim(bst,victimName);
}

 void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

int main()
{
    BST Hall;
    bst_init(&Hall);

   char murderer[NAME_SIZE],victim[NAME_SIZE];
   
   while(scanf("%s %s",murderer,victim ) != EOF){
       getchar();
        bst_insert(&Hall,murderer,victim);
   }
   
   
   printf("HALL OF MURDERERS\n");
   bst_preorder(&Hall);
   
    return 0;
}
