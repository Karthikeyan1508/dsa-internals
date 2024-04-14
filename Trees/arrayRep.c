#include<stdio.h>

void create(int tree[]) {
    int n, val, i, k;
    printf("no. of nodes:");
    scanf("%d", &n);
    printf("Enter the values of each node:");
    for (k = 1; k <= n; k++) {
        scanf("%d", &val);
        i = 1;
        while (tree[i] != 0) {
            if (val < tree[i])
                i = 2 * i;
            else
                i = 2 * i + 1;
        }
        tree[i] = val;
    }
}

int main() {
    int tree[20] = {0}, i;
    create(tree);
    for (i = 1; i < 20; i++)
        printf("%d ", tree[i]);
    return 0;
}
