

// 110825.
/*
    PREFIX -> POSTFIX.
*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch);

string getPostfix(const string& prefixExpr) {
    stack<string> stk;
    if (prefixExpr.empty()) return "Invalid PREFIX input!";

    for(auto it = prefixExpr.rbegin(); it != prefixExpr.rend(); it++) {
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
            string tempExpr = top1 + top2 + ch;
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

    string postfixResult = getPostfix(prefix);

    cout << "Result POSTFIX: " << postfixResult << "\n";
}

bool isOperand(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

/*
    TCs:
    * +ab => ab+
    * +a*bc => abc*+
    * *+ab*c+de => ab+cde+**
*/