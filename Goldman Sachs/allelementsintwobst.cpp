#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
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
    void inordertraversal(TreeNode *root, vector<int> &store)
    {
        if (!root)
            return;
        inordertraversal(root->left, store);
        store.push_back(root->val);
        inordertraversal(root->right, store);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        inordertraversal(root1, v1);
        inordertraversal(root2, v2);
        vector<int> ans;
        int m = v1.size(), n = v2.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (v1[i] <= v2[j])
            {
                ans.push_back(v1[i]);
                i++;
            }
            else
            {
                ans.push_back(v2[j]);
                j++;
            }
        }
        while (i < m)
        {
            ans.push_back(v1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
};