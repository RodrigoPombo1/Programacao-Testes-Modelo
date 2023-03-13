#include "complex.h"
using namespace std;

complex add_complex(complex a, complex b) {
    complex res;
    res.real = b.real + a.real;
    res.img = b.img + a.img;
    return res;
}

complex mult_complex(complex a, complex b) {
    complex res;
    res.real = a.real * b.real - a.img * b.img;
    res.img = a.real * b.img + b.real * a.img;
    return res;
}

complex mandel_recurrence(complex c, int n, complex z[]) {
    if (n == 0) {
        complex res;
        res.img = 0;
        res.real = 0;
        return res; 
    }
    complex previous_mandel_recurrence = mandel_recurrence(c, n - 1, z);
    z[n - 1] = previous_mandel_recurrence;
    return (add_complex(mult_complex(previous_mandel_recurrence, previous_mandel_recurrence), c));
}

void mandel(complex c, int n, complex z[]) {
    complex res = mandel_recurrence(c, n, z);
    complex res2;
    add_complex(res, res2);
    return;
}


int main() {
    complex c = { 1, 1 };
    const int n = 3;
    complex z[n];
    mandel(c, n, z);
    print(z, n);
    return 0;
}