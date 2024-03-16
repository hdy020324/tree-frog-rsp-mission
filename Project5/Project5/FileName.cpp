#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

class FrogGame {
private:
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> distrib{ 0, 2 };
    const int timeLimit = 3;
    int UserNum = 0;
    int ComputerNum;
    int PlayAgain;
    bool flag = false;
    string UserInput;
    string UserAnswer;
    string rockPaperScissors[3] = { "rock", "paper", "scissors" };


public:
    FrogGame() : gen(rd()), ComputerNum(distrib(gen)) {
        cout << "Frog Rock-paper-scissors game starts." << endl;
    }

    void PrintIntro() {
        cout << "Please input rock, paper, or scissors: ";
        cin >> UserInput;
    }

    void StrIntoNum() {
        if (UserInput == "rock")
            UserNum = 0;
        else if (UserInput == "paper")
            UserNum = 1;
        else if (UserInput == "scissors")
            UserNum = 2;
    }

    bool StartGame() {
        cout << "The opponent chose [" << rockPaperScissors[ComputerNum] << "] : ";
        time_t startTime = time(NULL);
        cin >> UserAnswer;
        time_t endTime = time(NULL);

        if (endTime - startTime < timeLimit) {
            flag = true;
            return flag;
        }
        else {
            return flag;
        }
    }

    void CalculResult(bool flag) {
        if (!flag) {
            cout << "You lose due to timelimit" << endl;
            return;
        }

        if (UserAnswer == "frog") {
            cout << "You Win!" << endl;
            return;
        }

        int result = (UserNum - ComputerNum + 3) % 3;

        switch (result) {
        case 0:
            cout << "Tie" << endl;
            break;
        case 1:
            cout << "You Win!" << endl;
            break;
        case 2:
            cout << "You lose" << endl;
            break;
        }
    }
    int PrintOuttro()
    {
        cout << "Input 1 to play again or Input 2 to quit" << endl;
        cin >> PlayAgain;
        if (PlayAgain)
            return 1;
        else
            return 0;

    }
};

int main() {
    int playAgain = 1;
    while (playAgain == 1) {
        FrogGame game;
        game.PrintIntro();
        game.StrIntoNum();
        bool flag = game.StartGame();
        game.CalculResult(flag);
        playAgain = game.PrintOuttro();
    }
    return 0;
}