class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int len = nums.size();  //注意size是无符号数
        if(len == 0) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                    res.push_back(vector<int>{nums[left], nums[right], nums[i]});
                    while(left < right && nums[left] == nums[left + 1]) left++; //这里也需要去重
                    while(left < right && nums[right] == nums[right - 1]) right--; 
                    left++;
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};