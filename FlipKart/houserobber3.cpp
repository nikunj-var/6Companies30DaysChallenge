#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int solve(unordered_map<TreeNode *, int> &m, TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int ans = root->val;
        if (m[root])
        {
            return m[root];
        }
        if (root->left)
        {
            ans += (solve(m, root->left->left) + solve(m, root->left->right));
        }
        if (root->right)
        {
            ans += (solve(m, root->right->left) + solve(m, root->right->right));
        }

        return m[root] = max(ans, (solve(m, root->left) + solve(m, root->right)));
    }
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> mp;
        return solve(mp, root);
    }
};
