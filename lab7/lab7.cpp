#include <iostream>
#include <iomanip>

using namespace std;

double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
    return (drivenMiles / milesPerGallon) * dollarsPerGallon;
}

int getInput() {
    int cents;
    
    cout << "Enter the change (in cents): ";
    cin >> cents;

    return cents;
}

int computeCoins(int coinValue, int &ammount) {
    int x = ammount / coinValue;
    ammount %= coinValue;
    return x;
}

void displayChange(int halfDollars, int quaters, int dimes, int nickles, int pennies) {
    cout << endl << "\tHalf Dollar(s): " << halfDollars << endl;
    cout << "\tQuater(s): " << quaters << endl;
    cout << "\tDime(s): " << dimes << endl;
    cout << "\tNickle(s): " << nickles << endl;
    cout << "\tPennie(s): " << pennies << endl;
}

int main() {
    
    cout << "Miles Driven\tCost" << endl;

    double drivenMiles = DrivingCost(10.0, 20.0, 3.1599);
    cout << setw(5) << "10 " << setw(15) << fixed << setprecision(4) << drivenMiles << endl;
    drivenMiles = DrivingCost(50.0, 20.0, 3.1599);
    cout << setw(5) << "50 " << setw(15) << fixed << setprecision(4) << drivenMiles << endl;
    drivenMiles = DrivingCost(400.0, 20.0, 3.1599);
    cout << setw(5) << "400 " << setw(15) << fixed << setprecision(4) << drivenMiles << endl << endl;
    
    int change = getInput();

    int nHalfDollars = computeCoins(50, change);
    int nQuaters = computeCoins(25, change);
    int nDimes = computeCoins(10, change);
    int nNickles = computeCoins(5, change);

    displayChange(nHalfDollars, nQuaters, nDimes, nNickles, change);
    return 0;
}