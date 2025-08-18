
// 160825.
/*
    Sum of Subarray Maximums.
        - Using ngeIdx[] & pgeeIdx[].
        - Contribution of each element:
            => total = (total + (1LL * left * right * ele)%MOD )%MOD
            left = idx - pgeIdx[idx]
            right = ngeIdx[idx] - idx
*/

#include <iostream>
#include <vector>
#include <stack>
using vi = vector<int>;

const int MOD = 1e9+7;

vi getNseIdx(vi& arr);
vi getNgeIdx(vi& arr);
vi getPseeIdx(vi& arr);
vi getPgeeIdx(vi& arr);

long long sumOfSubArrMinimums(vi& arr) {
    int n = arr.size();
    vi nseIdx = getNseIdx(arr);
    vi pseeIdx = getPseeIdx(arr);
    long long total = 0LL;

    for(int i=0; i<n; i++) {
        int left = i - pseeIdx[i];
        int right = nseIdx[i] - i;
        total = (total + (1LL * left * right * arr[i]) %MOD) %MOD;
    }
    return total;
}

int main(void) {
    int n;  cin >> n;

    vi arr (n);
    for(int i=0; i<n; i++) {    cin >> arr[i];  }

    long long sumOfSubArrMinimums = getSubArrMin_Sums(arr);
    cout << "Sum of Sub-Array Minimums: " << sumOfSubArrMinimums << "\n";

    return 0;
}

vi getNseIdx(vi& arr) {
    int n = arr.size();
    vi nseIdx (n, n);
    stack<int> stk;

    for(int i = n-1; i>=0; i--) {
        while(!stk.empty() && arr[stk.top()] >= arr[i]) {
            stk.pop();
        }

        nseIdx[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    return nseIdx;
}

vi getNgeIdx(vi& arr) {
    int n = arr.size();
    stack<int> st;
    vi ngeIdx (n, n);

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        ngeIdx[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ngeIdx;
}

vi getPseeIdx(vi& arr) {
    int n = arr.size();
    stack<int> stk;
    vi pseeIdx (n, -1);

    for(int i=0; i<n; i++) {
        while(!stk.empty() && arr[stk.top()] > arr[i]) {
            stk.pop();
        }
        pseeIdx[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    return pseeIdx;
}

vi getPgeeIdx(vi& arr) {
    int n = arr.size();
    stack<int> stk;
    vi pgeeIdx (n, -1);

    for(int i=0; i<n; i++) {
        while(!stk.empty() && arr[stk.top()] < arr[i]) {
            stk.pop();
        }
        pgeeIdx[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    return pgeeIdx;
}