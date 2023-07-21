#include <iostream>

#include "gamedata.h"
#include "team.h"

Team::Team(char roster[9]){
    memcpy(team,roster,9);
    for(char character : team){
        if(character <= CAPTAIN_CUTOFF){
            eligibleCaptains.push_back(character);
        }
    }
}

bool Team::hasCaptain() const{
    return !eligibleCaptains.empty();
}

bool Team::hasNoDuplicates() const{
    for(const std::unordered_set<char>& duplicateSet : duplicates){
        bool variant = false;
        bool already = false;
        for(const char& character : team) {
            variant = duplicateSet.count(character) != 0;
            if (variant && already) { return false; }
            already |= variant;
        }
    }
    return true;
}

bool Team::sharesPlayersWith(const Team &other) const{
    for(char teammate : team){
        for(char enemy : other.team){
            if(teammate == enemy){
                return true;
            }
        }
    }
    return false;
}

void Team::print(){
    for(char captain : eligibleCaptains){
        std::cout << "{ " << characters[captain] << " | ";
        for(char teammate : team){
            if(teammate != captain){
                std::cout << characters[teammate] << ", ";
            }
        }
        std::cout << "\b\b }\n";
    }
}