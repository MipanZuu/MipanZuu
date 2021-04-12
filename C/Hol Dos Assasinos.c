#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Structure for the two BSTs
typedef struct as_bstnode{
    char name[20];
    unsigned numberOfVictims;
    struct as_bstnode *left, *right;
} MurderNode;

typedef struct vi_bstnode{
    char name[20];
    struct vi_bstnode *left, *right;
} VictimNode;

typedef struct as_bst{
    MurderNode *_root;
} MurderBST;

typedef struct vi_bst{
    VictimNode *_root;
} VictimBST;

// Utility Functions
MurderNode* search_murderBST(MurderNode *root, char *findWho){
    while(root != NULL){
        if(strcmp(root->name,findWho)>0)
            root = root->left;
        else if(strcmp(root->name,findWho)<0)
            root = root->right;
        else
            return root;
    }
    return root;
}

VictimNode* search_victimBST(VictimNode *root, char *findWho){
    while(root != NULL){
        if(strcmp(root->name,findWho)>0)
            root = root->left;
        else if(strcmp(root->name,findWho)<0)
            root = root->right;
        else
            return root;
    }
    return root;
}

MurderNode* insert_murderBST(MurderNode *root, char *who){
    if (root == NULL){
        root = (MurderNode*) malloc(sizeof(MurderNode));
        strcpy(root->name,who);
        root->numberOfVictims = 1;
        root->left = root->right = NULL;
    }
    else if(strcmp(root->name,who)>0)
        root->left = insert_murderBST(root->left,who);
    else if(strcmp(root->name,who)<0)
        root->right = insert_murderBST(root->right,who);
    else
        root->numberOfVictims++;
    return root;

}

VictimNode* insert_victimBST(VictimNode *root, char *who){
    if (root == NULL){
        root = (VictimNode*) malloc(sizeof(VictimNode));
        strcpy(root->name,who);
        root->left = root->right = NULL;
    }
    else if(strcmp(root->name,who)>0)
        root->left = insert_victimBST(root->left,who);
    else if(strcmp(root->name,who)<0)
        root->right = insert_victimBST(root->right,who);
    return root;

}

// Primary Functions
bool find_murderBST(MurderBST *bst, char *findWho){
    MurderNode *temp = search_murderBST(bst->_root, findWho);
    if(temp == NULL)
        return false;

    if(strcmp(temp->name,findWho)==0)
        return true;
    else
        return false;
}

bool find_victimBST(VictimBST *bst, char *findWho){
    VictimNode *temp = search_victimBST(bst->_root, findWho);
    if(temp == NULL)
        return false;

    if(strcmp(temp->name,findWho)==0)
        return true;
    else
        return false;
}

void add_murderBST(MurderBST *bst, char *who){
    bst->_root = insert_murderBST(bst->_root,who);
}

void add_victimBST(VictimBST *bst, char *who){
    //if(!find_victimBST(bst,who))
        bst->_root = insert_victimBST(bst->_root,who);
}

void print_murderer(MurderNode *murder, VictimBST *victim){
    if(murder){
        print_murderer(murder->left,victim);
        if(!find_victimBST(victim,murder->name))
            printf("%s %u\n", murder->name, murder->numberOfVictims);
        print_murderer(murder->right,victim);
    }
}

void print_hall(MurderBST *murder, VictimBST *victim){
    if(murder->_root != NULL){
        puts("HALL OF MURDERERS");
        print_murderer(murder->_root,victim);
    }
}

void init_both(MurderBST *murder, VictimBST *victim){
    murder->_root = victim->_root = NULL;
}
// Main

int main(){

    MurderBST murder;
    VictimBST victim;
    init_both(&murder,&victim);
    char killer[20], dead[20];

    while(scanf(" %s %s", killer, dead) != EOF){
        add_murderBST(&murder, killer);
        add_victimBST(&victim, dead);
    }

    print_hall(&murder,&victim);
    return 0;
}
