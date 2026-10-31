#include <algorithm>
#include <iterator>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int lastSeen[256];
        std::fill(std::begin(lastSeen), std::end(lastSeen), -1);
        int start = 0;
        int longest = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            unsigned char character = static_cast<unsigned char>(s[i]);
            start = std::max(start, lastSeen[character] + 1);
            longest = std::max(longest, i - start + 1);
            lastSeen[character] = i;
        }
        return longest;
    }
};
