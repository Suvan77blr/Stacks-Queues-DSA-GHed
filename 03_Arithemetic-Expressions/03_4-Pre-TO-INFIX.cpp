
// 110825.
/*
    PREFIX -> INFIX.
*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch);

string getInfix(const string& prefixExpr) {
    stack<string> stk;
    if (prefixExpr.empty()) return "Invalid PREFIX input!";

    for(auto it=prefixExpr.rbegin(); it!=prefixExpr.rend(); it++) {
        char ch = *it;

        if(isOperand(ch)) {
            stk.push( string(1, ch) );
        }
        else {
            if(stk.size() < 2) {
                return "Invalid PREFIX input!";
            }
            string top1 = stk.top();    stk.pop();
            string top2 = stk.top();    stk.pop();
            string tempExpr = "(" + top1 + ch + top2 + ")";
            stk.push(tempExpr);
        }
    }

    if(stk.size() != 1) {
        return "Invalid PREFIX input!";
    }
    return stk.top();
}

int main(void) {
    string prefix;
    cin >> prefix;

    cout << "Input PREFIX: " << prefix << "\n";

    string infixResult = getInfix(prefix);

    cout << "Result INFIX: " << infixResult << "\n";
}

bool isOperand(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

/*
    TCs:
    * +ab => (a+b)
    * *+abc => ((a+b)*c)
    * +a => Invalid
*/