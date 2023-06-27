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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j])==target){
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
        }
        return temp;
    }
};

int main()
{
    Solution sol;
    vector<int> nums={1,5,3,2,4};
    int target = 7;
    vector<int> result = sol.twoSum(nums,target);
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}