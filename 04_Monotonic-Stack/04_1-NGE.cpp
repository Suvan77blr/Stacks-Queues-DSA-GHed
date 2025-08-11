
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using vi = vector<int>;

vi getNGE(vi& arr) {
    int n = arr.size();
    vi nge(n);
    stack<int> stk;

    for(int i=n-1; i>=0; i--) {
        while(!stk.empty() && stk.top()<=arr[i]) {
            stk.pop();
        }
        nge[i] = (stk.empty()) ? -1 : stk.top();
        // if(stk.empty()) nge[i] = -1;
        // else            nge[i] = stk.top();

        stk.push(arr[i]);
    }
    return nge;
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

    vi nge = getNGE(arr);
    display(arr);
    display(nge);

    return 0;
}