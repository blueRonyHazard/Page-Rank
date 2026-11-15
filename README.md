# Page-Rank

Proposed the mathematical methods of ranking web pages and compared the total probability of sites and total iterations to converge of all the methods using same inputs.

This repository holds two versions of the project:

- **2021 version (root folder):** the 5th-semester project at IIT (ISM) Dhanbad. It covers the original PageRank algorithm and two modified algorithms, with a LaTeX report (`PageRank.tex`).
- **2017 original (`2017-original/`):** the first implementation, previously the separate `PageRank-in-MATLAB` repository. Its full commit history is preserved.

## 2021 version

| File | Algorithm |
|---|---|
| `pr.cpp` | Original PageRank (damping factor 0.85, 2500 iterations) |
| `pri.cpp` | Original PageRank, iterating until convergence and counting iterations |
| `prw.cpp` | Modified algorithm 1: weighted graph |
| `prwi.cpp` | Weighted graph, iterating until convergence |
| `prd.cpp` | Modified algorithm 2: dynamic probability |
| `prdi.cpp` | Dynamic probability, iterating until convergence |

The programs read the graph from `input0.txt`, `input1.txt` or `inputw.txt` and write the results to `output*.txt` in the same folder. These input files are not included. Each input file starts with `n m` (number of pages and links), followed by `m` lines of `from to`.

Results comparing the methods:

![Total probability by method](Totalprob.png)
![Iterations to converge by method](iteration.png)

## 2017 original

| File | Algorithm |
|---|---|
| `pagerank.cpp` | Original PageRank, 10 iterations |
| `pagerank_it.cpp` | Original PageRank, iterating until convergence |
| `pagerank_mod.cpp` | Modified version where pages don't start with equal probability |
| `pagerank_mod_it.cpp` | Modified version, iterating until convergence |

These programs read from the keyboard. They ask for the number of sites, then for each site the number of outgoing links followed by the linked sites. Each `.png` in the folder shows the output of the program with the same name.

## Build and run

```bash
g++ -O2 -o pr pr.cpp && ./pr
```
