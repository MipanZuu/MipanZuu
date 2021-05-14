//
//  main.c
//  Praktikum M3
//
//  Created by Denta Bramasta Hidayat on 26/04/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
    int id;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

/* Struktur ADT Stack */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;



typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);



AVLNode* _avl_createNode(int id ,int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->id = id ;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int id) {
    while (root != NULL) {
        if (id < root->id)
            root = root->left;
        else if (id > root->id)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0;
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),_getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),_getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),_getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),_getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl, AVLNode* node, int id ,int value) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(id ,value);
    if(id < node->id)
        node->left = _insert_AVL(avl,node->left, id ,value);
    else if(id > node->id)
        node->right = _insert_AVL(avl,node->right,id,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right));

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && id < node->left->id)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && id > node->left->id)
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && id > node->right->id)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && id < node->right->id)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}


void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int id) {
    AVLNode *temp = _search(avl->_root, id);
    if (temp == NULL)
        return false;
    
    if (temp->id == id)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int id,int value){
    if(!avl_find(avl, id)){
        avl->_root=_insert_AVL(avl,avl->_root, id ,value);
        avl->_size++;
    }

}

void preOrder(AVLNode *root) {
    if (root) {
        preOrder(root->left);
        printf("%d %d ", root->id, root->data);
        preOrder(root->right);
    }
}

void stack_init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack)
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack)
{
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}


int price_avl(AVL *avl, int num ,int id){
    if(!avl_isEmpty(avl)){
        
        AVLNode *temp = _search(avl->_root, id);
        int price = temp->data * num;
        return price;
    }
    else
        return 0;
}

void total_price(Stack *stack){
    if(!stack_isEmpty(stack)){
    
        StackNode *temp = stack->_top;
        int total = 0;
        
        while(temp!= NULL){
            total += temp->data;
            temp = temp->next;
        }
        printf("%d\n", total);
    }
    else return;
}


int main () {
    
    int id, price;
    int id_urut = 0;
    bool condition = true;
    
    AVL Avl;
    avl_init(&Avl);
    Stack stack;
    stack_init(&stack);
    
    while (1) {
        scanf("%d %d", &id, &price);
        
        if (id == 0 && price == 0) {
            break;
        }
        id_urut++;
        if (id != id_urut) {
            printf("ID harus urut \n");
            condition = false;
            break;
        }
        else {
            avl_insert(&Avl, id, price);
        }
    }
    
    if (condition == true) {
        int amount, id_product;
        int total;
        do {
            scanf("%d %d", &amount, &id_product);
            
            if (amount == 0 && id_product == 0)
                break;
            if (!avl_find(&Avl, id_product)) {
                printf("Maaf barang tidak tersedia\n");
            } else {
                total = price_avl(&Avl, amount, id_product);
                stack_push(&stack, total);
            }
        }
        while (amount != 0 && id_product != 0);
            total_price(&stack);
    }
}

