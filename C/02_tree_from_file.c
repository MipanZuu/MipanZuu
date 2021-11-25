#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

unsigned int leaf(struct node *root) 
{ 
  if(root == NULL)        
    return 0; 
  if(root->left == NULL && root->right==NULL)       
    return 1;             
  else 
    return leaf(root->left); 
           leaf(root->right);       
} 

int leftLeafSum(struct node *root){
	int res = 0;
	
	if(root != NULL){
		if(leaf(root->left)){
			res += root->left->data; 
		}else{
			 res += leftLeafSum(root->left); 
			 res += leftLeafSum(root->right);
		}
	}
}

int rightLeafSum(struct node *root){
	int res = 0;
	
	if(root != NULL){
		if(leaf(root->right)){
			res += root->right->data; 
		}else{
			 res += leftLeafSum(root->left); 
			 res += leftLeafSum(root->right);
		}
	}
}

struct node *newnode(int i){
	struct node *curnode = (struct node*)malloc(sizeof(struct node));
	curnode->data = i;
	curnode->left = NULL;
	curnode->right = NULL;
	
	return curnode;
}

void printpreorder(struct node *root){
	if(root == NULL){
		return;
	}
	printf("%d", root->data);
	printpreorder(root->left);
	printpreorder(root->right);
}
	

int main(){
	
	FILE *fp;
	fp = fopen("02_file_input.txt", "r");
	char varinput[100];
	
	while(!feof(fp)){
		fgets(varinput, 100, fp);
		puts(varinput);
	}
	fclose(fp);
	
	printf("Binary tree in preorder traversal : \n");

	struct node *root = newnode(1);
	root->left = newnode(1);
	root->left->left = newnode(2); 
	root->left->right = newnode(1);
	root->right = newnode(4);
	root->right->right = newnode(5);
	root->right->left = newnode(3);
	
	printpreorder(root);
	
	printf("\n\n the leaf is : %d \n", leaf(root));
	
	printf("\n the left leaf sum is : %d \n", leftLeafSum(root));
	
	printf("\n the right leaf sum is : %d \n", rightLeafSum(root));
	
	return 0;
}

