#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int k=1;
	for(int i=1; i<nums.size(); i++)        
		if(nums[i]!=nums[i-1]) {
            nums[k] = nums[i];k++;
            };     
	return k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums ={0,0,1,1,1,2,2,3,3,4,5,6,7,8,9};
    cout<<"Number of unique elements are : ";
    cout<<sol.removeDuplicates(nums);
    return 0;
}