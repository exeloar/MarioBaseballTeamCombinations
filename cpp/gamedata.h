#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

const unsigned NUM_DISTINCT_CHARACTERS = 54;
const unsigned CAPTAIN_CUTOFF = 11;
const unsigned DUPLICATE_CUTOFF = 42;

extern std::unordered_map<char, std::string> characters;
extern std::vector<std::unordered_set<char>> duplicates;

unsigned getOffset(char dupe);

#endif