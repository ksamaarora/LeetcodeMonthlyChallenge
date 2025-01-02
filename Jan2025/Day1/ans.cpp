// Brute force 
// TC: O(N-1) x O(N) ~~ O(N^2)
// SC: O(1)
class Solution{
    public:
    int maxScore(string s){
        int ans=0;
        int n=s.size();
        for(int i=0; i<n-1; i++){
            int sum=0;
            for(int j=0; j<=i; j++){
                if(s[j]=='0') sum++;
            }
            for(int j=i+1; j<n; j++){
                if(s[j]=='1') sum++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};

// Better approach: Count left zeros and right ones 
// TC: O(N+(N-1)) ~~ O(2N)
// SC: O(1)
class Solution {
public:
    int maxScore(string s) {
        int maxSum=0;
        int total_ones=0;
        for(char c:s){
            if(c=='1') total_ones++;
        } // OR int total_ones=count(s.begin(), s.end(), '1'); // TC:O(N)
        int zero_left=0;
        int ones_right=total_ones;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0'){
                zero_left++;
            }
            else{
                ones_right--;
            }
            int sum=zero_left+ones_right;
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};

// Optimal solution - One Pass
// TC: O(N-1)
// SC:O(1)
class Solution {
public:
    int maxScore(string s){
        int n=s.size();
        int ones=0;
        int zeros=0;
        int best=INT_MIN;
        for(int i=0; i<n-1; i++){
            if(s[i]=='1') ones++;
            else zeros++;
            best=max(best,zeros-ones);
        }
        if(s[n-1]=='1'){
            ones++;
        }
        return best+ones;
    }
};

