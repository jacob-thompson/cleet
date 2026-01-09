#include <algorithm>
#include <print>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return static_cast<int>(std::distance(nums.begin(), it));
    }
};

int main()
{
    auto sol = new Solution;

    std::vector<int> nums = {1, 3, 5, 6};
    std::vector<int> targs = {5, 2, 7};

    std::print("nums = [");
    for (auto const &num : nums)
        std::print("{}, ", num);
    std::println("\b\b]");

    for (auto const &target : targs)
        std::println("target = {}; output = {}", target, sol->searchInsert(nums, target));

    return 0;
}
