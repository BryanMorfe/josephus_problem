#ifndef UTEST_H
#define UTEST_H

#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
#include <string>

using namespace std;

namespace utest
{
    template <typename T>
    class TestCase;
    
    template <typename T>
    class Tester;
    
    enum TestType
    {
        testEQ,
        testNEQ,
        testLT,
        testGT,
        testLE,
        testGE
    };
    
}



template <typename T>
struct utest::TestCase
{
    T computed;
    T expected;
    TestType testType;

    TestCase(const T &c, const T &e, const TestType type): computed(c), expected(e), testType(type) {}
    TestCase(const TestCase<T> &t): computed(t.computed), expected(t.expected), testType(t.testType) {}
};

template <typename T>
class utest::Tester
{
    map<string, queue<TestCase<T>>> tests;
public:
    void addTest(const string &name, const queue<TestCase<T>> &q);
    void runTests();
};

template <typename T>
void utest::Tester<T>::addTest(const string &name, const queue<TestCase<T>> &q)
{
    tests[name] = q;
}

template <typename T>
void utest::Tester<T>::runTests()
{
    
    typename map<string, queue<TestCase<T>>>::iterator it;
    
    for (it = tests.begin(); it != tests.end(); ++it)
    {
        cout << "Running tests for " << it->first << endl;
        cout << left << setw(20) << "---" << "Status" << endl;
        int testNum = 1;
        while (it->second.size() > 0)
        {
            TestCase<T> test(it->second.front());
            cout << "Running test " << left << setw(7) << testNum;
            bool passed;
            switch (test.testType)
            {
                case testEQ:
                    passed = test.computed == test.expected;
                case testNEQ:
                    passed = test.computed != test.expected;
                case testLT:
                    passed = test.computed < test.expected;
                case testGT:
                    passed = test.computed > test.expected;
                case testLE:
                    passed = test.computed <= test.expected;
                case testGE:
                    passed = test.computed >= test.expected;
            }
            cout << (passed ? "Passed" : "Failed") << endl;
            it->second.pop();
            testNum++;
        }
        cout << endl;
    }
}

#endif /* UTEST_H */
