class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int small = 0, total = 0;
        vector<int> index;
        for(int num : nums)
        {
            if(num < target) small++;
            else if(num == target) 
            {
                index.push_back(total);
                total++;
            }
        }
        for(int i = 0; i < total; i++)
        {
            index[i] += small;
        }
        return index;
    }
};