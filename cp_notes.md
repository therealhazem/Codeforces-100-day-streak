# Competitive Programming Notes (C++)
### `General • STL • Sorting & Binary Search • Prefix/Diff • Two Pointers • Frequency • Bits • Number Theory • Math • Strings • Greedy • Recursion & Backtracking`

> Style guide: for every tool → **what it is**, **when to use / when to think of it**, **syntax + tiny code**, **complexity table**, **never-use traps**, **famous combo**, **practice problems (≤ 2500 rated)**.

## Table of Contents
1. [General C++ / Cheat Sheet](#1-general-c-cheat-sheet)
2. [STL](#2-stl)
3. [Sorting & Binary Search](#3-sorting--binary-search)
4. [Prefix Sum & Difference Arrays](#4-prefix-sum--difference-arrays)
5. [Two Pointers / Sliding Window](#5-two-pointers--sliding-window)
6. [Frequency Techniques](#6-frequency-techniques)
7. [Bit Manipulation](#7-bit-manipulation)
8. [Number Theory](#8-number-theory)
9. [Mathematics](#9-mathematics-combinatorics--basics)
10. [Strings](#10-strings)
11. [Greedy](#11-greedy)
12. [Recursion & Backtracking](#12-recursion--backtracking)
13. [Master "When You See X, Think Y" Table](#master-when-you-see-x-think-y-table)

---
---

# 1. General C++ / Cheat Sheet

## Fast Template
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        // solve()
    }
    return 0;
}
```

**Why?** `sync_with_stdio(false)` + `cin.tie(NULL)` turns off C-I/O sync — turns 2-3 sec I/O into ~0.3 sec. **Always add this**, missing it is the #1 cause of TLE on large-IO problems.

## Common Typedefs / Macros

| Macro/Typedef       | Meaning                                  |
|----------------------|--------------------------------------------|
| `#define ll long long` | avoid overflow, most CP answers need it |
| `#define pb push_back` | shorthand                                |
| `#define all(x) x.begin(), x.end()` | shorthand for sort/reverse etc. |
| `#define endl '\n'`   | `'\n'` is faster than `std::endl` (no flush) |
| `INT_MAX`, `INT_MIN`  | `<climits>`, `2147483647` / `-2147483648` |
| `LLONG_MAX`           | `9223372036854775807`                    |

## Integer Sizes & Overflow

| Type        | Range (approx)         | When to use                          |
|--------------|--------------------------|----------------------------------------|
| `int`        | ±2.1 × 10⁹               | default counting, indices              |
| `long long`  | ±9.2 × 10¹⁸               | **anything that multiplies** (n up to 1e5, products up to 1e10+) |
| `unsigned long long` | 0 to 1.8×10¹⁹     | rare, bit tricks / modular tasks       |
| `double`     | ~15-17 sig digits         | geometry, avoid for exact equality     |

**Trigger:** if you see `n, m ≤ 1e5` and the answer involves `n * m` or `n * n`, → **switch to `long long` immediately**. This is the #1 WA cause in CP (int overflow).

## Common Header-to-Feature Map

| Header          | Contains                                    |
|------------------|-----------------------------------------------|
| `<algorithm>`     | sort, binary_search, lower/upper_bound, reverse, next_permutation |
| `<numeric>`       | accumulate, partial_sum, gcd, lcm            |
| `<vector>`, `<map>`, `<set>`, `<queue>`, `<stack>` | containers |
| `<cmath>`         | pow, sqrt, log, ceil, floor                  |
| `<bits/stdc++.h>` | everything (competitive-programming standard, not for production) |

## I/O Speed Checklist

| Do                                        | Don't                                       |
|-----------------------------------------------|--------------------------------------------------|
| `cin`/`cout` with sync off                    | `scanf`/`printf` mixed with unsynced `cin`/`cout` (UB) |
| `'\n'`                                          | `endl` in tight loops (flushes every time)         |
| reserve vector size if known: `v.reserve(n)`      | repeated `push_back` causing reallocations on huge n |
| pass big containers by `const&`                 | pass `vector`/`string` by value into recursive calls |

---
---

# 2. STL

## 2.0 Container Quick Index

*(trigger-word summary — jump to the detailed section below for each one)*

| When you see...                                        | Think of...                          |
|-----------------------------------------------------------|------------------------------------------|
| "process elements in order of arrival, remove from front" | `queue`                              |
| "undo last action" / "matching brackets"                  | `stack`                              |
| "always need the max/min so far, dynamically"              | `priority_queue`                     |
| "need both front and back fast operations"                 | `deque`                              |
| "unique + sorted elements, need floor/ceil"                | `set` (`lower_bound`/`upper_bound`)  |
| "unique + O(1) lookup, don't care about order"              | `unordered_set`                      |
| "key → value with sorted keys"                              | `map`                                |
| "key → value, just need fast lookup"                        | `unordered_map`                      |
| "next greater/smaller element"                               | Monotonic `stack`                    |
| "sliding window max/min"                                      | Monotonic `deque`                    |
| "group values that come as (a,b) together"                    | `pair` / `vector<pair<int,int>>`     |
| "traverse a container generically, works with algorithms"      | Iterators                            |

## 2.1 `vector` — Dynamic Array

- Resizable array, contiguous memory → supports random access (`v[i]`) and works with all pointer-based algorithms.

```cpp
vector<int> v = {5, 2, 8};
v.push_back(9);          // {5,2,8,9}
v.pop_back();             // {5,2,8}
v.insert(v.begin()+1, 7); // {5,7,2,8}
v.erase(v.begin());       // {7,2,8}
sort(v.begin(), v.end());
```

**Complexity**

| Operation            | Time            |
|-------------------------|-------------------|
| `v[i]` access            | O(1)              |
| `push_back` / `pop_back` | O(1) amortized     |
| `insert`/`erase` (middle)| O(n)               |
| `find` (linear scan)      | O(n)               |

**When to never use:** frequent `insert`/`erase` at the front or middle on large n (each shifts elements) — use `deque` or `list` instead.

## 2.2 `pair` / `tuple`

```cpp
pair<int,int> p = {1, 2};
cout << p.first << " " << p.second;

tuple<int,int,int> t = {1,2,3};
auto [a,b,c] = t;   // structured bindings, C++17
```
- Compares lexicographically by default → makes `vector<pair<int,int>>` sortable out of the box (sorts by `.first`, ties by `.second`).

**Famous CP combo:** `vector<pair<int,int>> v` for (value,index) or (start,end) pairs, then `sort(all(v))` — the standard building block for interval/greedy problems.

## 2.3 `set` / `multiset` (`<set>`, ordered, tree-based)

- Stores **unique** (`set`) or duplicate-allowed (`multiset`) elements, always kept **sorted**. Backed by a red-black tree.

```cpp
set<int> s = {5, 1, 3};
s.insert(4);
s.erase(1);
if (s.count(3)) { /* exists */ }

auto it = s.lower_bound(3);  // first element >= 3
auto it2 = s.upper_bound(3); // first element > 3
```

**Complexity**

| Operation                 | Time      |
|------------------------------|-------------|
| `insert` / `erase` / `find`  | O(log n)    |
| `count` (set: 0/1, multiset: true freq) | O(log n) |
| `lower_bound` / `upper_bound`| O(log n)    |
| in-order traversal            | O(n)        |

**Why? When to use:** need sorted unique data with fast insert/delete/floor/ceil queries (e.g. "closest value ≤ x").

**Never use:** `std::find()`/`std::count()` (the `<algorithm>` versions) on a `set` — they do an O(n) linear scan. Always call the **member function** `s.find(x)` / `s.count(x)` (O(log n)) instead.

## 2.4 `map` / `multimap` (`<map>`, ordered, tree-based)

- Key → value store, sorted by key.

```cpp
map<string,int> mp;
mp["apple"] = 3;
mp["banana"]++;
if (mp.count("apple")) cout << mp["apple"];
for (auto &[k, v] : mp) cout << k << " " << v << "\n"; // sorted by key
```

**Complexity:** `insert`/`erase`/`find`/`operator[]` all O(log n).

**Trap:** `mp[key]` **creates** the key with default value (0) if it doesn't exist — don't use `[]` for pure existence checks in a hot loop if you don't want side-effect insertions; use `mp.count(key)` or `mp.find(key)` instead.

## 2.5 `unordered_set` / `unordered_map` (`<unordered_set>`, `<unordered_map>`, hash-based)

```cpp
unordered_map<int,int> freq;
freq[5]++;
if (freq.count(5)) { /* exists */ }
```

**Complexity:** O(1) average for insert/erase/find, **O(n) worst case** (hash collisions / adversarial input on Codeforces — a known attack against naive `unordered_map<int,...>`).

**When to never use:** if the judge is Codeforces and keys are plain `int`/`long long` chosen by an adversarial setter → use `map` instead, or add a custom hash (splitmix64) to `unordered_map` to avoid anti-hash-test TLE.

**Famous CP combo:** `unordered_map` (or array) frequency counting inside an O(n) loop — turns an O(n²) brute force pair-count into O(n).

## 2.6 `stack` (`<stack>`, LIFO)

```cpp
stack<int> st;
st.push(1); st.push(2);
st.top();   // 2
st.pop();   // removes 2
st.empty(); // false
```
**Complexity:** all operations O(1). **No iterator support** — can't traverse without popping.

**Trigger:** "matching brackets/parentheses", "undo", "next greater element" (monotonic stack).

## 2.7 `queue` (`<queue>`, FIFO)

```cpp
queue<int> q;
q.push(1); q.push(2);
q.front(); // 1
q.pop();   // removes 1
```
**Complexity:** O(1) all ops. **No iterator support.**

**Trigger:** BFS, "process in arrival order".

## 2.8 `deque` (`<deque>`, double-ended queue)

```cpp
deque<int> dq;
dq.push_back(1); dq.push_front(2);
dq.pop_back(); dq.pop_front();
dq[0]; // random access supported too
```
**Complexity:** O(1) push/pop at **both** ends, O(1) random access.

**Trigger:** sliding window max/min (monotonic deque), 0-1 BFS.

## 2.9 `priority_queue` (`<queue>`, binary heap)

```cpp
priority_queue<int> pq;               // max-heap by default
pq.push(5); pq.push(1); pq.push(9);
pq.top();  // 9
pq.pop();

// min-heap:
priority_queue<int, vector<int>, greater<int>> minPQ;
```
**Complexity:** `push`/`pop` O(log n), `top` O(1).

**Trigger:** "always need current max/min while inserting dynamically" → Dijkstra, Huffman-style merging, k-way merge, "kth largest element".

## 2.10 Iterators (`container_type::iterator it;`)

- An **iterator** is an object that behaves like a pointer and is used to access and traverse elements stored in STL containers.
- Gives a generic interface to STL algorithms so they work the same way regardless of the container's internal implementation.
- Modern C++ shortcut: `auto it = container.begin();`

**Basic Operations**

| Operation    | Description                              |
|--------------|-------------------------------------------|
| `*it`        | Access the element pointed to by `it`      |
| `++it`       | Move to next element                       |
| `--it`       | Move to previous element (if supported)    |
| `it1 == it2` | Compare two iterators                      |
| `it1 != it2` | Check if two iterators differ              |

**Types of Iterators**

| Iterator        | Description                                                             |
|------------------|--------------------------------------------------------------------------|
| Input            | Read-only, sequential access                                             |
| Output           | Write-only, sequential access                                            |
| Forward          | Read + write, sequential, one direction                                  |
| Bidirectional    | Forward + can move backward (`--it`)                                     |
| Random-Access    | Bidirectional + jump anywhere (`it + n`, `it[n]`), direct index access   |

**Iterator Support Per Container**

| Container      | Iterator Type   |
|----------------|------------------|
| vector         | Random-Access    |
| deque          | Random-Access    |
| list           | Bidirectional    |
| map / multimap | Bidirectional    |
| set / multiset | Bidirectional    |
| stack          | ❌ Not supported |
| queue          | ❌ Not supported |
| priority_queue | ❌ Not supported |

**Why? When to use**
- Use whenever you need to traverse/modify a container without caring about index-based access (needed for `list`, `set`, `map` which don't support `[]`).
- Almost every STL algorithm (`sort`, `find`, `count`, `reverse`, `lower_bound`...) takes iterators as arguments — this is *the* glue of STL.
- **Never** try `it + 5` or `it[5]` on a `list`/`set`/`map` iterator (not random-access) — use `next(it, 5)` or `advance(it, 5)` instead. This is a very common WA/RE trap in CP.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = v.begin();      // random-access iterator
    cout << *it << " ";       // 1
    cout << *(it + 2);        // 3 (only valid because vector is random-access)
    return 0;
}
```
Output
```
1 3
```

**Common CP combo:** `for (auto it = mp.begin(); it != mp.end(); it++)` to walk a `map`/`set` in sorted order when you need the previous/next key too (paired with `prev(it)` / `next(it)`).

## 2.11 `binary_search()` (`<algorithm>`)

- Checks whether a value exists in a **sorted** range. Returns `true`/`false` only (no position).
- Internally does an actual binary search → **O(log n)**, but only if the container gives random-access iterators (vector/array/deque). On `set`/`map` it silently degrades to **O(n)** — always prefer the member function `s.count(x)` or `s.find(x)` for those.

**Syntax**
```cpp
binary_search(first, last, val, comp /*optional*/);
```

| Parameter | Description                                   |
|-----------|------------------------------------------------|
| first     | Iterator to start of range                     |
| last      | Iterator to one-past-last                       |
| val       | Value to search for                             |
| comp      | Optional custom comparator (default `<`)        |

**Complexity**

| Container            | Time Complexity |
|-----------------------|------------------|
| vector / array / deque| O(log n)         |
| set / map (avoid!)    | O(n) — use `.find()`/`.count()` instead |

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 6, 8, 9};
    int k = 8;

    if (binary_search(v.begin(), v.end(), k))
        cout << k << " is Present";
    else
        cout << k << " is NOT Present";
    return 0;
}
```
Output
```
8 is Present
```

**Why? When to use**
- Use whenever you just need a yes/no existence check on a sorted array — cleaner than manually writing binary search.
- **When to never use:** if the range isn't sorted (undefined behavior — silent wrong answer, not a crash — dangerous in CP), or if you also need the *position*/*count* — use `lower_bound()` / `upper_bound()` instead, since `binary_search()` throws away that info.

**Most common CP combo:** `sort(v.begin(), v.end())` → `binary_search(...)` for existence checks inside a loop (turns an O(n²) brute force into O(n log n)).

**Practice Problems**
- [ ] [Codeforces 977C — Less or Equal](https://codeforces.com/problemset/problem/977/C) — sort + binary search on answer, ~1200
- [ ] [LeetCode 704. Binary Search](https://leetcode.com/problems/binary-search/) — direct application
- [ ] [Codeforces 4C — Registration System](https://codeforces.com/problemset/problem/4/C) — pairs with `map` lookup instead, good contrast problem

## 2.12 `count()` (`<algorithm>`)

- Counts how many times a value appears in a given range (works on arrays, vectors, lists, sets, multisets, etc.).
- Does a **linear scan** — O(n) always, regardless of container. (Not to be confused with `set/map::count()` member function which is O(log n).)

**Syntax**
```cpp
count(first, last, val);
```

| Parameter | Description                              |
|-----------|--------------------------------------------|
| first     | Iterator to start of range                 |
| last      | Iterator to one-past-last                  |
| val       | Value to count occurrences of              |

**Return value:** number of occurrences (`0` if not found).

**Complexity**

| Function                | Time Complexity | Notes                                   |
|--------------------------|------------------|--------------------------------------------|
| `std::count()`           | O(n)             | works on any container/array, linear scan|
| `set/map/multiset::count()` | O(log n)      | member function, use this on ordered containers instead |
| `unordered_set/map::count()`| O(1) avg      | member function, fastest existence check |

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {2, 3, 2, 1, 5, 4, 2};
    cout << count(v.begin(), v.end(), 2);
    return 0;
}
```
Output
```
3
```

**Why? When to use**
- Use `std::count()` on a `vector`/`array`/`list` when you need a frequency of one specific value.
- **Never** use `std::count()` on a `set`/`map` for a lookup-heavy loop — call the member function `s.count(x)` instead (O(log n) vs O(n), huge difference in CP time limits).
- On a `set`/`multiset` note: `set::count()` only ever returns `0` or `1` (unique elements), while `multiset::count()` can return the true frequency.

**Most common CP combo:** frequency counting with `map<int,int> freq;` + `freq[x]++` is usually faster to write and O(1) amortized per query — prefer that pattern over `count()` inside nested loops for CP, since `count()` in a loop can silently blow up to O(n²).

**Practice Problems**
- [ ] [LeetCode 1. Two Sum](https://leetcode.com/problems/two-sum/) — best solved with `unordered_map` frequency, not `count()`, good contrast
- [ ] [Codeforces 158A — Next Round](https://codeforces.com/problemset/problem/158/A) — trivial `count()` usage, ~800
- [ ] [Codeforces 546A — Soldier and Bananas](https://codeforces.com/problemset/problem/546/A) — simulation practice pairing with frequency counting, ~1000

## 2.13 Other Useful `<algorithm>` / `<numeric>` Functions

| Function                              | Description                                       | Complexity |
|-----------------------------------------|--------------------------------------------------------|--------------|
| `reverse(first, last)`                  | reverse range in place                                  | O(n)         |
| `unique(first, last)`                   | removes **consecutive** duplicates (sort first!), returns new logical end | O(n) |
| `min_element` / `max_element`           | iterator to min/max in range                             | O(n)         |
| `accumulate(first, last, init)`          | sum (or custom fold) of range (`<numeric>`)               | O(n)         |
| `next_permutation(first, last)`          | rearranges to next lexicographic permutation, `false` if last one | O(n) per call |
| `__gcd(a, b)`                            | gcd, built-in (or `gcd()` from `<numeric>` in C++17+)      | O(log(min)) |
| `fill(first, last, val)`                 | fill range with value                                     | O(n)         |
| `iota(first, last, start)`               | fill range with increasing values starting at `start` (`<numeric>`) | O(n) |

**Trap:** `unique()` only removes **adjacent** duplicates — always `sort()` first if you want all duplicates gone: `v.erase(unique(all(v)), v.end());` is the standard "dedupe a vector" idiom.

**Practice Problems**
- [ ] [LeetCode 31. Next Permutation](https://leetcode.com/problems/next-permutation/) — `next_permutation` logic from scratch
- [ ] [Codeforces 1355C — Count Triangles](https://codeforces.com/problemset/problem/1355/C) — binary search + two pointers combo, ~1300

## 2.14 STL Quick Reference: Which Tool When?

| Need                                             | Use                              | Time Complexity      |
|---------------------------------------------------|-----------------------------------|------------------------|
| Traverse any container generically                | Iterators (`begin()`/`end()`)     | O(n) to traverse       |
| Check if value exists (sorted array)               | `binary_search()`                 | O(log n)               |
| Check if value exists (set/map)                    | `s.count(x)` / `s.find(x)`        | O(log n)               |
| Check if value exists (unordered_set/map)          | `s.count(x)` / `s.find(x)`        | O(1) avg               |
| Count frequency in array/vector                    | `count()`                         | O(n)                   |
| Count frequency, many queries                      | `map`/`unordered_map` + `freq[x]++` | O(log n) / O(1) avg  |
| Find first element ≥ val (sorted)                  | `lower_bound()`                   | O(log n)               |
| Find first element > val (sorted)                  | `upper_bound()`                   | O(log n)               |
| Dynamic max/min while inserting                    | `priority_queue`                  | O(log n) push/pop      |
| LIFO / bracket matching                            | `stack`                           | O(1)                   |
| FIFO / BFS order                                   | `queue`                           | O(1)                   |
| Both-end fast push/pop                             | `deque`                           | O(1)                   |
| Dedupe a sorted vector                             | `unique()` + `erase()`            | O(n)                   |

---
---

# 3. Sorting & Binary Search

## `sort()` — Custom Comparators

```cpp
vector<pair<int,int>> v = {{3,1},{1,2},{2,0}};

// ascending by first, then by second
sort(v.begin(), v.end());

// descending by first
sort(v.begin(), v.end(), [](auto &a, auto &b){
    return a.first > b.first;
});
```

| Comparator returns...         | Meaning                     |
|---------------------------------|--------------------------------|
| `true` if `a` should come before `b` | standard rule |
| Must be a **strict weak ordering** (never `a < a` true) | else UB / crash on some STL implementations |

**Complexity:** O(n log n) — introsort (quicksort + heapsort + insertion sort hybrid).

## Binary Search on Value (`lower_bound`/`upper_bound`) — recap

| Function        | Finds                          |
|-------------------|-----------------------------------|
| `lower_bound(v.begin(), v.end(), x)` | first element ≥ x |
| `upper_bound(v.begin(), v.end(), x)` | first element > x |

## Binary Search on Answer (the CP superpower)

**Trigger:** "find the minimum/maximum X such that condition(X) is true", and `condition()` is **monotonic** (once true, stays true / once false, stays false).

```cpp
int lo = 1, hi = 1e9, ans = -1;
while(lo <= hi){
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {          // condition holds
        ans = mid;
        hi = mid - 1;          // try smaller (looking for minimum valid)
    } else {
        lo = mid + 1;
    }
}
```

**Complexity:** O(log(range) × cost of `check()`).

**When to never use plain binary search:** if the array isn't sorted / the answer function isn't monotonic — verify monotonicity first, it's the #1 wrong-approach trap.

**Famous CP combo:** "minimize the maximum" / "maximize the minimum" phrasing in a problem statement → binary search on answer, `check()` usually greedy or two-pointer.

**Practice Problems**
- [ ] [Codeforces 1183D2 — Candies (hard)](https://codeforces.com/problemset/problem/1183/D2) — binary search + math, ~1600
- [ ] [Codeforces 1201C — Maximum Median](https://codeforces.com/problemset/problem/1201/C) — binary search on answer, ~1500
- [ ] [LeetCode 875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) — classic "minimize the max" template

---
---

# 4. Prefix Sum & Difference Arrays

## Prefix Sum

- `pre[i] = arr[0] + arr[1] + ... + arr[i-1]` (1-indexed prefix, `pre[0] = 0`)
- Answers **range sum queries** in O(1) after O(n) preprocessing.

```cpp
vector<int> pre(n + 1, 0);
for (int i = 0; i < n; i++)
    pre[i+1] = pre[i] + arr[i];

// sum of arr[l..r] (0-indexed, inclusive)
int rangeSum = pre[r+1] - pre[l];
```

| Operation             | Naive     | With prefix sum |
|-------------------------|-------------|--------------------|
| Build                  | —           | O(n)               |
| Range sum query        | O(n) each   | O(1) each          |

**Trigger:** "answer Q queries of sum of subarray [l, r]" → prefix sum, always.

## 2D Prefix Sum (submatrix sum)

```cpp
// pre[i][j] = sum of rectangle (0,0) to (i-1,j-1)
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        pre[i][j] = grid[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];

// sum of rectangle (r1,c1) to (r2,c2), 0-indexed inclusive
int sum = pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1];
```

## Difference Array (range update, point query)

- Opposite use-case of prefix sum: many **range updates**, then read final array once.

```cpp
vector<int> diff(n + 1, 0);
// add val to arr[l..r]
diff[l] += val;
diff[r+1] -= val;

// after all updates, reconstruct:
for (int i = 1; i < n; i++)
    diff[i] += diff[i-1];
// diff[i] now holds arr[i]
```

| Technique         | Good for                                   | Bad for                        |
|---------------------|-----------------------------------------------|-----------------------------------|
| Prefix sum         | many range **sum queries**, static array       | frequent updates                 |
| Difference array   | many range **updates**, few final reads         | interleaved query/update (use Fenwick/segment tree instead) |

**Trigger words:** "add X to every element from l to r, Q times, print final array" → difference array. "how many intervals cover point i" → difference array with +1/-1.

**Practice Problems**
- [ ] [Codeforces 1462B — Last Year's Substring](https://codeforces.com/problemset/problem/1462/B) — prefix-sum idea, ~1500
- [ ] [Codeforces 1360C — Similar Pairs](https://codeforces.com/problemset/problem/1360/C) — parity + counting, ~1300
- [ ] [LeetCode 370. Range Addition](https://leetcode.com/problems/range-addition/) — pure difference array
- [ ] [Codeforces 1004B — Sonya and Exhibition](https://codeforces.com/problemset/problem/1004/B) — array construction, ~1300

---
---

# 5. Two Pointers / Sliding Window

## Two Pointers (opposite ends)

**Trigger:** sorted array + "find pair/triplet with sum == / ≤ / ≥ target".

```cpp
sort(v.begin(), v.end());
int l = 0, r = v.size() - 1;
while (l < r) {
    int sum = v[l] + v[r];
    if (sum == target) { /* found */ break; }
    else if (sum < target) l++;
    else r--;
}
```
**Complexity:** O(n log n) (sort) + O(n) scan.

## Sliding Window (same direction, variable size)

**Trigger:** "longest/shortest subarray satisfying some condition" (sum ≤ K, no repeats, at most K distinct, etc.) where the condition is monotonic as window grows/shrinks.

```cpp
int l = 0, sum = 0, best = 0;
for (int r = 0; r < n; r++) {
    sum += arr[r];
    while (sum > K) {          // shrink while invalid
        sum -= arr[l];
        l++;
    }
    best = max(best, r - l + 1);
}
```
**Complexity:** O(n) — each index enters/leaves window at most once (amortized).

## Fixed-Size Window

```cpp
int sum = 0;
for (int i = 0; i < k; i++) sum += arr[i];
int best = sum;
for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i-k];   // slide
    best = max(best, sum);
}
```

| Pattern            | When                                                     |
|-----------------------|--------------------------------------------------------------|
| Two pointers (ends)   | sorted array, pair/triplet sum problems                       |
| Sliding window (var)  | subarray with sum/count condition, monotonic shrink/grow      |
| Sliding window (fixed)| "window of size k" — max/min/avg                              |

**Never use when:** the condition isn't monotonic in window size (adding an element could make an invalid window valid again) — that breaks the shrink logic; fall back to prefix sums / hashmap instead.

**Famous CP combo:** two pointers + sorting is the standard replacement for O(n²) brute-force pair search → O(n log n).

**Practice Problems**
- [ ] [LeetCode 3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) — classic variable window
- [ ] [Codeforces 279B — Books](https://codeforces.com/problemset/problem/279/B) — sliding window, ~1200
- [ ] [Codeforces 1200B — Block Adventure](https://codeforces.com/problemset/problem/1200/B) — two pointer style simulation, ~1500
- [ ] [LeetCode 167. Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) — two pointer template

---
---

# 6. Frequency Techniques

## Hashmap Frequency Counting

```cpp
unordered_map<int,int> freq;
for (int x : arr) freq[x]++;
```
**Complexity:** O(1) average insert/lookup, O(n) total.

**Trigger:** "count occurrences", "find majority element", "find duplicate", "anagram check".

## Array as Frequency Table (when values are bounded)

```cpp
// values in [0, MAXV)
vector<int> freq(MAXV, 0);
for (int x : arr) freq[x]++;
```
Faster than `unordered_map` (no hashing overhead) — **always prefer this if the value range is small (≤ 1e6 or so)**.

| Technique                  | Time      | When                                   |
|-------------------------------|-------------|-------------------------------------------|
| `unordered_map<int,int>`     | O(1) avg    | large/sparse value range                   |
| plain array frequency table  | O(1)        | small bounded value range — faster, no hashing |
| `map<int,int>`                | O(log n)    | need sorted key iteration too              |
| sort + linear scan            | O(n log n)  | one-time frequency need, no extra memory   |

## Two-Sum Pattern (frequency-based)

```cpp
unordered_map<int,int> seen;
for (int i = 0; i < n; i++) {
    int need = target - arr[i];
    if (seen.count(need)) { /* pair found: seen[need], i */ }
    seen[arr[i]] = i;
}
```
**Complexity:** O(n) — beats sort + two pointers (O(n log n)) when you need original indices / can't sort.

## Frequency of Frequencies

**Trigger:** "count how many elements appear exactly k times" → build `freq[value]`, then build a second map/array `countOfCount[freq_value]++`.

**Never use `std::count()` in a loop over distinct values** — that's O(n) per call → O(n²) total; always precompute frequency once.

**Famous CP combo:** frequency map + sliding window = "longest substring with at most K distinct characters" family.

**Practice Problems**
- [ ] [LeetCode 1. Two Sum](https://leetcode.com/problems/two-sum/) — hashmap frequency pattern
- [ ] [Codeforces 1660B — Vlad and Candies](https://codeforces.com/problemset/problem/1660/B) — frequency + greedy, ~800
- [ ] [Codeforces 1352C — K-th Not Divisible by n](https://codeforces.com/problemset/problem/1352/C) — light math + counting, ~800
- [ ] [LeetCode 1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/) — frequency of frequency

---
---

# 7. Bit Manipulation

## Core Operators

| Operator | Meaning              | Example (`a=5=101, b=3=011`) |
|-----------|------------------------|----------------------------------|
| `&`       | AND                    | `a & b = 001 = 1`                |
| `\|`      | OR                     | `a \| b = 111 = 7`               |
| `^`       | XOR                    | `a ^ b = 110 = 6`                |
| `~`       | NOT (flips all bits)   | `~a = ...11111010`               |
| `<<`      | left shift (× 2)       | `a << 1 = 1010 = 10`             |
| `>>`      | right shift (÷ 2)      | `a >> 1 = 010 = 2`                |

## Common Bit Tricks

| Goal                                   | Code                          |
|-------------------------------------------|----------------------------------|
| Check if `i`-th bit is set                | `(n >> i) & 1`                  |
| Set `i`-th bit                            | `n \| (1 << i)`                 |
| Unset `i`-th bit                          | `n & ~(1 << i)`                 |
| Toggle `i`-th bit                         | `n ^ (1 << i)`                  |
| Check if `n` is a power of 2              | `n > 0 && (n & (n-1)) == 0`     |
| Count set bits                            | `__builtin_popcount(n)` (int), `__builtin_popcountll(n)` (long long) |
| Lowest set bit                            | `n & (-n)`                      |
| Clear lowest set bit                      | `n & (n-1)`                     |
| XOR of all elements                       | `for(x : arr) res ^= x;`        |

**Complexity:** every bit op above is O(1); `__builtin_popcount` is O(1) (hardware instruction) — **always prefer built-ins over manual loops** counting bits.

**Trigger words:**
- "find the single/unique element where all others appear twice" → XOR all elements.
- "subsets of a set of size n" → iterate `mask` from `0` to `(1<<n)-1`, bitmask DP/enumeration.
- "toggle switches / on-off states" → bitmask represents state.
- "XOR of range [l, r]" → prefix XOR array (`preXor[i] = preXor[i-1] ^ arr[i]`).

## Bitmask Enumeration (subsets)

```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // i is included in this subset
        }
    }
}
```
**Complexity:** O(2ⁿ × n) — only feasible for **n ≤ ~20**. If `n > 20`, bitmask DP is the wrong tool — think elsewhere.

**Never use when:** n is large (> 20-22) — 2ⁿ blows up instantly, classic "TLE from bitmask on big n" mistake.

**Famous CP combo:** Bitmask DP — `dp[mask][i]` = "minimum cost to visit set of cities `mask` ending at city `i`" (Traveling Salesman-style), always O(2ⁿ · n) or O(2ⁿ · n²).

**Practice Problems**
- [ ] [LeetCode 136. Single Number](https://leetcode.com/problems/single-number/) — XOR trick
- [ ] [Codeforces 1097D — Makoto and a Blackboard](https://codeforces.com/problemset/problem/1097/D) — bit/divisor DP, ~2100 (upper edge, still ≤2500)
- [ ] [Codeforces 1328D — Carousel](https://codeforces.com/problemset/problem/1328/D) — parity/bit reasoning, ~1600
- [ ] [Codeforces 231A — Team](https://codeforces.com/problemset/problem/231/A) — trivial bit-style counting, ~800

---
---

# 8. Number Theory

## GCD / LCM

```cpp
#include <numeric>   // gcd, lcm are C++17+
int g = gcd(a, b);
int l = lcm(a, b);   // = a / gcd(a,b) * b  (avoid overflow: divide first!)
```
**Complexity:** O(log(min(a,b))) — Euclidean algorithm.

## Sieve of Eratosthenes (primes up to N)

```cpp
vector<bool> isComposite(N+1, false);
for (int i = 2; i * i <= N; i++)
    if (!isComposite[i])
        for (int j = i * i; j <= N; j += i)
            isComposite[j] = true;
// isComposite[i] == false && i >= 2  →  i is prime
```
**Complexity:** O(N log log N) — near-linear, precompute once for all primes ≤ N.

**Trigger:** need primality for **many numbers up to N** → sieve once, O(1) lookup after. If you only need **one or two numbers checked**, trial division up to `sqrt(n)` (O(√n)) is enough — sieve would be overkill.

## Modular Arithmetic

```cpp
const ll MOD = 1e9 + 7;
ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
```

## Modular Exponentiation (Fast Power)

```cpp
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}
```
**Complexity:** O(log exp) — vs. O(exp) for naive looped multiplication.

## Modular Inverse (for division under mod)

- Only works when `mod` is prime (Fermat's Little Theorem): `inv(a) = power(a, mod-2, mod)`.

| Operation under mod  | How                                    |
|------------------------|--------------------------------------------|
| addition               | `(a + b) % mod`                            |
| subtraction             | `((a - b) % mod + mod) % mod` (avoid negative) |
| multiplication          | `(a * b) % mod`                            |
| division                | `(a * modInverse(b)) % mod` — **never** `a / b % mod` directly |

**Trigger words:** "print the answer modulo 1e9+7" → everywhere you add/multiply, apply `% MOD`; if division is needed → modular inverse via fast power.

**Never use plain division under a modulus** — this is one of the most common WA bugs for beginners in modular-arithmetic problems.

**Famous CP combo:** sieve (primes) + fast power (mod exponent) is the backbone of most number-theory div2 C/D problems.

**Practice Problems**
- [ ] [Codeforces 4C — Watermelon](https://codeforces.com/problemset/problem/4/A) — parity/basic NT, ~800
- [ ] [Codeforces 271B — Prime Matrix](https://codeforces.com/problemset/problem/271/B) — sieve + primality, ~1300
- [ ] [Codeforces 630I — Parking Lot](https://codeforces.com/problemset/problem/630/I) — modular counting, ~1400
- [ ] [Codeforces 1097B — Petr and a Combination Lock](https://codeforces.com/problemset/problem/1097/B) — bitmask + subset sum, ~1600
- [ ] [LeetCode 50. Pow(x, n)](https://leetcode.com/problems/powx-n/) — fast power template

---
---

# 9. Mathematics (Combinatorics & Basics)

## Factorials & nCr (Combinations)

```cpp
const int MAXN = 2e5 + 5;
ll fact[MAXN], invFact[MAXN];

void precompute(ll mod) {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % mod;
    invFact[MAXN-1] = power(fact[MAXN-1], mod-2, mod);
    for (int i = MAXN-2; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % mod;
}

ll nCr(int n, int r, ll mod) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n-r] % mod;
}
```
**Complexity:** O(MAXN) precompute once, then O(1) per `nCr` query.

| Formula          | Meaning                              |
|--------------------|-----------------------------------------|
| `n! / (r! (n-r)!)` | ways to choose r items from n, order doesn't matter |
| `n! / (n-r)!`      | permutations — order matters             |
| `2ⁿ`                | total subsets of an n-element set        |

**Trigger words:** "number of ways to choose/arrange" → combinatorics; "count subsets/permutations satisfying X" → often `nCr` + inclusion-exclusion, or DP if constraints repeat.

## GCD-based / Basic Math Patterns

| Problem phrase                                     | Technique                          |
|--------------------------------------------------------|----------------------------------------|
| "minimum operations to make all elements equal"         | often math (median / gcd) not brute force |
| "sum of digits", "digit DP style constraints"            | digit-by-digit processing              |
| "is it possible to split into k equal parts"              | check divisibility / gcd conditions first |

**Never use** brute-force factorial-time permutation generation for `n > 10-11` — switch to combinatorial formulas or DP.

**Famous CP combo:** precomputed factorials + modular inverse = standard setup for any "count ways mod 1e9+7" problem.

**Practice Problems**
- [ ] [Codeforces 1342A — Yet Another Digit Array](https://codeforces.com/problemset/problem/1342/A) — light math/greedy, ~1200
- [ ] [Codeforces 1352A — Sum of Round Numbers](https://codeforces.com/problemset/problem/1352/A) — digit decomposition, ~800
- [ ] [LeetCode 62. Unique Paths](https://leetcode.com/problems/unique-paths/) — combinatorics vs DP contrast
- [ ] [Codeforces 1155C — Alarm Clocks Everywhere](https://codeforces.com/problemset/problem/1155/C) — harder combinatorial reasoning, ~2100

---
---

# 10. Strings

## Common Built-ins

| Function                     | Description                             | Complexity |
|---------------------------------|---------------------------------------------|--------------|
| `s.substr(pos, len)`            | substring starting at `pos`, length `len`     | O(len)       |
| `s.find(t)`                     | index of first occurrence of `t`, else `string::npos` | O(n·m) naive |
| `s + t` / `s.append(t)`         | concatenation                                | O(n+m)       |
| `reverse(s.begin(), s.end())`   | reverse in place                             | O(n)         |
| `sort(s.begin(), s.end())`      | sort characters                              | O(n log n)   |
| `stoi(s)` / `to_string(x)`      | string ↔ number conversion                   | O(len)       |
| `isalpha`, `isdigit`, `toupper`, `tolower` (`<cctype>`) | character checks/conversion | O(1) |

## Palindrome Check (two pointers)

```cpp
bool isPalindrome(string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}
```
**Complexity:** O(n).

## String Hashing (fast substring comparison)

```cpp
const ll MOD = 1e9+7, BASE = 31;
vector<ll> hashPre(n+1), power(n+1);
power[0] = 1;
for (int i = 1; i <= n; i++) power[i] = power[i-1] * BASE % MOD;
for (int i = 0; i < n; i++)
    hashPre[i+1] = (hashPre[i] * BASE + s[i]) % MOD;

// hash of s[l..r] (0-indexed, inclusive)
ll getHash(int l, int r) {
    return ((hashPre[r+1] - hashPre[l] * power[r-l+1]) % MOD + MOD) % MOD;
}
```
**Complexity:** O(n) preprocess, O(1) per substring hash comparison — turns O(n) string comparisons into O(1).

**Trigger:** "compare many substrings for equality fast" / "count distinct substrings" → hashing.

## KMP — Pattern Matching (find occurrences in O(n+m))

```cpp
vector<int> buildLPS(string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}
```
**Complexity:** O(n + m) — vs. O(n·m) naive substring search.

| Technique          | Use case                                     | Complexity     |
|-----------------------|---------------------------------------------------|-------------------|
| Naive substring search| small strings, one-off check                       | O(n·m)            |
| KMP                    | find all occurrences of pattern in text             | O(n+m)             |
| String hashing          | many substring equality / distinct-substring counting | O(n) build, O(1) query |
| Two pointers / palindrome check | palindrome, anagram-adjacent checks         | O(n)               |

**Never use** naive O(n·m) substring matching when `n, m` can both be ~1e5 — will TLE; switch to KMP or hashing.

**Famous CP combo:** frequency array (size 26 for lowercase letters) + sliding window = anagram-in-string / permutation-in-string family of problems.

**Practice Problems**
- [ ] [LeetCode 28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) — KMP practice
- [ ] [Codeforces 1200C — Round Corridor](https://codeforces.com/problemset/problem/1200/C) — math+parsing, ~1500
- [ ] [Codeforces 1200E — Compress Words](https://codeforces.com/problemset/problem/1200/E) — KMP/hashing merge, ~2100
- [ ] [LeetCode 242. Valid Anagram](https://leetcode.com/problems/valid-anagram/) — frequency array template

---
---

# 11. Greedy

## Core Idea
- Make the **locally optimal choice** at each step, hoping it leads to a globally optimal solution. Requires **proof** (exchange argument / matroid / greedy-stays-ahead) — "seems greedy" is not enough on harder problems.

## Classic Greedy Patterns

| Pattern                                        | Approach                                                |
|---------------------------------------------------|--------------------------------------------------------------|
| Activity/interval selection (max non-overlapping)  | sort by **end time**, pick earliest-ending first that fits     |
| Minimize max / maximize min                         | usually sort + binary search on answer                         |
| Fractional knapsack                                 | sort by value/weight ratio, take greedily                      |
| Huffman-coding style "merge cheapest first"         | `priority_queue` (min-heap), always merge two smallest          |
| Coin change (only works for canonical coin systems) | sort coins descending, take biggest first — **not general**, verify canonicity first |

```cpp
// classic: max number of non-overlapping intervals
sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
    return a.second < b.second;   // sort by end time
});
int count = 0, lastEnd = INT_MIN;
for (auto &[s, e] : intervals) {
    if (s >= lastEnd) { count++; lastEnd = e; }
}
```
**Complexity:** O(n log n) (dominated by sort).

**Trigger words:** "maximum number of non-overlapping", "minimum number of platforms/rooms", "assign to minimize cost", "schedule to minimize lateness" → greedy + sort, often paired with a `priority_queue`.

**When to never trust greedy:** if you can't find/prove an exchange argument and the problem has overlapping subproblems / "choose subset to optimize" with dependencies → it's DP, not greedy. Classic trap: 0/1 knapsack (NOT solvable greedily) vs fractional knapsack (IS greedy).

**Famous CP combo:** sort + greedy sweep is the most common "easy problem" pattern in Div2 A/B — if sorting simplifies the condition into monotonic left-to-right decisions, greedy usually works.

**Practice Problems**
- [ ] [Codeforces 1157B — Long Number](https://codeforces.com/problemset/problem/1157/B) — greedy digit swap, ~1300
- [ ] [Codeforces 545C — Woodcutters](https://codeforces.com/problemset/problem/545/C) — classic interval greedy, ~1500
- [ ] [LeetCode 435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) — interval greedy template
- [ ] [Codeforces 1330B — Numbers Box](https://codeforces.com/problemset/problem/1330/B) — parity greedy, ~1400

---
---

# 12. Recursion & Backtracking

## Recursion Basics

- Every recursive function needs: **base case** (stop condition) + **recursive case** (reduce toward base case).
- Watch **stack depth**: default recursion limit in competitive judges is usually fine up to ~1e4-1e5 depth, but deep recursion (e.g. on a skewed tree/linked structure of size 1e6) can stack-overflow — convert to iterative in that case.

```cpp
int fact(int n) {
    if (n == 0) return 1;         // base case
    return n * fact(n - 1);       // recursive case
}
```

## Backtracking Template

- Backtracking = recursion + **undo the choice** after exploring it ("try, recurse, undo").
- Used for generating **all** subsets / permutations / combinations, or searching for **any valid** configuration (N-Queens, Sudoku).

```cpp
void backtrack(vector<int>& path, vector<int>& nums, vector<bool>& used, vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);

        backtrack(path, nums, used, res);   // recurse

        path.pop_back();                     // undo (backtrack)
        used[i] = false;
    }
}
```
**Complexity:** generating all permutations is O(n · n!) — feasible only for **n ≤ ~10-11**.

## Subset Generation (bitmask vs recursion)

| Method                | Complexity        | When                                     |
|--------------------------|----------------------|-----------------------------------------------|
| Recursive backtracking   | O(2ⁿ) (or n·n! for perms) | need early pruning / constraints mid-way   |
| Bitmask iteration        | O(2ⁿ · n)             | n ≤ ~20, no need for early pruning              |

## Pruning (the key to making backtracking fast)

- Add an early `if (invalid) return;` check **before** recursing further, so invalid branches are cut immediately instead of explored fully.
- **Trigger:** "count/find all ways satisfying constraints" (N-Queens, Sudoku, word search, combination sum) → backtracking + prune as early as possible.

**Never use plain backtracking without pruning** on problems with n > ~15-20 — always add constraint checks inline to cut the search tree, or the naive version will TLE even though it's "technically correct".

**Famous CP combo:** backtracking + memoization = DP (when subproblems repeat) — if you notice the same `(state)` being recomputed, add a `map`/array cache and it becomes top-down DP instantly.

**Practice Problems**
- [ ] [LeetCode 46. Permutations](https://leetcode.com/problems/permutations/) — backtracking template
- [ ] [LeetCode 78. Subsets](https://leetcode.com/problems/subsets/) — subset backtracking
- [ ] [Codeforces 4D — Mysterious Present](https://codeforces.com/problemset/problem/4/D) — recursion + DP hybrid, ~1700
- [ ] [LeetCode 51. N-Queens](https://leetcode.com/problems/n-queens/) — classic pruning-heavy backtracking
- [ ] [Codeforces 1097D — Makoto and a Blackboard](https://codeforces.com/problemset/problem/1097/D) — backtracking→DP transition example, ~2100

---
---

# Master "When You See X, Think Y" Table

| Trigger phrase in problem statement                          | Technique to reach for                    |
|-------------------------------------------------------------------|------------------------------------------------|
| "sum of subarray [l, r]", many queries                            | Prefix sum                                     |
| "add value to range [l, r]", many updates, one final read          | Difference array                               |
| "longest/shortest subarray with condition"                          | Sliding window                                 |
| "pair with sum ==/≤/≥ target", sorted array                         | Two pointers                                   |
| "minimum X such that condition(X) holds", monotonic condition         | Binary search on answer                        |
| "check existence in sorted array"                                       | `binary_search()` / `lower_bound()`             |
| "check existence, need floor/ceil too"                                   | `set` + `lower_bound`/`upper_bound`             |
| "count occurrences / duplicates / majority element"                   | Frequency map / array                          |
| "single unique element, rest appear twice"                             | XOR bit trick                                  |
| "subsets of n ≤ 20 elements"                                            | Bitmask enumeration                            |
| "print answer modulo 1e9+7"                                              | Modular arithmetic + fast power                 |
| "number of ways to choose/arrange"                                        | Combinatorics (nCr, factorials)                 |
| "find all occurrences of pattern in text"                                  | KMP / string hashing                            |
| "max non-overlapping intervals / min rooms/platforms"                       | Greedy + sort                                   |
| "always need current max/min while inserting"                                | `priority_queue`                                |
| "matching brackets / undo last action"                                       | `stack`                                          |
| "BFS / process in arrival order"                                              | `queue`                                          |
| "sliding window max/min"                                                       | Monotonic `deque`                               |
| "generate all permutations/subsets/combinations"                              | Backtracking                                    |
| "same subproblem recomputed in backtracking"                                   | Add memoization → becomes DP                    |
