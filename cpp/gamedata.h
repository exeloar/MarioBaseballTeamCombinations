#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

const unsigned NUM_PLAYERS_PER_ROSTER = 9;
const unsigned NUM_NON_DUPE_CHARACTERS = 32;
const unsigned TOTAL_DISTINCT_CHARACTERS = 54;
const unsigned CAPTAIN_CUTOFF = 11;
const unsigned DUPLICATE_CUTOFF_COUNTED = 20;
const unsigned DUPLICATE_CUTOFF_UNCOUNTED = 42;

extern std::unordered_map<char, std::string> characters;
extern std::vector<std::unordered_set<char>> duplicates;

unsigned getOffset(char dupe);

#endif