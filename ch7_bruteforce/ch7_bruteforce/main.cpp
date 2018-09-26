//
//  main.cpp
//  ch7_bruteforce
//
//  Created by Wenzhen Zhu on 5/16/18.
//  Copyright © 2018 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

/* STUDY GOAL
 + UNDERSTAND INTEGER, STRING SIMPLE OBJECT'S ENUMERATION METHOD
 + FAMILIAR WITH RECURSIVE WAY TO GENERATE COMBINATIONS
 + FAMILY WITH "NEXT COMBINATION" MEHTOD TO ENUMERATE PERMUTATION
 + UNDERSTAND ANSWER TREE AND ESTIMATE NODE NUMBER
 + TEMPLATE TO DO BACKTRACKING (ALSO UNDERSTAND WHY IT'S MORE EFFICIENT THAN GENERATE-TEST
 + BFS & DEPTH
 + WATER STATE GRAPH AND 8-QUEENS
 + HASH SET AND STL SET
 */
using namespace std;
// -------------------- 7.1 SIMPLE ENUMERATION --------------------
//
// 7.1.1 Division
// Given integer n, from small to large to output all expression as
// abcde/ fghij = n
// a-j is 0-9's permutation
// 2 <= n <= 79
// Example:
// input 62
// output: 79546 / 01283 = 62
// 94736 / 01528

// Enumerate fghij and then compute abcde, then check if all numbers are different
void division(int n) {
    string res = "";
    for (int i = 1234; i < 98765; i++ ) {
        int mult = i * n;
        string abcde = to_string(mult);
        string fghij = to_string(i);
        string all = abcde + fghij;
        if (all.compare("0123456789") != 0){
            continue;
        }else{
            cout << abcde << "/" << fghij << endl;
        }
    }
}

// -------------------- 7.2 ENUMRATE PERMUTATION --------------------
// 7.2.1 Generarte permutation(n)
void print_permutation(int *A, int cur, int n) {
    int i, j;
    if (cur == n) {
        for (i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    } else {
        for (i = 0; i < n; i++) {
            int ok = 1;
            for (j = 0; j < cur; j++) {
                if (A[j] == i) ok = 0;
            }
            if (ok) {
                A[cur] = i;
                print_permutation(A, cur+1, n);
            }
        }
    }
}

class Permutation {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > res;
        size_t n = nums.size();
        if (n == 0) {
            res.push_back(vector<int>());
            return res;
        }
        helper(res, nums, n - 1);
        return res;
    }
    void helper(vector<vector<int> > &res, vector<int> nums, int n){
        if(n == 0){
            res.push_back(nums);
        }
        for(int i = 0 ; i <= n; i++){
            swap(nums[i], nums[n]);
            helper(res, nums, n - 1);
            swap(nums[i], nums[n]);
        }
    }
};


int main(int argc, const char * argv[]) {
    int A[1000];
    print_permutation(A, 0, 4);
    return 0;
}
