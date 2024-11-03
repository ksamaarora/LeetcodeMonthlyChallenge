// Method 1: Brute force solution
// TC: O(N x (N-1)) ~~ O(NxN)
// SC:O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s==goal) return true;
        for(int i=0; i<n; i++){
            char firstElement= s[0];
            for(int j=1; j<n; j++){
                s[j-1]=s[j];
            }
            s[n-1]=firstElement;
            if(s==goal) return true;
        }
        return false;
    }
};


// Method 2: (Not goood SC and same TC)
// TC: O(N + N^2) ~~ O(N^2)
// SC: O(2N) for s concatenation & substring space is not counted as it is used temporarily and not stored

class Solution{
public:
    bool rotateString(string s, string goal){
        int n=s.size();
        if(n!=goal.size()) return false;
        // concatenate s with itselse
        s+=s; // O(N)
        // for loop: O(N x (N+1)) ~~ O(N^2)
        for(int i=0; i<=n; i++){ // O(N)
            if(s.substr(i,n)==goal) return true; // O(N+1) - 0 and N inclusive for substring extraction
        }
        return false;
    }
};


// Method 3: Optimal Solution
// TC:O(N) The find method internally uses an efficient algorithm (like Knuth-Morris-Pratt or Boyer-Moore), which typically runs in linear time, O(n), for substring search.
// SC:O(2N)

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false; // Check lengths of s and goal
        s += s; // Concatenate s with itself
        return s.find(goal) != string::npos; // Check if goal is in the concatenated string
    }
};
