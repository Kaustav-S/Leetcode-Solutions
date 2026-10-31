#include <climits>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const long long complement = static_cast<long long>(target) - nums[i];
            if (complement >= INT_MIN && complement <= INT_MAX) {
                auto it = seen.find(static_cast<int>(complement));
                if (it != seen.end()) {
                    return {it->second, i};
                }
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
