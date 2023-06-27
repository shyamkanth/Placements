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
    int pivotIndex(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int sumL=0,sumR=0;
            for(int j=0;j<i;j++){
                sumL=sumL+nums[j];
            }
            for(int k=nums.size()-1;k>i;k--){
                sumR=sumR+nums[k];
            }
            if(sumL==sumR){
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums={1,7,3,6,5,6};
    cout<<sol.pivotIndex(nums);
    return 0;
}