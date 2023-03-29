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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        //The following is my own solution implementation using queue, it has a time complexity of O(N) and space complexity of O(1)
        
        /*The idea is to find the middle element of the array and make it the root of the tree, then perform the same operation on the left subarray for the root's left child nad the same operation on the right subarray for the root's left child. */

        int n = nums.size();
        int mid = n / 2;

        

        //initialize our root node
        TreeNode* root = new TreeNode{nums[mid], NULL, NULL};  //initially, the left and right pointer's value is nullptr
        //initialize queue
        queue<pair<TreeNode*, pair<int, int>>> q;
        //push the root and its indices to the queue
        q.push({root, {0, mid - 1}});  //this represents left node
        q.push({root, {mid+1, n-1}});  //this represents the right node

        while (!q.empty())  //while the queue hasn't been emptied yet
        {
            //get the front element from the queue, as in the value inserted first
            pair<TreeNode*, pair<int, int>> curr = q.front();
            q.pop();

            //get the parent node and its indices
            TreeNode* parent = curr.first;  //initialize another node here and set it to the value of the root node we defined previously
            int left = curr.second.first;
            int right = curr.second.second;

            //if there are elements to process and parent node is not nullptr
            if (left <= right && parent != NULL) {
                int mid = (left + right) / 2;
                TreeNode* child = new TreeNode{nums[mid], NULL, NULL};
                //if there are elements to process and parent node is not NULL
                if (nums[mid] < parent->val)  //if the root value is less than the current node value
                {
                    parent->left = child;  //move right and set the new value to taht of the child node
                }
                else {  //in the case that nums[mid] > parent->val
                    parent->right = child;  //move right and set the new value to taht of the child node
                }
                // push the left and right child and their indices to the queue
                q.push({child, {left, mid-1}});
                q.push({child, {mid+1, right}});
            }
        }
        return root;
    }
};
