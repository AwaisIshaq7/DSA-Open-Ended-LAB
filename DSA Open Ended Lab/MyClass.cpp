#include "MyClass.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Node constructor
Node::Node(float c, int d) : coeff(c), degree(d), next(nullptr), prev(nullptr) {}

// MyClass constructor
MyClass::MyClass() : head(nullptr), tail(nullptr) {}

void MyClass::insertTerm(float coeff, int degree) {
    Node* newNode = new Node(coeff, degree);
    if (!head) {
        head = tail = newNode;
    }
    else if (head->degree > degree) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next && curr->next->degree < degree) {
            curr = curr->next;
        }
        if (curr->degree == degree) {
            curr->coeff += coeff;
            if (curr->coeff == 0) removeTerm(degree);
            delete newNode;
        }
        else {
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next) curr->next->prev = newNode;
            else tail = newNode;
            curr->next = newNode;
        }
    }
}

void MyClass::removeTerm(int degree) {
    Node* curr = head;
    while (curr && curr->degree != degree) curr = curr->next;
    if (!curr) return;
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    else tail = curr->prev;
    delete curr;
}

void MyClass::readFromFile(const string& filename) 
{
    ifstream file(filename);
    if (!file) 
    {
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }
    float coeff;
    int degree;
    while (file >> coeff >> degree) 
    {
        insertTerm(coeff, degree);
    }
    file.close();
}

// Add two polynomials
MyClass MyClass::add(const MyClass& other) const
{
    MyClass result;
    Node* p1 = head;
    Node* p2 = other.head;
    while (p1 || p2) {
        if (!p2 || (p1 && p1->degree < p2->degree)) 
        {
            result.insertTerm(p1->coeff, p1->degree);
            p1 = p1->next;
        }
        else if (!p1 || (p2 && p2->degree < p1->degree))
        {
            result.insertTerm(p2->coeff, p2->degree);
            p2 = p2->next;
        }
        else {
            result.insertTerm(p1->coeff + p2->coeff, p1->degree);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return result;
}

MyClass MyClass::multiply(const MyClass& other) const
{
    MyClass result;
    for (Node* p1 = head; p1; p1 = p1->next) {
        for (Node* p2 = other.head; p2; p2 = p2->next)
        {
            result.insertTerm(p1->coeff * p2->coeff, p1->degree + p2->degree);
        }
    }
    return result;
}

// Evaluate polynomial at a given point
float MyClass::evaluate(float x) const
{
    float result = 0;
    for (Node* curr = head; curr; curr = curr->next) {
        result += curr->coeff * pow(x, curr->degree);
    }
    return result;
}

void MyClass::print() const {
    if (!head) {
        cout << " 0 " << endl;
        return;
    }
    Node* curr = head;
    while (curr) {
        if (curr->coeff >= 0 && curr != head) cout << " + ";
        cout << curr->coeff << "x^" << curr->degree;
        curr = curr->next;
    }
    cout << endl;
}

MyClass::~MyClass() 
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
