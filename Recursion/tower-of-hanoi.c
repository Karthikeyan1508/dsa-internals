#include <stdio.h>

void tower(int n, char source, char dest, char temp);

int main() {
    int n;
    printf("Enter the number of disks\n");
    scanf("%d", &n);
    tower(n, 's', 'd', 't');
    return 0;
}

void tower(int n, char source, char dest, char temp) {
    if (n > 0) {
        tower(n - 1, source, temp, dest);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        tower(n - 1, temp, dest, source);
    }
}
