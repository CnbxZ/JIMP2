//
// Created by Moodaway-w on 22/03/2017.
//

#include <ostream>
#include <memory>

#include "SmartTree.h"

namespace datastructures
{
    std::unique_ptr<SmartTree> CreateLeaf(int value)
    {
        auto st = std::make_unique<SmartTree>();

        st->left = nullptr;
        st->right = nullptr;
        st->value = value;

        return std::move(st);
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        if (tree) {
            tree->left = std::move (left_subtree);
        }
        return std::move(tree);
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        if (tree) {
            tree->right = std::move (right_subtree);
        }
        return std::move(tree);
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (!unique_ptr)
            return;
        PrintTreeInOrder(unique_ptr->left,out);
        (*out) << unique_ptr->value << ", ";
        PrintTreeInOrder(unique_ptr->right,out);
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        if (!tree)
            return "[none]";
        else {
            return "[" + std::to_string(tree->value) + " " + DumpTree(tree->left) + " " + DumpTree(tree->right) + "]";
        }
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        int i = 1;

        if (tree[i] == 'n' && tree[i+1] == 'o' && tree[i+2] == 'n' && tree[i+3] == 'e') {
            return nullptr;
        }

        int value = atoi(&tree[i]);

        while (tree[i] != '[') {
            i++;
        }

        int begin_left = i;

        int open_brackets = 1;
        while (open_brackets != 0) {
            i++;
            if (tree[i] == '[') {
                open_brackets++;
            }
            if (tree[i] == ']') {
                open_brackets--;
            }
        }

        int end_left = i;
        int begin_right = i+2;
        int end_right = tree.size ()-1;

        std::string left = tree.substr(begin_left, end_left-begin_left+1);
        std::string right = tree.substr(begin_right, end_right-begin_right+1);

        std::unique_ptr<SmartTree> left_subtree = RestoreTree (left);
        std::unique_ptr<SmartTree> right_subtree = RestoreTree (right);
        std::unique_ptr<SmartTree> root = CreateLeaf(value);
        root = InsertLeftChild (std::move(root), std::move(left_subtree));
        root = InsertRightChild (std::move(root), std::move(right_subtree));

        return std::move(root);
    }
}