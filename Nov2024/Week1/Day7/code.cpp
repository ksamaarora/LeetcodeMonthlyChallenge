// Method 1: Using bitCount Array to store the count of set bits at each bit position from 0 to 23
// TC:O((n*b)+b) where b=24 and n=integers in candidates 
// SC:O(b)=O(24)~~O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(24,0); // size 24 with zeros to store count of set bits at each position from 0 to 23
        for(int i=0; i<24; i++){
            for(int num:candidates){
                // Check if the ith bit is set 
                if((num & (1<<i))!=0){
                    bitCount[i]++;
                }
            }
        }
        return *max_element(bitCount.begin(), bitCount.end());
    }
};

// Method 2: Using count variable to track the max_count
// TC:O(b*n)
// SC:O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_count=0;
        for(int i=0; i<24; i++){
            int count=0;
            for(int num:candidates){
                if((num & (1<<i))!=0){
                    count++;
                }
                max_count=max(max_count,count);
            }
        }
        return max_count;
    }
};