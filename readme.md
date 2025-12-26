# Constraint-Aware Task Scheduler

## Overview

Constraint-Aware Task Scheduler models a classical real-world scheduling problem where tasks compete for limited time and must be completed before their deadlines.

Each task is defined by a deadline and an execution duration. The system selects an optimal subset of tasks such that the maximum number of tasks are completed without violating deadline constraints.

This project emphasizes algorithmic problem-solving, greedy decision-making, and correctness under constraints—core skills required to design efficient and reliable software systems.

---
## Problem Description
Each task is defined by:
- a **deadline** (latest completion time)
- a **duration** (time required to execute)

Constraints:
- Only one task can be executed at a time
- Tasks are non-preemptive
- The objective is to **maximize the number of completed tasks**

---

## Approach
1. Tasks are sorted in increasing order of deadlines
2. Tasks are selected greedily while tracking total execution time
3. A **priority queue (max-heap)** stores durations of selected tasks
4. If total time exceeds the current deadline, the longest task is removed
5. Remaining tasks form an optimal schedule

This strategy ensures feasibility while preserving the maximum task count.

---

## Why This Works
When a deadline constraint is violated, removing the **longest task** frees the most time while minimally affecting earlier deadlines.  
This greedy choice leads to an optimal solution.

---

## Technologies Used
- **Programming Language:** C++
- **Algorithmic Paradigm:** Greedy Algorithms
- **Data Structures:** Priority Queue (Heap)
- **Tools:** Git, GitHub, Visual Studio Code
- **Libraries:** C++ Standard Template Library (STL)

---

## Complexity
**Time Complexity:**  
O(n log n), where *n* is the number of tasks (due to sorting and heap operations).

**Space Complexity:**  
O(n), for storing selected tasks in the priority queue.

---

## Example Usage


### Sample Input
```
Enter number of tasks: 5
Enter each task as: deadline   duration
 2 1 
 3 2 
 4 1 
 5 3 
 6 2

 ```


### Sample Output
Maximum tasks completed: 4

## Design Rationale
This project was chosen to demonstrate fundamental algorithmic reasoning commonly evaluated in technical interviews.  
It focuses on modeling constraints explicitly, making greedy decisions, and reasoning about optimality using data structures such as heaps.
