#include "gamedata.h"
#include "team.h"

#include <vector>
#include <iostream>
#include <climits>

unsigned long long int dp[NUM_PLAYERS_PER_ROSTER][NUM_NON_DUPE_CHARACTERS];

// We need a few things pre-initialized for the recursion:
// Case of 0 picks
// Case of 1 pick
// Captain Rules
// Duplicate Characters (taken care of in recursion & initialization along w/ 1 distinct dp entry per duplicate)
void initialize(){
    // Set "uninitialized value" as ULLONG_MAX. Could be done w/ memset
    for(uint_8 i = 0; i < NUM_PLAYERS_PER_ROSTER; i++){
        for(uint_8 j = 0; j < NUM_NON_DUPE_CHARACTERS; j++){
            dp[i][j] = ULLONG_MAX;
        }
    }

    // No more picks
    for(uint_8 i = 0 ; i < NUM_PLAYERS_PER_ROSTER; i++){
        dp[NUM_PLAYERS_PER_ROSTER - 1][i] = 0; //impossible
    }
    for(uint_8 i = NUM_PLAYERS_PER_ROSTER; i < NUM_NON_DUPE_CHARACTERS; i++){
        dp[NUM_PLAYERS_PER_ROSTER - 1][i] = 1; //this is a single team w/ the roster we have
    }

    // Last pick
    for(uint_8 i = 0 ; i < 8; i++){
        dp[NUM_PLAYERS_PER_ROSTER - 2][i] = 0; //impossible
    }
    for(uint_8 i = DUPLICATE_CUTOFF_UNCOUNTED+1; i < NUM_NON_DUPE_CHARACTERS; i++){
        dp[NUM_PLAYERS_PER_ROSTER - 2][i] = NUM_NON_DUPE_CHARACTERS-i; //# players left = # possible teams
    }
    for(uint_8 i = DUPLICATE_CUTOFF_UNCOUNTED; i > CAPTAIN_CUTOFF; i--){
        dp[NUM_PLAYERS_PER_ROSTER - 2][i] = numDupesPerNoDupeIndex[i] + solve(NUM_PLAYERS_PER_ROSTER - 2, i+1); //# duplicates of this player + # of picks possible later
    }

    // No more captains
    for(uint_8 i = CAPTAIN_CUTOFF + 1; i < NUM_NON_DUPE_CHARACTERS; i++){
        dp[0][i] = 0;
    }
}

long long unsigned int solve(uint_8 numChosen,uint_8 characterIndex){
    if(dp[numChosen][characterIndex] != ULLONG_MAX){
        return dp[numChosen][characterIndex];
    }

    if(characterIndex != CAPTAIN_CUTOFF){
        // Num Teams = (variants * pick player) + don't pick them
        uint_8 variants = 1;
        if(numDupesPerNoDupeIndex.count(characterIndex) >= 0){
            variants = numDupesPerNoDupeIndex[characterIndex];
        }
        return dp[numChosen][characterIndex] = 
                (variants * solve(numChosen+1,characterIndex+1))  //picked
            +   solve(numChosen,characterIndex+1);                //not picked
    }

    //Accounting for multiple captain choices, we check on the final captain
    //If we pick the last captain, then we have numChosen + 1 possible captain variations
    //If we don't, then we have numChosen possible captains for our team
    return dp[numChosen][characterIndex] = 
            ((numChosen+1) * solve(numChosen + 1,characterIndex+1))
        +   (numChosen * solve(numChosen,characterIndex+1));
    
}

int main(){
    std::cout << "Num Teams Possible: " << solve(0,0) << "\n";
    return 0;
}