
// 110825.
/*
    POSTFIX -> INFIX.
*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch);

string getInfix(const string& postfixExpr) {
    stack<string> stk;
    if (postfixExpr.empty()) return "Invalid POSTFIX input!";

    for(char ch: postfixExpr) {
        if(isOperand(ch)) {
            stk.push( string(1, ch) );
        }
        else {
            if(stk.size() < 2) {
                return "Invalid POSTFIX input!";
            }
            string top1 = stk.top();    stk.pop();
            string top2 = stk.top();    stk.pop();
            string tempExpr = "(" + top2 + ch + top1 + ")";
            stk.push(tempExpr);
        }
    }

    if(stk.size() != 1) {
        return "Invalid POSTFIX input!";
    }
    return stk.top();
}

int main(void) {
    string postfix;
    cin >> postfix;

    cout << "Input POSTFIX: " << postfix << "\n";

    string infixResult = getInfix(postfix);

    cout << "Result INFIX: " << infixResult << "\n";
}

bool isOperand(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

/*
    TCs:
    * ab+ => (a+b)
    * abc*+ => (a+(b*c))
    * ab+cde+** => ((a+b)*(c*(d+e)))
*/