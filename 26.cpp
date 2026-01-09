#include <algorithm>
#include <cassert>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        const auto last = std::unique(nums.begin(), nums.end());

        nums.erase(last, nums.end());

        return nums.size();
    }
};

int main()
{
    auto sol = new Solution;

    std::vector<int> ex1 = {1, 1, 2};
    assert(sol->removeDuplicates(ex1) == 2);

    std::vector<int> ex2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    assert(sol->removeDuplicates(ex2) == 5);

    return 0;
}
