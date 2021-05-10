class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int target = nums.size() - k;
        int start = 0;
        int end = nums.size() - 1;
        while (true) {
            int part = partition(nums, start, end);
            if (part == target) {
                return nums[target];
            } else if (part > target) {
                end = part - 1;
            } else {
                start = part + 1;
            }
        }
    }

private:
    int partition(vector<int> &nums, int start, int end) {
        int t = nums[start];
        int left = start;
        int right = end;
        while (left < right) {
            while (left < right && nums[right] >= t) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] < t) {
                left++;
            }
            nums[right] = nums[left];

        }
        nums[left] = t;
        return left;
    }

    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};