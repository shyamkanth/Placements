#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<array>
#include<list>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = nums[0];
        vector<int> sums;
        sums.push_back(sum);
        for(int i =1;i<nums.size();i++){
            sum = sum+nums[i];
            sums.push_back(sum);
        }
        return sums;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> sums = sol.runningSum(nums);
    for(int i=0;i<sums.size();i++){
        cout<<sums[i]<<" ";
    }
    return 0;
}