//
//  main.cpp
//  ch6-basic-data-structure
//
//  Created by Wenzhen Zhu on 5/11/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//
/* STUDY GOAL
 + STACK QUEUE IMPLEMENTATION
 + DOUBLY LINKEDLIST
 + COMPARISION TEST
 + RANDOM NUMBER GENERATION
 + BINARY TREE ARRAY IMPLEMENTATION
 + DYNAMIC MEMORY ALLOCATION AND RELEASE
 + BINARY TREE'S LINKEDLIST REPRESENTATION
 + IN-ORDER, BACK-ORDER, TRAVERSAL
 + DFS AND NUM OF COMPONENT
 + BFS AND SHORTEST PATH
 + TOPOLOGICAL SORTING
 + EULER BACKTRACK
 */

#include <iostream>

using namespace std;
// --------------------  --------------------
// -------------------- 6.1 QUEUE --------------------
// EXAMPLE 6.1.1 CARD GAME
// Everytime get two card, throw 1st, put 2nd in the bottom.
#include <queue>
void cardGame() {
    int n;
    scanf("%d", &n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
}
// -------------------- 6.2 LinkedList --------------------
// EXAMPLE 6.1 MOVING BALL
// Given some balls, labeled as 1, 2, 3, ..., n
// You can do 2 operations:
//      A X Y: move X to left of Y
//      B X Y: move X to right of Y
// INPUT: num of balls: n; numb of operations: m
// 6 2
// A 1 4
// B 3 5
// OUTPUT:
// 2 1 4 5 3 6
int find (int arr[], int target) {
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void moveBall1 () {
    int n, m;
    scanf("%d %d", &n, &m);
    int A[n];
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }
    char type;
    int X, Y, p, q;
    for (int i = 0; i < m; i++) {
        scanf("%s%d%d", type, &X, &Y);
        p = find(A, X);
        q = find(A, Y);
    }
}

// -------------------- 6.3 BINARY TREE --------------------
#include "string.h"
const int MAXD = 20;
int s[1<<MAXD];
void fallingBall() {
    int D, I;
    while (scanf("%d%d", &D, &I) == 2) {
        memset(s, 0, sizeof(s));
        int k, n = (1 << D) - 1;
        for (int i = 0; i < I; i++) {
            k = 1;
            for(;;) {
                s[k] = !s[k];
                k = s[k] ? k * 2: k * 2 + 1;
                if (k > n) break;
            }
        }
        cout << k/2 << endl;
    }
}


int main(int argc, const char * argv[]) {
    cardGame();
}
