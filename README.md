*This project has been created as part of the 42 curriculum by mozay, sumdogan*.

# Push_swap

# 📋 Description

**Push_swap** is a sorting algorithm project that sorts data on a stack using a limited set of instructions with the lowest possible number of actions.

The program takes a list of integers as input and outputs a sequence of operations that sorts the stack in **ascending order**.

The challenge lies in sorting the numbers efficiently using only **two stacks** (`stack a` and `stack b`) and the following restricted operations:

```
sa, sb, ss    -> Swap operations
pa, pb        -> Push operations
ra, rb, rr    -> Rotate operations
rra, rrb, rrr -> Reverse rotate operations
```

The project demonstrates understanding of:

* Algorithm complexity
* Data structures
* Optimization techniques
* Low-level program design

---

# 🧮 Algorithms Implemented

## 1️⃣ Simple Algorithm — O(n²) — Bubble Sort

### Implementation

The **bubble sort** algorithm repeatedly steps through the stack, compares adjacent elements, and swaps them if they are in the wrong order.
This process continues until the stack is fully sorted.

### Justification

This algorithm serves as a **baseline implementation**.

It is:

* Easy to implement
* Easy to understand
* Suitable for **very small stacks (≤5 elements)**

The quadratic complexity is acceptable for such small inputs and avoids the overhead of more complex algorithms.

---

## 2️⃣ Medium Algorithm — O(n√n) — Block-Based Sort

### Implementation

The stack is divided into **√n sized chunks** based on element indices.

Steps:

1. Elements are pushed to **stack b** chunk by chunk.
2. After all chunks are transferred, elements are returned to **stack a**.
3. The algorithm always moves the **maximum element in stack b to the top** before pushing it back.

### Justification

This approach:

* Reduces the number of operations compared to O(n²)
* Keeps implementation complexity reasonable
* Works well for **medium sized stacks (6–100 elements)**

---

## 3️⃣ Complex Algorithm — O(n log n) — Radix Sort Adaptation

### Implementation

This algorithm simulates a **heap-like selection strategy**:

1. Find the **maximum element in stack a**
2. Rotate stack `a` until the element reaches the top
3. Push it to **stack b**
4. Repeat until stack `a` is empty
5. Push all elements back from **b → a**

Occasional swaps are used to maintain correct order.

### Justification

In the push_swap model, **operation count** is the main cost.

This approach:

* Reduces total operations
* Performs well for **large inputs (100+ elements)**

---

## 4️⃣ Adaptive Algorithm — Disorder-Based Strategy

### Implementation

The algorithm first calculates a **disorder metric** of the stack:

```
0   = already sorted
1   = reverse sorted
```

Based on this metric, the program automatically selects the best strategy.

| Disorder Level | Algorithm Used       | Complexity |
| -------------- | -------------------- | ---------- |
| < 0.2          | Bubble Sort          | O(n²)      |
| 0.2 – 0.5      | Block-Based Sort     | O(n√n)     |
| ≥ 0.5          | Radix Sort Adaptation| O(n log n) |

### Justification

No single algorithm performs optimally for every input.

Adaptive selection allows:

* Faster sorting for **nearly sorted stacks**
* Better performance for **highly disordered stacks**
* Improved **average-case efficiency**

---

# ✨ Features

* ✅ **Multiple Sorting Strategies** – Four algorithms with different complexity classes
* ✅ **Runtime Strategy Selection** – Choose algorithms using command-line flags
* ✅ **Benchmark Mode** – Detailed operation statistics with `--bench`
* ✅ **Disorder Calculation** – Automatic measurement of input disorder
* ✅ **Error Handling** – Validation for invalid inputs
* ✅ **Memory Management** – Proper allocation and deallocation

Input validation includes:

* Non-integer values
* Duplicate numbers
* Out-of-range values

---

# 🛠️ Instructions

## Prerequisites

* CC Compiler
* Make
* Unix-like OS (Linux / macOS)

---

## Compilation

```bash
# Compile the program
make

# Remove object files
make clean

# Remove object files and executable
make fclean

# Recompile from scratch
make re
```

After compilation, the executable `push_swap` will be created.

---

# 🚀 Execution

## Basic Usage

```bash
# Pass numbers as separate arguments
./push_swap 5 2 8 1 9

# Pass numbers as a single quoted string
./push_swap "5 2 8 1 9"

# Use a variable
ARG="5 2 8 1 9"; ./push_swap $ARG
```

---

## Strategy Selection

```bash
# Simple algorithm
./push_swap --simple 5 2 8 1 9

# Medium algorithm
./push_swap --medium 5 2 8 1 9

# Complex algorithm
./push_swap --complex 5 2 8 1 9

# Adaptive algorithm (default)
./push_swap --adaptive 5 2 8 1 9
```

---

# 📊 Benchmark Mode

```bash
# Run with benchmark statistics
./push_swap --bench 5 2 8 1 9

# Save benchmark output
./push_swap --bench 5 2 8 1 9 2> bench.txt

# Combine with strategy selection
./push_swap --bench --complex 5 2 8 1 9
```

---

# ✔ Using With Checker

```bash
ARG="5 2 8 1 9"
./push_swap $ARG | ./checker_linux $ARG
```

Benchmark and verify:

```bash
ARG="5 2 8 1 9"
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
```

---

# 📈 Performance Testing

### 100 Random Numbers

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

### Benchmark Test

```bash
./push_swap --bench $ARG 2> bench.txt
cat bench.txt
```

### 500 Random Numbers

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
echo "Operation count: $(./push_swap $ARG | wc -l)"
```

---

# 📊 Example Outputs

## Normal Execution

```
$ ./push_swap 5 2 8 1 9

pb
pb
ra
pa
pa
```

---

## Benchmark Mode

```
$ ./push_swap --bench 5 2 8 1 9

pb
pb
ra
pa
pa

[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 5
[bench] sa: 0 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 1 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

# ❌ Error Handling

Duplicate values:

```
$ ./push_swap 5 2 8 1 2
Error
```

Out-of-range values:

```
$ ./push_swap 5 2 8 1 2147483648
Error
```

Invalid input:

```
$ ./push_swap 5 2 8 1 "abc"
Error
```

# 📚 Resources

### Documentation

* 42 School Norm
* Push_swap Subject
* Big O Notation

### Articles

* Sorting Algorithms Visualized
* Stack Data Structure
* Bubble Sort
* Heap Sort

### Tools

* Push_swap Visualizer
* Checker for Linux

---

# 🤖 AI Usage

Artificial intelligence tools were used **ethically and responsibly** during development.

AI assistance included:

### Algorithm Design

* Chunk size optimization for block sort
* Heap-based element selection strategies
* Disorder threshold tuning

### Code Structure

* Splitting functions to comply with **42 Norm (≤25 lines)**
* Reducing parameter counts
* Improving modular file organization

### Debugging

* Memory leak detection
* Edge case identification
* Operation sequence optimization

### Documentation

AI helped generate:

* README structure
* Documentation text
* Code comments

---

# 👥 Contributors

| Name     | Role      | Contributions                                              |
| -------- | --------- | ---------------------------------------------------------- |
| mozay    | Developer | Algorithm implementation, stack operations, error handling ,bench operations|
| sumdogan | Developer | Algorithm implementation,arguman checks , testing , memory managements      |

Both contributors participated in all stages of development and fully understand the entire codebase.
