#include <iostream>
#include <limits.h>
#include <vector>
#include <time.h>

using namespace std;

/**
    Stores integer numbers from user input and find the highest one.
*/
void ex01() {
    vector<int> mVector; 
    int input = -1;
    int higher = INT_MIN;

    cout << "Enter integer values (0 to stop): " << endl;

    do {
        cin >> input;
        if(input != 0){
            mVector.push_back(input);
        }
    }
    while(input != 0);
    
    for(auto &value : mVector) {
        if(value > higher){
            higher = value;
        }
    }
    cout << "Highest value is " << higher << endl;
}

/**
    Guess the number game. 
    Generates a fake random number and asks for the user to guess it.
*/
void ex02() {
    srand(time(NULL));
    int random, guess;

    random = (rand() % 100) +1;

    do {
        cout << "Guess the number (1 to 100): ";
        cin >>  guess;
        if(guess > random) {
            cout << "Try lower" << endl;
        }
        else if(guess < random) {
            cout << "Try higher" << endl;
        }
    } while(random != guess);
    cout << "You win!" << endl;
}

/**
    Roll a six face dice n times and shows their percentage.
*/
void ex03() {
    const int N_FACES = 6;
    int n, random;
    int faces[N_FACES];
    
    cout << "Enter number of throws: ";
    cin >> n;
    srand(time(NULL));

    // initialize array
    for(int i = 0; i < N_FACES; i++){
        faces[i] = 0;
    }

    for(int i = 0; i < n; i++){
        random = (rand() % 6) +1;
        switch(random) {
            case 1:                 // face 1
                faces[0]++;
                break;
            case 2:                 // face 2
                faces[1]++;
                break;
            case 3:                 // face 3
                faces[2]++;
                break;
            case 4:                 // face 4
                faces[3]++;
                break;
            case 5:                 // face 5
                faces[4]++;
                break;
            case 6:                 // face 6
                faces[5]++;
                break;
        }
    }
    cout << "Each face percentagem according to n" << endl;
    printf("Face 1: %5.1f%c\n", ((float)faces[0] / n) * 100, '%');
    printf("Face 2: %5.1f%c\n", ((float)faces[1] / n) * 100, '%');
    printf("Face 3: %5.1f%c\n", ((float)faces[2] / n) * 100, '%');
    printf("Face 4: %5.1f%c\n", ((float)faces[3] / n) * 100, '%');
    printf("Face 5: %5.1f%c\n", ((float)faces[4] / n) * 100, '%');
    printf("Face 6: %5.1f%c\n", ((float)faces[5] / n) * 100, '%');
}

