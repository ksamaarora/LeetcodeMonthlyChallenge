// Brute force solution
// TC: ~~O(N^2) (Time Limit Exceeded)
// SC: O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int left_sum=0;
        int right_sum=0;
        int count=0;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            left_sum=right_sum=0;
            for(int j=0; j<n; j++){
                if(j<=i) left_sum+=nums[j];
                if(j>i) right_sum+=nums[j];
            }
            if(left_sum>=right_sum) count++;
        }
        return count;
    }
};

// Better solution: One Pass (Prefix Sum Array)
// TC: O(2N-1)
// SC: O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        long long left_sum=0;
        int count=0;
        for(int i=0; i<n-1; i++){
            left_sum+=nums[i];
            long long right_sum=sum-left_sum;
            if(left_sum>=right_sum) count++;
        }
        return count;
    }
};