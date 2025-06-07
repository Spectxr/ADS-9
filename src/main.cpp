// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include "tree.h"

int main() {
    std::vector<char> symbols = { '1', '2', '3', '4'};
    PMTree tree(symbols);
    std::vector<std::vector<char>> perms = getAllPerms(tree);
    std::cout << "All permutations:\n";
    int i = 1;
    for (const auto& perm : perms) {
        std::cout << i++ << ": ";
        for (char c : perm) {
            std::cout << c;
        }
        std::cout << '\n';
    }
    int num = 1;
    std::vector<char> perm1 = getPerm1(tree, num);
    std::vector<char> perm2 = getPerm2(tree, num);
    std::cout << "\nPermutation " << num << " using getPerm1: ";
    for (char c : perm1) {
        std::cout << c;
    }
    std::cout << "\n";
    std::cout << "Permutation " << num << " using getPerm2: ";
    for (char c : perm2) {
        std::cout << c;
    }
    std::cout << "\n";
    return 0;
}
