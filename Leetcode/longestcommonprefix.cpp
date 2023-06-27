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
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string a = strs[0],e = strs[n-1],sum = "";
        for(int i=0;i<a.length();i++){
            if(a[i]==e[i]){
                sum+=a[i];
            }else{
                break;
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<string> strs={""};
    cout<<sol.longestCommonPrefix(strs);
    return 0;
}