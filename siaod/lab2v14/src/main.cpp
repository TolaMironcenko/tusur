// Variant 14

// Задать последовательность чисел. 
// Написать программу, выполняющую построение 
// и вывод бинарного дерева на экран. 
// Для построенного дерева найти все вершины, 
// имеющие поддеревья одинаковой высоты, и для
// каждой из этих вершин вывести список потомков. 
// После выполнения программы очистить память, 
// занятую древовидной структурой.

#include <iostream>
#include <vector>
#include <queue>

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

// func for get tree height
int getHeight(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// func for find nodes with equal subtrees height
void findEqualHeightSubtrees(TreeNode* node) {
    if (!node) return;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (leftHeight == rightHeight) {
        std::cout << "Node: " << node->value << " have subtrees height: " << leftHeight << std::endl;
        std::cout << "Subtrees: ";
        std::vector<int> descendants;
        std::queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode *current = q.front();
            q.pop();
            if (current != node) {
                descendants.push_back(current->value);
            }
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        for (int val : descendants) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // recurse for left and right subtree
    findEqualHeightSubtrees(node->left);
    findEqualHeightSubtrees(node->right);
}

// func for delete tree memory
void deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// func for print tree in order
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        std::cout << root->value << " ";
        printInOrder(root->right);
    }
}

int main() {
    std::vector<int> nums = {40, 20, 60, 10, 11, 24, 46, 80, 456, 123, 789}; // example input
    TreeNode* root = nullptr;

    // create tree
    for (int num : nums) {
        root = insert(root, num);
    }

    // print order tree
    std::cout << "Order tree: ";
    printInOrder(root);
    std::cout << std::endl;

    // find equal height subtrees
    findEqualHeightSubtrees(root);

    // delete tree memory
    deleteTree(root);

    return 0;
}
