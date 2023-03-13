//#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int bull;
    int cow;
    int find_count;
    int value1;
    int value2;
    int value3;
    int value4;
    int calculate_cows;
    string secret_number = "";
    string guess = "";
    bool run_game = true;
    char again;
    bool win;
    cout << "Welcome to the Bulls and Cows game!" << endl;
    while (run_game == true) {
        bull = 0;
        cow = 0;
        find_count = 0;
        calculate_cows = 0;
        //random number generation begin
        srand(time(NULL));
        value1 = rand() % 10;
        value2 = rand() % 10;
        value3 = rand() % 10;
        value4 = rand() % 10;
        // random number generation stop
        stringstream ss;
        ss << value1 << value2 << value3 << value4;
        secret_number = ss.str();
        win = false;
        while (win == false) {
            cout << "Make a guess: (XXXX)" << endl;
            cin >> guess;

            for (int i = 0; i < secret_number.length(); i++) {
                if (guess.at(i) == secret_number.at(i)) {
                    bull++;
                }
            }

            for (int i = 0; i < guess.length(); i++) {
                int secret = secret_number.at(i);
                if (guess.find(secret)) {
                    find_count++;
                }
            }

            calculate_cows = find_count - bull;
            cow = (calculate_cows < 0) ? 0 : calculate_cows;

            cout << "Bulls: " << bull << endl << "Cows: " << cow << endl;
            if (bull == 4) {
                cout << "You win!" << endl;
                win = true;
            }
            else {
                bull = 0;
                cow = 0;
                find_count = 0;
            }
        }
        cout << "Play again? (y/n)" << endl;
        cin >> again;
        run_game = (again == 'y') ? true : false;
    }
    cout << "Thanks for playing! :)" << endl;
    return 0;
}
//c++ beginner game
