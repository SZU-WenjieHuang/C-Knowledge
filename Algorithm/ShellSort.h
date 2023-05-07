class Solution {
public:
    /*
    希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1。
    */

    //希尔排序
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        // Get the Gap
        int gap = 1;
        while (gap < len / 3){ //保证整个数组至少被分成三份
            gap = 3 * gap + 1;
        }

        while (gap >= 1){
            for(int i = gap; i < len; i++){ //从第二组开始向前比较
                for(int j = i; j >= gap && nums[j] < nums[j-gap] ; j -= gap){
                    swap(nums[j], nums[j - gap]);
                }
            }
            gap = gap / 3;
        }
        return nums;
    }
};
