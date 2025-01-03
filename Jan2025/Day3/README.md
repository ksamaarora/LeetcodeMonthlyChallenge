### 2270. Number of Ways to Split Array

#### Problem Description:
You are given a **0-indexed** integer array `nums` of length `n`.

An index \( i \) in the array is considered a **valid split** if it satisfies the following conditions:
1. The sum of the first \( i+1 \) elements (left subarray) is **greater than or equal to** the sum of the last \( n-i-1 \) elements (right subarray).
2. There is at least one element in the right subarray, i.e., \( 0 \leq i < n-1 \).

Your task is to **return the number of valid splits** in the array.

---

#### Examples:

##### Example 1:
**Input**:  
`nums = [10, 4, -8, 7]`

**Output**:  
`2`

**Explanation**:  
- Split `nums` at index `0`:  
  Left part = `[10]`, sum = `10`.  
  Right part = `[4, -8, 7]`, sum = `3`.  
  Since \( 10 \geq 3 \), this is a valid split.
  
- Split `nums` at index `1`:  
  Left part = `[10, 4]`, sum = `14`.  
  Right part = `[-8, 7]`, sum = `-1`.  
  Since \( 14 \geq -1 \), this is a valid split.

- Split `nums` at index `2`:  
  Left part = `[10, 4, -8]`, sum = `6`.  
  Right part = `[7]`, sum = `7`.  
  Since \( 6 < 7 \), this is **not** a valid split.

Thus, there are **2 valid splits**.

---

##### Example 2:
**Input**:  
`nums = [2, 3, 1, 0]`

**Output**:  
`2`

**Explanation**:  
- Split `nums` at index `1`:  
  Left part = `[2, 3]`, sum = `5`.  
  Right part = `[1, 0]`, sum = `1`.  
  Since \( 5 \geq 1 \), this is a valid split.

- Split `nums` at index `2`:  
  Left part = `[2, 3, 1]`, sum = `6`.  
  Right part = `[0]`, sum = `0`.  
  Since \( 6 \geq 0 \), this is a valid split.

Thus, there are **2 valid splits**.

---

#### Constraints:
- \( 2 \leq \text{nums.length} \leq 10^5 \)
- \( -10^5 \leq \text{nums[i]} \leq 10^5 \)

---