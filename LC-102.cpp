/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time = O(n)

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> ans; // level order is BFS traversal
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        int len;
        while (!q.empty())
        {
            len = q.size();
            vector<int> v;
            for (int i = 0; i < len; i++)
            {
                temp = q.front();
                q.pop();
                v.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

/* Recursive Solution

(DFS Traversal) space: O(2^logn)  time = O(n)

We can also use a DFS traversal to solve this problem. Here, we would need to maintain a depth variable that tells us the current depth we are at. This allows us to push the current node into the ans vector at its correct depth (ans[depth])

At each depth, if this is the first time we are visting this deep, then push an empty vector into ans. This would allow us to index the current depth and push the node into ans at its correct depth. Then continue with the DFS traversal as usual

vector<vector<int> > ans;
vector<vector<int>>& levelOrder(TreeNode* root, int depth = 0) {
    if(!root) return ans;
    if(depth == size(ans)) ans.push_back({});
    ans[depth].push_back(root -> val);
    levelOrder(root -> left, depth + 1);
    levelOrder(root -> right, depth + 1);
    return ans;
}

*/