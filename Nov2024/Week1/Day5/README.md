### Problem: 2914. Minimum Number of Changes to Make Binary String Beautiful

#### Difficulty: Medium

#### Problem Description:
You are given a binary string `s` (only contains '0's and '1's) with an even length. A binary string is considered **beautiful** if it can be divided into one or more contiguous substrings that meet the following criteria:
1. Each substring has an even length.
2. Each substring contains either only '1's or only '0's (no mixed substrings).

You can change any character in `s` to '0' or '1' to make the string beautiful. Your task is to return the **minimum number of changes** needed to make the string `s` beautiful.

---

#### Examples:

**Example 1:**
- **Input:** `s = "1001"`
- **Output:** `2`
- **Explanation:** Changing `s[1]` to '1' and `s[3]` to '0' gives "1100", which can be split as "11|00". Both substrings meet the conditions, so "1100" is beautiful. The minimum changes needed are 2.

**Example 2:**
- **Input:** `s = "10"`
- **Output:** `1`
- **Explanation:** Changing `s[1]` to '1' gives "11", which meets the condition as it’s a single substring with even length. Minimum changes needed are 1.

**Example 3:**
- **Input:** `s = "0000"`
- **Output:** `0`
- **Explanation:** The string "0000" already meets the conditions for being beautiful, so no changes are needed.

---

#### Constraints:
- \( 2 \leq s.length \leq 10^5 \)
- `s` has an even length.
- `s[i]` is either '0' or '1'.

---