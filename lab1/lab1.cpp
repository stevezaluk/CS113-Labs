#include <iostream>

using namespace std;

void face() {
    cout << "/\\   /\\\n";
    cout << "  o o \n";
    cout << " =   = \n";
    cout << "  --- \n";
}

void square() {
    int ret;
    cout << "Enter a number: ";
    cin >> ret;

    ret = ret * ret;
    cout << "The number sqaured = " << ret;
}

int main() {
    cout << "Hello World\n";
    face();
    square();
    return 0;
}
