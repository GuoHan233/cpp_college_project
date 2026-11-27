/*
    Description:
    Esports team could scout for professional players for their team.

    Entry point of the program:
      1. Loads the players and the fixtures from the two CSV files
      2. Builds the game list out of the fixtures
      3. Starts the interactive menu
*/

#include <iostream>

#include "main_functions.h"

using namespace std;

int main()
{
  // Arrays holding everything the program reads from the CSV files
  player players[MAX_PLAYERS];
  int numPlayers = 0;

  fixture fixtures[MAX_FIXTURES];
  int numFixtures = 0;

  game games[MAX_FIXTURES];
  int numGames = 0;

  // The two data files live next to the source files / the .exe
  readingInputfiles("existingPlayers.csv", players, &numPlayers);
  readingFixturesInputFiles("fixtures.csv", fixtures, &numFixtures);

  // There is no separate games file, so the unique games are taken
  // from the fixtures that were just read (gameid + game name)
  for (int i = 0; i < numFixtures; i++)
  {
    bool alreadyAdded = false;

    for (int j = 0; j < numGames; j++)
    {
      if (games[j].gameid == fixtures[i].match_stats.gameid)
      {
        alreadyAdded = true;
      }
    }

    if (!alreadyAdded && numGames < MAX_FIXTURES)
    {
      games[numGames].gameid = fixtures[i].match_stats.gameid;
      games[numGames].game_name = fixtures[i].match_stats.game_name;
      numGames++;
    }
  }

  cout << "Loaded " << numPlayers << " player(s) and " << numFixtures
       << " fixture(s) from the CSV files." << endl;

  // Hand everything over to the menu loop
  runMenu(players, numPlayers, fixtures, numFixtures, games, numGames);

  return 0;
}
