
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>
#include<map>
#include<queue>

using namespace std;

string firstNrc(string st){
    map<char,int> mp;
    string res="";
    queue<char> q; 
    
    for(int i=0;i<st.length();i++){
        char ch = st[i];
        mp[ch]++;
        q.push(ch);

        while(!q.empty()){
            if(mp[q.front()]>1){ //The character is repeating
                q.pop();
            }else{ //Character is non-repeating
                res.push_back(q.front());
                break;
            }
        }
        if(q.empty()){ //if queue is empty
            res.push_back('#');
        }
    }

    return res;
}

int main()
{
    string st = "aabc";
    string ans = firstNrc(st);
    cout<<ans;
    return 0;
}