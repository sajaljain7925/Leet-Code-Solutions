class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        ans.push_back(cur_ans);
        for (int i = 0; i < nums.size(); i++) {
            int cur_ans_size = ans.size();
            for (int j = 0; j < cur_ans_size; j++) {
                cur_ans = ans[j];
                cur_ans.push_back(nums[i]);
                ans.push_back(cur_ans);
            }
        }
        return ans;
    }
};