
#include <format>
#include <iostream>
#include <random>

int rollDice();

enum class Status { keepRolling, won, lost };

// C++20 feature: don't have to do Status::xyz every time
// using enum Status;

int main() {

  int myPoint{0};
  Status gameStatus{Status::keepRolling};

  switch (const int sumOfDice{rollDice()}) {
  case 7:
  case 11:
    gameStatus = Status::won;
    break;
  case 2:
  case 3:
  case 12:
    gameStatus = Status::lost;
    break;
  default:
    myPoint = sumOfDice;
    std::cout << std::format("Point is {}\n", myPoint);
    break;
  }

  while (Status::keepRolling == gameStatus) {
    const int sumOfDice{rollDice()};
    if (sumOfDice == myPoint) {
      gameStatus = Status::won;
    } else if (sumOfDice == 7) { // lost by rolling 7 before making the point
      gameStatus = Status::lost;
    }
  }

  if (Status::won == gameStatus) {
    std::cout << "Player wins\n";
  } else {
    std::cout << "Player lost\n";
  }
}

int rollDice() {
  // static variables are not re-initialized when rollDice runs again
  static std::random_device rd;
  static std::default_random_engine engine{rd()};
  static std::uniform_int_distribution randomDie{1, 6};

  const int die1{randomDie(engine)};
  const int die2{randomDie(engine)};
  const int sum{die1 + die2};

  std::cout << std::format("Player rolled {} + {} = {}\n", die1, die2, sum);
  return sum;
}
