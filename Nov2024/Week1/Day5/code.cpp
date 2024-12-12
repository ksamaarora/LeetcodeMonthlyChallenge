// Method 1: Brute Force
// TC:O(N) SC:O(1)
class Solution {
public:
    int minChanges(string s) {
        char currentChar=s[0];
        int consecutiveCount=0;
        int minChangesRequired=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]==currentChar){
                consecutiveCount++;
                continue;
            }
            if(consecutiveCount%2==0){
                consecutiveCount=1;
            }
            else{
                consecutiveCount=0;
                minChangesRequired++;
            }
            currentChar=s[i];
        }
        return minChangesRequired;
    }
};

// Method 2: Optimised Code
// TC: O(N/2) SC:O(1)
class Solution {
public:
    int minChanges(string s) {
        int minChangesRequired=0;
        int n=s.size();
        for(int i=0; i<n; i+=2){
            if(s[i]!=s[i+1]){
                minChangesRequired++;
            }
        }
        return minChangesRequired;
    }
};
