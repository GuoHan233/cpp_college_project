/*
    guo_functions.cpp
    ---------------------------------------------------------------
    Implementation of the NEW functions implemented by Guo (Group 4).

    Contains the definitions of:
      - [Screen / Menu]   functions (Task 2, Guo & Zihao)
      - [Parameter Passing] functions (Task 5, Guo)
      - [Recursion]       functions (Task 9, Guo)

    Kept in a separate file so the original main_functions.cpp stays
    unchanged. Uses only structures (no classes), per the assignment.
    ---------------------------------------------------------------
*/

#include "guo_functions.h"

/* =========================================================================
   [Screen / Menu]  - Task 2 (Guo & Zihao)
   -------------------------------------------------------------------------
   The application is a console menu system. The user navigates by typing
   the number of the option they want. Each option either runs a feature
   or opens a sub-menu. This section provides the display functions and the
   main loop (runApp) that ties everything together.
   ========================================================================= */

// Prints the top-level menu. This is the first thing the user sees.
void displayMainMenu() {
  cout << "\n============================================\n";
  cout << "   E-SPORTS SCOUTING & RECRUITMENT SYSTEM\n";
  cout << "============================================\n";
  cout << " 1. Manage Players\n";
  cout << " 2. Recruit New Player\n";
  cout << " 3. Show Team Statistics (Recursion demo)\n";
  cout << " 4. Exit\n";
  cout << "--------------------------------------------\n";
  cout << "Enter your choice: ";
}

// Sub-menu for player management. Called when the user picks option 1.
void displayPlayerMenu() {
  cout << "\n---- Manage Players ----\n";
  cout << " 1. Add a player\n";
  cout << " 2. Update a player's rating\n";
  cout << " 3. List all players\n";
  cout << " 4. Back to main menu\n";
  cout << "-----------------------\n";
  cout << "Enter your choice: ";
}

// Sub-menu for recruitment. Called when the user picks option 2.
void displayRecruitMenu() {
  cout << "\n---- Recruit New Player ----\n";
  cout << " 1. Scout a player\n";
  cout << " 2. Sign a player to the team\n";
  cout << " 3. Back to main menu\n";
  cout << "----------------------------\n";
  cout << "Enter your choice: ";
}

// The main program loop. It repeatedly shows the main menu, reads the
// user's choice and dispatches to the matching feature. This keeps the
// program running until the user chooses to exit.
void runApp() {
  int choice = 0;

  // A small sample roster used so the menus have something to act on.
  // In the full integrated program this data is read from a file.
  player roster[3] = {
      {"Alex Smith", "Blaze",   "DPS",     2400, 62.5f, 1.8f, "Scouted"},
      {"Jamie Lee",  "Vortex",  "Support", 2150, 58.0f, 1.2f, "Scouted"},
      {"Sam Rivera", "Nightowl","Tank",    2600, 71.0f, 2.1f, "Signed"}
  };

  while (true) {
    displayMainMenu();
    cin >> choice;

    switch (choice) {
      case 1: { // Manage players -> show the player sub-menu
        int sub = 0;
        displayPlayerMenu();
        cin >> sub;
        if (sub == 1) {
          cout << "  (Add player feature goes here)\n";
        } else if (sub == 2) {
          // Demonstrate parameter passing (Task 5) in a real menu action:
          // update the first player's rating by reference.
          cout << "  Updating " << roster[0].gamer_tag
               << "'s rating from " << roster[0].rating << " to 2500...\n";
          updateRatingByRefVar(roster[0], 2500);
          cout << "  New rating: " << roster[0].rating << "\n";
        } else if (sub == 3) {
          // Demonstrate passing an array of structures (Task 5, 2.2).
          cout << "  Current roster:\n";
          passArrayOfPlayers(roster, 3);
        }
        // sub == 4 (or anything else) simply falls back to the main menu.
        break;
      }
      case 2: { // Recruit -> show the recruit sub-menu
        int sub = 0;
        displayRecruitMenu();
        cin >> sub;
        if (sub == 1) {
          cout << "  (Scout player feature goes here)\n";
        } else if (sub == 2) {
          cout << "  (Sign player feature goes here)\n";
        }
        break;
      }
      case 3: { // Show team statistics using recursion (Task 9)
        int total = sumTeamWins(roster, 3);
        int best  = findBestPlayerIndex(roster, 3);
        cout << "  Total rating points across roster: " << total << "\n";
        cout << "  Highest-rated player: " << roster[best].gamer_tag
             << " (" << roster[best].rating << ")\n";
        break;
      }
      case 4:
        cout << "  Goodbye!\n";
        return; // exit the loop and the program
      default:
        cout << "  Invalid choice, please try again.\n";
        break;
    }
  }
}

/* =========================================================================
   [Parameter Passing]  - Task 5 (Guo)
   -------------------------------------------------------------------------
   The assignment requires examples of five parameter-passing methods.
   Each function below shows one method, used in a way that makes sense
   in the e-sports scouting domain.

     2.1 passing a variable by value
     2.2 passing an array of structures
     2.3 passing by reference using a pointer
     2.4 passing by reference using a reference variable
     2.5 passing a pointer by reference
   ========================================================================= */

// 2.1 Passing a variable BY VALUE.
// The function receives a COPY of 'rating'. Any change made to 'rating'
// inside this function does NOT affect the caller's original variable.
// This is appropriate when the function only needs to READ the value and
// must not modify the caller's data (e.g. just displaying a rating).
void passByValue(int rating) {
  cout << "  passByValue: received rating = " << rating << "\n";
  rating = rating + 100; // changes only the local copy
  cout << "  passByValue: local rating is now " << rating
       << " (caller is unchanged)\n";
}

// 2.2 Passing an ARRAY OF STRUCTURES.
// Arrays are passed as a pointer to their first element, so the function
// can access (and modify) the original data directly. This is used to
// iterate over the whole roster and print every player.
void passArrayOfPlayers(player team[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "  [" << i << "] " << team[i].gamer_tag
         << " (" << team[i].real_name << ") - "
         << team[i].current_role << " - rating " << team[i].rating << "\n";
  }
}

// 2.3 Passing by reference USING A POINTER.
// The caller passes the ADDRESS of a player (&p). The function uses the
// pointer to modify the original player's rating directly. This is useful
// when you must change the caller's data and want an explicit "address"
// style, and when the function should also be allowed to receive nullptr.
void updateRatingByPointer(player* p, int newRating) {
  if (p != nullptr) {          // guard against a null pointer
    p->rating = newRating;     // dereference and update the original
  }
}

// 2.4 Passing by reference USING A REFERENCE VARIABLE.
// The parameter 'p' is an alias for the caller's player. Changes to 'p'
// affect the original directly, but the syntax is cleaner than a pointer
// (no need for * or ->). This is the preferred C++ style when the object
// must always be valid and must be modified.
void updateRatingByRefVar(player& p, int newRating) {
  p.rating = newRating;        // updates the original through the alias
}

// 2.5 Passing a POINTER BY REFERENCE.
// Here we pass the pointer itself by reference (player*&). This lets the
// function change WHICH player the caller's pointer points to, not just
// the pointed-to data. Used when "resetting" a top-player pointer to a
// newly recruited player.
void resetTopPlayerPtr(player*& topPtr) {
  // For demonstration we make the pointer point to a new player.
  // In the full program this new player would come from user input.
  static player newcomer = {"New Recruit", "Rookie", "DPS",
                            2000, 50.0f, 1.0f, "Scouted"};
  topPtr = &newcomer;          // repoint the caller's pointer
}

/* =========================================================================
   [Recursion]  - Task 9 (Guo)
   -------------------------------------------------------------------------
   Recursion is a function calling itself to solve smaller sub-problems.
   Each function below stops at a base case and otherwise calls itself
   with a reduced problem size.

   We use the team's 'rating' field as the integer metric being summed /
   searched, since the structure already stores it.
   ========================================================================= */

// Recursively sum the rating points of the first n players in 'team'.
// Base case : n <= 0 -> nothing left to add, return 0.
// Recursive  : return last player's rating + sum of the rest.
int sumTeamWins(player team[], int n) {
  if (n <= 0) {
    return 0;                          // base case: no players left
  }
  // Reduce the problem: add the last player's rating and recurse on n-1.
  return team[n - 1].rating + sumTeamWins(team, n - 1);
}

// Recursively find the index of the highest-rated player among the first
// n players. Uses a helper-style recursion comparing the last element
// against the best found in the remaining n-1 players.
int findBestPlayerIndex(player team[], int n) {
  if (n == 1) {
    return 0;                          // base case: only one player -> index 0
  }
  // Recursively find the best in the first n-1 players.
  int bestIdx = findBestPlayerIndex(team, n - 1);
  // Compare the last player (index n-1) against the best so far.
  if (team[n - 1].rating > team[bestIdx].rating) {
    return n - 1;
  }
  return bestIdx;
}

// Classic recursion: factorial. In the scouting domain this can model
// the number of possible line-up permutations for n players.
// Base case : n <= 1 -> 1.
// Recursive  : n * factorial(n-1).
long factorialRecursive(int n) {
  if (n <= 1) {
    return 1;                          // base case
  }
  return n * factorialRecursive(n - 1); // recursive step
}
