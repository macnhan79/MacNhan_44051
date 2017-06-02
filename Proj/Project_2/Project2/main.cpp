#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <typeinfo>
#include <fstream>
using namespace std;
#include "Scores.h"
#include "Object.h"
#include "Walls.h"
#include "BaseMap.h"
#include "Fruit.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"

void draw(Scores*, BaseMap*, int);
void update(int&, bool&, Snake*, Fruit*, BaseMap*, Scores*);
void resizeConsole(int, int);
void clearScreen();
void moveSnake(Snake*);
void handleLevel(int&, Snake*, Fruit*, BaseMap*);
void save(string, Scores, const int);
Scores * printScoreFromFile(string, const int);
const string FILE_NAME = "Scores.dat"; /*!< The name of file will save the high score */

int main() {
    Scores *score = printScoreFromFile(FILE_NAME, 5);
    srand(static_cast<unsigned int> (time(0)));
    resizeConsole(800, 600);
    int timeSleep = 10;
    int points = 0;
    bool isRun = true;
    BaseMap *map = new BaseMap;
    Snake *snake = new Snake;
    Fruit *fruit = new Fruit;
    while (isRun) {
        moveSnake(snake);
        update(points, isRun, snake, fruit, map, score);
        handleLevel(points, snake, fruit, map);
        clearScreen();
        printf("\a");
        Sleep(timeSleep);
    }
    Scores newScore;
    newScore.scores = points;
    save(FILE_NAME, newScore, 5);
    delete map;
    delete snake;
    delete fruit;
    return 0;
}

/*!
 * \brief Function control the level of game. When play reach to some, the function will
 * increase speed of snake or change to another map
 * \param points The points of game
 * \param snake Snake
 * \param fruit Fruit
 * \param map Current map
 * \return None
 */
void handleLevel(int &points, Snake *snake, Fruit *fruit, BaseMap *map) {
    if (points > 100) {
        snake->setMaxSpeed(25);
    }
    if (points > 200) {
        snake->setMaxSpeed(20);
    }
    //change map 1
    if (points == 300) {
        Sleep(3000);
        Map1 *map1 = new Map1;
        *map = *map1;
        snake->init();
        fruit->reLocation();
        delete map1;
        points += 5;
    }
    if (points > 400) {
        snake->setMaxSpeed(25);
    } else if (points > 500) {
        snake->setMaxSpeed(20);
    }
    //change map 2
    if (points == 600) {
        Sleep(3000);
        Map2 *map2 = new Map2;
        *map = *map2;
        snake->init();
        fruit->reLocation();
        delete map2;
        points += 5;
    }
    if (points > 700) {
        snake->setMaxSpeed(20);
    } else if (points > 800) {
        snake->setMaxSpeed(15);
    }//change map 3
    if (points == 900) {
        Sleep(3000);
        Map3 *map3 = new Map3;
        *map = *map3;
        snake->init();
        fruit->reLocation();
        delete map3;
        points += 5;
    }
    if (points > 1000) {
        snake->setMaxSpeed(10);
    }
}

/*!
 * \brief Function update the state of game and combine snake, fruit, map together
 * \param points The points of game
 * \param isRun State of game run or not
 * \param snake Snake
 * \param fruit Fruit
 * \param map Current map
 * \param score Current score
 * \return None
 */
void update(int &points, bool &isRun, Snake *snake, Fruit *fruit, BaseMap *map, Scores *score) {
    snake->move();
    BaseMap *tempMap = new BaseMap;
    *tempMap = *map;
    //set fruit
    tempMap->map[fruit->getY()][fruit->getX()] = *fruit;
    int p = tempMap->map[fruit->getY()][fruit->getX()].getPoints();
    while (p < 0) {
        fruit->reLocation();
        p = tempMap->map[fruit->getY()][fruit->getX()].getPoints();
    }

    //set [x,y] snake
    ListNode* current = snake->getHead();
    //check collision
    tempMap->map[current->getY()][current->getX()] = *current;
    int checkCollision = tempMap->map[current->getY()][current->getX()].getPoints();
    //collision wall
    if (checkCollision < 0 || checkCollision == 2) {
        isRun = false;
        //collision fruits
    } else if (checkCollision >= 5) {
        points += checkCollision;
        //add snake
        snake->insertBack();
        //re location fruit
        fruit->reLocation();
    }
    current = current->getNextNode();

    //move snake
    while (current != nullptr) {
        tempMap->map[current->getY()][current->getX()] = *current;
        //collision snake
        checkCollision = tempMap->map[current->getY()][current->getX()].getPoints();
        if (checkCollision == 2) {
            isRun = false;
        }
        current = current->getNextNode();
    }

    draw(score, tempMap, points);
    delete tempMap;
}

/*!
 * \brief Function will print the map to screen
 * \param points The points of game
 * \param map Current map
 * \param score Current score
 * \return None
 */
void draw(Scores *score, BaseMap *tempMap, int points) {
    //draw whole map
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 60; j++) {
            cout << tempMap->map[i][j].getSymbol();
        }
        if (i == 0) {
            cout << "\t#: Walls";
        }
        if (i == 1) {
            cout << "\t@: Fruits";
        }
        if (i == 5) {
            cout << "\tScores: " << points;
        }

        if (i == 20) {
            cout << "\tHigh Scores";
        }
        if (i == 21) {
            cout << "\t1.\t" << score->scores;
        }
        if (i == 22) {
            cout << "\t2.\t" << score[1].scores;
        }
        if (i == 23) {
            cout << "\t3.\t" << score[2].scores;
        }
        if (i == 24) {
            cout << "\t4.\t" << score[3].scores;
        }
        if (i == 25) {
            cout << "\t5.\t" << score[4].scores;
        }
        cout << endl;
    }
}

/*!
 * \brief Function get direction of snake
 * \param snake Snake
 * \return None
 */
void moveSnake(Snake *snake) {
    if (GetAsyncKeyState(VK_LEFT)) {
        if (snake->state != snake->RIGHT)
            snake->state = snake->LEFT;
    } else if (GetAsyncKeyState(VK_RIGHT)) {
        if (snake->state != snake->LEFT)
            snake->state = snake->RIGHT;
    } else if (GetAsyncKeyState(VK_UP)) {
        if (snake->state != snake->DOWN)
            snake->state = snake->UP;
    } else if (GetAsyncKeyState(VK_DOWN)) {
        if (snake->state != snake->UP)
            snake->state = snake->DOWN;
    }
}

/*!
 * \brief Function clear everything on screen
 * \param snake Snake
 * \return None
 */
void clearScreen() {
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle

            (STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
/*!
 * \brief Function change size of screen
 * \param width Width of screen
 * \param height Height of screen
 * \return None
 */
void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
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
    //check exist , write 1 score and return
    if (in.fail()) {
        in.open("Scores.dat", ios::out | ios::binary);
        score.rank = 1;
        in.write(reinterpret_cast<char *> (&score), sizeof (score));
        return;
    }
    //read the first element
    in.read(reinterpret_cast<char *> (&sFile[0]), sizeof (sFile[0]));
    int i = 1;
    //loop to end file && < size
    while (!in.eof()) {
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
    sFile[0].rank = 1;
    out.write(reinterpret_cast<char *> (&sFile[0]), sizeof (sFile[0]));
    i = 1;
    while (!out.eof() && i < size) {
        sFile[i].rank = i + 1;
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
 * \return Score
 */
Scores *printScoreFromFile(string fileName, const int size = 5) {
    Scores *score = new Scores[5];
    fstream file;
    file.open("Scores.dat", ios::in | ios::binary);

    if (file.fail()) {
        file.open("Scores.dat", ios::out | ios::binary);
    } else {
        file.read(reinterpret_cast<char *> (&score[0]), sizeof (score[0]));
        int i = 1;
        while (!file.eof()) {
            file.read(reinterpret_cast<char *> (&score[i]), sizeof (score[i]));
            i++;
        }
        file.close();
    }
    return score;
}