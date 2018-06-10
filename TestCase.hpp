#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class TestCase {
    
    string caseName;
    int passed, failed, total;
    ostream& os;

    public:
    
    TestCase(string name, ostream& os) : passed(0), failed(0), total(0), caseName(name), os(os){}

    template <typename T> TestCase& check_equal(const T t1, const T t2){
        total++;
        if(t1 == t2) passed++;
        else {
            os << caseName << ": " << "Failure in test #" << total << ": " << t1 << " should be equal to " << t2 << "!" << endl;
            failed++; 
        }
        return *this;
    }
    
    template <typename T> TestCase& check_different(const T t1, const T t2){
        total++;
        if(t1 != t2) passed++;
        else {
            os << caseName << ": " << "Failure in test #" << total << ": " << t1 << " should be different from " << t2 << "!" << endl;
            failed++; 
        }
        return *this;
    }

    template <typename T> TestCase& check_output(const T t1, const string t2){
        total++;
        stringstream strT1;
        strT1 << t1;
        if(strT1.str() == t2) passed++;
        else{
            os << caseName << ": " << "Failure in test #" << total << ": " << "string value should be " << t2 << " but is " << strT1.str() << endl;    
            failed++; 
        }
        return *this;
    }
    
    template <typename T, typename Function> TestCase& check_function(const Function fun, const T t1, const int t2){
        total++;
        if((*fun)(t1) == t2) passed++;
        else {
           os << caseName << ": " << "Failure in test #" << total << ": " << "Function should return " << t2 << " but returned " << (*fun)(t1) << "!" << endl; 
           failed++; 
        }
        return *this;
    }

    void print(){
        os << caseName << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl; 
    }

};