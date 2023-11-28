//
// Created by Tori Lim on 11/20/23.
//
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#ifndef ADVENT_OF_CODE_2022_P3_H
#define ADVENT_OF_CODE_2022_P3_H

char findCommon(std::vector<char> const &a, std::vector<char> const &b) {
    std::unordered_map<char, int> a_items;
    for(auto& e : a) {
        a_items[e] = 1;
    }
    for(auto& e : b) {
        if(a_items.contains(e))
            return e;
    }
    return 0;
}

char findThreeCommon(std::vector<char> const &e1, std::vector<char> &e2, std::vector<char> const &e3) {
    std::unordered_map<char, int> e1_items, e2_items;
    for(auto& e : e1)
        e1_items[e] = 1;
    for(auto& e : e2)
        e2_items[e] = 1;
    for(auto& e : e3) {
        if(e1_items.contains(e) && e2_items.contains(e))
            return e;
    }
    std::cout << "Not found" << std::endl;
    return 0;
}

int convertToPriority(char const &item) {
    int val = static_cast<int>(item);
    if(val >= 97)
        return (val - 96);
    else if(val < 97 && val > 0)
        return (val - 38);
    else
        return 0;
}

int p3_1() {
    std::ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p3/rucksack.txt");
    if(fstream.is_open()) {
        std::string buf;
        int total{};

        while(std::getline(fstream, buf)) {
            std::vector<char> items;
            for (auto& ch : buf) {
                items.push_back(ch);
            }
            std::vector<char> a(items.begin(), items.begin() + items.size()/2), b(items.begin()+items.size()/2, items.end());
            char common = findCommon(a, b);
            total += convertToPriority(common);
        }
        std::cout << total << std::endl;
        fstream.close();
    }
}

int p3_2() {
    std::ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p3/rucksack.txt");
    if(fstream.is_open()) {
        std::string buf;
        int total{}, count = 1;
        std::vector<char> elf1, elf2, elf3;

        while(std::getline(fstream, buf)) {
            for (auto &ch: buf) {
                if (count == 1)
                    elf1.push_back(ch);
                else if (count == 2)
                    elf2.push_back(ch);
                else {
                    elf3.push_back(ch);
                }
            }
            if(count != 3)
                count++;
            else {
                char common = findThreeCommon(elf1, elf2, elf3);
                total += convertToPriority(common);
                count = 1;
                elf1.clear(); elf2.clear(); elf3.clear();
            }
        }
        std::cout << total << std::endl;
        fstream.close();
    }
}
#endif //ADVENT_OF_CODE_2022_P3_H
