
// 100825
/*
    INFIX -> POSTFIX.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch);
bool isOperand(char ch);

string getPostfix(string& expr) {
    string ans = "";
    stack<char> stk;
    for(char ch: expr) {
        if(isOperand(ch)) {
            ans += ch;
        }

        else if(ch=='(') {
            stk.push(ch);
        }

        else if(ch == ')') {
            while(stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }
            stk.pop();  // Removing the '(';
        }
        else {  // ch is operator.
            while( !stk.empty() && stk.top() != '('
                    && (precedence(ch) <= precedence(stk.top()))  )
            {   
                ans += stk.top();
                stk.pop();
            }
            stk.push(ch);
            // if(stk.empty() || (precedence(stk.top()) < precedence(ch))) {
            //     stk.push(ch);
            // }
        }
    }
    
    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

int main(void) {
    string expr;
    cin >> expr;

    cout << "Orig expr: ";
    for(char ch: expr) cout << ch << " ";
    
    string postfix = getPostfix(expr);
    cout << "\nPOSTFIX : ";
    for(char ch: postfix) cout << ch << " ";

    return 0;
}

int precedence(char ch) {
    switch(ch) {
        case '^': return 3;
        case '%': 
        case '/': 
        case '*': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

bool isOperand(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

/*
    TCs:
    * a+b*c
    * (a+b)*c
    * a+b*(C^d-e)
*/