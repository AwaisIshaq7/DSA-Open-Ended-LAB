#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>

#include "MyClass.h"

using namespace std;

int main() {
    MyClass p1;

    
    string file1 = "FILE1.txt";
    cout << "Reading polynomial from file1 : " << file1 << endl;
    p1.readFromFile(file1);
    cout << "\nThe Polynomial is: ";
    p1.print();

    int choice;
    do {

        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout << "\tMain Menu";
        cout << "\nChoose form one of the following option: ";
        cout << "\n1. ADD A polynomial\n";
        cout << "2. MULTIPLY polynomial\n";
        cout << "3. EVALUATE polynomial\n";
        cout << "4. To QUIT\n";
        cout << "Enter a choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            MyClass p2;
            string file2 = "FILE2.txt";
            cout << "\nReading polynomial to add from file 2 : " << file2 << endl;
            p2.readFromFile(file2);
            MyClass sum = p1.add(p2);
            cout << "The second polynomial is: ";
            p2.print();
            cout<< "\nThe sum of the two polynomials is: ";
            sum.print();
            break;
        }
        case 2:
        {
            MyClass p2;
            string file2 = "FILE2.txt";
            cout << "\nReading the  polynomial to multiply from file2 : " << file2 << endl;
            p2.readFromFile(file2);
            MyClass product = p1.multiply(p2);
            cout << "The second polynomial is: ";
            p2.print();
            cout << "\nThe Product is:  ";
            product.print();
            break;
        }
        case 3: 
        {
            float x;
            cout << "\nEnter the value of x for evaluation: ";
            cin >> x;
            cout << "Result:  " << p1.evaluate(x) << endl;
            break;
        }
        case 4:
           
        cout<<"\nNow exiting the program\n";
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Plz Try again.\n";
        }
        
    } while (choice != 4);

    return 0;
}
