#include <vector>
#include <cstring> //memcpy

class Team {
public:
    char team[9];
    std::vector<char> eligibleCaptains;

    Team(){}

    Team(char[9]);
    
    bool hasCaptain() const;
    bool hasNoDuplicates() const;
    bool sharesPlayersWith(const Team &) const;
    void print();
};
