

// 110825.
/*
    POSTFIX -> PREFIX.
*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch);

string getPrefix(const string& postfixExpr) {
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
            string tempExpr = ch + top2 + top1;
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

    string prefixResult = getPrefix(postfix);

    cout << "Result PREFIX: " << prefixResult << "\n";
}

bool isOperand(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

/*
    TCs:
    * ab+ => +ab
    * abc*+ => +a*bc
    * ab+cde+** => *+ab*c+de
*/