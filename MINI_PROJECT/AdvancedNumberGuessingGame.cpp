#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void easyMode(int &RandomNumber, int &maxAttempts){

    RandomNumber = rand() % 100;
    maxAttempts = 10;

    cout << "I have selected a number between 0 and 99. Try to guess it. You have " << maxAttempts << " attempts. \n";
}

void mediumMode(int &RandomNumber, int &maxAttempts){

    RandomNumber = rand() % 1000;
    maxAttempts = 15;

    cout << "I have selected a number between 0 and 999. Try to guess it. You have " << maxAttempts << " attempts. \n";
}

void hardMode(int &RandomNumber, int &maxAttempts){

    RandomNumber = rand() % 10000;
    maxAttempts = 20;

    cout << "I have selected a number between 0 and 9999. Try to guess it. You have " << maxAttempts << " attempts. \n";
}
void intro(int &RandomNumber, int &maxAttempts){

    cout << "Welcome to the Number Guessing Game! \n";
    cout << "Select difficulty level: \n";
    cout << "1. Easy (0-99, 10 attempts) \n";
    cout << "2. Medium (0-999, 15 attempts) \n";
    cout << "3. Hard (0-9999, 20 attempts) \n";

    int difficulty;

    while(true){
    cin >> difficulty;
        if (difficulty == 1){
            easyMode(RandomNumber, maxAttempts);
            break;
        }
        else if (difficulty == 2){
            mediumMode(RandomNumber, maxAttempts);
            break;
        }
        else if (difficulty == 3){
            hardMode(RandomNumber, maxAttempts);
            break;
        }
        else {
            cout << "Invalid input. Please select a valid difficulty level (1, 2, or 3). \n";
        }
    }
}

bool outro(){
    while(true){
        cout << "Would you like to play again? (y/n): ";

        char playAgain;
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y'){
            return true;
        } else if (playAgain == 'n' || playAgain == 'N'){
            cout << "Thank you for playing! Goodbye! \n";
            cout << "Exiting the game... \n";
            return false;
        }
        else {
            cout << "Invalid input. Reenter your choice. \n";
        }
    }
}

int main(){

    srand(time(0)); // seed random generator
    do {
        int UserGuess, count = 0;

        int RandomNumber, maxAttempts;
        intro(RandomNumber, maxAttempts);

        do {
            cout << "Enter your guess: ";
            cin >> UserGuess;
            count++;

            if (UserGuess < RandomNumber){
                cout << "Higher \n";
            } 
            else if (UserGuess > RandomNumber){
                cout << "Lower \n";
            } 
            else {
                cout << "Congratulations!! You guessed the correct number in "<< count << " attempts! \n";
            }

            if(count <= maxAttempts / 2 && abs(UserGuess - RandomNumber) <= 5)
                cout << "(Very close!)";
            cout << "\nAttempts left: " << maxAttempts - count << "\n";

        } while (UserGuess != RandomNumber && count < maxAttempts);

        if (UserGuess != RandomNumber){
            cout << "Game Over! The correct number was: " << RandomNumber << ". \n";
            cout << "Better luck next time! \n";
        }

    } while(outro());

    return 0;
}