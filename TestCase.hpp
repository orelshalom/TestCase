#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
using namespace std;


class TestCase {
    
    string caseName;
    int passed, failed, total;

    public:
    
    TestCase(string name, ostream& os) : passed(0), failed(0), total(0), caseName(name){}

    template <typename T> bool check_equal(T a, T b){}
    
    template <typename T> bool check_different(T a, T b){}

    template <typename T> bool check_output(T a, T b){}
    
    template <typename T, typename Function> bool check_function(Function f, T a, T b){}

    template <typename T> void print(){}

};