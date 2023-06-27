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
    int romanToInt(string s) {
        int n = s.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            switch(s[i]){
                case 'I':
                    v[i]=1;
                    break;
                case 'V':
                    v[i]=5;
                    break;
                case 'X':
                    v[i]=10;
                    break;
                case 'L':
                    v[i]=50;
                    break;
                case 'C':
                    v[i]=100;
                    break;
                case 'D':
                    v[i]=500;
                    break;
                case 'M':
                    v[i]=1000;
                    break;
                default:
                    return 0;
            }
        }
        int sum =0;
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1] || v[i]==v[i+1]){
                sum = sum+v[i];
            }else{
                sum = sum-v[i];
            }
        }
        sum = sum+v[n-1];
        return sum;
    }
};

int main()
{
    Solution sol;
    cout<<sol.romanToInt("LVIII");
    return 0;
}