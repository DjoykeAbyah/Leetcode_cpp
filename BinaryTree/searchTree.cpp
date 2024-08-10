#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
			return nullptr;
		else if (root->val == val)
			return root;
		else if (val < root->val)
			return searchBST(root->left, val);
		else 
			return searchBST(root->right, val);
    }
};

// Helper function to print the tree
void printTree(TreeNode* node, int space = 0, int indent = 4) {
    if (node == nullptr)
        return;

    // Increase the space between levels
    space += indent;

    // Print the right child first (this will be on top in the output)
    printTree(node->right, space);

    // Print the current node after space
    std::cout << std::endl;
    for (int i = indent; i < space; i++)
        std::cout << " ";
    std::cout << node->val << "\n";

    // Print the left child (this will be below in the output)
    printTree(node->left, space);
}

int main() {
	Solution solution;

	TreeNode *node4 = new TreeNode(5);
	TreeNode *node5 = new TreeNode(2);
	TreeNode *node6 = new TreeNode(7);

	TreeNode *node3 = new TreeNode(1, node4, node5);
	TreeNode *node2 = new TreeNode(6, node6, nullptr);

	TreeNode *root = new TreeNode(8, node3, node2);

	std::cout << "Root: " << root->val << std::endl;
    std::cout << "Left child of root: " << root->left->val << std::endl;
    std::cout << "Right child of root: " << root->right->val << std::endl;

	printTree(root);

	TreeNode *test = solution.searchBST(root, 1);

	if (test != nullptr) {
        std::cout << "\nNode with value " << 1 << " found. Subtree rooted at this node:\n";
        printTree(test);
    } else {
        std::cout << "Node with value " << value_to_search << " not found.\n";
    }

	return 0;
}