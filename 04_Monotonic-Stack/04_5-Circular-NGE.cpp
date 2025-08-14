
// 140825.
/*
    Circular NGE version.
        - Ver1: Using for(i:2n-1 -> 0) 
        - Ver2: Using 2 for loops with idx = (i+j) %n
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using vi = vector<int>;

void display(vi& arr, int n);

vi getNGE_Circular_ver1(vi& arr, int n) {
    vi nge(n, -1);
    stack<int> stk;

    for(int i=2*n-1; i>=0; i--) {
        int idx = (i%n);
        while(!stk.empty() && stk.top() <= arr[idx]) {
            stk.pop();
        }

        if(i < n) {
            nge[i] = stk.empty() ? -1 : stk.top();
        }
        stk.push(arr[idx]);
    }
    return nge;
}

vi getNGE_Circular_ver2(vi& arr, int n) {
    vi nge (n, -1);
    for(int i=0; i<n; i++) {
        for(int j=1; j<n; j++) {
            int idx = (i+j)%n;
            if(arr[idx] > arr[i]) {
                nge[i] = arr[idx];
                break;
            }
        }
    }
    return nge;
}

int main(void) {
    int n; 
    cin >> n;

    vi arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Orig Vec: "; display(arr, n);
    
    vi nge = getNGE_Circular_ver1(arr, n);
    // vi nge = getNGE_Circular_ver2(arr, n);

    cout << "NGE: "; display(nge, n);
    return 0;
}

void display(vi& arr, int n) {
    cout << "[ ";
    for(int ele: arr) {     cout << ele << " ";     }
    cout << "]\n";
    
}