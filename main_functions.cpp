#include "main_functions.h"

#include <iostream>

// Demonstrates pass-by-value; modifies a local copy without affecting the caller's variable.
void passByValue(int rating) {
  std::cout << "passByValue received rating = " << rating << std::endl;
  rating = rating + 100;
  std::cout << "passByValue local rating = " << rating << std::endl;
}

// Prints all players in the team array (demonstrates passing an array and its size).
void passArrayOfPlayers(player team[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << team[i].gamer_tag << " (" << team[i].real_name << ") - "
              << team[i].current_role << " - rating " << team[i].rating
              << std::endl;
  }
}

// Updates a player's rating via pointer, safely ignoring null pointers.
void updateRatingByPointer(player* p, int newRating) {
  if (p != nullptr) {
    p->rating = newRating;
  }
}

// Updates a player's rating directly using a reference parameter.
void updateRatingByRefVar(player& p, int newRating) {
  p.rating = newRating;
}

// Reassigns the caller's player pointer by reference to point to a default rookie.
void resetTopPlayerPtr(player*& topPtr) {
  static player newcomer = {"New Recruit", "Rookie", "DPS",
                            2000, 50.0f, 1.0f, "Scouted"};
  topPtr = &newcomer;
}

// Recursively calculates the total rating of the first n players in the team.
int sumTeamRatings(player team[], int n) {
  if (n <= 0) {
    return 0;
  }
  return team[n - 1].rating + sumTeamRatings(team, n - 1);
}

// Recursively finds and returns the index of the player with the highest rating.
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

// Recursively computes the factorial of n (n!).
long factorialRecursive(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorialRecursive(n - 1);
}

// Displays the main scouting system menu options and prompts for user input.
void showMenu() {
  std::cout << "\n===== E-SPORTS SCOUTING SYSTEM =====\n";
  std::cout << "1. Add player\n";
  std::cout << "2. Delete player\n";
  std::cout << "3. Edit player rating\n";
  std::cout << "4. View roster\n";
  std::cout << "5. View best player\n";
  std::cout << "6. Exit\n";
  std::cout << "Enter your choice: ";
}

// Prompts for details and adds a new player to the roster if space is available.
void addPlayer(player team[], int& size, int capacity) {
  if (size >= capacity) {
    std::cout << "Roster is full.\n";
    return;
  }
  std::cout << "Enter real name: ";
  std::cin >> team[size].real_name;
  std::cout << "Enter gamer tag: ";
  std::cin >> team[size].gamer_tag;
  std::cout << "Enter role: ";
  std::cin >> team[size].current_role;
  std::cout << "Enter rating: ";
  std::cin >> team[size].rating;
  std::cout << "Enter win rate: ";
  std::cin >> team[size].winRate;
  std::cout << "Enter KD ratio: ";
  std::cin >> team[size].kdRatio;
  team[size].scout_status = "Scouted";
  size++;
}

// Removes the player at the given index from the roster and shifts remaining players.
void deletePlayer(player team[], int& size, int index) {
  if (index < 0 || index >= size) {
    std::cout << "Invalid index.\n";
    return;
  }
  for (int i = index; i < size - 1; i++) {
    team[i] = team[i + 1];
  }
  size--;
}

// Prompts for a new rating and updates the given player by reference.
void editPlayerRating(player& p) {
  int newRating;
  std::cout << "Enter new rating: ";
  std::cin >> newRating;
  updateRatingByRefVar(p, newRating);
}

// Prompts for a new rating and updates the given player via pointer.
void editPlayerRatingByPointer(player* p) {
  int newRating;
  std::cout << "Enter new rating: ";
  std::cin >> newRating;
  updateRatingByPointer(p, newRating);
}

// Displays all players currently in the roster.
void viewRoster(player team[], int size) {
  passArrayOfPlayers(team, size);
}

// Initializes sample roster data and runs the main interactive menu loop.
void runApp() {
  const int capacity = 10;
  player team[capacity] = {
      {"Alex Smith", "Blaze", "DPS", 2400, 62.5f, 1.8f, "Scouted"},
      {"Jamie Lee", "Vortex", "Support", 2150, 58.0f, 1.2f, "Scouted"},
      {"Sam Rivera", "Nightowl", "Tank", 2600, 71.0f, 2.1f, "Signed"}
  };
  int size = 3;
  int choice = 0;

  while (choice != 6) {
    showMenu();
    std::cin >> choice;

    switch (choice) {
      case 1:
        addPlayer(team, size, capacity);
        break;
      case 2: {
        int index;
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        deletePlayer(team, size, index);
        break;
      }
      case 3: {
        int index;
        std::cout << "Enter index to edit: ";
        std::cin >> index;
        if (index >= 0 && index < size) {
          editPlayerRating(team[index]);
        } else {
          std::cout << "Invalid index.\n";
        }
        break;
      }
      case 4:
        viewRoster(team, size);
        break;
      case 5: {
        if (size > 0) {
          int best = findBestPlayerIndex(team, size);
          std::cout << "Best player: " << team[best].gamer_tag
                    << " (rating " << team[best].rating << ")\n";
        } else {
          std::cout << "No players in roster.\n";
        }
        break;
      }
      case 6:
        std::cout << "Goodbye!\n";
        break;
      default:
        std::cout << "Invalid choice.\n";
        break;
    }
  }
}
