// Next smaller element
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include<algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> res;
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (!st.empty() && st.top() >= curr) {
            st.pop();
        }
        res.push_back(st.top());
        st.push(curr);
    }

    // Reverse the vector 'res' to get the correct order
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    vector<int> arr = {2, 3, 1};
    vector<int> result = nextSmallerElement(arr, 3);

    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}

