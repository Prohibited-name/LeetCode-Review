#include <queue>
#include <map>
using namespace std;
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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)return 0;
        return rootSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int rootSum(TreeNode* root, int targetSum) {
        if (root == nullptr)return 0;
        int ret = root->val == targetSum?1:0;
        return ret + rootSum(root->left, targetSum - root->val) + rootSum(root->right, targetSum - root->val);
    }

};