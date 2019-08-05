//
//  main.cpp
//  josephus_problem
//
//  Created by Bryan Morfe on 8/4/19.
//  Copyright © 2019 Bryan Morfe. All rights reserved.
//

#include <iostream>
#include <vector>

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

struct TestCase
{
    TestCase(int c, int e): computed(c), expected(e) {}
    int computed;
    int expected;
};

class Test
{
public:
    Test(const vector<TestCase> &testCases) : tests(testCases) {}
    void runEqualTests()
    {
        for (int i = 0; i < tests.size(); i++)
        {
            cout << "Running test " << i + 1 << "  ...";
            
            if (tests[i].computed != tests[i].expected)
                cout << "  Failed." << endl;
            else
                cout << "  Passed." << endl;
        }
    }
    
private:
    vector<TestCase> tests;
};

int main() {
    
    // Run tests
    Test test({
        //       ---------- COMPUTED -----------     --- EXPECTED ---
        TestCase(Solution::josephusRecursive(5),            3),
        TestCase(Solution::josephusRecursive(6),            5),
        TestCase(Solution::josephusRecursive(10),           5),
        TestCase(Solution::josephusRecursive(16),           1),
        TestCase(Solution::josephusRecursive(40),          17)
    });
    
    test.runEqualTests();
    
    return 0;
}
