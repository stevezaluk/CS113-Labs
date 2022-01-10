#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;

void menu() {
    cout << endl << "1 - Using base & height" << endl;
    cout << "2 - Using 3 sides (Heron's Formula)" << endl;
    cout << "3 - Using 2 sides and include angle (SAS)" << endl;
    cout << "X - Exit" << endl;
}

double degrees_to_rad(double degrees) {
    return (degrees * M_PI) / 180;
}

double area_of_triangle(double base, double height) {
    if ((base < 0 || height < 0)) {
        cout << "! Sides cannot be negative" << endl;
        return 0;
    }
    return (base * height) * 1 / 2;
}

double area_herons_formula(double side1, double side2, double side3) {
    if ((side1 < 0 || side2 < 0 || side3 < 0)) {
        cout << "! Sides cannot be negative" << endl;
        return 0;
    }

    if(side1 + side2 <= side3) {
        cout << "! Sum of two sides cannot be greater than or equal to the other two sides" << endl;
        return 0;
    } else if(side2 + side3 <= side1) {
        cout << "! Sum of two sides cannot be greater than or equal to the other two sides" << endl;
        return 0;
    } else if(side1 + side3 <= side2) {
        cout << "! Sum of two sides cannot be greater than or equal to the other two sides" << endl;
        return 0;
    }

    double perimiter = side1 + side2 + side3;
    double semi_perimiter = perimiter / 2;

    double calc = (semi_perimiter * (semi_perimiter - side1) * (semi_perimiter - side2) * (semi_perimiter - side3));

    return sqrt(calc);
}

double area_of_triangle(double side1, double side2, double degrees) { // doesnt work
    if(degrees >= 180) {
        cout << "! Degrees must be smaller than 180 degrees" << endl;
        return 0;
    }

    if ((side1 < 0 || side2 < 0)) {
        cout << "! Sides cannot be negative" << endl;
        return 0;
    }

    return (0.5 * side2 * side1) * sin(degrees_to_rad(degrees));
}

void loop() {
    bool sentinel = true;
    char input;
    double ret = 0;

    double side1 = 0;
    double side2 = 0;
    double side3 = 0;
    
    while(sentinel) {
        menu();
        cout << "Enter choice: ";
        cin >> input;
        switch(input) {
            case '1':
            case 1:
                double base;
                double height;
                
                cout << endl << "Enter base: ";
                cin >> base;
                cout << "Enter height: ";
                cin >> height;

                ret = area_of_triangle(base, height);
                if(ret != 0) {
                    cout << endl << "Area of Triangle: " << fixed << setprecision(2) << ret << endl;
                }
                break;

            case '2':
            case 2:
                cout << "Side 1: ";
                cin >> side1;
                cout << "Side 2: ";
                cin >> side2;
                cout << "Side 3: "; 
                cin >> side3;

                ret = area_herons_formula(side1, side2, side3);
                if(ret != 0) {
                    cout << endl << "Area of Triangle: " << fixed << setprecision(2) << ret << endl;
                }
                break;
            
            case '3':
            case 3:
                double degrees;

                cout << "Side 1: ";
                cin >> side1;

                cout << "Side 2: ";
                cin >> side2;

                cout << "Angle: ";
                cin >> degrees;

                ret = area_of_triangle(side1, side2, degrees);
                if(ret != 0) {
                    cout << endl << "Area of Triangle: " << fixed << setprecision(2) << ret << endl;
                }
                break;
            
            case 'x':
            case 'X':
                sentinel = false;
                break;
        }
    }
}

int main() {
    loop();
    return 0;
}