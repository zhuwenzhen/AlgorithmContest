//
//  main.cpp
//  ch3_function_and_recursion
//
//  Created by Wenzhen Zhu on 5/9/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//
/*  STUDY GOAL
 + MULTI-PARAM MATH FUNCTION
 + USE TYPEDEF
 + USE ASSERT
 + UNDERSTAND STRUCT
 + UNDERSTAND DEFINE GLOBAL LOCAL VARIABLE
 + STACK
 + ADDRESS AND POINTER
 + UNDERSTAND RECURSION
 */
#include <iostream>
#include <math.h>

using namespace std;

// Use function with struct
//double dist (double x1, double y1, double x2, double y2) {
//    // return sqrt (pow(x1-x2,2) + pow(y1-y2, 2))
//    double dx = x1 - x2;
//    double dy = y1 - y2;
//    return hypot(dx, dy);
//}
//
//struct Point{
//    double x, y;
//};
//double distance (struct Point a, struct Point b) {
//    return hypot(a.x - b.x, a.y - b.y);
//}
//
//typedef struct {double x, y;} Point;
//double distance (Point a, Point b) {
//    return hypot(a.x - b.x, a.y - b.y);
//}

// Example 4-1: Combination Number
int f(int n) {
    if (n <= 1) return 1;
    int m = 1;
    for (int i = 1; i <= n; i++) {
        m *= i;
    }
    return m;
}
int combinatorics(int m, int n) {
    return f(n)/(f(m) * f(n - m));
}

// Example 4-2: Twin Prime Numbers
#define MAXN 1e5
int isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
void twinPrimeNumbers() {
    int m;
    scanf("%d", &m);
    for (int i = m - 2; i >= 3; i--) {
        if (isPrime(i) && isPrime(i+2)) {
            cout << i << " " << i + 2 << endl;
            break;
        }
    }
}

// Example 4-3: Swap by Pointers
void swap (int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}
void test_swap() {
    int a = 3, b = 4;
    swap(&a, &b);
    cout << a << " " << b << endl;
}

// recursion
int factorial (int n) {
    return n == 0 ? 1 : factorial(n-1)*n;
    // a ? b : c
    // if a is true: do b, else do c.
}

int main(int argc, const char * argv[]) {
    // cout << combinatorics(2, 10) << endl;
    // twinPrimeNumbers();
    test_swap();
    return 0;
}

