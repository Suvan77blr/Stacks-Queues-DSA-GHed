
// 100825.
/*
    INFIX -> PREFIX.
*/

#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch);
bool isOperand(char ch);
void prepareExpression(string& expr);       // Func to reverse and '(' -> ')' & vice-versa.

// CORE-Function.
string getPrefix(string& expr) {
    prepareExpression(expr);
    string ans = "";
    stack<char> stk;

    for(char ch: expr) {
        if(isOperand(ch)) {     ans += ch;      }
        else if(ch == '(') {    stk.push(ch);   }
        else if(ch == ')') {
            while(stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }
            stk.pop(); // Popping the '('.
        }

        else { // ch is now operator.
            if(ch == '^') { // spl R->L associativity.
                while( !stk.empty() && stk.top() != '(' && 
                    precedence(ch) <= precedence(stk.top()) )
                {     ans += stk.top(); stk.pop();    }
            }
            else {
                while (!stk.empty() && stk.top()!='(' && 
                    precedence(ch) < precedence(stk.top()) )
                {     ans += stk.top(); stk.pop();    }
            }
            stk.push(ch);
        }
    }

    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    prepareExpression(ans);
    return ans;
}

int main(void) {
    // int tcs; cin >> tcs;
    // int i=1;
    // while(i <= tcs) {
    
    string expr;
    cin >> expr;

    cout << "Orig expr: ";
    for(char ch: expr) cout << ch << " ";
    
    string prefix = getPrefix(expr);
    cout << "\nPREFIX : ";
    for(char ch: prefix) cout << ch << " ";
    
    // cout << i << ": " << prefix << "\n";
    // i++;
    // }
    return 0;
}


void prepareExpression(string& expr) {
    int left=0, right=expr.size()-1;
    while(left <= right) {
        swap(expr[left], expr[right]);
        left++; right--;
    }

    for(char& ch: expr) {
        if(ch == '(') ch = ')';
        else if(ch == ')') ch = '(';
    }
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '%' || ch == '/' || ch == '*') return 2;
    if (ch == '+' || ch == '-') return 1;
    else return 0;
}

bool isOperand(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}