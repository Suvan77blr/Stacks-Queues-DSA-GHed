
// 160825.
/*
    Sum of Subarray Minimums.
        - Using nseIdx[] & pseeIdx[].
        - Contribution of each element:
            => total = (total + (1LL * left * right * ele)%MOD )%MOD
            left = idx - pseIdx[idx]
            right = nseIdx[idx] - idx
*/

#include <iostream>
#include <vector>
#include <stack>
using vi = vector<int>;

const int MOD = 1e9+7;

vi getNseIdx(vi& arr);
vi getPseeIdx(vi& arr);

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