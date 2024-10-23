#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    float coeff;  // Coefficient of the term
    int degree;   // Degree of the term
    Node* next;  
    Node* prev;  

    Node(float c, int d);
};

class MyClass
 {
private:
    Node* head;
    Node* tail;

public:
    MyClass();

    void insertTerm(float coeff, int degree);       //TO insert a new item to the polynomial expression file
    void removeTerm(int degree);                   //To remove it
    void readFromFile(const string& filename);
    MyClass add(const MyClass& other) const; 
    MyClass multiply(const MyClass& other) const;
    float evaluate(float x) const;
    void print() const;

    ~MyClass();
};



#endif
