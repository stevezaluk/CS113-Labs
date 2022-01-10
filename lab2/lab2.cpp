#include <iostream>
#include <iomanip>

using namespace std;

void part3() {
    double farenheight;

    cout << endl << "Enter the temperature in Fahrenheit: ";
    cin >> farenheight;

    double celcius = (farenheight - 32) * 5/9;

    cout << "\tThe temperature is " << fixed << setprecision(2) << celcius << " celcius" << endl;
}

void part2() {
    int cents;

    cout << "Enter the change (in cents): ";
    cin >> cents;

    int x = cents / 50;
    cents = cents % 50;

    cout << "\tHalf Dollars: " << x << endl;

    x = cents / 25;
    cents = cents % 25;

    cout << "\tQuaters: " << x << endl;

    x = cents / 10;
    cents = cents % 10;

    cout << "\tDimes: " << x << endl;

    x = cents / 5;
    cents = cents % 5;

    cout << "\tNickels: " << x << endl;
    cout << "\tPennies: " << cents << endl;
}

void part1() {
    cout << "Coin Calculator - Part 1" << endl << endl;
    
    int quaters;
    int dimes;
    int nickels;

    int total = 0;

    cout << "Enter the number of quaters: ";
    cin >> quaters;
    
    cout << "Enter the number of dimes: ";
    cin >> dimes;
    
    cout << "Enter the number of nickels: ";
    cin >> nickels;

    total += quaters * 25;
    total += dimes * 10;
    total += nickels * 5;

    cout << "\tTotal coins are worth " << total << " cents" << endl << endl;
}

int main() {
    
    part1();
    part2();
    part3();
    
    return 0;
}