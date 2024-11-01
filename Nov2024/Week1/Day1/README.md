### 1957. Delete Characters to Make Fancy String
**Difficulty**: Easy

---

### Problem Description

A **fancy string** is a string where no three consecutive characters are equal.

Given a string `s`, delete the minimum possible number of characters from `s` to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

---

### Examples

**Example 1**:
- **Input**: `s = "leeetcode"`
- **Output**: `"leetcode"`
- **Explanation**: Remove an `'e'` from the first group of `'e's` to create `"leetcode"`. No three consecutive characters are equal, so the result is `"leetcode"`.

**Example 2**:
- **Input**: `s = "aaabaaaa"`
- **Output**: `"aabaa"`
- **Explanation**: 
  - Remove one `'a'` from the first group of `'a's` to create `"aabaaaa"`.
  - Then remove two `'a's` from the second group of `'a's` to create `"aabaa"`.
  - No three consecutive characters are equal, so the result is `"aabaa"`.

**Example 3**:
- **Input**: `s = "aab"`
- **Output**: `"aab"`
- **Explanation**: No three consecutive characters are equal, so return `"aab"`.

---

### Constraints
- \( 1 \leq s.length \leq 10^5 \)
- `s` consists only of lowercase English letters.

