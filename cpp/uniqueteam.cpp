#include "gamedata.h"
#include "team.h"

#include <vector>
#include <iostream>

std::vector<Team> combinations; // 5317936260 = 54 choose 9
//unsigned long long int currentCombo = 0; 

void generateCombinations(char teamSoFar[], char size, char start) {
    if(start == NUM_DISTINCT_CHARACTERS){ return; }

    char roster[size + 1];
    memcpy(roster, teamSoFar, size);
    if (size == 9) {
        combinations.emplace_back(teamSoFar);
        std::cout << combinations.size() << "\n";
    }
    else {
        // did not choose character (must choose if no captain)
        if(!(start == CAPTAIN_CUTOFF && size == 0)){
            generateCombinations(roster, size, start + 1);
        }

        // chose character
        roster[size] = start;
        unsigned offset = getOffset(start);
        generateCombinations(roster, size + 1, start + offset); 
    }
}

int main(){
    long long unsigned int num_teams = 0;
    generateCombinations(nullptr, 0, 0);
    for(const Team& team : combinations){
        num_teams += team.eligibleCaptains.size();
    }
    std::cout << "Num Teams Possible: " << num_teams << "\n";
    return 0;
}