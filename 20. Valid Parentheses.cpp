#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::string openings;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                openings.push_back(c);
            } else {
                if (openings.empty() ||
                    (c == ')' && openings.back() != '(') ||
                    (c == ']' && openings.back() != '[') ||
                    (c == '}' && openings.back() != '{')) {
                    return false;
                }
                openings.pop_back();
            }
        }
        return openings.empty();
    }
};
