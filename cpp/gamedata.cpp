#include "gamedata.h"

std::unordered_map<char, std::string> characters = {

// Captains
        {0, "Mario"},
        {1, "Luigi"},
        {2, "DK"},
        {3, "Diddy"},
        {4, "Peach"},
        {5, "Daisy"},
        {6, "Yoshi"},
        {7, "Birdo"},
        {8, "Wario"},
        {9, "Waluigi"},
        {10, "Bowser"},
        {11, "Bowser Jr"},
        
// Duplicate Sets
        {12, "Koopa(G)"},
        {13, "Koopa(R)"},

        {14, "Toad(R)"},
        {15, "Toad(B)"},
        {16, "Toad(Y)"},
        {17, "Toad(G)"},
        {18, "Toad(P)"},
        
        {19, "Shy Guy(R)"},
        {20, "Shy Guy(B)"},
        {21, "Shy Guy(Y)"},
        {22, "Shy Guy(G)"},
        {23, "Shy Guy(Bk)"},
        
        {24, "Paratroopa(R)"},
        {25, "Paratroopa(G)"},
        
        {26, "Pianta(B)"},
        {27, "Pianta(R)"},
        {28, "Pianta(Y)"},
        
        {29, "Noki(B)"},
        {30, "Noki(R)"},
        {31, "Noki(G)"},
        
        {32, "Hammer Bro"},
        {33, "Boomerang Bro"},
        {34, "Fire Bro"},
        
        {35, "Magikoopa(B)"},
        {36, "Magikoopa(R)"},
        {37, "Magikoopa(G)"},
        {38, "Magikoopa(Y)"},
        
        {39, "Dry Bones(Gy)"},
        {40, "Dry Bones(G)"},
        {41, "Dry Bones(B)"},
        {42, "Dry Bones(R)"},

// Normal Characters
        {43, "Toadsworth"},
        {44, "King Boo"},
        {45, "Petey"},
        {46, "Dixie"},
        {47, "Goomba"},
        {48, "Paragoomba"},
        {49, "Baby Mario"},
        {50, "Baby Luigi"},
        {51, "Boo"},
        {52, "Toadette"},
        {53, "Monty"}, // saving the best for last
};

std::vector<std::unordered_set<char>> duplicates = {
        {12,13},
        {14,15,16,17,18},
        {19,20,21,22,23},
        {24,25},
        {26,27,28},
        {29,30,31},
        {32,33,34},
        {35,36,37,38},
        {39,40,41,42}
};

std::unordered_map<char, unsigned> numDupesPerNoDupeIndex = {
        {12, 2},
        {13, 5},
        {14, 5},
        {15, 2},
        {16, 3},
        {17, 3},
        {18, 3},
        {19, 4},
        {20, 4}
};

unsigned getOffset(char dupe){
        if(dupe < 12 || dupe >= 43){ return 1; }

        const char setStarts[] = {14,19,24,26,29,32,35,39};
        for(char c : setStarts){
                if(dupe < c){ return c - dupe; }
        }
        return 43 - dupe;
}