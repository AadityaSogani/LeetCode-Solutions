
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }

    return {};
}

int main()
{
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No two numbers found." << endl;
    }

    return 0;
}
