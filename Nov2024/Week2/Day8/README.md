### Problem 1829: Maximum XOR for Each Query

**Difficulty**: Medium

---

You are given a sorted array `nums` of \( n \) non-negative integers and an integer `maximumBit`. You want to perform the following query \( n \) times:

1. Find a non-negative integer `k` such that:
   - \( k < 2^{\text{maximumBit}} \)
   - \( \text{nums[0]} \oplus \text{nums[1]} \oplus \dots \oplus \text{nums[nums.length - 1]} \oplus k \) is maximized.
2. Remove the last element from `nums` after each query.

Return an array `answer` where `answer[i]` is the answer to the \( i \)-th query.

---

### Examples

#### Example 1
**Input**:  
`nums = [0,1,1,3]`, `maximumBit = 2`  
**Output**:  
`[0,3,2,3]`  
**Explanation**:
- 1st query: `nums = [0,1,1,3]`, `k = 0` (since \(0 \oplus 1 \oplus 1 \oplus 3 \oplus 0 = 3\))
- 2nd query: `nums = [0,1,1]`, `k = 3` (since \(0 \oplus 1 \oplus 1 \oplus 3 = 3\))
- 3rd query: `nums = [0,1]`, `k = 2` (since \(0 \oplus 1 \oplus 2 = 3\))
- 4th query: `nums = [0]`, `k = 3` (since \(0 \oplus 3 = 3\))

#### Example 2
**Input**:  
`nums = [2,3,4,7]`, `maximumBit = 3`  
**Output**:  
`[5,2,6,5]`  
**Explanation**:
- 1st query: `nums = [2,3,4,7]`, `k = 5` (since \(2 \oplus 3 \oplus 4 \oplus 7 \oplus 5 = 7\))
- 2nd query: `nums = [2,3,4]`, `k = 2` (since \(2 \oplus 3 \oplus 4 \oplus 2 = 7\))
- 3rd query: `nums = [2,3]`, `k = 6` (since \(2 \oplus 3 \oplus 6 = 7\))
- 4th query: `nums = [2]`, `k = 5` (since \(2 \oplus 5 = 7\))

---

### Constraints:
- \( \text{nums.length} = n \)
- \( 1 \leq n \leq 10^5 \)
- \( 1 \leq \text{maximumBit} \leq 20 \)
- \( 0 \leq \text{nums[i]} < 2^{\text{maximumBit}} \)
- `nums` is sorted in ascending order.

---