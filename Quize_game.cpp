#include <iostream>
#include <cstdlib> // for store the questions
#include <ctime> // for handling time based operation
#include <conio.h> // allowing decting keypress using_getch
#include <windows.h> // provide function like beep and text color

using namespace std;

//  just set for color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//  used for animation 
void welcomeAnimation() {
    setColor(11); // graphics color code
    cout << "\n\n\t   Loading Quiz Game ";
    for (int i = 0; i < 5; i++) {
        Sleep(500); // its used to stay the program for some time
        cout << ". ";
    }
    cout << "\n\n";
    setColor(7);
    system("cls");
}

// these line decade sound timer beep sound 
void tickTockSound() {
    Beep(1500, 100);
    Beep(1700, 100);
}

//time's up sound beep
void timeUpSound() {
    Beep(500, 500);
}

//  generally asking the question
struct Question {
    string question;
    string options[4];
    char correctAnswer;
};

// show that question
void displayQuestion(Question q, int &score) {
    char userAnswer;
    int timer = 15;

    system("cls");
    setColor(14);
    cout << "Time Remaining: ";
    setColor(12);
    cout << timer << " sec\n\n";
    setColor(11);
    cout << q.question << "\n";
    setColor(10);
    
    for (int i = 0; i < 4; i++) {
        cout << char('A' + i) << ") " << q.options[i] << "\n";
    }
    
    setColor(7);
    cout << "\nEnter your answer (A/B/C/D): ";

    while (timer > 0) {
        if (_kbhit()) { // its a keyword fun its checked to the button pressed or not
            userAnswer = toupper(_getch());
            cout << userAnswer << "\n";
            if (userAnswer == q.correctAnswer) {
                setColor(10);
                cout << "Correct Answer! +1 Point\n";
                score++;
                Beep(1000, 200); 
            } else {
                setColor(12);
                cout << "Wrong Answer! Correct Answer: " << q.correctAnswer << "\n";
                Beep(300, 500); 
            }
            Sleep(1000);
            return;
        }
        Sleep(1000);
        timer--;
        system("cls");
        setColor(14);
        cout << "Time Remaining: ";
        setColor(12);
        cout << timer << " sec\n\n";
        setColor(11);
        cout << q.question << "\n";
        setColor(10);
        for (int i = 0; i < 4; i++) {
            cout << char('A' + i) << ") " << q.options[i] << "\n";
        }
        setColor(7);
        cout << "\nEnter your answer (A/B/C/D): ";

        tickTockSound();
    }

    timeUpSound();
    setColor(12);
    cout << "\nTime's up! The correct answer was: " << q.correctAnswer << "\n";
    Sleep(1500);
}

int main() {
    system("cls");
    welcomeAnimation();

    string playerName;
    int score = 0;

    setColor(11); //graphics color code
    cout << "Welcome to the Ultimate Quiz Game!\n";
    cout << "Enter your name: ";
    setColor(10);
    cin >> playerName;
    system("cls");

    Question questions[] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 'C'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 'B'},
        {"Who developed C++?", {"Dennis Ritchie", "Bjarne Stroustrup", "James Gosling", "Guido van Rossum"}, 'B'},
        {"Solve: 15 + 27", {"32", "42", "45", "40"}, 'B'},
        {"What is the full form of CPU?", {"Central Processing Unit", "Computer Processing Unit", "Central Power Unit", "Central Processor Utility"}, 'A'},
        {"Which data structure follows FIFO?", {"Stack", "Queue", "Linked List", "Tree"}, 'B'},
        {"Solve: 2^5", {"10", "25", "32", "64"}, 'C'},
        {"Who is known as the father of computers?", {"Alan Turing", "Charles Babbage", "Bill Gates", "Steve Jobs"}, 'B'},
        {"Which keyword is used to declare a constant in C++?", {"static", "const", "final", "define"}, 'B'},
        {"What is 1001 in binary?", {"5", "9", "11", "13"}, 'C'},
        {"Which is the smallest prime number?", {"0", "1", "2", "3"}, 'C'},
        {"Which of these is NOT a programming language?", {"Python", "HTML", "C++", "Java"}, 'B'},
        {"Solve: 9 * 9", {"72", "81", "90", "99"}, 'B'},
        {"What is the output of 5 % 2?", {"2", "1", "0", "5"}, 'B'},
        {"What does RAM stand for?", {"Random Access Memory", "Read Access Memory", "Run Access Memory", "Rapid Access Memory"}, 'A'},
        {"Who wrote 'Harry Potter'?", {"J.K. Rowling", "George Orwell", "Agatha Christie", "Mark Twain"}, 'A'},
        {"Which gas do plants absorb?", {"Oxygen", "Carbon Dioxide", "Hydrogen", "Nitrogen"}, 'B'},
        {"How many bits are in a byte?", {"4", "8", "16", "32"}, 'B'},
        {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 'A'},
        {"Solve: 12 / 4", {"2", "3", "4", "6"}, 'B'},
        {"Which animal is known as the 'Ship of the Desert'?", {"Camel", "Horse", "Elephant", "Donkey"}, 'A'},
        {"Who painted the Mona Lisa?", {"Van Gogh", "Picasso", "Da Vinci", "Rembrandt"}, 'C'},
        {"What is 5 squared?", {"15", "20", "25", "30"}, 'C'},
        {"Who invented the telephone?", {"Edison", "Tesla", "Bell", "Newton"}, 'C'},
        {"What is 10! (10 factorial)?", {"362880", "3628800", "40320", "1000000"}, 'B'},
        {"Which element is represented by 'O'?", {"Gold", "Oxygen", "Osmium", "Obsidian"}, 'B'},
        {"What is 7 + 8?", {"12", "15", "16", "14"}, 'B'},
        {"Which part of a computer is the 'brain'?", {"Monitor", "Keyboard", "CPU", "RAM"}, 'C'},
        {"Who discovered gravity?", {"Einstein", "Newton", "Galileo", "Kepler"}, 'B'},
        {"Which language is used in web development?", {"C++", "Java", "HTML", "Python"}, 'C'}
    };

    for (int i = 0; i < 30; i++) {
        displayQuestion(questions[i], score);
    }

    setColor(14);
    cout << "\nGame Over, " << playerName << "! Your final score is: " << score << " out of 30\n";
    setColor(7);
    Beep(1200, 500);
    return 0;
}
