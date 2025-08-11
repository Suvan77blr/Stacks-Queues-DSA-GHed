
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using vi = vector<int>;

vi getNSE(vi& arr) {
    int n = arr.size();
    vi nse(n);
    stack<int> stk;

    for(int i=n-1; i>=0; i--) {
        while(!stk.empty() && stk.top()>=arr[i]) {
            stk.pop();
        }
        nse[i] = (stk.empty()) ? -1 : stk.top();
        // if(stk.empty()) nse[i] = -1;
        // else            nse[i] = stk.top();

        stk.push(arr[i]);
    }
    return nse;
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

    vi nse = getNSE(arr);
    display(arr);
    display(nse);

    return 0;
}