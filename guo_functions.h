/*
    guo_functions.h
    ---------------------------------------------------------------
    Header file for the functions implemented by Guo (Group 4).

    These are NEW functions added for the following assignment topics:
      - Task 2 : Screen / Menu          (Guo & Zihao)
      - Task 5 : Parameter Passing      (Guo)
      - Task 9 : Recursion              (Guo)

    They are kept in a separate file so the original files
    (main_functions.h / main_functions.cpp) stay unchanged.
    ---------------------------------------------------------------
*/

#pragma once

#include "main_functions.h"   // reuse the existing player/game/fixture structs

#include <iostream>

/* -------------------------------------------------------------------------
   [Screen / Menu]  - Task 2 (Guo & Zihao)
   Functions that print and drive the console menu system.
   ------------------------------------------------------------------------- */
void displayMainMenu();                 // Prints the main menu options
void displayPlayerMenu();               // Prints the player-management sub-menu
void displayRecruitMenu();              // Prints the recruitment sub-menu
void runApp();                          // Main program loop: shows menus,
                                        // reads the user's choice and calls
                                        // the matching feature

/* -------------------------------------------------------------------------
   [Parameter Passing]  - Task 5 (Guo)
   Each function below demonstrates a different parameter-passing method,
   all within the e-sports scouting domain.

     2.1 passByValue           -> passing a variable by value
     2.2 passArrayOfPlayers    -> passing an array of structures
     2.3 updateRatingByPointer -> passing by reference using a pointer
     2.4 updateRatingByRefVar  -> passing by reference using a reference var
     2.5 resetTopPlayerPtr     -> passing a pointer by reference
   ------------------------------------------------------------------------- */
void passByValue(int rating);
void passArrayOfPlayers(player team[], int size);
void updateRatingByPointer(player* p, int newRating);
void updateRatingByRefVar(player& p, int newRating);
void resetTopPlayerPtr(player*& topPtr);

/* -------------------------------------------------------------------------
   [Recursion]  - Task 9 (Guo)
   Recursive functions used in the scouting domain.
   ------------------------------------------------------------------------- */
int  sumTeamWins(player team[], int n);          // Recursively sum a metric
                                                 // (used to total wins)
int  findBestPlayerIndex(player team[], int n);  // Recursively find the index
                                                 // of the highest-rated player
long factorialRecursive(int n);                  // Classic recursion example
                                                 // (used for rating tiers)
