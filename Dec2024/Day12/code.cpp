// Brute force solution 
// TC: O(k)xO(n) + O(n) for printing sum
// SC: O(1)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        for(int i=0; i<k; i++){
            int max=0;
            int index;
            for(int j=0; j<n; j++){
                if(gifts[j]>max){
                    max=gifts[j];
                    index=j;
                }
            }
            gifts[index]=sqrt(gifts[index]);
        }
        long long sum=0;
        for(int i=0; i<n; i++){
            sum=sum+gifts[i];
        }
        return sum;
    }
};


// Better Solution - sorting
// TC: O(k*n*logn)
// SC: O(N)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        vector<int> sortedGifts=gifts;
        for(int i=0; i<k; i++){ // k times loop
            sort(sortedGifts.begin(), sortedGifts.end()); // O(N*logN)
            int maxElement=sortedGifts.back();
            sortedGifts.back()=floor(sqrt(maxElement));
        }
        long long sum=0;
        for(int i=0; i<n; i++){ // O(N)
            sum=sum+sortedGifts[i];
        }
        return sum;
    }
};

// Optimal Solution - priority_queue maxHeap
// TC: O(N) + O(klogN)
// SC: O(N)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end()); // O(N)
        for(int i=0; i<k; i++){ // O(klogN)
            int maxGift=maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(maxGift)));
        }
        long long sum=0;
        while(!maxHeap.empty()){ // O(N)
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};