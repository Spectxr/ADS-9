// Copyright 2022 NNTU-CS
#include <algorithm>
#include <vector>
#include  "tree.h"

int factorial(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

void collectPerms(Node* node, std::vector<char>& path, std::vector<std::vector<char>>& output) {
    path.push_back(node->val);
    if (node->children.empty()) {
        output.push_back(path);
    } else {
        for (Node* child : node->children) {
            collectPerms(child, path, output);
        }
    }
    path.pop_back();
}

PMTree::PMTree(const std::vector<char>& symbols) {
    root = new Node('\0');
    build(root, symbols);
}

PMTree::~PMTree() {
    delete root;
}

void PMTree::build(Node* node, const std::vector<char>& symbols) {
    if (symbols.empty()) {
        return;
    }
    std::vector<char> sorted = symbols;
    std::sort(sorted.begin(), sorted.end());
    for (size_t i = 0; i < sorted.size(); ++i) {
        char c = sorted[i];
        Node* child = new Node(c);
        node->children.push_back(child);
        std::vector<char> next = sorted;
        next.erase(next.begin() + i);
        build(child, next);
    }
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    std::vector<std::vector<char>> all;
    Node* root = tree.getRoot();
    std::vector<char> path;
    for (Node* child : root->children) {
        collectPerms(child, path, all);
    }
    return all;
}

std::vector<char> getPerm1(PMTree& tree, int index) {
    auto perms = getAllPerms(tree);
    if (index <= 0 || index > static_cast<int>(perms.size())) {
        return {};
    }
    return perms[index - 1];
}

std::vector<char> getPerm2(PMTree& tree, int index) {
    Node* root = tree.getRoot();
    if (!root) {
        return {};
    }
    std::vector<char> symbols;
    for (Node* child : root->children) {
        symbols.push_back(child->val);
    }
    int n = static_cast<int>(symbols.size());
    int total = factorial(n);
    if (index <= 0 || index > total) {
        return {};
    }
    int idx = index - 1;
    std::vector<char> result;
    result.reserve(n);
    for (int k = n; k >= 1; --k) {
        int blockSize = factorial(k - 1);
        int pos = idx / blockSize;
        idx %= blockSize;
        result.push_back(symbols[pos]);
        symbols.erase(symbols.begin() + pos);
    }
    return result;
}
