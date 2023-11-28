//
// Created by Tori Lim on 11/20/23.
//

#ifndef ADVENT_OF_CODE_2022_P1_H
#define ADVENT_OF_CODE_2022_P1_H
//
// Created by Tori Lim on 11/20/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int p1(void)
{
    ifstream list("/Users/tori/Desktop/C++/Advent_of_Code_2022/calories.txt");

    if (list.is_open())
    {
        vector<int> calories;
        string buf{};
        int current_total;
        while(getline(list, buf))
        {
            if(buf.empty()) {
                calories.push_back(current_total);
                current_total = 0;
            }
            else
                current_total += stoi(buf);
        }
        std::sort(calories.begin(), calories.end(), std::greater<int>());
        cout << (calories[0] + calories[1] + calories[2]) << endl;
        list.close();
    }
}

#endif //ADVENT_OF_CODE_2022_P1_H
