### Problem 3011: Find if Array Can Be Sorted

**Difficulty**: Medium

---

You are given a 0-indexed array of positive integers `nums`.

In one operation, you can swap any two adjacent elements if they have the same number of set bits (1s in their binary representation). You are allowed to perform this operation any number of times (including zero).

Return `true` if you can sort the array in non-decreasing order, otherwise return `false`.

---

### Example 1:
**Input**: `nums = [8,4,2,30,15]`  
**Output**: `true`  
**Explanation**:  
We can sort the array using the following operations based on set bits:
- **Binary representations**:  
  - 2 = "10" (1 set bit)  
  - 4 = "100" (1 set bit)  
  - 8 = "1000" (1 set bit)  
  - 15 = "1111" (4 set bits)  
  - 30 = "11110" (4 set bits)
- **Sorting steps**:  
  - Swap `nums[0]` and `nums[1]`: `[4,8,2,30,15]`
  - Swap `nums[1]` and `nums[2]`: `[4,2,8,30,15]`
  - Swap `nums[0]` and `nums[1]`: `[2,4,8,30,15]`
  - Swap `nums[3]` and `nums[4]`: `[2,4,8,15,30]`  

The array is now sorted, so the answer is `true`.

---

### Example 2:
**Input**: `nums = [1,2,3,4,5]`  
**Output**: `true`  
**Explanation**:  
The array is already sorted, so no operations are needed.

---

### Example 3:
**Input**: `nums = [3,16,8,4,2]`  
**Output**: `false`  
**Explanation**:  
It is not possible to sort this array using the allowed operations.

---

### Constraints:
- \(1 \leq \text{nums.length} \leq 100\)
- \(1 \leq \text{nums[i]} \leq 2^{28}\)

---