#### 快排和归并排序

我们知道冒泡排序的时间复杂度为O(n^2)，所以有归并排序和快排，归并排序的时间复杂度为稳定的O(nlogn),快排的时间复杂度为不稳定的O(nlogn),最好为O(n)，最坏为O(n^2)。但是归并排序需要额外的空间

归并排序	

```c++
class Solution {
public:
    void merge(vector<int> &nums, int left, int mid, int right)
   {
	if (left >= right)
		return;
	vector<int> tmp;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (nums[i] < nums[j])
		{
			tmp.push_back(nums[i]);
			i++;
		}
		else if (nums[i] >= nums[j])
		{
			tmp.push_back(nums[j]);
			j++;
		}
	}
	while (i <= mid)
	{
		tmp.push_back(nums[i]);
		i++;
	}
	while (j <= right)
	{
		tmp.push_back(nums[j]);
		j++;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		nums[i+left] = tmp[i];
	}
}
     void  merge_sort(vector<int> &nums,int left,int right)
     {
         if(left>=right)
         return;
        int mid=left+(right-left)/2;
        merge_sort(nums,left,mid);
        merge_sort(nums,mid+1,right);
        merge(nums,left,mid,right);
     }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};
```

快排

```c++
class Solution {
public:
   void quick_sort(vector<int>& nums,int left,int right) 
   {
        if(left>=right)
        return;
        int i=left;
        int j=right;
        while(i<j)
        {
            // j向左走，找出比nums[left]小的数
             while(nums[j]>nums[left]&&i<j)
                 j--;   
            //i向右走，找出比nums[left]大的数
            while(nums[i]<=nums[left]&&i<j)
                 i++; 
            if(i<j)    
             swap(nums[i],nums[j]);
        }
        swap(nums[left],nums[i]);
        quick_sort(nums,left,i-1);
        quick_sort(nums,i+1,right);
   }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
        return nums;
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
};
```

#### [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

​	在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 

```c++
class Solution {
public:
void quick_sort(vector<int>& nums, int left, int right,int k)
{
    //从大到小排列
    if(left>=right)
    return;
    int i=left,j=right;
    while(i<j)
    {
        //从right向左找出大于nums[left]
        while(i<j&&nums[j]<nums[left])
        {
            j--;
        }
         //从left向右找出小于nums[left]
        while(i<j&&nums[i]>=nums[left])
        {
            i++;
        }
        if(i<j)
        swap(nums[i],nums[j]);
    }
        swap(nums[left], nums[i]);
	if (i - left + 1 == k)
		return;
	if (i - left + 1 > k)
		quick_sort(nums, left, i - 1, k);
	else
		quick_sort(nums, i + 1, right, k - (i-left)-1);
}
    int findKthLargest(vector<int>& nums, int k) {
       //使用快排
       quick_sort(nums,0,nums.size()-1,k);
       return nums[k-1];
        /*
      priority_queue<int> pq;
      for(auto e:nums)
      pq.push(e);
      for(int i=0;i<k-1;i++)
      {
          pq.pop();
      }
      return pq.top();
    }
    */
    /*
     sort(nums.begin(), nums.end(), greater<int>());
     return nums[k-1];
     */
    }
};
```

