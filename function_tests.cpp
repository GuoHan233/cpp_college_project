/*
    Google Test (gtest) unit tests for the functions implemented by Guo.

    Covers:
      - Parameter passing functions (Task 5)
      - Recursion functions          (Task 9)

    Each test follows the AAA (Arrange - Act - Assert) approach:
      1. Arrange : set up the inputs and expected result
      2. Act     : call the function under test
      3. Assert  : verify the outcome matches the expectation
*/

#include "guo_functions.h"   // Guo's new functions (menu / parameter
                             // passing / recursion)

#include <gtest/gtest.h>

// -------------------------------------------------------------------------
// Parameter passing tests (Task 5)
// -------------------------------------------------------------------------

// 2.1 pass-by-value must NOT change the caller's variable.
TEST(ParameterPassing, PassByValueDoesNotModifyCaller) {
  int rating = 2000;            // Arrange
  passByValue(rating);          // Act (prints, but should not change rating)
  EXPECT_EQ(rating, 2000);      // Assert: caller unchanged
}

// 2.3 pass-by-pointer must update the original player's rating.
TEST(ParameterPassing, UpdateRatingByPointer) {
  player p{"Test", "T", "DPS", 2000, 50.0f, 1.0f, "Scouted"}; // Arrange
  updateRatingByPointer(&p, 2600);                            // Act
  EXPECT_EQ(p.rating, 2600);                                  // Assert
}

// 2.3 pass-by-pointer must be safe when given a null pointer.
TEST(ParameterPassing, UpdateRatingByPointerNullSafe) {
  player* p = nullptr;          // Arrange
  EXPECT_NO_THROW(updateRatingByPointer(p, 2600)); // Act + Assert: no crash
}

// 2.4 pass-by-reference (reference variable) must update the original.
TEST(ParameterPassing, UpdateRatingByRefVar) {
  player p{"Test", "T", "DPS", 2000, 50.0f, 1.0f, "Scouted"}; // Arrange
  updateRatingByRefVar(p, 2700);                              // Act
  EXPECT_EQ(p.rating, 2700);                                  // Assert
}

// 2.5 pass-pointer-by-reference must repoint the caller's pointer.
TEST(ParameterPassing, ResetTopPlayerPtr) {
  player a{"A", "a", "DPS", 1000, 50.0f, 1.0f, "Scouted"}; // Arrange
  player* topPtr = &a;
  resetTopPlayerPtr(topPtr);                               // Act
  ASSERT_NE(topPtr, nullptr);                              // Assert: not null
  EXPECT_EQ(topPtr->gamer_tag, "Rookie");                  // Assert: repointed
}

// -------------------------------------------------------------------------
// Recursion tests (Task 9)
// -------------------------------------------------------------------------

TEST(Recursion, SumTeamWins) {
  player team[3] = {
      {"A", "a", "DPS", 100, 50.0f, 1.0f, "Scouted"},
      {"B", "b", "DPS", 200, 50.0f, 1.0f, "Scouted"},
      {"C", "c", "DPS", 300, 50.0f, 1.0f, "Scouted"}
  };                                  // Arrange
  EXPECT_EQ(sumTeamWins(team, 3), 600); // Act + Assert
  EXPECT_EQ(sumTeamWins(team, 0), 0);   // base case
}

TEST(Recursion, FindBestPlayerIndex) {
  player team[3] = {
      {"A", "a", "DPS", 100, 50.0f, 1.0f, "Scouted"},
      {"B", "b", "DPS", 300, 50.0f, 1.0f, "Scouted"},
      {"C", "c", "DPS", 200, 50.0f, 1.0f, "Scouted"}
  };                                  // Arrange
  EXPECT_EQ(findBestPlayerIndex(team, 3), 1); // Act + Assert (B has 300)
}

TEST(Recursion, FactorialRecursive) {
  EXPECT_EQ(factorialRecursive(0), 1);  // Act + Assert
  EXPECT_EQ(factorialRecursive(1), 1);
  EXPECT_EQ(factorialRecursive(5), 120);
}
