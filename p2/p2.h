//
// Created by Tori Lim on 11/20/23.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifndef ADVENT_OF_CODE_2022_P2_H
#define ADVENT_OF_CODE_2022_P2_H

/*
 * A,X = ROCK
 * B,Y = PAPER
 * C,Z = SCISSORS
 */

inline int outcomeToPoints(const char &letter) {
    switch (letter) {
        case 'X': return 0; // Lose
        case 'Y': return 3; // Draw
        case 'Z': return 6; // Win
        default: return -1;
    }
}

inline int decisionToPoints(const char& letter) {
    switch (letter) {
        case 'R': return 1;
        case 'P': return 2;
        case 'S': return 3;
        default: return -1;
    }
}

inline int playOutcome(char opp, char mine) {
    switch (mine) {
        // Lose
        case 'X':
            if(opp == 'A')  // Rock
                return outcomeToPoints(mine) + decisionToPoints('S');
            else if(opp == 'B') // Paper
                return outcomeToPoints(mine) + decisionToPoints('R');
            else    // Scissors
                return outcomeToPoints(mine) + decisionToPoints('P');
        case 'Y':   // Draw
            if(opp == 'A')  // Rock
                return outcomeToPoints(mine) + decisionToPoints('R');
            else if(opp == 'B') // Paper
                return outcomeToPoints(mine) + decisionToPoints('P');
            else    // Scissors
                return outcomeToPoints(mine) + decisionToPoints('S');
        case 'Z':   // Win
            if(opp == 'A')  // Rock
                return outcomeToPoints(mine) + decisionToPoints('P');
            else if(opp == 'B') // Paper
                return outcomeToPoints(mine) + decisionToPoints('S');
            else    // Scissors
                return outcomeToPoints(mine) + decisionToPoints('R');
        default:
            return -1;
    }
}

int p2(void) {
    std::ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p2/rps.txt");
    if(fstream.is_open())
    {
        std::string buf, piece;
        int total_score{};
        while(std::getline(fstream, buf)){
            std::istringstream ss(buf);
            const char *chars = buf.c_str();
            total_score += playOutcome(chars[0], chars[2]);
        }
        std::cout << total_score << std::endl;
    }
    return 0;
}

#endif //ADVENT_OF_CODE_2022_P2_H
