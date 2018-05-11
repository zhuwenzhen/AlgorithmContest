//
//  main.cpp
//  ch5_basic_problems
//
//  Created by Wenzhen Zhu on 5/10/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//

/*  STUDY GOAL
 + USE CONSTANT TABLE TO SIMPLIFY CODE
 + USE STATE VARIABLE TO HELP STRING TO BE READ IN
 + USE STRUCT TO DEFINE HIGH PRECISION INTEGER
 + DEFINE OPERATORS FOR STRUCT
 + MASTER BUBBLE-SORT AND INTERSION-SORT
 + USE QSORT LIBRARY TO SORT INTEGER AND STRINGS
 + PRIME NUMBER DECOMPOSITION
 + TRIANGLE AREA
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

// EXAMPLE 5.1.1 WERTYU
void fixSentence() {
    char const *s = "`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./";
    int c;
    while ((c = getchar()) != EOF) {
        for (int i = 1; s[i] && s[i] != c; i++) {
            if (s[i]) putchar(s[i-1]);
            else putchar(c);
        }
    }
}

// EXAMPLE 5.1.2 LATEX
void latex() {
    int c, q = 1;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", q ? "``" : "''");
            q = !q;
        } else {
            printf("%c", c);
        }
    }
}

// EXAMPLE 5.1.3 PERIODIC STRING
void periodicString() {
    char word[100];
    scanf("%s", word);
    int len = (int) strlen(word);
    for (int i = 1; i <= len; i++) {
        bool ok = 1;
        for (int j = i; j < len; j++) {
            if (word[j] != word[j % i]) {
                ok = 0;
                break;
            }
        }
        if (ok)  {
            cout << i << endl;
            break;
        }
    }
}

// -------------------- 5.3 SORT & SEARCH --------------------
// EXAMPLE 5.3.1: 6174
// step1: get next number
int get_next(int x) {
    int a, b;
    
    char s[10];
    // convert x to string
    sprintf(s, "%d", x);
    size_t n = strlen(s);
    
    // bubble sort (ascending order)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    sscanf(s, "%d", &b);
    
    // Reverse string (so ascending order becomes descending order)
    for (int i = 0; i < n/2; i++) {
        char t = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = t;
    }
    sscanf(s, "%d", &a);
    return a - b;
}
// step2: enumerate next number and check if it's exists before.
void playfulNumber() {
    int num[1000];
    scanf("%d", &num[0]);
    int count = 1;
    cout << num[0];
    for (;;) {
        // generate and print next number
        num[count] = get_next(num[count - 1]);
        cout << " -> " << num[count];
        // find the new number in array num
        bool found = 0;
        for (int i = 0; i < count; i++) {
            if (num[i] == num[count]) {
                found = 1;
                break;
            }
        }
        if (found) break;
        count ++;
    }
    cout << endl;
}

// EXAMPLE: 5.3.2: Reordering letters
// COMPARE CHAR
int compare_char (const void* _a, const void* _b) {
    char* a = (char*) _a;
    char* b = (char*) _b;
    return *a - *b;
}
int compare_string (const void* _a, const void* _b) {
    char* a = (char*) _a;
    char* b = (char*) _b;
    return strcmp(a, b);
}
void reorderingLetters() {
    int n = 0;
    char word[1000][10], sorted[1000][10];
//    FILE *fin, *fout;
//    fin = fopen("letter-reordering.in", "rb");
//    fout = fopen("letter-reordering.out", "wb");
    
    for (;;) {
        scanf("%s", word[n]);
        if (word[n][0] == '*') break;   // break loop when we see the terminator sign
        n++;
    }
    
    qsort(word, n, sizeof(word[0]), compare_string);    // sort all the words
    for (int i = 0; i < n; i++) {
        strcpy(sorted[i], word[i]); // copy word to sorted array
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), compare_char); // sort each word
    }

    char s[10];
    while(scanf("%s", s) == 1) { // keep reading until end
        qsort(s, strlen(s), sizeof(char), compare_char); // sort the input words
        bool found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp (sorted[i], s) == 0) { // compare readin word s with sorted dictotionary
                found = 1;
                cout << word[i] << " ";
            }
        }
        if (!found) cout << ":(";
        cout << endl;
    }
}
// -------------------- 5.4 Math --------------------
// EXAMPLE 5.4.1: CANTOR TABLE
// 1/1      1/2     1/3     1/4     1/5
// 2/1      2/2     2/3     2/4
// 3/1      3/2     3/3
// 4/1      4/2
// 5/1
// INPUT: n
// OUTPUT: n-th number in cantor table
void cantor(int n) {
    int k = 1, s = 0;
    for (;;) {
        s += k;
        if (s >= n) {
            cout << (s - n + 1) << "/" << (k - s + n) << endl;
            break;
        }
        k++;
    }
}

void test_cantor() {
    int test [4] = {3, 14, 7, 12345};
    for (int i = 0; i < 4; i++) {
        cantor(test[i]);
    }
}

// EXAMPLE 5.4.3: TREES IN GARDEN
// For each point, we check if it's inside of triangle
typedef struct {double x, y;} Point;
typedef struct {Point a, b, c;} Triangle;

#define EPS 1e-9
int orientation (Point p0, Point p1, Point p2) {
    double val = (p1.y - p0.y) * (p2.x - p1.x) - (p1.x - p0.x) * (p2.y - p1.y);
    if (val <= 1e-9) return 0;  // colinear
    return (val > 0)? 1: 2;  // clock or counterclock wise
}

void printPoint (Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}
void swap (int *a, int* b) {
    int t = *a; *a = *b; *b = t;
}
double area (Point p0, Point p1, Point p2) {
    if (orientation(p0, p1, p2) == 1) {
        Point t = p0;
        p0 = p1;
        p1 = t;
    }
    return p0.x*p1.y + p2.x*p0.y + p1.x*p2.y - p2.x*p1.y-p0.x*p2.y -p1.x*p0.y;
}
// Given triangle ABC, and pt O
// O is in ABC <=> S_ABC = S_OAB + S_OBC + S_OCA
// a == b => fabs(a-b) < eps = 1e-9
bool tree_in_triangle(Point O, Triangle ABC) {
    double S_ABC = area(ABC.a, ABC.b, ABC.c);
    double S_OAB = area(O, ABC.a, ABC.b);
    double S_OBC = area(O, ABC.b, ABC.c);
    double S_OCA = area(O, ABC.c, ABC.a);
    //cout << S_ABC << " " << S_OAB << " " << S_OBC << " " << S_OCA << endl;
    return (fabs(S_ABC - S_OAB - S_OBC - S_OCA) < EPS) ? true : false;
}

void treesInGarden(){
    Triangle triangle = Triangle {Point{1.5, 1.5}, Point{1.5, 6.8}, Point{6.8, 1.5}};
    Triangle triangle2 = Triangle {Point{10.7, 6.9}, Point{8.5, 1.5}, Point{14.5, 1.5}};
    vector<Triangle> triangleList = {triangle, triangle2};
    int m = 15, n = 15;
    int count = 0;
    cout << area(triangle.a, triangle.b, triangle.c) << endl;
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            Point O = Point{1.0 * i, 1.0 * j};
            if (tree_in_triangle(O, triangle2)) {
                printPoint(O);
                count ++;
            }
        }
    }
    cout << "There are " << count << " trees in garden" << endl;
}

// Practice

int main(int argc, const char * argv[]) {
    // fixSentence();
    // playfulNumber();
    // reorderingLetters();
    // test_cantor();
    treesInGarden();
    return 0;
}
