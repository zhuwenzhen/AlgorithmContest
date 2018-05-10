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
    int i, m = 1;
    for (i = 1; i <= n; i++) {
        m *= i;
    }
    return m;
}
int combinatorics(int m, int n) {
    return f(n)/(f(m) * f(n - m));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << combinatorics(2, 1) << endl;
    return 0;
}
