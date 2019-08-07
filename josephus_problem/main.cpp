//
//  main.cpp
//  josephus_problem
//
//  Created by Bryan Morfe on 8/4/19.
//  Copyright © 2019 Bryan Morfe. All rights reserved.
//

#include <iostream>
#include "utest/utest.h"
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    
    // Full recursive solution
    // O(log n)
    static int josephusRecursive(int n)
    {
        if (n == 1)     // Base condition
            return 1;
        
        if (n % 2 == 0) // Even numbers
            return 2 * josephusRecursive(n / 2) - 1;
        else            // Odd numbers
            return 2 * josephusRecursive(n / 2) + 1;
    }
    
};

int main() {
    
    utest::Tester<int> tester;
    queue<utest::TestCase<int>> tests;
    
    // Add tests
    //                              Computed                           Expected     Test Type
    tests.push(utest::TestCase<int>(Solution::josephusRecursive(5),    3,           utest::testEQ));
    tests.push(utest::TestCase<int>(Solution::josephusRecursive(6),    5,           utest::testEQ));
    tests.push(utest::TestCase<int>(Solution::josephusRecursive(10),   5,           utest::testEQ));
    tests.push(utest::TestCase<int>(Solution::josephusRecursive(16),   1,           utest::testEQ));
    tests.push(utest::TestCase<int>(Solution::josephusRecursive(40),   17,          utest::testEQ));
    
    tester.addTest("JosephusRecursiveTests", tests);
    tester.runTests();
    
    return 0;
}
