// Method 1: Using string concatenation directly
// TC:O(N)  SC:O(2N) in worst case when each element is different and their count is 1
class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n=word.size();
        int i=0;
        char currentChar;
        while(i<n){
            currentChar=word[i];
            int count=0;
            while(i<n && currentChar==word[i] && count<9){
                count++;
                i++;
            }
            comp+=to_string(count)+currentChar;
        }
        return comp;
    }
};

// Method 2: Using vector<string> (Alternative method)
// TC:O(N)+O(M) SC:O(2N) for comp in worst case 
class Solution {
public:
    string compressedString(string word) {
        vector<string> comp;
        int n=word.size();
        int i=0;
        char currentChar;
        while(i<n){ // O(N)
            currentChar=word[i];
            int count=0;
            while(i<n && currentChar==word[i] && count<9){
                count++;
                i++;
            }
            
            // Append the count and character as separate strings to comp
            comp.push_back(to_string(count)); // Convert count to string
            comp.push_back(string(1, currentChar)); // Convert char to string
        }
        
        // Combine all elements in comp into a single string
        string result;
        for (const string s : comp) { // O(M) where M is length of comps contents i.e. O(N) in worst case
            result += s;
        }
        return result;
    }
};

