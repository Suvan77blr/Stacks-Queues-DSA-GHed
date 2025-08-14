
// 150825.
/*
    Trapping Rainwater.
        - Soln1: Two-Pointers.
        - Soln2: Prefix-Max & SUffix-Max arrays.
*/

#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
void displayVec(vi& arr);

// Solution1: Two-Pointers.
int getTotalWaterAmt_Soln1(vi& heights, int n) {
    int left = 0, right = n-1;
    int totalAmt = 0, leftMax = 0, rightMax = 0;

    while(left <= right) {
        if(leftMax <= rightMax) {
            if(leftMax > heights[left]) {
                totalAmt += leftMax - heights[left];
            }
            else {
                leftMax = heights[left];
            }
            left++;
        }
        else {
            if(rightMax > heights[right]) {
                totalAmt += rightMax - heights[right];
            }
            else {
                rightMax = heights[right];
            }
            right--;
        }
    }
    return totalAmt;
}

// Solution2: Prefix-Max & Suffix-Max.
vi getPrefixMax(vi& arr);
vi getSuffixMax(vi& arr);

int getTotalWaterAmt_Soln2(vi& heights, int n) {
    int totalAmt = 0, leftMax, rightMax;
    vi prefixMax = getPrefixMax(heights);
    vi suffixMax = getSuffixMax(heights);

    for(int i=0; i<n; i++) {
        leftMax = prefixMax[i];
        rightMax = suffixMax[i];
        if(heights[i] < leftMax && heights[i] < rightMax) {
            totalAmt += min(leftMax, rightMax) - heights[i];
        }
    }
    return totalAmt;
}

int main(void) {
    int n;
    cin >> n;

    vi heights(n);
    for(int i=0; i<n; i++) {
        cin >> heights[i];
    }

    cout << "Input: "; displayVec(heights);

    int waterLoggedAmt = getTotalWaterAmt_Soln1(heights, n);
    // int waterLoggedAmt = getTotalWaterAmt_Soln2(heights, n);
    cout << "Water Logged: " << waterLoggedAmt << "\n";
    
    return 0;
}

void displayVec(vi& arr) {
    cout << "[ ";
    for(int ele: arr) {  cout << ele << " ";    }
    cout << "]\n";
}

vi getPrefixMax(vi& arr) {
    int n = arr.size();
    vi prefixMax (n, 0);
    prefixMax[0] = arr[0];

    for(int i=1; i<n; i++) {
        prefixMax[i] = max(prefixMax[i-1], arr[i]);
    }
    cout << "PrefixMax: "; displayVec(prefixMax);
    return prefixMax;
}

vi getSuffixMax(vi& arr) {
    int n = arr.size();
    vi suffixMax (n, 0);
    suffixMax[n-1] = arr[n-1];

    for(int i=n-2; i>=0; i--) {
        suffixMax[i] = max(suffixMax[i+1], arr[i]);
    }
    cout << "SuffixMax: "; displayVec(suffixMax);
    return suffixMax;
}

/*
    TCs:
    1. 12, [ 0 1 0 2 1 0 1 3 2 1 2 1 ] => 6.
    2. 6, [4 2 0 3 2 5] => 9
*/