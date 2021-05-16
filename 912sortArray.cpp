class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        qSort(nums, 0, (int) (nums.size() - 1));
        return nums;
    }

private:
    void qSort(vector<int> &nums, int start, int end) {  //得要随机找基准才行，不然超时呀。。
        if (start < end) {
            int p = randomized_partition(nums, start, end);
            qSort(nums, start, p - 1);
            qSort(nums, p + 1, end);
        }
    }

    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[l], nums[i]);
        return partition(nums, l, r);
    }

    int partition(vector<int> &nums, int start, int end) {
        int base = nums[start];
        int l = start;
        int r = end;
        while (l < r) {
            while (l < r && nums[r] >= base) r--;
            while (l < r && nums[l] <= base) l++;
            swap(nums[l], nums[r]);
        }
        swap(nums[start], nums[l]);
        return l;
    }

    void swap(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
};