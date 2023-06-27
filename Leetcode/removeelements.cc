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
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int i=0;i<k;i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                k--;
                i--;
            }
        }
        return k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums={1,2,3,4};
    int val = 4;
    cout<<sol.removeElement(nums,val);
    return 0;
}