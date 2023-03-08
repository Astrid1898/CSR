#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        for (auto num: nums)
        {
            sum += num;
        }
        if (sum % k != 0 || nums.size() < k)
            return false;
        else
        {
            int correct = sum / k;
            vector<int> numSetsRequest(k, correct);
            return partition(nums, k, 0, correct, numSetsRequest);
        }
    }

    bool partition(vector<int> &nums, int k, int index, int correct, vector<int> &numSetsRequest)
    {
        int correctCount = 0;
        int requestSum = 0;
        for (auto numSetRequest: numSetsRequest)
        {
            if (numSetRequest == 0)
            {
                correctCount++;
            }
            else
            {
                requestSum += numSetRequest;
            }
        }

        if (index == nums.size())
        {
            if (correctCount == k)
                return true;
            else
                return false;
        }

        int partialSum = 0;
        for (int i = index; i < nums.size(); i++)
            partialSum += nums[i];


        if (partialSum != requestSum)
            return false;

        for (int i = 0; i < k; i++)
        {
            if (numSetsRequest[i] >= nums[index])
            {
                numSetsRequest[i] -= nums[index];
                if (partition(nums, k, index + 1, correct, numSetsRequest))
                    return true;
                numSetsRequest[i] += nums[index];
            }
        }

        return false;

    }


};