// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct Node {
    char val;
    std::vector<Node*> children;
    explicit Node(char v) : val(v) {}
    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }
};

class PMTree {
public:
    explicit PMTree(const std::vector<char>& symbols);
    ~PMTree();
    Node* getRoot() const {
        return root;
    }

private:
    Node* root;
    void build(Node* node, const std::vector<char>& symbols);
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int index);
std::vector<char> getPerm2(PMTree& tree, int index);

#endif  // INCLUDE_TREE_H_
