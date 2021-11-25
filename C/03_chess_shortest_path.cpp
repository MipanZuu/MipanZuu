#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct listNode {
    int x,y; /* define data as char */
    struct listNode *child[8]; /* listNode pointer */
}; /* end structure listNode */

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

int route[64];
int visited[8][8];

/* Protoypes */
int find (ListNodePtr *nPtr, int x, int y, int n);
void printRoute(ListNodePtr nPtr, int s);


int main () {
    int ax,ay,tx,ty;
    int i,j,len;
    ListNodePtr startPtr;
    
    /* Initialize array */
    for(i = 0; i < 64; i++) route[i] = -1;
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            visited[i][j] = 1000;
    
    /* Getting the input */
    while(1) {
        printf("Where the knight is: ");
        scanf("%d,%d",&ax,&ay);
        if(ax >= 0 && ax < 8 && ay >= 0 & ay < 8) break;
        printf("Invalid!!!\n");
    }
    while(1) {
        printf("Where do you want it to move: ");
        scanf("%d,%d",&tx,&ty);
        if(tx >= 0 && tx < 8 && ty >= 0 & ty < 8) break;
        printf("Invalid!!\n");
    }

    /* Initialize list */
    startPtr = (ListNodePtr) malloc( sizeof( ListNode ) );
    startPtr->x = ax;
    startPtr->y = ay;
    for(i = 0; i < 8; i++) startPtr->child[i] = NULL;

    /* Finding the route */
    len = find(&startPtr,tx,ty,0);
    
    printf("\nHow many moves = %d moves",len);
    printRoute(startPtr,len);
    
    return 0;
}

int find (ListNodePtr *nPtr, int x, int y, int n) {
    int i, j, c, l=100;
    ListNodePtr cPtr = *nPtr;
    int dx,dy;
    ListNodePtr newPtr;

    /* Pattern for Horse Step*/
    int ox[8] = {-2,-2,2,2,-1,-1,1,1};
    int oy[8] = {-1,1,-1,1,-2,2,-2,2};

    /* There are 8 possible option in each step, try them all */
    c = 0;
    for(i = 0; i < 8; i++) {
        dx = cPtr->x + ox[i];
        dy = cPtr->y + oy[i];

        /* Test if this options is feasible */
        if(dx >= 0 && dx < 8 && dy >= 0 && dy < 8 && visited[dx][dy] > n) {
            
            /* This options is feasible, let's create a new node */
            newPtr = (ListNodePtr) malloc( sizeof( ListNode ) );
            newPtr->x = dx;
            newPtr->y = dy;
            for(j = 0; j < 8; j++) newPtr->child[j] = NULL;
            cPtr->child[c] = newPtr;
            
            /* Mark this location as visited */
            visited[dx][dy]=n;
            
            /* Test if yhis location is finishing point */
            if(dx == x && dy == y) {
                route[n] = c;
                return(1);
            }

            /* This location is not finishing poit,
                so let's start new search in next level (n+1) */
            j = find (&newPtr,x,y,n+1);
            if(j < l) {
                l = j;
                route[n] = c;
            }
            c++;
        }
    }
    return (l+1);
}

void printRoute(ListNodePtr nPtr, int s) {
    int c = 0;
    ListNodePtr cPtr = nPtr;

    printf("\nThe Shortest Route is : \n");
    while(c < s) {
        printf("%d,%d ==> ", cPtr->x,cPtr->y);
        cPtr = cPtr->child[route[c]];
        c++;
    }
    printf("%d,%d \n\n (Finished) \n\n", cPtr->x,cPtr->y);
   
    return;
}
