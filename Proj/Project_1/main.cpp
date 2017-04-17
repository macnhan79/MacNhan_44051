/**
 * @file   main.cpp
 * @Author Nhan Mac
 * @date   April, 2017
 * @brief  Calculation Game
 *
 * Calculation Game is a game 
 * that measure how long a gamer can calculation math
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Scores.h"
/*  
 * A group of function prototype
 */
int calcTime(int &);
void callMainMenu(int level);
bool cinValidNumber(int &);
bool cinValidNumber(float &);
int getRandomNumber(int min, int max);
char getRandomOperations();
int generationOperation(int level);
void startGame(int);
void save(string, Scores, const int);
void printScoreFromFile(string, const int);
bool checkPrimeNumber(int);
int countScores(int);
/*
 *  Constant
 */
const char OPERATORS[4] = {'+', '-', '*', '/'}; /*!< Contain 4 operators: add,sub,div,multi */
const int NUMBER_OF_LEVEL = 3; /*!< The number of level */
const int ROUND_EACH_LEVEL = 10; /*!< Round for each level */
const int SIZE_SCORE_TO_FILE = 5; /*!< Maximum recored scores to write down file */
const string FILE_NAME = "Scores.dat"; /*!< The name of file will save the high score */
const int SIZE_TIME_SCORES = 5; /*!< How many level of points */
const int SCORE_TIME[SIZE_TIME_SCORES][2] = {
    {0, 10},
    {1, 8},
    {2, 6},
    {3, 4},
    {4, 2}
}; /*!< Array stored the points for each timing - Description: [time][points] */

int main(int argc, char** argv) {
    /* initialize random seed: */
    srand(time(NULL));
    int level = 1;
    callMainMenu(level);
    return 0;
}

/*!
 * \brief startGame function is a function will execute the game 
 * and print the result of game when user win or lose the game 
 * \param level current level of game
 * \return none
 */
void startGame(int level) {
    //init total score from beginning
    int totalScores = 0;
    bool isGameOver = false;
    //loop number of level
    for (int i = 0; i < NUMBER_OF_LEVEL; i++) {
        //loop round for each level
        for (int j = 1; j <= ROUND_EACH_LEVEL * level; j++) {
            //create operator-->input from player-->count time
            int time = generationOperation(level);
            //if time  < 0 --> game over
            if (time >= 0) {
                totalScores += countScores(time);
            } else {
                //game over
                isGameOver = true;
                break;
            }
        }
        //game over
        if (isGameOver) {
            break;
        }
        //passed level
        cout << "Congratulation! You passed level " << level << "." << endl;
        level++;
        cin.ignore();
        cout << "Press [Enter] to continue next level ...";
        cin.get();
    }
    Scores score;
    string name;
    score.scores = totalScores;
    //game over
    if (isGameOver) {
        //print info
        cout << "GAME OVER!" << endl;
        cout << "Your scores: " << totalScores << endl;
        cout << "Enter your name: ";
        cin >> name;
        score.name = name;
        //save score to file
        save(FILE_NAME, score, SIZE_SCORE_TO_FILE);
        cout << "Press [Enter] to play again.";
        cin.ignore();
        cin.get();
        level = 1;
        callMainMenu(level);
    } else {
        //complete game
        cout << "Congratulation! You won!" << endl;
        cout << "Your scores: " << totalScores << endl;
        cout << "Enter your name: ";
        cin >> name;
        score.name = name;
        save(FILE_NAME, score, SIZE_SCORE_TO_FILE);
        cin.ignore();
        cout << "Press [Enter] to play again.";
        cin.get();
        callMainMenu(level);
    }
}

/*!
 * \brief return the points for user
 * depend on the time user enter their result.
 * \param time The time in second from begin input to end input
 * \return The score
 */
int countScores(int time) {
    for (int i = 0; i < SIZE_TIME_SCORES; i++) {
        //SCORE_TIME[i][0] description [time][point]
        if (SCORE_TIME[i][0] == time)
            return SCORE_TIME[i][1];
    }
    return 0;
}

/**
 * \brief Get time in second from begin input to end input
 * @param result the value from input
 * @return the time in second
 */
int calcTime(int &result) {
    time_t start, end;
    //current time start
    time(&start);
    cinValidNumber(result);
    //current time end
    time(&end);
    //different time
    int dif = difftime(end, start);
    return dif;
}

/*!
 * \brief Create a random number in range
 * \param min min value in range
 * \param max max value in range
 * \return a random number
 */
int getRandomNumber(int min, int max) {
    int number;
    //random number in range [min-max]
    number = (rand() % (max - min + 1)) + min; // 
    return number;
}

/*!
 * \brief Get a random operator from array char OPERATORS[4] = {'+', '-', '*', '/'}
 * \return a character '+' or '-' or '*' or '/'
 */
char getRandomOperations() {
    return OPERATORS[getRandomNumber(0, 3)];
}

/*!
 * \brief Checking a number is a prime number or not
 * \param number number will be checked
 * \return True: is a prime number | False: is not a prime number
 */
bool checkPrimeNumber(int number) {
    bool isPrime = true;
    //loop to number/2
    for (int i = 2; i < number / 2; i++) {
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

/*!
 * \brief Create a Mathematical operation, receive the input from user, calculate the time,
 * and check the result from input of user
 * \param level The level of game
 * \return The time of process
 * \note if the result of user is incorrect, the function will return the time = -1
 */
int generationOperation(int level) {
    int number1;
    int number2;
    char oper = getRandomOperations();
    //generation number depend on level
    if (level == 3) {
        number1 = getRandomNumber(10, 99);
        number2 = getRandomNumber(0, 99);
    } else if (level == 2) {
        number1 = getRandomNumber(10, 99);
        number2 = getRandomNumber(0, 9);
    } else {
        number1 = getRandomNumber(0, 9);
        number2 = getRandomNumber(0, 9);
    }

    //generation operations and count the time when begin input to end input
    int result;
    int time;
    switch (oper) {
            //if operator is +
        case '+':
            //print result;
            cout << number1 << " + " << number2 << " = ";
            //count time
            time = calcTime(result);
            //check result
            if (result == (number1 + number2))
                return time;
            else
                return -1;
            break;
            //if operator is -
        case '-':
            //print result;
            cout << number1 << " - " << number2 << " = ";
            //count time
            time = calcTime(result);
            //check result
            if (result == (number1 - number2))
                return time;
            else
                return -1;
            break;
            //if operator is *
        case '*':
            // print result;
            cout << number1 << " x " << number2 << " = ";
            //count time
            time = calcTime(result);
            //check result
            if (result == (number1 * number2))
                return time;
            else
                return -1;
            break;
            //if operator is /
        case '/':
            //find number2 while it not a zero based-on level
            if (number2 == 0) {
                if (level == 3) {
                    do {
                        number2 = getRandomNumber(0, 99);
                    } while (number2 == 0);
                } else {
                    do {
                        number2 = getRandomNumber(0, 9);
                    } while (number2 == 0);
                }
            }
            if (number1 % number2 != 0) {
                if (level == 3 || level == 2) {
                    //create number 1 is not a prime number
                    do {
                        number1 = getRandomNumber(0, 99);
                    } while (!checkPrimeNumber(number1) || number1 % number2 != 0);
                } else {
                    //create number 1 is not a prime number
                    do {
                        number1 = getRandomNumber(0, 9);
                    } while (!checkPrimeNumber(number1) || number1 % number2 != 0);
                }
            }
            cout << number1 << " / " << number2 << " = ";
            time = calcTime(result);
            if (result == (number1 / number2))
                return time;
            else
                return -1;
            break;
    }
}

/*!
 * \brief Create a menu for choosing
 * 1. Start game
 * 2. Show high score
 * 3. Exit
 * \param level the level of game
 * \return none
 */
void callMainMenu(int level) {
    int choice = -1;
    //loop while choice is correct
    do {
        //print list of choice
        do {
            cout << "1. Start game." << endl;
            cout << "2. Show high scores." << endl;
            cout << "3. Exit." << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 3);
    switch (choice) {
        //if choice == 1 --> start game
        case 1:
            startGame(level);
            break;
        case 2:
            //choice == 2 --> print the high score
            printScoreFromFile(FILE_NAME, SIZE_SCORE_TO_FILE);
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu(level);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMainMenu(level);
    }
}

/*!
 * \brief Save the high score to file. The function will get the scores
 * that are stored in file and check the current score. If the current score is
 * greater than the other scores in file. The function will insert the current score
 * and store those to file.
 * \param fileName the name of file stores the high score
 * \param score the current score
 * \param size the size of record will be stored in file
 * \return none
 */
void save(string fileName, Scores score, const int size = 5) {
    //create a array to store high score
    Scores *sFile = new Scores[size];
    fstream in;
    //open document
    in.open("Scores.dat", ios::in | ios::binary);
    //read the first element
    in.read(reinterpret_cast<char *> (&sFile[0]), sizeof (sFile[0]));
    int i = 1;
    //loop to end file && < size
    while (!in.eof() && i < size) {
        //read next element
        in.read(reinterpret_cast<char *> (&sFile[i]), sizeof (sFile[i]));
        i++;
    }
    bool isChange = false;
    Scores temp;
    //loop to each element high score
    for (int j = 0; j < size; j++) {
        //check if have new high score
        if (!isChange) {
            //current score < new score
            if (sFile[j].scores < score.scores) {
                score.rank = sFile[j].rank;
                temp = sFile[j];
                sFile[j] = score;
                isChange = true;
            }
        } else {
            Scores temp1 = sFile[j];
            sFile[j] = temp;
            temp = temp1;
        }
    }
    in.close();
    //write to file
    fstream out;
    out.open("Scores.dat", ios::out | ios::binary);
    out.write(reinterpret_cast<char *> (&sFile[0]), sizeof (sFile[0]));
    i = 1;
    while (!out.eof() && i < size) {
        out.write(reinterpret_cast<char *> (&sFile[i]), sizeof (sFile[i]));
        i++;
    }
    out.close();
    delete []sFile;
    //printScoreFromFile(fileName, SIZE_SCORE_TO_FILE);
}

/*!
 * \brief Printing the high score that stored in file.
 * \param fileName the name of file stores the high score
 * \param size the size of record will be stored in file
 * \return none
 */
void printScoreFromFile(string fileName, const int size = 5) {
    Scores score;
    fstream file;
    file.open("Scores.dat", ios::in | ios::binary);
    file.read(reinterpret_cast<char *> (&score), sizeof (score));
    cout << "Rank\t\tName\t\tScores" << endl;
    cout << "--------------------------------------" << endl;
    while (!file.eof()) {
        cout << score.rank << "\t\t" << score.name << "\t\t" << score.scores << endl;
        file.read(reinterpret_cast<char *> (&score), sizeof (score));
    }
    file.close();
}

/*!
 * \brief Checking the input from user. Only check integer data type.
 * \param number store the input from user
 * \return none
 */
bool cinValidNumber(int &number) {
    float temp;
    cin >> temp;
    number = static_cast<int> (temp);
    bool isCorrect = true;
    if (cin.fail()) {

        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}