#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    srand(time(0)); // seed random generator

    int RandomNumber = rand() % 100 + 1;
    int UserGuess, count = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Try to guess it." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> UserGuess;
        count++;

        if (UserGuess < RandomNumber){
            cout << "Higher" << endl;
        } 
        else if (UserGuess > RandomNumber){
            cout << "Lower" << endl;
        } 
        else {
            cout << "Congratulations!! You guessed the correct number in "<< count << " attempts!" << endl;
        }

    } while (UserGuess != RandomNumber);

    return 0;
}