#pragma once

#include <string>

using namespace std;

struct player {
  string real_name;
  string gamer_tag;
  string current_role;
  int rating;
  float winRate;
  float kdRatio;
  string scout_status;
};

struct game {
  int gameid;
  string game;
  player *topPlayer;
  int kills;
  int deaths;
};

struct fixture {
  int fixture_id;
  string opponent;
  string matchdate;
  game match_stats;
};

void passByValue(int rating);
void passArrayOfPlayers(player team[], int size);
void updateRatingByPointer(player* p, int newRating);
void updateRatingByRefVar(player& p, int newRating);
void resetTopPlayerPtr(player*& topPtr);

int sumTeamRatings(player team[], int n);
int findBestPlayerIndex(player team[], int n);
long factorialRecursive(int n);

void showMenu();
void addPlayer(player team[], int& size, int capacity);
void deletePlayer(player team[], int& size, int index);
void editPlayerRating(player& p);
void editPlayerRatingByPointer(player* p);
void viewRoster(player team[], int size);
void runApp();
