#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int ints[5];
    double doubles[] = {10.0, 20.0, 30.0, 40.0, 50.0};

    for(int i = 1; i < 6; i++) {
        ints[i] = i;
        cout << ints[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < (sizeof(doubles) / sizeof(double)); i++) {
        cout << fixed << setprecision(1) << doubles[i] << " ";
    }

    string months[] = {"January", "Febuary", "March",
                        "April", "May", "June", "July",
                        "August", "September", "October",
                        "November", "December"};

    /*
        I didnt know what you meant by use two arrays, so I just
        decided to make them both the same size. I could have acheived
        this easily with if statements but I dont think thats what you
        were asking of me

        I would have loved to represent these values with a linked list!
        Would have been very cool to do :)

        Hopefuly, we can chat more in class on tuesday so that I could better
        understand what you meant by map them using two arrays.
    */
    string seasons[] = {"Winter", "Winter", "Spring", "Spring", 
                        "Spring", "Summer", "Summer", "Summer", 
                        "Fall", "Fall", "Fall", "Winter"};

    int input;

    cout << endl << endl << "Enter the number of the month: ";
    cin >> input;

    if((input <= 0 || input > 12)) {
        cout << "* Invalid month: " << input << endl;
        exit(0);
    }
    cout << "The month " << months[input - 1] << " is in " << seasons[input - 1];
   
    return 0;
}