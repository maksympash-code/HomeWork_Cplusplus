#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << *(a + i) << " ";
    // }
    // cout << endl;
}

void input(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void dynamic_array_c() {
    int n;
    cin >> n;
    int* a;
    // a = (int*)malloc(n*sizeof(*a));
    a = (int*)calloc(n,sizeof(*a));

    if (a == NULL) {
        exit(1);
    }

    print(a, n);
    //input.txt(a, n);
    //print(a, n);


    int* b = (int*)realloc(a, (n+30)*sizeof(*a));
    cout << a << ' ';
    cout << b << ' ';
    free(b);
}

void dynamic_array_cpp() {
    int n;
    cin >> n;

    int* a = new int[n];
    int* x = new int(10);

    input(a, n);
    print(a, n);
    cout << *x << endl;

    delete[] a;
    delete x;
}

void exercize_1() {
    int n, sum = 0;
    cin >> n;

    float *a = new float[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
        sum += a[i];
    }

    cout << sum << endl;
}

int input(int** a) {
    *a = (int *)malloc(0 * sizeof(**a));
    int n = 0;
    while (n < 100) {
        int x;
        scanf("%d", &x);
        if (x == 0)
            break;
        *a = (int *) realloc(*a, (n+1) * sizeof(**a));
        if (*a == NULL) {
            exit(1);
        }
        (*a)[n++] = x;
    }
    return n;
}

// int main() {
//     int* a ;
//     int n = input.txt(&a);
//
//     print(a, n);
//
//     free(a);
//     return 0;
// }