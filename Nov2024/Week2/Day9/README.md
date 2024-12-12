### Problem 3133: Minimum Array End

**Difficulty**: Medium

---

You are given two integers, `n` and `x`. Your task is to construct an array `nums` of positive integers with the following properties:

1. `nums` has size `n`.
2. For every \( 0 \leq i < n - 1 \), `nums[i + 1]` is greater than `nums[i]`.
3. The result of the bitwise AND operation between all elements in `nums` is exactly `x`.

Return the minimum possible value of `nums[n - 1]`.

---

### Example

#### Example 1
**Input**:  
`n = 3`, `x = 4`  
**Output**:  
`6`  
**Explanation**:  
An array that satisfies the conditions is `[4, 5, 6]`, where:
- The bitwise AND of all elements \( 4 \& 5 \& 6 = 4 \), which matches `x = 4`.
- The last element is `6`, which is the minimum possible value for `nums[n - 1]`.

#### Example 2
**Input**:  
`n = 2`, `x = 7`  
**Output**:  
`15`  
**Explanation**:  
An array that satisfies the conditions is `[7, 15]`, where:
- The bitwise AND of all elements \( 7 \& 15 = 7 \), which matches `x = 7`.
- The last element is `15`, which is the minimum possible value for `nums[n - 1]`.

---

### Constraints:
- \( 1 \leq n, x \leq 10^8 \)

---