# Ford-Johnson Algorithm
https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42

I'll trace through a concrete example: sorting `[0, 3, 5, 8, 1, 9, 2, 7, 6, 4]`. Watch how the algorithm descends through levels, hits a base case, then unwinds — inserting losers via Jacobsthal-ordered binary search on the way back.

---

## The Big Picture

Ford-Johnson at each level does three things:

```/dev/null/overview.txt#L1-9
   ┌─────────────────────────────────────────────┐
   │  Phase 1: pair adjacent groups               │
   │           compare their LEADERS              │
   │           swap so loser-group comes FIRST    │
   │  Phase 2: RECURSE with doubled group size    │
   │           (sorts the winner-groups)          │
   │  Phase 3: insert loser-groups into the       │
   │           main chain via Jacobsthal-ordered  │
   │           binary search                      │
   └─────────────────────────────────────────────┘
```

A "group" is `group_size` consecutive elements. Its **leader** is its last element (always the largest within the group, thanks to deeper-level work).

---

## Going Down: Phase 1 at Each Level

### Level 0 — `group_size = 1` (each element is its own group)

We pair adjacent elements; if the left is bigger, swap them so the smaller-leader group comes first.

```/dev/null/level0_phase1.txt#L1-10
positions:  0   1   2   3   4   5   6   7   8   9
input:    [ 0 ][ 3 ][ 5 ][ 8 ][ 1 ][ 9 ][ 2 ][ 7 ][ 6 ][ 4 ]
            \___/    \___/    \___/    \___/    \___/
             0<3     5<8     1<9     2<7     6>4  SWAP
             ✓        ✓        ✓        ✓        ↻

after:    [ 0 ][ 3 ][ 5 ][ 8 ][ 1 ][ 9 ][ 2 ][ 7 ][ 4 ][ 6 ]
           \loser/   \loser/   \loser/   \loser/   \loser/
            winner    winner    winner    winner    winner
```

5 comparisons. Each pair now has the **smaller element first (the loser of that pair) and the larger element second (the winner)**.

---

### Level 1 — `group_size = 2`

Now each "group" is a pair of two ints. We pair adjacent groups (forming meta-pairs of 4 ints each) and compare their **leaders** (last element of each group).

```/dev/null/level1_phase1.txt#L1-12
groups:   [ 0  3 ][ 5  8 ]  [ 1  9 ][ 2  7 ]  [ 4  6 ]
                ↑       ↑        ↑       ↑        ↑
            leader=3  =8     leader=9  =7   (stray)
                \_______/         \_______/
                  3<8 ✓             9>7  SWAP groups
                                    ↻

after:    [ 0  3 ][ 5  8 ]  [ 2  7 ][ 1  9 ]  [ 4  6 ]
           \loser-/ \winr-/  \loser-/ \winr-/   \stray/
            group   group    group   group
```

2 comparisons. With 5 groups, we made 2 meta-pairs and one **stray** is left over (no partner). The stray gets handled later in Phase 3.

---

### Level 2 — `group_size = 4`

Each "group" is now 4 ints. We compare their leaders again.

```/dev/null/level2_phase1.txt#L1-9
groups:   [ 0  3  5  8 ]  [ 2  7  1  9 ]   [ 4  6 ]
                       ↑              ↑      \____/
                  leader=8       leader=9    remainder
                   \____________/             (only 2 ints,
                        8<9 ✓                  can't form a
                                               full group at
                                               this level)
```

1 comparison. The 2 trailing ints don't form a full group of 4 at this level — they're stored in `remainder` until later.

---

### Level 3 — `group_size = 8`

Only 10/8 = 1 group fits. `num_groups < 2`, so we **stop recursing**. This is the base case.

```/dev/null/level3.txt#L1-3
groups:   [ 0  3  5  8  2  7  1  9 ]  [ 4  6 ]
            only 1 full group — nothing to pair
            -> RETURN (base case)
```

---

## Coming Back Up: Phase 3 at Each Level

Phase 3 is where the **loser-groups** get inserted into the **main chain** using Jacobsthal-ordered binary search.

The trick: each loser `b_i` (from pair *i*) is *known to be smaller than* its corresponding winner `a_i`. So when binary-searching for where to insert `b_i`, we never need to look past `a_i`'s current position — that's our upper bound.

---

### Level 2 Phase 3 — `group_size = 4`

```/dev/null/level2_phase3.txt#L1-10
snapshot:   groups[0] = [0,3,5,8]    ← loser of pair 0  (b₁)
            groups[1] = [2,7,1,9]    ← winner of pair 0 (a₁)
            remainder = [4,6]

main chain (as group indices, top-to-bottom = left-to-right):
            [ 0, 1 ]
              ↑  ↑
              b₁ a₁

pend: empty (only 1 pair, so no losers besides b₁ which is "free")
→ no insertions, no comparisons
```

Nothing to do. Write back groups in order, append remainder:

```/dev/null/level2_writeback.txt#L1-2
seq after L2 Phase 3:
[ 0  3  5  8 | 2  7  1  9 | 4  6 ]
```

---

### Level 1 Phase 3 — `group_size = 2`

Now we have 5 groups of size 2. After Phase 1, they sit as `[loser₀, winner₀, loser₁, winner₁, stray]`.

```/dev/null/level1_phase3_setup.txt#L1-15
snapshot:   groups[0] = [0,3]    ← b₁ (loser of pair 0)
            groups[1] = [5,8]    ← a₁ (winner of pair 0)
            groups[2] = [2,7]    ← b₂ (loser of pair 1)
            groups[3] = [1,9]    ← a₂ (winner of pair 1)
            groups[4] = [4,6]    ← stray

leaders:        3    8    7    9    6

main chain (as group indices):
            [ 0, 1, 3 ]
              ↑  ↑  ↑
              b₁ a₁ a₂
            leaders:  3  8  9   (sorted by leader ✓)

pend = { b₂ (index 1), stray (index 2) }
```

**Jacobsthal block k=3** says: insert pend[2] first, then pend[1].

#### Insertion 1: stray (pend index 2)

Bound = entire chain (no corresponding winner). Search for leader `6`:

```/dev/null/level1_insert_stray.txt#L1-12
main chain leaders:   [ 3,  8,  9 ]   key = 6
                        0   1   2     search range [0, 3)

   binary search:  mid=1  → 8 < 6? NO   hi=1   (compare #1)
                   mid=0  → 3 < 6? YES  lo=1   (compare #2)
                   → insert at position 1

main chain becomes:   [ 0, 4, 1, 3 ]
                        ↑  ↑  ↑  ↑
                        b₁ stray a₁ a₂
                      leaders: 3, 6, 8, 9 ✓
```

#### Insertion 2: b₂ (pend index 1)

Bound = current position of `a₂` (which shifted to index 3). Key = 7:

```/dev/null/level1_insert_b2.txt#L1-11
main chain leaders:   [ 3,  6,  8,  9 ]   key = 7
                        0   1   2   3     search range [0, 3)

   binary search:  mid=1  → 6 < 7? YES  lo=2   (compare #3)
                   mid=2  → 8 < 7? NO   hi=2   (compare #4)
                   → insert at position 2

main chain becomes:   [ 0, 4, 2, 1, 3 ]
                        ↑  ↑  ↑  ↑  ↑
                        b₁ stray b₂ a₁ a₂
                      leaders: 3, 6, 7, 8, 9 ✓
```

**Write back** the main chain (concatenating each group's contents):

```/dev/null/level1_writeback.txt#L1-3
seq after L1 Phase 3:
[ 0  3 | 4  6 | 2  7 | 5  8 | 1  9 ]
   g₀     g₄    g₂     g₁     g₃
```

4 comparisons at level 1 Phase 3.

---

### Level 0 Phase 3 — `group_size = 1`

Now each "group" is a single int. 5 pairs, no stray.

```/dev/null/level0_phase3_setup.txt#L1-17
snapshot:   groups[0]=[0]   ← b₁           groups[5]=[7]   ← a₃
            groups[1]=[3]   ← a₁           groups[6]=[5]   ← b₄
            groups[2]=[4]   ← b₂           groups[7]=[8]   ← a₄
            groups[3]=[6]   ← a₂           groups[8]=[1]   ← b₅
            groups[4]=[2]   ← b₃           groups[9]=[9]   ← a₅

main chain (group indices):    [ 0, 1, 3, 5, 7, 9 ]
                                 ↑  ↑  ↑  ↑  ↑  ↑
                                 b₁ a₁ a₂ a₃ a₄ a₅
                               leaders: 0, 3, 6, 7, 8, 9  ✓

pend = { b₂(1), b₃(2), b₄(3), b₅(4) }   — 4 items
```

**Jacobsthal blocks:**
- k=3: pend indices 1..2 → insert order pend[2], pend[1] (= b₃, b₂)
- k=4: pend indices 3..4 → insert order pend[4], pend[3] (= b₅, b₄)

#### Insertion 1: b₃ (pend index 2, value 2)

Bound = position of a₃ = 3.

```/dev/null/insert_b3.txt#L1-10
main chain leaders:   [ 0,  3,  6,  7,  8,  9 ]   key = 2
                        0   1   2   3   4   5     range [0, 3)

   binary search:  mid=1  → 3 < 2? NO   hi=1
                   mid=0  → 0 < 2? YES  lo=1
                   → insert at 1

main chain:  [ 0, 4, 1, 3, 5, 7, 9 ]
            leaders: 0, 2, 3, 6, 7, 8, 9 ✓
```

#### Insertion 2: b₂ (pend index 1, value 4)

Bound = position of a₂ (now shifted to 3).

```/dev/null/insert_b2.txt#L1-10
main chain leaders:   [ 0,  2,  3,  6,  7,  8,  9 ]   key = 4
                        0   1   2   3   4   5   6     range [0, 3)

   binary search:  mid=1  → 2 < 4? YES  lo=2
                   mid=2  → 3 < 4? YES  lo=3
                   → insert at 3

main chain:  [ 0, 4, 1, 2, 3, 5, 7, 9 ]
            leaders: 0, 2, 3, 4, 6, 7, 8, 9 ✓
```

#### Insertion 3: b₅ (pend index 4, value 1)

Bound = position of a₅ (now at 7).

```/dev/null/insert_b5.txt#L1-11
main chain leaders:   [ 0,  2,  3,  4,  6,  7,  8,  9 ]   key = 1
                        0   1   2   3   4   5   6   7     range [0, 7)

   binary search:  mid=3  → 4 < 1? NO   hi=3
                   mid=1  → 2 < 1? NO   hi=1
                   mid=0  → 0 < 1? YES  lo=1
                   → insert at 1

main chain:  [ 0, 8, 4, 1, 2, 3, 5, 7, 9 ]
            leaders: 0, 1, 2, 3, 4, 6, 7, 8, 9 ✓
```

#### Insertion 4: b₄ (pend index 3, value 5)

Bound = position of a₄ (now at 7).

```/dev/null/insert_b4.txt#L1-11
main chain leaders:   [ 0,  1,  2,  3,  4,  6,  7,  8,  9 ]   key = 5
                        0   1   2   3   4   5   6   7   8     range [0, 7)

   binary search:  mid=3  → 3 < 5? YES  lo=4
                   mid=5  → 6 < 5? NO   hi=5
                   mid=4  → 4 < 5? YES  lo=5
                   → insert at 5

main chain:  [ 0, 8, 4, 1, 2, 6, 3, 5, 7, 9 ]
            leaders: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ✓
```

10 comparisons at level 0 Phase 3.

---

## Final Result

Write back the main chain in order (each group is just one int at this level):

```/dev/null/final.txt#L1-4
sorted output:
[ 0  1  2  3  4  5  6  7  8  9 ]
```

---

## The Comparison Tally

```/dev/null/tally.txt#L1-10
                          comparisons
Phase 1, level 0 (pair elements)               5
Phase 1, level 1 (pair groups of 2)            2
Phase 1, level 2 (pair groups of 4)            1
Phase 3, level 2 (no pend, no stray)           0
Phase 3, level 1 (stray + b₂)                  4
Phase 3, level 0 (b₃, b₂, b₅, b₄)             10
                                              ───
                                          TOTAL 22
```

**F(10) = 22.** We hit the Ford-Johnson optimum exactly.

---

## Why the Algorithm Works: Two Key Invariants

```/dev/null/invariants.txt#L1-12
INVARIANT 1 (after Phase 1 at level k):
   Within each meta-pair of groups, the loser-group has the smaller
   leader. Group leaders are still meaningful keys at the next level.

INVARIANT 2 (bound for inserting bᵢ in Phase 3):
   bᵢ < aᵢ  (established during pairing at level 0 for elements,
            propagated through deeper levels for whole groups)
   ⇒ when inserting bᵢ, binary search never needs to look past
     aᵢ's current position in the main chain.
   ⇒ search range size stays bounded by 2^k − 1 for items inserted
     in Jacobsthal block k, giving exactly k comparisons per insert
     in the worst case — and that's the Ford-Johnson optimum.
```

The Jacobsthal numbers (1, 3, 5, 11, 21, 43, ...) are chosen precisely so that the search range size at the *first* insertion of each block hits a power of 2 minus 1, making the binary search comparison-optimal.

# Ford-Johnson tester
This is a program that tests the implementation of the [Ford-Johnson algorithm](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91), also known as [merge-insertion sort](https://en.wikipedia.org/wiki/Merge-insertion_sort). The tester was made specifically for testing the exercises from cpp09 module from the common core of the 42 school, where you have to implement this algorithm.

https://github.com/user-attachments/assets/658ca645-9b64-4097-9269-9f833d97e17e

Just drop this single-file script into the directory with your program and run it against its executable.

## Prerequisites
This script requires Python 3.10 to run properly.

It also requires you to modify your program to print on separate lines:
- The sorted sequence. The format should be: `After: {number}, {number}, ... {number}`
- The number of comparisons. Add some variable to your program and increment it each time you compare numbers against each other. Then, print the number of comparisons in the format: `Number of comparisons: {number}`.

It expects something similar to this:
![image](https://github.com/user-attachments/assets/159ba7af-cbfe-45ff-9b9b-171ba739186b)

## Usage
Default usage:
```sh
python3 ford-johnson-tester.py
```

This will run the executable `./PmergeMe` using the default parameters.

You can specify the following CLI options:
```
python3 ford-johnson-tester.py -h                                  # prints help
python3 ford-johnson-tester.py --times={number}                    # how many times to run the executable against every single rage
python3 ford-johnson-tester.py --ranges={[start-end)[, start=end)} # specify ranges of numbers to test with inclusive start and exclusive end
python3 ford-johnson-tester.py --executable={path-to-executable}   # specify the path to the valid executable
python3 ford-johnson-tester.py --no-colors                         # if you hate fun and colors :( (or if you want to redirect stderr to somewhere without fancy styling)
python3 ford-johnson-tester.py --no-output-check                   # DO NOT check if the outputted sequence is sorted and corresponds to the input, use it if you know that your program sorts the number correctly and just want to benchmark it
```

## Example usage:
- Run the program `2000` times on the ranges of `0..21` and `10..40` numbers each.
```
python3 ford-johnson-tester.py --executable=./PmergeMe2 --times=2000 --ranges="0-21, 10-40"
```

- Do the same, but strip the colors and redirect the `stderr` to the `log.txt`.
```
python3 ford-johnson-tester.py --executable=./PmergeMe2 --times=2000 --ranges="0-21, 10-40" --no-colors 2> log.txt
```
