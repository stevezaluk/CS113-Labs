#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// sorry this was a day late

void printLetter(string name, string address, string townStateZip, double propertyValue) {
    string lastName = name.substr(name.find(' ') + 1);
    
    string street = address.substr(address.find(' ') + 1);
    string townName = townStateZip.substr(0, townStateZip.find(','));
    transform(townName.begin(), townName.end(), townName.begin(), ::toupper);

    cout << "Dear Mr/Mrs " << lastName << endl;
    cout << "Taxes for " << townName << " are due by the 15th of the month." << endl;
    cout << "Based on your property value of $" << fixed << setprecision(2) << propertyValue << ", your tax is $" << fixed << setprecision(2) << propertyValue * 0.04 << endl;
    cout << "Due to increased development on " << street << ", your taxes will increase next year to $" << fixed << setprecision(2) << propertyValue * 0.06 << endl;
}

int main() {
    string name;
    string address;
    string townStateZip;
    double propertyValue;
    
    cout << "Enter Name (First Last): ";
    getline(cin, name);

    cout << "Enter Street Address: ";
    getline(cin, address);
    
    cout << "Enter Town, State and Zip Code (Town, State ZIP): ";
    getline(cin, townStateZip);
    
    cout << "Enter Property Value: ";
    cin >> propertyValue;

    cout << endl;

    printLetter(name, address, townStateZip, propertyValue);
    return 0;
}
