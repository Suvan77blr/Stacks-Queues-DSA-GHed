
// 130825.
/*
    Previous Greater Element => Monotonic Decreasing Stk.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using vi = vector<int>;

vi getPGE(vi& arr) {
    const int n = arr.size();
    stack<int> stk;
    vi pge (n);

    for(int i=0; i<n; i++) {
        while(!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }
        pge[i] = (stk.empty()) ? -1 : stk.top();
        stk.push(arr[i]);
    }
    return pge;
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

    vi pge = getPGE(arr);
    display(arr);
    display(pge);

    return 0;
}