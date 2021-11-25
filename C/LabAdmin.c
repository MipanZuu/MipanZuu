#include <stdio.h>
#include <stdbool.h>

#define Computers 51

int main () {
    int com, switches;
    bool electric[Computers] = {false};

    scanf("%d %d", &com, &switches);
    for (int i = 0; i < switches; i++)
    {
        int concom;
        scanf("%d", &concom);
        for (int j = 0; j < concom; j++)
        {
            int x;
            scanf("%d", &x);
            electric[x] = !electric[x];

        }
        
    }
    bool yes = true;
    for (int i = 0; i < com; i++)
    {
        if (electric[i] == false)
        {
            printf("NO\n");
            yes = false;
            break;
        }
        else {
            printf("YES\n");
            break;
        }
    }
}