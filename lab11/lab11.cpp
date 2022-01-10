#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

int monthIndex(string months[12], const string &month) {
    int index = -1;

    for(int i = 0; i < 12; i++) {
        string curr = months[i];
        if(curr == month) {
            index = i;
            return index;
        }
    }
 
    return index;
}

string formatCurrency(double value) {
    stringstream ss;

    ss.imbue(locale(""));
    ss << fixed << setprecision(2) << value;

    return ss.str();
}

int main() {
    ifstream file("sales.txt");
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    double totals[12] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    while(!file.eof()) {
        string line;
        string month;
        string cash;

        getline(file, line);

        month = line.substr(0, line.find(' '));
        cash = line.substr(line.find(' ') + 1); // returns cash
        
        for(int i = 0; i < 12; i++) {
            if(month == months[i]) {
                int index = monthIndex(months, month);
                totals[index] = totals[index] + stod(cash);
                break;
            }
        }
    }

    for(int i = 0; i < 12; i++) {
        cout << months[i] << "\t $" << formatCurrency(totals[i]) << endl;
    }    

    file.close();
    return 0;
}