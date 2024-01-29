/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.



Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

*/

#include <iostream>
#include <vector>

class Solution
{
	private:
		double max(double val_a, double val_b)
		{
			if (val_a > val_b)
			{
				return val_a;
			}
			else
			{
				return val_b;
			}
		}
	public:
		double findFirstSum(std::vector<int>& nums, int k)
		{
			double sum = 0;
			int index  = 0;
			while (index < k)
			{
				sum += nums[index];
				index += 1;
			}
			return sum;
		}
        double findMaxAverage(std::vector<int>& nums, int k)
        {
            int len = nums.size();
            double sum = findFirstSum(nums, k);
            int index = k;
            double average = sum / k;
            double tmp = average;
            while (index < len)
            {
                sum += nums[index] - nums[index - k];
                tmp = sum / k;
                average = max(average, tmp);
                index += 1;
            }
            return average;
        }
};
