#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

const unsigned NUM_DISTINCT_CHARACTERS = 54;
extern std::unordered_map<char, std::string> characters;
extern std::unordered_set<char> captains;
extern std::vector<std::unordered_set<char>> duplicates;

#endif