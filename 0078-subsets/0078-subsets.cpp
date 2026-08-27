class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& nums, int n, int m, int k)
    {
        if(m >= k) return;
        for(int i = 0; i < n; i++)
        {
            vector<int> temp = ans[i];
            temp.push_back(nums[m]);
            ans.push_back(temp);
        }
        fun(ans, nums, n * 2, m + 1, k);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        fun(ans, nums, 1, 0, nums.size());
        return ans;
    }
};