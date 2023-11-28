//
// Created by Tori Lim on 11/21/23.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#ifndef ADVENT_OF_CODE_2022_P4_H
#define ADVENT_OF_CODE_2022_P4_H

void p4_1() {
    ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p4/cleaning_sections.txt");
    if(fstream.is_open()) {
        int overlaps = 0;
        // Gets line: 13-53,17-82
        for(string line; getline(fstream, line);) {
            istringstream ss(line);
            /*
             *       Zone 1  Zone 2
             * Elf 1
             * Elf 2
             */
            int grid[2][2];

            // Gets elf zone: 13-53 and 17-82
            for(int elf = 0; elf <= 1; elf++) {
                string zones;
                getline(ss, zones, ',');
                istringstream ss2(zones);

                // Gets beginning and end sections 13 and 53
                for(int zone = 0; zone <= 1; zone++) {
                    string section;
                    getline(ss2, section, '-');
                    grid[elf][zone] = stoi(section);
                }
            }
            if(grid[0][0] >= grid[1][0] && grid[0][1] <= grid[1][1])
                overlaps++;
            else if(grid[1][0] >= grid[0][0] && grid[1][1] <= grid[0][1])
                overlaps++;
        }
        cout << "Overlaps: " << overlaps << endl;
        fstream.close();
    }
}

void p4_2() {
    ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p4/cleaning_sections.txt");
    if(fstream.is_open()) {
        int overlaps = 0;
        // Gets line: 13-53,17-82
        for(string line; getline(fstream, line);) {
            istringstream ss(line);
            /*
             *       Zone 1  Zone 2
             * Elf 1
             * Elf 2
             */
            int grid[2][2];

            // Gets elf zone: 13-53 and 17-82
            for(int elf = 0; elf <= 1; elf++) {
                string zones;
                getline(ss, zones, ',');
                istringstream ss2(zones);

                // Gets beginning and end sections 13 and 53
                for(int zone = 0; zone <= 1; zone++) {
                    string section;
                    getline(ss2, section, '-');
                    grid[elf][zone] = stoi(section);
                }
            }
            if(grid[0][0] >= grid[1][0] && grid[0][0] <= grid[1][1] || grid[0][1] <= grid[1][1] && grid[0][1] >= grid[1][0])
                overlaps++;
            else if(grid[1][0] >= grid[0][0] && grid[1][0] <= grid[0][1] || grid[1][1] <= grid[0][1] && grid[1][1] >= grid[0][0])
                overlaps++;
        }
        cout << "Overlaps: " << overlaps << endl;
        fstream.close();
    }
}
#endif //ADVENT_OF_CODE_2022_P4_H
