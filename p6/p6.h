//
// Created by Tori Lim on 11/22/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#ifndef ADVENT_OF_CODE_2022_P6_H
#define ADVENT_OF_CODE_2022_P6_H

void p6(int k) {
    std::ifstream fs("/Users/tori/Desktop/C++/Advent_of_Code_2022/p6/broadcast.txt");
    if(fs.is_open()) {
        // Store broadcast in string
        std::string buf;
        std::getline(fs, buf);

        std::unordered_map<char, int> window{};
        for(int i = 0; i < k; i++) {
            if(window.contains(buf[i]))
                window[buf[i]]++;
            else
                window[buf[i]] = 1;
        }
        for(int i = k; i < buf.size(); i++) {
            if(window.size() == k) {
                std::cout << i << std::endl;
                break;
            }
            if(--window[buf[i-k]] == 0)
                window.erase(buf[i-k]);
            window.insert_or_assign(buf[i], (window.contains(buf[i]) ? ++window[buf[i]] : 1));
        }
    }
}

#endif //ADVENT_OF_CODE_2022_P6_H
