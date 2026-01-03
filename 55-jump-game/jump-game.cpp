class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        int i = 0;
        while (i <= cur) {
            if (cur >= nums.size() - 1)
                return true;
            cur = max(cur, i + nums[i]);
            i += 1;
        }
        return false;
    }
};
