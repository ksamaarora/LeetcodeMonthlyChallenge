class Solution {
public:
    string makeFancyString(string s) {
        
        // Method 1: TC:O(N) SC:O(N)
        if(s.empty()) return "";
        int n=s.size();
        string result;
        int count=1;
        result+=s[0]; // add first character
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else if(s[i]!=s[i-1]){
                count=1;
            }
            if(count<3){
                result+=s[i];
            }
        }
        return result;
        
        // Method 2: TC:O(N) SC:O(1) In-Place Two Pointer Method
        int n=s.size();
        int count=1;
        int writePos=1;
        for(int i=1; i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                count=1;
            }
            if(count<3){
                s[writePos++]=s[i];
            }
        }
        return s.substr(0,writePos); // return sub string till writePos
    }
};