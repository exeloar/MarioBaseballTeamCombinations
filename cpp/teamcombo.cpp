#include "gamedata.h"
#include "team.h"

#include <vector>
#include <iostream>

std::vector<std::pair<Team,Team>> combinations(96926348578605); // 54 choose 18
unsigned long long int currentCombo = 0;

void generateCombinations(char teamSoFar[], char size, char start) {
    if(start == NUM_DISTINCT_CHARACTERS){ return; }

    char roster[size + 1];
    memcpy(roster, teamSoFar, size);
    if (size == 18) {
        char team1[9];
        char team2[9];
        memcpy(team1,teamSoFar,9);
        memcpy(team2,teamSoFar+9, 9);
        combinations[currentCombo++] = std::make_pair(Team(team1), Team(team2));
    }
    else {
        // did not choose character
        generateCombinations(roster, size, start + 1); 
        
        // chose character
        roster[size] = start;
        generateCombinations(roster, size + 1, start + 1); 
    }
}

bool isValidMatch(const Team &team1, const Team &team2) {
    if(team1.hasCaptain()
    && team1.hasNoDuplicates()
    && team2.hasCaptain()
    && team2.hasNoDuplicates()
    &&!team1.sharesPlayersWith(team2)){
        return true;
    }
    return false;
}

int main(){
    long long unsigned int num_matches = 0;
    generateCombinations(nullptr, 0, 0);
    for(const std::pair<Team,Team>& match : combinations){
        num_matches += isValidMatch(match.first, match.second);
    }
    std::cout << "Num Matches Possible: " << num_matches << "\n";
    return 0;
}