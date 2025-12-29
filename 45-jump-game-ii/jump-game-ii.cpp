class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur1 = 0;
        int cur2 = 0;  
        for (int i = 0; i < nums.size(); i++) {
            if (cur1 < i) {
                cur1 = cur2;
                ans += 1;
            }
            cur2 = max(cur2, i + nums[i]);
        }
        return ans;
    }
};