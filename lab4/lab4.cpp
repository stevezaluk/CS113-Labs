#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double gratuity = 0.18;
    const double room_tax = 0.065;
    const double beef_meal = 15.95;
    const double vegan_meal = 10.95;
    
    int beef_count; // number of beef meals
    int vegan_count; // number of vegan meals

    double grand_total;
    double room_cost;

    double total_gratuity = 0;

    int number_in_party;

    cout << "Enter the number of Beef Meals: ";
    cin >> beef_count;

    cout << "Enter the number of Vegan Meals: ";
    cin >> vegan_count;

    number_in_party = beef_count + vegan_count;
    cout << endl << "Number in party: " << setw(7) << number_in_party << endl;

    if(number_in_party <= 50 && number_in_party != 0) {
        room_cost = 75;
    } else if(number_in_party > 50 && number_in_party <= 100) {
        room_cost = 150;
    } else if(number_in_party == 0) {
        room_cost = 0;
        cout << "Cant rent a room for zero people" << endl;
        exit(1);
    } else {
        room_cost = 250;
    }

    cout << "Room Cost: " << fixed << setprecision(2) << setw(7) << "$ " << room_cost << endl;
    double total_room_tax = room_cost * room_tax;
    cout << "Room Tax: " << fixed << setprecision(2) << setw(7) << "$ " << total_room_tax << endl;

    grand_total += room_cost + total_room_tax;

    if(beef_count > 0 ) {
        double total_beef_price = beef_count * beef_meal;
        grand_total += total_beef_price;
        cout << "Beef Meals: " << setw(7) << beef_count << setw(7) << "$ " << fixed << setprecision(2) << total_beef_price << endl;
        total_gratuity += total_beef_price * 0.18;
    }

    if(vegan_count > 0) {
        double total_vegan_price = vegan_count * vegan_meal;
        cout << "Vegan Meals: " << setw(7) << vegan_count << "$ " << setw(7) << fixed << setprecision(2) << total_vegan_price << endl;
        grand_total += total_vegan_price;
        total_gratuity += total_vegan_price * 0.18;
    }

    grand_total += total_gratuity;
    cout << "Gratuity: " << setw(7) << "$ " << fixed << setprecision(2) << total_gratuity << endl;

    cout << "Total: " << setw(7) << "$ " << fixed << setprecision(2) << grand_total << endl;
    
    return 0;
}