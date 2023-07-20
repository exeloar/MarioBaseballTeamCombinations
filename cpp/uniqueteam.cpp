#include "gamedata.h"
#include "team.h"

#include <vector>
#include <iostream>

std::vector<Team> combinations(5317936260); // 54 choose 9
unsigned long long int currentCombo = 0; 

void generateCombinations(char teamSoFar[], char size, char start) {
    if(start == NUM_DISTINCT_CHARACTERS){ return; }

    char roster[size + 1];
    memcpy(roster, teamSoFar, size);
    if (size == 9) {
        combinations[currentCombo++] = Team(teamSoFar);
    }
    else {
        // did not choose character
        generateCombinations(roster, size, start + 1); 
        
        // chose character
        roster[size] = start;
        generateCombinations(roster, size + 1, start + 1); 
    }
}

int main(){
    long long unsigned int num_teams = 0;
    generateCombinations(nullptr, 0, 0);
    for(const Team& team : combinations){
        num_teams += (team.hasCaptain() && team.hasNoDuplicates());
    }
    std::cout << "Num Teams Possible: " << num_teams << "\n";
    return 0;
}