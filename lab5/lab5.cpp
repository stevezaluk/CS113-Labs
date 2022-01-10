#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

void caffeine() {
    int number_of_cups;
    int hours = 0;

    const int caffine_in_cup = 130;
    const int caffine_threshold = 65;
    const double percent_eliminated = 0.13;

    cout << "Enter the cups of coffee: ";
    cin >> number_of_cups;

    double caffeine_absorbed = caffine_in_cup * number_of_cups;

    cout << endl << "Hours" << "\t\t" << "Caffeine (mg)" << endl;
    while(caffeine_absorbed > caffine_threshold) {
        hours++;
        caffeine_absorbed = caffeine_absorbed - (caffeine_absorbed * percent_eliminated);
        cout << hours << "\t\t" << fixed << setprecision(1) << caffeine_absorbed << endl;
    }
}

void menu() {
    cout << endl << "W - Cash Withdrawl" << endl;
    cout << "D - Deposit" << endl;
    cout << "T - Transfer to/from Checking Account" << endl;
    cout << "B - Display balances" << endl;
    cout << "X - Exit" << endl;
}

void checkbook() {
    double checking_balance;
    double savings_balance;

    cout << "Enter checking account balance:   $";
    cin >> checking_balance;

    cout << "Enter savings account balance:   $";
    cin >> savings_balance;

    int ammount; // the ammount the user wants to withdraw/deposit
    char choice; // any choice you make in an action
    char input; // main input for you to pick your action
    
    while(true) {
        menu();
        cout << "\tEnter choice ";
        cin >> input;
        switch(input) {
            case 'w':
            case 'W':
                cout << "Enter withdrawl ammount:   $";
                cin >> ammount;

                if(ammount > checking_balance && ammount <= savings_balance) {
                    cout << "** Overdraft Protection provided by the Bank of Steve **" << endl;
                    savings_balance -= ammount;
                    checking_balance += ammount;
                } else if(ammount > checking_balance) {
                    cout << "** Not enough balance in checking account **" << endl;
                    break;
                }
                
                checking_balance -= ammount;
                break;

            case 'd':
            case 'D':
                cout << "Enter deposit ammount:   $";
                cin >> ammount;

                checking_balance += ammount;
                break;

            case 't':
            case 'T':
                cout << "Enter transfer ammount:   $";
                cin >> ammount;

                cout << "[T]o/[F]rom Savings account:   ";
                cin >> choice;

                if(choice == 'T' || choice == 't') {
                    savings_balance += ammount;
                } else if(choice == 'F' || choice == 'f') {
                    checking_balance += ammount;
                    savings_balance -= ammount;
                }
                break;

            case 'b':
            case 'B':
                cout << endl << "Checking account balance:   $" << fixed << setprecision(2) << checking_balance << endl;
                cout << "Savings account balance:   $" << fixed << setprecision(2) << savings_balance << endl;
                break;

            case 'x':
            case 'X':
                exit(0); // exit success
        }
    }
}

int main() {
    caffeine();
    checkbook();
    return 0;
}