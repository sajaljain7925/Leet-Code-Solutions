class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left, right;
        
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid] &&
                (mid == 0 || target != nums[mid - 1])) {
                ans.push_back(mid);
                break;
            } else if (target <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        // search for ending position
        left = ans[0];
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid] &&
                (mid == nums.size() - 1 || target != nums[mid + 1])) {
                ans.push_back(mid);
                break;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};