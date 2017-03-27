/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 26, 2017, 7:49 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "CustomerAccount.h"
#include "MovieData.h"
#include "Player.h"
#include "Speaker.h"
#include "WeatherData.h"
//problem 1
void problem1();
void inputData(CustomerAccount *);
void displayData(CustomerAccount *);
void changeData(CustomerAccount *);
void inputAnCustomer(CustomerAccount &);
void callMenu(CustomerAccount *);
bool cinValidNumber(int &);
bool cinValidNumber(float &);
const int SIZE_C = 12;
//problem 2
void problem2();
void callMenuProblem2(CustomerAccount *);
void searchAndDisplay(CustomerAccount *, string);
//problem 3
void problem3();
void displayMovie(MovieData *);
//problem 4
void problem4();
void displayMovieProblem4(MovieData *);
//problem 5
void problem5();
void displayPlayers(Player *);
const int SIZE_SOCCER = 12;
//problem 6
void problem6();
void inputData(Speaker *);
void displayData(Speaker *);
void changeData(Speaker *);
void inputAnSpeaker(Speaker &);
void callMenu(Speaker *);
const int SIZE_SPEAKER = 10;
//problem 7
void problem7();
//problem 8
void problem8();

enum Month {
    January, February, March, April, May, June, July, August, September, October, November, December
};
string displayMonth(Month);
//menu main
void callMenuMain();

/*
 * 
 */
int main(int argc, char** argv) {
    callMenuMain();
    return 0;
}

void problem1() {
    CustomerAccount *c = new CustomerAccount[SIZE_C];

    callMenu(c);
}

void callMenu(CustomerAccount *c) {
    int choice = -1;
    do {
        do {
            cout << "1. Enter data into the array." << endl;
            cout << "2. Change the content." << endl;
            cout << "3. Display all the data." << endl;
            cout << "4. Exit." << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 4);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1: inputData(c);
            break;
        case 2: changeData(c);
            break;
        case 3: displayData(c);
            break;
        default:
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenuMain();
    }
}

void inputData(CustomerAccount *c) {
    for (int i = 0; i < SIZE_C; i++) {
        cout << "\tCustomer " << i + 1 << endl;
        inputAnCustomer(c[i]);
    }
    callMenu(c);
}

void displayData(CustomerAccount *c) {
    for (int i = 0; i < SIZE_C; i++) {
        cout << "Name of customer: " << c[i].name << endl;
        cout << "Address of customer: " << c[i].address << endl;
        cout << "City of customer: " << c[i].city << endl;
        cout << "State of customer: " << c[i].state << endl;
        cout << "Zip of customer: " << c[i].zip << endl;
        cout << "Telephone of customer: " << c[i].telephoneNumber << endl;
        cout << "Balance of customer: " << c[i].accountBalance << endl;
        cout << "Data of last payment: " << c[i].dateLastPayment << endl;
        cout << "---------------------------------------" << endl;
    }
    callMenu(c);
}

void changeData(CustomerAccount *c) {
    int index = -1;
    do {
        do {
            cout << "Enter index (0 to 11): ";
        } while (!cinValidNumber(index));
    } while (index < 0 || index > 11);
    inputAnCustomer(c[index]);
    callMenu(c);
}

void inputAnCustomer(CustomerAccount &c) {
    //name
    do {
        cout << "Enter name of customer: ";
        cin.ignore();
        getline(cin, c.name);
    } while (!c.name.compare(""));
    //address
    do {
        cout << "Enter address of customer: ";
        getline(cin, c.address);
    } while (!c.address.compare(""));
    //city
    do {
        cout << "Enter city of customer: ";
        getline(cin, c.city);
    } while (!c.city.compare(""));
    //state
    do {
        cout << "Enter state of customer: ";
        getline(cin, c.state);
    } while (!c.state.compare(""));
    //zipcode
    do {
        cout << "Enter zip code of customer: ";
    } while (!cinValidNumber(c.zip));
    //telephone
    do {
        cout << "Enter telephone number of customer: ";
        getline(cin, c.telephoneNumber);
    } while (!c.telephoneNumber.compare(""));
    //balance
    do {
        do {
            cout << "Enter balance of customer: ";
        } while (!cinValidNumber(c.accountBalance));
    } while (c.accountBalance < 0);
    //date
    do {
        cout << "Enter date of last payment: ";
        getline(cin, c.dateLastPayment);
    } while (!c.dateLastPayment.compare(""));
}

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

bool cinValidNumber(float &number) {
    cin >> number;
    bool isCorrect = true;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}

//-------------------------------------------------------------

void problem2() {
    CustomerAccount *c = new CustomerAccount[SIZE_C];
    callMenuProblem2(c);
}

void searchAndDisplay(CustomerAccount *c, string name) {
    int counter = 0;
    for (int i = 0; i < SIZE_C; i++) {
        if (!c[i].name.compare(name)) {
            cout << "Name of customer: " << c[i].name << endl;
            cout << "Address of customer: " << c[i].address << endl;
            cout << "City of customer: " << c[i].city << endl;
            cout << "State of customer: " << c[i].state << endl;
            cout << "Zip of customer: " << c[i].zip << endl;
            cout << "Telephone of customer: " << c[i].telephoneNumber << endl;
            cout << "Balance of customer: " << c[i].accountBalance << endl;
            cout << "Data of last payment: " << c[i].dateLastPayment << endl;
            cout << "---------------------------------------" << endl;
            counter++;
        }
    }
    if (counter == 0)
        cout << "Not found customer: " << name << endl;
    callMenu(c);
}

void callMenuProblem2(CustomerAccount *c) {
    int choice = -1;
    do {
        do {
            cout << "1. Enter data into the array." << endl;
            cout << "2. Change the content." << endl;
            cout << "3. Display all the data." << endl;
            cout << "4. Search customers." << endl;
            cout << "5. Exit.";
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 5);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1: inputData(c);
            break;
        case 2: changeData(c);
            break;
        case 3: displayData(c);
            break;
        case 4:{
            string name;
            cout << "Enter customer name: ";
            cin >> name;
            searchAndDisplay(c, name);
            break;}
        case 5:
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenuMain();
            break;
    }
}
//-------------------------------------------------------------

void problem3() {
    MovieData *m1 = new MovieData();
    m1->director = "Kevin";
    m1->title = "Love 90 days";
    m1->yearRelease = 2010;
    m1->runningTime = 90;

    MovieData *m2 = new MovieData();
    m2->director = "John";
    m2->title = "Batman";
    m2->runningTime = 120;
    m2->yearRelease = 2011;

    displayMovie(m1);
    displayMovie(m2);
    cout << "Press [Enter] to continue...";
    cin.ignore();
    cin.get();
    callMenuMain();
}

void displayMovie(MovieData *m) {
    cout << "Movie name: " << m->title << endl;
    cout << "Director of movie: " << m->director << endl;
    cout << "Time: " << m->runningTime << endl;
    cout << "Year release: " << m->yearRelease << endl;
    cout << "---------------------------------" << endl;
}

//-------------------------------------------------------------

void problem4() {
    MovieData *m1 = new MovieData();
    m1->director = "Kevin";
    m1->title = "Love 90 days";
    m1->yearRelease = 2010;
    m1->runningTime = 90;
    m1->productionCost = 13523.34f;
    m1->firstYearRevenues = 32356.12f;

    MovieData *m2 = new MovieData();
    m2->director = "John";
    m2->title = "Batman";
    m2->runningTime = 120;
    m2->yearRelease = 2011;
    m2->productionCost = 43657.43f;
    m2->firstYearRevenues = 13569.2f;

    displayMovieProblem4(m1);
    displayMovieProblem4(m2);
    cout << "Press [Enter] to continue...";
    cin.ignore();
    cin.get();
    callMenuMain();
}

void displayMovieProblem4(MovieData *m) {
    cout << "Movie name: " << m->title << endl;
    cout << "Director of movie: " << m->director << endl;
    cout << "Time: " << m->runningTime << endl;
    cout << "Year release: " << m->yearRelease << endl;
    cout << "Production cost: " << m->productionCost << endl;
    cout << "Revenues: " << m->firstYearRevenues << endl;
    cout << "First year's revenues: " << (((m->firstYearRevenues - m->productionCost) > 0) ? "profit" : "loss") << endl;
    cout << "---------------------------------" << endl;
}

//-------------------------------------------------------------

void problem5() {
    Player *player = new Player[SIZE_SOCCER];
    for (int i = 0; i < SIZE_SOCCER; i++) {
        cout << "Player " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> player[i].name;
        do {
            cout << "Enter number of player: ";
            cin >> player[i].number;
        } while (player[i].number < 0);
        do {
            cout << "Enter point scored by player: ";
            cin >> player[i].point;
        } while (player[i].point < 0);
    }
    displayPlayers(player);
    int totalPoints = 0;
    int highestPoint = 0;
    for (int i = 0; i < SIZE_SOCCER; i++) {
        if (player[i].point > highestPoint)highestPoint = player[i].point;
        totalPoints += player[i].point;
    }
    cout << "The total points earned by them team: " << totalPoints << endl;
    cout << "The players have the highest points" << endl;
    cout << "Name\tNumber\tPoints" << endl;
    for (int i = 0; i < SIZE_SOCCER; i++) {
        if (highestPoint == player[i].point) {
            cout << player[i].name << "\t" << player[i].number << "\t" << player[i].point << endl;
        }
    }
    cout << "Press [Enter] to continue...";
    cin.ignore();
    cin.get();
    callMenuMain();
}

void displayPlayers(Player *p) {
    cout << "List of players" << endl;
    cout << "Name\tNumber\tPoints" << endl;
    for (int i = 0; i < SIZE_SOCCER; i++) {
        cout << p[i].name << "\t" << p[i].number << "\t" << p[i].point << endl;
    }
}
//-------------------------------------------------------------

void problem6() {
    Speaker *s = new Speaker[SIZE_SPEAKER];
    for (int i = 0; i < 10; i++) {
        s[i].fee = 0.0f + i;
        s[i].telephone = "test";
        s[i].speakingTopic = "test";
        s[i].name = "test";
    }
    callMenu(s);
}

void callMenu(Speaker *s) {
    int choice = -1;
    do {
        do {
            cout << "1. Enter data into the array." << endl;
            cout << "2. Change the content." << endl;
            cout << "3. Display all the data." << endl;
            cout << "4. Exit.";
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 4);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1: inputData(s);
            break;
        case 2: changeData(s);
            break;
        case 3: displayData(s);
            break;
        case 4:
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenuMain();
    }
}

void inputData(Speaker *s) {
    for (int i = 0; i < SIZE_SPEAKER; i++) {
        cout << "Speaker " << i + 1 << endl;
        inputAnSpeaker(s[i]);
    }
    callMenu(s);
}

void displayData(Speaker *s) {
    for (int i = 0; i < SIZE_SPEAKER; i++) {
        cout << "Name of speaker: " << s[i].name << endl;
        cout << "Telephone of speaker: " << s[i].telephone << endl;
        cout << "Topic of speaker: " << s[i].speakingTopic << endl;
        cout << "Free required: " << s[i].fee << endl;
        cout << "---------------------------------------" << endl;
    }
    callMenu(s);
}

void changeData(Speaker *s) {
    int index;
    do {
        do {
            cout << "Enter index (0 to 11): ";
        } while (!cinValidNumber(index));
    } while (index < 0 || index > 11);
    inputAnSpeaker(s[index]);
    callMenu(s);
}

void inputAnSpeaker(Speaker &s) {

    cout << "Enter name of speaker: ";
    cin.ignore();
    getline(cin, s.name);


    cout << "Enter telephone of speaker: ";
    getline(cin, s.telephone);

    cout << "Enter topic of speaker: ";
    getline(cin, s.speakingTopic);

    do {
        do {
            cout << "Enter fee required: ";
        } while (!cinValidNumber(s.fee));
    } while (s.fee < 0);
}
//-------------------------------------------------------------

void problem7() {
    int SIZE = 12;
    float totalRain = 0;
    float highestTemp = 0;
    int monthHighestTemp = 0;
    float lowestTemp = 0;
    int monthLowestTemp = 0;
    float averageTemp = 0;
    WeatherData *weather = new WeatherData[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Month " << i + 1 << endl;
        //input total rain
        cout << "Enter total rainfall: ";
        cin >> weather[i].totalRainfall;
        //add total rain
        totalRain += weather[i].totalRainfall;
        //input high temp
        do {
            cout << "Enter high temperature: ";
            cin >> weather[i].highTemperature;
        } while (weather[i].highTemperature < -100 || weather[i].highTemperature > 140);
        //set the highest temperature
        if (weather[i].highTemperature > highestTemp) {
            highestTemp = weather[i].highTemperature;
            monthHighestTemp = i;
        }
        //input low temp
        do {
            cout << "Enter low temperature: ";
            cin >> weather[i].lowTemperature;
            if (i == 0) lowestTemp = weather[i].lowTemperature;
        } while ((weather[i].lowTemperature < -100 || weather[i].lowTemperature > 140) || weather[i].lowTemperature > weather[i].highTemperature);
        //set the lowest temperature
        if (weather[i].lowTemperature < lowestTemp) {
            lowestTemp = weather[i].lowTemperature;
            monthLowestTemp = i;
        }
        //set the average temp of the month
        weather[i].averageTemperature = (weather[i].highTemperature + weather[i].lowTemperature) / 2;
        //add average temp
        averageTemp += weather[i].averageTemperature;
    }
    cout << "-----------------------\n";
    cout << "Total rainfall for the year: " << totalRain << endl;
    cout << "The average monthly rainfall: " << totalRain / 12 << endl;
    cout << "The highest temperature in month " << monthHighestTemp << ": " << highestTemp << endl;
    cout << "The lowest temperature in month " << monthLowestTemp << ": " << lowestTemp << endl;
    cout << "The average temperature: " << averageTemp / 12 << endl;
    cout << "Press [Enter] to continue...";
    cin.ignore();
    cin.get();
    callMenuMain();
}

//-------------------------------------------------------------

void problem8() {
    Month month;
    int SIZE = 12;
    float totalRain = 0;
    float highestTemp = 0;
    Month monthHighestTemp = January;
    float lowestTemp = 0;
    Month monthLowestTemp = January;
    float averageTemp = 0;
    WeatherData *weather = new WeatherData[SIZE];
    for (month = January; month <= December; month = static_cast<Month> (month + 1)) {
        cout << "Month " << displayMonth(month) << endl;
        //input total rain
        cout << "Enter total rainfall: ";
        cin >> weather[month].totalRainfall;
        //add total rain
        totalRain += weather[month].totalRainfall;
        //input high temp
        do {
            cout << "Enter high temperature: ";
            cin >> weather[month].highTemperature;
        } while (weather[month].highTemperature < -100 || weather[month].highTemperature > 140);
        //set the highest temperature
        if (weather[month].highTemperature > highestTemp) {
            highestTemp = weather[month].highTemperature;
            monthHighestTemp = month;
        }
        //input low temp
        do {
            cout << "Enter low temperature: ";
            cin >> weather[month].lowTemperature;
            if (month == 0) lowestTemp = weather[month].lowTemperature;
        } while ((weather[month].lowTemperature < -100 || weather[month].lowTemperature > 140) || weather[month].lowTemperature > weather[month].highTemperature);
        //set the lowest temperature
        if (weather[month].lowTemperature < lowestTemp) {
            lowestTemp = weather[month].lowTemperature;
            monthLowestTemp = month;
        }
        //set the average temp of the month
        weather[month].averageTemperature = (weather[month].highTemperature + weather[month].lowTemperature) / 2;
        //add average temp
        averageTemp += weather[month].averageTemperature;
    }
    cout << "-----------------------\n";
    cout << "Total rainfall for the year: " << totalRain << endl;
    cout << "The average monthly rainfall: " << totalRain / 12 << endl;
    cout << "The highest temperature is " << displayMonth(monthHighestTemp) << ": " << highestTemp << endl;
    cout << "The lowest temperature is " << displayMonth(monthLowestTemp) << ": " << lowestTemp << endl;
    cout << "The average temperature: " << averageTemp / 12 << endl;
    cout << "Press [Enter] to continue...";
    cin.ignore();
    cin.get();
    callMenuMain();
}

string displayMonth(Month m) {
    string name;
    switch (m) {
        case January: name = "January";
            break;
        case February: name = "February";
            break;
        case March: name = "March";
            break;
        case April: name = "April";
            break;
        case May: name = "May";
            break;
        case June: name = "June";
            break;
        case July: name = "July";
            break;
        case August: name = "August";
            break;
        case September: name = "September";
            break;
        case October: name = "October";
            break;
        case November: name = "November";
            break;
        case December: name = "December";
    }
    return name;
}

void callMenuMain() {
    int menu;
    do {
        do {
            cout << "1.  Type 1  for Customer account 1\n";
            cout << "2.  Type 2  for Customer account 2\n";
            cout << "3.  Type 3  for Movie data 1\n";
            cout << "4.  Type 4  for Movie data 2\n";
            cout << "5.  Type 5  for Soccer Scores\n";
            cout << "6.  Type 6  for Speaker Bureau\n";
            cout << "7.  Type 7  for Weather Statistics 1\n";
            cout << "8.  Type 8  for Weather Statistics 2\n";
            cout << "Enter problem you want: ";
            cin>>menu;
        } while (menu < 1 || menu > 8);

        switch (menu) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            case 7: problem7();
                break;
            case 8: problem8();
                break;

        }
    } while (menu > 0 && menu <= 8);
}

