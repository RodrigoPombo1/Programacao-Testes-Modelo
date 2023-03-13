#include "print_array.h"
using namespace std;

int filter_duplicates(const int a[], int n, int b[]) {
    int count = 0;
    int i = 0;
    if (n == 1) {
        b[0] = a[0];
        return 1;
    }
    if (n == 2) {
        if (a[i] == a[i + 1]) {
            b[0] = a[1];
            return 1;
        }
        b[0] = a[0];
        b[1] = a[1];
        return 2;
    }
    if (n <= 0) {
        return 0;
    }
    // previous char written in b
    char last_chr = a[0];
    b[count] = a[0];
    count++;
    for (i = 0; i < n - 1; i++) {
        if (last_chr != a[i + 1]) {
            b[count] = a[i + 1];
            count++;
            last_chr = a[i + 1];
        }
    }
    return count;
}