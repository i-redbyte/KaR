#include <stdio.h>

int binsearch(int x, const int v[], int n);

int main(void) {
    int test[] = {1, 3, 4, 5, 6, 7, 8};
    int n = sizeof(test) / sizeof(*test);
    printf("Search result: %d\n", binsearch(3, test, n));
    printf("Search result: %d\n", binsearch(8, test, n));
    printf("Search result: %d\n", binsearch(1, test, n));
    printf("Search result: %d\n", binsearch(2, test, n));
    return 0;
}

int binsearch(int x, const int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return (x == v[low]) ? low : -1;
}
