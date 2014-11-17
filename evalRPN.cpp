#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> expr;
        int result = 0;
        for (size_t i = 0; i < tokens.size(); ++i) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (expr.size() < 2) {
                    break;
                }
                
                string v2Str = expr.top(); expr.pop();
                string v1Str = expr.top(); expr.pop();
                
                int v1 = stoi(v1Str);
                int v2 = stoi(v2Str);
                int v3 = 0;
                //cout << "calculate: " << v1 << token << v2 << endl;
                cout << "calculate: " << v1Str << token << v2Str << endl;
                if (token == "+") {
                    v3 = v1 + v2;
                } else if (token == "-") {
                    v3 = v1 - v2;
                } else if (token == "*") {
                    v3 = v1 * v2;
                } else if (token == "/") {
                    v3 = v1 / v2;
                }
                
                expr.push(to_string(v3));
            } else {
                expr.push(token);
            }
        }
        
        if (expr.size() > 0) {
            string resultStr = expr.top(); expr.pop();
            result = stoi(resultStr);
        }
        
        return result;
    }
};

int main() {
    Solution sln;
    vector<string> tokens;
    const char* tokens_c[] = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    for (auto s : tokens_c) {
       tokens.push_back(s); 
    }

    cout << sln.evalRPN(tokens) << endl;
    return 0;
}