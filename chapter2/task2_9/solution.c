#include <stdio.h>

int bitcount(unsigned x) {
    int counter = 0;
    while (x != 0) {
        x &= (x - 1);
        counter++;
    }
    return counter;
}

int main() {
    printf("%d\n", bitcount(7));
    printf("%d\n", bitcount(1));
    printf("%d\n", bitcount(10));
    printf("%d\n", bitcount(255));
    printf("%d\n", bitcount(25));
    return 0;
}
