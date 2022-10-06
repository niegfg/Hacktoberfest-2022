#include <stdio.h>
int linearsearch(int a[100], int n, int key)
{
    int i, pos, found = -1;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            found = i;
            break;
        }
    }
    return found;
}
int main()
{
    int a[100], i, n, key, p;
    printf("Enter no of elements in an array: ");
    scanf("%d", &n);
    printf("Enter the elements of array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &key);
    p = linearsearch(a, n, key);
    if (p == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", p + 1);
}
