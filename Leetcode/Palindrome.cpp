#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<array>
#include<list>

using namespace std;

class Solution {
public:
   bool isPalindrome(int x) {
        int counter =0;
            if(x<0){
                return false;
            }
            string s = to_string(x);
            for(int i=0;i<s.size();i++){
                if(s[i]==s[s.size()-i-1]){
                    counter++;
                }
            }
            if(s.size()==counter){
                return true;
            }
        return false;
        }
};

int main()
{
    Solution pal;
    cout<<pal.isPalindrome(100);
    return 0;
}