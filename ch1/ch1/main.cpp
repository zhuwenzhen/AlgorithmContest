//
//  main.cpp
//  ch1
//
//  Created by Wenzhen Zhu on 5/9/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//

/*** Study Goal
 
 
 */

#include <iostream>
#include <math.h>

using namespace std;
// Example 1.1
void computeCylinderArea() {
    const double pi = 4.0 * atan(1.0); // use const to declare constant
    // place holder corresponds to variable's data type. Each variable need &
    double r, h, s1, s2, s;
    scanf("%lf%lf", &r, &h); // read in input
    s1 = pi * r * r;
    s2 = 2 * pi * r * h;
    s = s1 * 2.0 + s2;
    printf("area = %.5lf\n", s); // print output
}

// Example 1.2 Reverse 3 digit number
// input: 127, output: 721
void reverse3DigitNumber() {
    int n;
    scanf("%d", &n);
    int d100 = n / 100;
    int d10 = n / 10 % 10;
    int d1 = n % 10;
    
    printf("%d%d%d\n", d1, d10, d100);
}

// Example 1.3 Exchange (swap) Variable
void swapVariables() {
    int a, b, t;
    scanf("%d%d", &a, &b);
    t = a;
    a = b;
    b = t;
    printf("%d %d\n", a, b);
}

// Example 1.4 Chicken & Bunny
// Given n_chick + n_bunny = n, n_legs_total = m, find n_chicken and n_bunny
void chickAndBunny() {
    int chick, bunny, n, m;
    scanf("%d%d", &n, &m);
    // chick + bunny = n
    // 2 * chick + 4 * bunny = m
    bunny = (m - 2 * n) / 2;
    chick = n - bunny;
    if (m % 2 == 1 || chick < 0 || bunny < 0) {
        cout << "No answer\n";
    } else {
        printf("bunny = %d, chick = %d\n", bunny, chick);
    }
}

/*
 * PRACTICE
 */
void average() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    double average = (a + b + c) / 3;
    cout << "avg = " << average << endl;
}

void sum() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    for (int i = 1; i < n; i++) {
        cout << i << " + ";
    }
    cout << n;
    cout << " = " << sum << endl;
    cout << "1 + 2 + ... + " << n << " = " << sum << endl;
}

#define Pi 3.1415926
void sincos() {
    int n;
    scanf("%d", &n);
    if (n > 360 || n < 0) {
        cout << "input should be in (0, 360)" << endl;
        return;
    }
    double cos_val = cos(n * Pi / 180.);
    double sin_val = sin(n * Pi / 180.);
    cout << "cos = " << cos_val << ", sin = " << sin_val << endl;
}

int main(int argc, const char * argv[]) {
    sincos();
    return 0;
}
