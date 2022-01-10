#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int house_length;
    int house_width;

    int yard_length;
    int yard_width;

    cout << "Enter the length of the yard: ";
    cin >> yard_length;

    cout << "Enter the width of the yard: ";
    cin >> yard_width;

    cout << "Enter the length of the house: ";
    cin >> house_length;

    cout << "Enter the width of the house: ";
    cin >> house_width;

    int house_area = house_length * house_width;
    int yard_area = yard_length * yard_width;
    double grass_area =  yard_area - house_area;

    cout << endl << "Area of yard: " << yard_area;
    cout << endl << "Area of House: " << house_area;
    cout << endl << "Area of Grass: " << grass_area << endl;

    double time_to_cut_seconds = (grass_area / 7) / 60;

    cout << "Minutes to mow lawn: " << fixed << setprecision(2) << time_to_cut_seconds << endl;

    double initial_velocity;
    double initial_height;
    double seconds;

    cout << "\nEnter the initial velocity (feet/sec): ";
    cin >> initial_velocity;

    cout << "Enter the initial height (feet): ";
    cin >> initial_height;

    cout << "Enter seconds: ";
    cin >> seconds;

    cout << endl;
    for(int i = 0; i < 3; i++) {
        double ball_height = -16.0 * (seconds * seconds) + initial_velocity * seconds + initial_height;    
        cout << "Height Sec +" << i << ":  " << fixed << setprecision(1) << ball_height  << endl;
        seconds++;
    }

    
    return 0;
}