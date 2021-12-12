#include <stdio.h>
#include <stdlib.h>
#include "DisjSet.h"
 
void initialize(DisjSet set)
{
    for (int i = NumSets; i > 0; i--)
        set[i] = -1;
    

}
 
void setUnion(DisjSet set, SetType root1, SetType root2)
{
    if (set[root1] >= 0 || set[root2] >= 0)
        printf("Fail to union: Root1 and Root2 is not a root of tree");
    
    if (set[root1] == set[root2]) 
        return;
    else
    {
        if (set[root1] > set[root2]) 
            set[root1] = root2;
        else 
            set[root2] = root1;
    }
}
 
SetType find(ElementType x, DisjSet set)
{
    if (x > NumSets)
    {
        printf("x is not in DisjSet");
        return 0;
    }
    
    if (set[x] == 0) 
    {
        printf("Error: set[x] can not be 0");
        return 0;
    }
    

    if (set[x] < 0)
        return x;
    else
        return set[x] = find(set[x], set);
}
