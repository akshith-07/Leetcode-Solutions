class Solution 
{
private:
    TreeNode* createTree(int start,int end,vector<int>&vec)
    {
        if(start > end) return NULL;

        int midPoint = (start+end)/2;
        TreeNode* root = new TreeNode(vec[midPoint]);
        root->left = createTree(start,midPoint-1,vec);
        root->right = createTree(midPoint+1,end,vec);

        return root;
    }
    void fillArray(vector<int> & vec,TreeNode * root)
    {
        if(!root) return ;
        fillArray(vec,root->left);
        vec.push_back(root->val);
        fillArray(vec,root->right);
    }
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> vec;
        fillArray(vec,root);
        return createTree(0,vec.size()-1,vec);        
        return root;
    }
};
auto init = []() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();