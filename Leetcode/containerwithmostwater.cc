#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<array>
#include<list>

using namespace std;

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int area=0,newarea=0;
//         for(int i=0;i<height.size();i++){
//             for(int j=i;j<height.size();j++){
//                 int width = j-i;
//                 newarea = height[i]>height[j]?height[j]*width : height[i]*width;
//                 area = area>newarea? area:newarea;
//             }
//         }
//         return area;
//     }
// };
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int width = j - i;
            int h = min(height[i], height[j]);
            area = max(area, width * h);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return area;
    }
};

int main()
{
    Solution sol;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<sol.maxArea(height);
    return 0;
}