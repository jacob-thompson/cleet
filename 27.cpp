#include <algorithm>
#include <cassert>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        const auto end = std::remove(nums.begin(), nums.end(), val);
        return end - nums.begin();
    }
};

int main()
{
    auto sol = new Solution;

    std::vector<int> ex1 = {3, 2, 2, 3};
    assert(sol->removeElement(ex1, 3) == 2);

    std::vector<int> ex2 = {0, 1, 2, 2, 3, 0, 4, 2};
    assert(sol->removeElement(ex2, 2) == 5);

    return 0;
}
