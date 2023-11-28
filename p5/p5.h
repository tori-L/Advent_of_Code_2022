//
// Created by Tori Lim on 11/21/23.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#ifndef ADVENT_OF_CODE_2022_P5_H
#define ADVENT_OF_CODE_2022_P5_H

vector<deque<char>> crates{ {'T','R','D','H','Q','N','P','B'},
                             {'V','T','J','B','G','W'},
                             {'Q','M','V','S','D','H','R','N'},
                             {'C','M','N','Z','P'},
                             {'B','Z','D'},
                             {'Z','W','C','V'},
                             {'S','L','Q','V','C','N','Z','G'},
                             {'V','N','D','M','J','G','L'},
                             {'G','C','Z','F','M','P','T'}};

void print_crates() {
    for(auto& stack : crates) {
        for(auto& crate : stack)
            cout << crate << " ";
        cout << endl;
    }
    cout << "----------------------" << endl;
}

void move_crates(const int &amount, const int &from, const int &to) {
    for(int i = 1; i <= amount; i++) {
        char to_move = crates[from-1].front(); crates[from-1].pop_front();
        crates[to-1].push_front(to_move);
    }
}

void move_multiple_crates(const int &amount, const int &from, const int &to) {
    deque<char> temp{};
    for(int i = 1; i <= amount; i++) {
        char to_move = crates[from-1].front(); crates[from-1].pop_front();
        temp.push_front(to_move);
    }
    for(int i = 1; i <= amount; i++) {
        char to_move = temp.front(); temp.pop_front();
        crates[to-1].push_front(to_move);
    }
}

void p5_1() {
    ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p5/crates.txt");
    if(fstream.is_open()) {
        for(string instruction; getline(fstream, instruction);) {
            stringstream ss(instruction);
            vector<int> moves{};
            for(string piece; getline(ss, piece, ' ');) {
                if(isdigit(piece[0])) {
                    moves.push_back(stoi(piece));
                }
            }
            move_crates(moves[0], moves[1], moves[2]);
            moves.clear();
        }
        for(auto& stack : crates)
            cout << stack.front();
        fstream.close();
    }
}

void p5_2() {
    ifstream fstream("/Users/tori/Desktop/C++/Advent_of_Code_2022/p5/crates.txt");
    if(fstream.is_open()) {
        for(string instruction; getline(fstream, instruction);) {
            stringstream ss(instruction);
            vector<int> moves{};
            for(string piece; getline(ss, piece, ' ');) {
                if(isdigit(piece[0])) {
                    moves.push_back(stoi(piece));
                }
            }
            move_multiple_crates(moves[0], moves[1], moves[2]);
            moves.clear();
//            print_crates();
        }
        for(auto& stack : crates)
            cout << stack.front();
        fstream.close();
    }
}
#endif //ADVENT_OF_CODE_2022_P5_H
