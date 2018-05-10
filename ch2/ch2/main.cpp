//
//  main.cpp
//  ch2
//
//  Created by Wenzhen Zhu on 5/9/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//

/*
 * Study Goal:
 + for loop
 + while loop
 + counter
 + fopen
 */

#include <iostream>
#include <math.h>

using namespace std;

// Example 2-1: AABB
// output all 4-digit square integer with form of AABB
void aabb() {
    int n;
    double m;
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            n = a * 1100 + b * 11;
            m = sqrt(n);
            cout << n << " ";
            // if (floor(m + 0.5) == m) cout << n << " ";
        }
    }
    cout << endl;
}

// Example 2-2: 3n+1
void count3nPlus1() {
    int n, count = 0;
    scanf("%d", &n);
    while (n > 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        count ++;
    }
    printf("%d\n", count);
}

// Example 2-3: Sum of factorial
void sumOfFactorial() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        sum += factorial;
    }
    printf("%d\n", sum % int(1e6));
}

void sumOfFactorial2() {
    const int MOD = 1e6;
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        int factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial = (factorial * j) % MOD;
        }
        sum = (sum + factorial) % MOD;
    }
    printf("%d\n", sum);
    printf("TIme used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
}

// Example 2-4: Data Statistics
// Given some integers n_i, find min, max, avg. n_i < 1000
// num of intergers is unknown
#define INF 1e9;
void dataStats() {
    int x, n = 0;
    int min = INF;
    int max = -INF;
    double avg = 0;
    while (scanf("%d", &x) == 1) {
        avg += x;
        if (x < min) min = x;
        if (x > max) max = x;
        n++;
    }
    avg = avg / n;
    cout <<"min = " << min << ", max = " << max << ", avg = " << avg << endl;
}

#define LOCAL
void dataStatsFile() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int x, n = 0;
    int min = INF; int max = -INF; int sum = 0;
    while(scanf("%d", &x) == 1) {
        sum += x;
        if (x < min) min = x;
        if (x > max) max = x;
        n++;
    }
    printf("%d %d %.3lf\n", min, max, (double) sum/n);
}

void dataStatsFile2() {
    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    
    int x, n = 0;
    int min = INF; int max = -INF; int sum = 0;
    while(fscanf(fin, "%d", &x) == 1) {
        sum += x;
        if (x < min) min = x;
        if (x > max) max = x;
        n++;
    }
    fprintf(fout, "%d %d %.3lf\n", min, max, (double) sum/n);
    fclose(fin);
    fclose(fout);
}

// C++ INPUT AND OUTPUT
#include <fstream>
ifstream fin("data.in");
ofstream fout("data.out");
int readAndWrite() {
    int a , b;
    while(fin >> a >> b) {
        fout << a + b << "\n";
    }
    return 0;
}

// 2.4.1 OUTPUT TRICK
// If you need to output 2, 4, 6, 8, ..., 2n, can you do it by modifying the following program little bit
void outputTrick() {
    int n;
    scanf("%d", &n);
    // 2 ways
    for (int i = 2; i <= 2*n; i+=2) {
        cout << i << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << 2 * i << endl;
    }
}

// 2.4.2 Floating Number Trap
void floatingNumberTrap() {
    for (double i = 0; i - 10 < 0.01; i+= 0.1) {
        cout << i << endl;
    }
    // This loops forever
}

/* PRACTICE */
void digit() {
    int n;
    int k = 0;
    scanf("%d", &n);
    int num = n;
    
    while (n / 10 >= 1) {
        n /= 10;
        k++;
    }
    cout << num <<" has " << k+1 << " digits" << endl;
}

void daffodil() {
    for (int i = 100; i <= 999; i++) {
        int d1 = i / 100;
        int d10 = i / 10 % 10;
        int d100 = i % 10;
        
        if (i == (int)pow(d1, 3) + (int)pow(d10, 3) + (int)pow(d100,3)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void harmony() {
    int n;
    double h = 0.;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        h += 1./i;
    }
    cout << h << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    harmony();
    return 0;
}

