
// 130825.
/*
    Previous Smaller Element => Monotonic Increasing Stk.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using vi = vector<int>;

vi getPSE(vi& arr) {
    int n = arr.size();
    stack<int> stk;
    vi pse(n);

    for(int i=0; i<n; i++) {
        while(!stk.empty() && stk.top() >= arr[i]) {
            stk.pop();
        }
        pse[i] = stk.empty() ? -1 : stk.top();
        stk.push(arr[i]);
    }
    return pse;
}

void display(const vi& arr) {
    cout << "[ ";
    for(const int ele: arr) { cout << ele << " ";  }
    cout << "]\n";
}

int main(void) {
    int n; 
    cin >> n;

    vi arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vi pse = getPSE(arr);
    display(arr);
    display(pse);

    return 0;
}