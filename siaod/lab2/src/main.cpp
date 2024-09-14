// Variant 3

// Дана последовательность чисел. 
// Построить бинарное дерево, содержащее эти числа. 
// Произвести обход дерева справа налево и вывести результаты на экран. 
// После выполнения программы очистить память, 
// занятую древовидной структурой.

#include <iostream>
#include <vector>

// struct node of binary tree
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// func to insert node to binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// func to go tree from right to left
void reverseOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // start right subtree
    reverseOrderTraversal(root->right);
    // next print node value
    std::cout << root->value << " ";
    // then left subtree
    reverseOrderTraversal(root->left);
}

// func for delete memory for tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    std::vector<int> nums = {40, 20, 60, 10, 11, 24, 46, 80, 456, 123}; // example input
    TreeNode *root = nullptr;

    // create tree
    for (int num : nums) {
        root = insert(root, num);
    }

    // go tree from right to left
    std::cout << "go tree from right to left: ";
    reverseOrderTraversal(root);
    std::cout << std::endl;

    // free memory
    deleteTree(root);
    return 0;
}
