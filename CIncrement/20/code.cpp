class Solution {
public:
    bool match(char fromStr, char fromStack) {
        if (fromStr == '}') {
            if (fromStack == '{') {
                return true;
            }
        } else if (fromStr == ')') {
            if (fromStack == '(') {
                return true;
            }
        } else if (fromStr == ']') {
            if (fromStack == '[') {
                return true;
            }
        }
        return false;
    }
    bool isOpening(char ch) {
        if (ch == '{' || ch == '(' || ch == '[') {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        stack<char> pStack;
        for (string::size_type i = 0; i < s.length(); i++) {
            if (isOpening(s[i])) {
                pStack.push(s[i]);
            } else {
                if (pStack.empty()) {
                    return false;
                }
                if (match(s[i], pStack.top())) {
                    pStack.pop();
                } else {
                    return false;
                }
            }
        }
        return pStack.empty() ? true : false;
    }
};
