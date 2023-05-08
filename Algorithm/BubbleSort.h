/*

（无序区，有序区）。从无序区通过交换找出最大元素放到有序区前端。

选择排序思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

*/

// 冒泡排序
void BubbleSort(vector<int>& v) {
	int len = v.size();
	for (int i = 0; i < len - 1; ++i)
		for (int j = 0; j < len - 1 - i; ++j)
			if (v[j] > v[j + 1]) 
				swap(v[j], v[j + 1]);
}

// 模板实现冒泡排序
template<typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定大於(>)的運算子功能
void bubble_sort(T arr[], int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

//Patrick's 冒泡改进版
class Solution {
public:
    /*
    改进之后的冒泡排序，就是加了一个，要是发现某一次都是顺序的，那就不继续下去排序了
    */
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        bool orderly = false; //要是某一次都是顺序了，那就不用再继续了
        for(int i = 0; i <  len - 1 && orderly == false; i++){
            for(int j = 0; j < len - 1 - i; j++){ //注意边界条件 外层遍历了i之后，倒数的i个就是已经sort的了
                if(nums[j] > nums[j + 1]){
                    orderly = false;
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return nums;
    }
};
