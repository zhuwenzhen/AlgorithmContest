//
//  main.cpp
//  ch3_array_string
//
//  Created by Wenzhen Zhu on 5/9/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//

/*  STUDY GOAL
 + 1D ARRAY
 + 2D ARRAY
 + STRING DECLARE, ASSIGN, COMPARE, CONCATENATE
 + ASCII, CTYPE.H
 + OPERATORS ++, +=
 + FGETC, GETCHAR
 + PREPROCESS
 */

#include <iostream>
#include <string.h>
using namespace std;

// Example 3-1: Light
// n lights: 1, 2, ..., n
// 1st person turn all of them on
// 2nd person turn off 2i, i = 1, ...
// Given n lights, k persons

void light() {
    #define MAXN 1000+10 // safer
    int a[MAXN];
    int n, k;
    scanf("%d%d", &n, &k);
    memset(a, 0, sizeof(a));    // clear array a.
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % i == 0) a[j] = !a[j];   // turn off lights
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Example 3-2: Snake shape matrix
// Make matrix like a snake
void snakeMatrix() {
    int x = 0, y = 0, tot = 0;
    int n;
    scanf("%d", &n);
    int a[10][10];
    memset(a, 0, sizeof(a));
    tot = a[x = 0][y = n-1] = 1;

    while (tot < n * n) {
        while (x + 1 <  n && !a[x+1][y]) a[++x][y] = ++tot;      // go down
        while (y - 1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;      // go left
        while (x - 1 >= 0 && !a[x-1][y]) a[--x][y] = ++tot;      // go up
        while (y + 1 <  n && !a[x][y+1]) a[x][++y] = ++tot;      // go right
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}




int main(int argc, const char * argv[]) {
    // light();
    snakeMatrix();
    return 0;
}
