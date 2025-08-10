
// 100825.
/*
    Balanced Parenthesis: 
        - Given is a string w/ just '(', ')', '[', ']', '{', and '}'.
        - Determine if the given string is valid or not.

        - Conditions: Opening brackets must be closed by the same type.
                      Order must be preserved in the closing brackets.

        - Rough Soln: Use of Stack.
            > Any OPENING: push it.
            > Any closing: 
                            IF stk is currently empty => FALSE.
                            Else, get TOP and compare.
                                IF Different Type => FALSE.
                                ELSE pop and continue.
            > End of String:
                            IF STK is not empty => FALSE.
            Otherwise: TRUE.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool parenthesisChecker(string& str) {
        stack<char> stk;

        for(char ch: str) {
            if(ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            }

            else {
                // Now a closing bracket is encountered.
                if( stk.empty() ) return false;

                char topCh = stk.top();
                if( ch==')' && topCh != '(' || 
                    ch==']' && topCh != '[' ||
                    ch=='}' && topCh != '{' ) 
                {   return false;     }

                stk.pop();
            }
        }

        return stk.empty();
    }
};

int main(void) {
    string s;
    cin >> s;

    bool result = Solution().parenthesisChecker(s);
    cout << "Balanced Parenthesis String?: " << (result ? "YES\n" : "NO\n");

    return 0;
}

/*
    TCs:
        * ()[{}()]
        * ()[{}(])
        * )]
        * {{}
        * ([]{
*/