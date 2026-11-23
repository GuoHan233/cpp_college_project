#include "main_functions.h"

#include <iostream>

void passByValue(int rating) {
  std::cout << "passByValue received rating = " << rating << std::endl;
  rating = rating + 100;
  std::cout << "passByValue local rating = " << rating << std::endl;
}

void passArrayOfPlayers(player team[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << team[i].gamer_tag << " (" << team[i].real_name << ") - "
              << team[i].current_role << " - rating " << team[i].rating
              << std::endl;
  }
}

void updateRatingByPointer(player* p, int newRating) {
  if (p != nullptr) {
    p->rating = newRating;
  }
}

void updateRatingByRefVar(player& p, int newRating) {
  p.rating = newRating;
}

void resetTopPlayerPtr(player*& topPtr) {
  static player newcomer = {"New Recruit", "Rookie", "DPS",
                            2000, 50.0f, 1.0f, "Scouted"};
  topPtr = &newcomer;
}

int sumTeamWins(player team[], int n) {
  if (n <= 0) {
    return 0;
  }
  return team[n - 1].rating + sumTeamWins(team, n - 1);
}

int findBestPlayerIndex(player team[], int n) {
  if (n == 1) {
    return 0;
  }
  int bestIdx = findBestPlayerIndex(team, n - 1);
  if (team[n - 1].rating > team[bestIdx].rating) {
    return n - 1;
  }
  return bestIdx;
}

long factorialRecursive(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorialRecursive(n - 1);
}
