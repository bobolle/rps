#include <iostream>
#include <random>

using namespace std;

const string rpsMoves[3] = {"Rock", "Paper", "Scissors"};

class Player {
  public:
    int score = 0;
    int move;
    void pick(int random);
};

void Player::pick(int random = false) {
  if (random) {
    this->move = rand() % 3;
  } else {
    do {
      cout << "Rock (0), Paper (1) or Scissors (2)?\n";
      cin >> this->move;
      cin.clear();
      cin.ignore(10000, '\n');
    } while (move < 0 || move > 2);
  }
}

class Game {
  private:
    int player_total = 0;
    int pc_total = 0;
    int moves_counter[3] = {0,0,0};

  public:
    void print_statistics();
    void startGame();
    void menu();
    void comparePicks();
};

void Game::print_statistics() {
        
          std::cout << "Total MOVES PER CHOICE\n"
                    << rpsMoves[0] << " " << this->moves_counter[0] << "\n" 
                    << rpsMoves[1] << " " << this->moves_counter[1] << "\n"
                    << rpsMoves[2] << " " << this->moves_counter[2] << "\n"
                    << "Total by User:  "   << player_total << "\n"
                    << "Total by Computer: "<<  pc_total << "\n";
       
}   

void Game::startGame() {
  Player user;
  Player computer;

  while (user.score < 3 && computer.score < 3) {
    //pick
    user.pick();
    computer.pick(true);

    //print
    cout << "Player: " << rpsMoves[user.move] << "\n";
    cout << "Computer: " << rpsMoves[computer.move] << "\n";

    // history
    this->player_total++;
    this->pc_total++;
    moves_counter[user.move]++;
    moves_counter[computer.move]++;

    //  replace with comparePick method
    //  if (user.move == computer.move) {
    //  cout << "It's a tie!\n";
    //}
  }
}

void Game::comparePicks() {

}

void Game::menu() {
  int menu_answer;

  while (1) {
    cout << "------------------------------" << endl;
    cout << "\nWELCOME TO ROCK PAPER SCISSOR!" << endl;
    cout << "------------------------------" << endl;
    cout << "NEW GAME (1)" << endl;
    cout << "SHOW STATISTICS (2)" << endl;
    cout << "QUIT (3)" << endl;
    cout << "------------------------------" << endl;

    cout << "What do you want to do?" << endl;
    cin >> menu_answer;
    switch (menu_answer)
    {
      case 1:
        Game::startGame();
        break;

      case 2:
        Game::print_statistics();
        break;

      case 3:
          cout << "Thank you for playing!" << endl;
          exit(0);

      default:
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "Try again!" << endl;
    }
  }
}

int main() {
  srand(time(0));
  Game game;
  game.menu();

  return 0;
}
