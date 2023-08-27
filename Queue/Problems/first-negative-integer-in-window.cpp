#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N,long long int K) {
    deque<int> dq;
    vector<long long> ans;

    for(int i=0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }

    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }

    for(int i=K;i<N;i++){
        if(!dq.empty() && (i-dq.front())>=K){
            dq.pop_front();
        }

        if(A[i]<0){
            dq.push_back(i);
        }

        if(dq.size()>0){
        ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }

    return ans;
                                                 
 }

int main(){
    long long int A[10000]= {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = 8;
    long long int K = 3;

    vector<long long> res = printFirstNegativeInteger(A,N,K);

    for(int i : res){
        cout<<i<<" ";
    }


    
}