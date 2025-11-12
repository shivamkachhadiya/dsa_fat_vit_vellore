#include <iostream>
#include <vector>
using namespace std;

void findsubsets(int index, vector<int> &arr, int target, vector<int> &curr, vector<vector<int>> &result)
{
    if (index == arr.size())
    {
        if (target == 0)
        {
            result.push_back(curr);
        }
        return;
    }

    curr.push_back(arr[index]);
    findsubsets(index + 1, arr, target - arr[index], curr, result);
    curr.pop_back();

    findsubsets(index + 1, arr, target, curr, result);
}
int main()
{
    vector<int> arr = {5, 10, 12, 13, 30, 15, 18};
    int target = 30;

    vector<int> curr;
    vector<vector<int>> result;
    findsubsets(0, arr, target, curr, result);
    for (auto &subset : result)
    {
        cout << "{";
        for (int x : subset)
            cout << x << " ";
        cout << "}\n";
    }
}