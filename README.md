# All problem in this responsitory are my own creation, and i bet you cannot find any solution like me anything else

# Problem 1: https://codeforces.com/contest/2179/problem/D

# Solution Strategy

We observe that the bitwise operation `1 & 1 = 1`, while all other combinations result in `0`.  
Based on this observation, we define the following strategy.

## Key Idea

For each integer from **1 to \(2^n\)**, we count the number of `1` bits when reading its binary representation **from right to left**.  
We denote this value as **`sli`**.

## Algorithm

1. **Compute `sli`**  
   - For every number in the range \([1, 2^n]\), count the number of `1` bits in its binary form (from right to left).
   - Store this count as `sli`.

2. **Sorting rule**
   - First, sort all elements in **descending order of `sli`**.
   - If two or more elements have the same `sli`, sort them in **ascending order of `ai`** (the element value).

3. **Lexicographical order guarantee**
   - The secondary sort by `ai` ensures that, among all valid sequences, the resulting sequence has the **smallest lexicographical order**.

## Result
By prioritizing higher numbers of `1` bits and resolving ties with smaller values, this approach produces a correct and lexicographically minimal sequence according to the problem requirements.

## Notes
- The algorithm relies on bitwise properties.
- The sorting criteria are crucial for correctness.
- This method is efficient and deterministic.
- 

# Problem 2: https://codeforces.com/contest/2179/problem/E

# Gerrymandering with Bitstring Pattern

## Problem Description

Blackslex is responsible for drawing borders for `n` voting districts.

- There are:
  - `x` voters supporting **Party A**
  - `y` voters supporting **Party B**
- Each district `i` must contain **at least `p[i]` voters**
- The winner of each district must follow a given **binary string `s`**:
  - `s[i] = 0` → Party A must win (`a[i] > b[i]`)
  - `s[i] = 1` → Party B must win (`b[i] > a[i]`)

### Goal

Determine whether there exist two arrays of non-negative integers `a[]` and `b[]` such that:

- `a1 + a2 + ... + an = x`
- `b1 + b2 + ... + bn = y`
- `a[i] + b[i] ≥ p[i]` for every district
- The winning condition follows the bitstring `s`


## Key Idea

For each district, we want:
1. The total number of voters to be at least `p[i]`
2. One party to strictly win according to `s[i]`

##  Strategy

###  Minimal valid allocation per district

For each district `i`:
- Split `p[i]` into two parts:
  - `l = floor(p[i] / 2)`
  - `r = ceil(p[i] / 2)`
- If `l == r`, adjust to ensure `r > l`

Then:
- If `s[i] = 0` → assign `a[i] = r`, `b[i] = l`
- If `s[i] = 1` → assign `a[i] = l`, `b[i] = r`

This guarantees:
- `a[i] + b[i] ≥ p[i]`
- The correct party wins the district

### Compute total voters used

Let:
- `sa = sum(a[i])`
- `sb = sum(b[i])`

Compare them with the available voters `x` and `y`.

### Adjustment and feasibility checks

- If both `sa ≤ x` and `sb ≤ y`, extra voters can be distributed.
- If one party exceeds its total limit, we attempt to rebalance using districts where adjustment is possible.
- Special handling is required when:
  - Only `0`s appear in `s`
  - Only `1`s appear in `s`
  - Both appear

If a valid redistribution exists, the answer is `YES`.

## Output

- Print `YES` if a valid distribution exists
- Otherwise, print `NO`

## Time Complexity

- Each test case runs in **O(n)**
- The sum of all `n` across test cases is ≤ **2 × 10⁵**
- Efficient and safe within constraints

# Problem 3: https://codeforces.com/contest/2182/problem/C

## Description: 

  - This is a very interesting problem. It is essentially a basic dynamic programming problem, but you need to be truly subtle to recognize the right approach.
  - At the time, I'am posting this article, codeoforces is not allowing everyone read code and solution of others :)).
  This is a very interesting problem. It is essentially a basic dynamic programming problem, but you need to be truly subtle to recognize the right approach.

## Observations:

  - We can notice that if we solve it using brute force, the time complexity would reach O(n⁴) by using three nested loops over the three arrays a, b, c and then finding suitable indices i, j, k.

  - At this point, we need a different approach. We observe that if (aᵢ, bⱼ, cₖ) satisfies the condition, then (a[i + h], b[j + h], c[k + h]) will also satisfy it (as long as this triple is valid).

  - Another important observation is that instead of directly searching for a valid triple (aᵢ, bⱼ, cₖ), we can split the problem:
  suppose we look for pairs (aᵢ, bⱼ) and (bₕ, cₖ) that both satisfy the condition.

  - And then, boom 💥, something magical happens: once we find such (aᵢ, bⱼ) and (bₕ, cₖ), the triple (aᵢ, bⱼ, c[k + j − h]) (or another triple in this case—if you understand the problem, you’ll know what “the other triple” refers to 😆 I’m too lazy to explain it fully) will also be a valid triple that we are looking for.

## Strategy:
  
  - Therefore, our strategy is: instead of finding valid triples (aᵢ, bⱼ, cₖ) directly, we count how many valid pairs (aᵢ, bⱼ) and how many valid pairs (bₕ, cₖ) there are.

  - Then, we simply multiply these two counts together and multiply by n to obtain the final answer.

## Complexity:
  - Time complexity: **O(n^2)**


# Problem 4: https://codeforces.com/contest/2184/problem/D

## Description: 

  Similar with problem 3. This is a very interesting problem. It is essentially a basic dynamic programming problem, but you need to be truly subtle to recognize the right approach.

## Observations:
  - Call number of transform `a` equal to 0 is `costA`.
  - `a` is only devided to 2 only when `a` is even, else `a -= 1`. Sound so familar :vv, that's right
  when you represent a integer in binary, `0` mean at that time a is even, `1` mean at that time a is odd.
  - For example, `15 = 1111` mean that in the period that u transform `5` to `0`, you need to `-= 1` 4 times 
  and `/= 2` 4 times -> `costA = 4 + 4 = 8`.
  - Therefore, we can infer `costA = log2(n) +  __builtin_popcountll(a)`

## Strategy:
  - If n = 1 -> 0 (this is exception case 1)
  - Call:
    + m = log2(n)
    + h = max(m + log2(n - 1), m + 1)
  - If k >= h -> 0 (This is exception case 2, U can totally know why is it) 
  - First, U using dp to find `C[i][j]`: combination of k element from n (i: 1 -> m - 1, j: 1 -> m - 1), what to do? Please keep reading.
  - Second, like i said above, `costA = log2(n) +  __builtin_popcountll(a)`. So now, u follow this pseudo code:
    ```
      for (i: 1 -> m) {
          for (j: k + 1 -> h) { // because we just find number what satify its cost > k
              // Now we have j is cost i is number of bit 1
              tmp = j - i + 1; // length of bit str
              if (tmp < 1) continue; // Of course
              if (tmp <= m && i <= tmp) ans += C[i - 1][tmp - 1]; 
              // let suppose we have a bit str: 1100. Now we have to keep a bit 1 on highest bit and permmut 
              // remaining bit. So ans will add to C[i - 1][tmp - 1] 
          }
      }
    ```
  - Finally, we can obtain the final answer is equal to `ans + (n >= k)`. why `+ (n >= k)`. Because log2(n) is only length
  of bit str when present the number 0 to n - 1 in binary, so now n is never processed on above algorithm. So we have to `+ (n >= k)`, and Why `+ (n >= k)` i think you totally understand why is it :vv.

  ## Complexity:
  - Time complexity: **O(m^2 + (m * (h - k)))**


# Problem 5: https://codeforces.com/contest/2189/problem/C2

## Suggestion: You can see (1 ^ n) == n - 1 and (1 ^ (n - 1)) == n, with every n is odd.

## Solution: U can totally releaze solution for this problem from above suggestion :vv.

## Time Complexity: **O(n)**
