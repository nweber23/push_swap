# push_swap
A highly efficient sorting algorithm implementation using only stack operations, developed as part of the 42 School curriculum.

## Overview
This project implements a sorting algorithm using two stacks and a limited set of operations. The goal is to sort a list of integers in ascending order using the minimum number of operations possible. The program demonstrates algorithm optimization, data structure manipulation, and complexity analysis in C.

## Features
### Core Functionality
- Sorts integers using only two stacks (A and B)
- Implements 11 specific stack operations (push, pop, swap, rotate)
- Optimized algorithms for different input sizes
- Outputs the sequence of operations needed to sort
- Handles edge cases and error conditions gracefully

### Bonus Features
- **Checker Program**: Validates if a sequence of operations correctly sorts the stack
- **Interactive Verification**: Reads operations from stdin and verifies the result
- **Complete Validation**: Checks both correctness and final stack state

### Algorithm Optimization
- **Small Lists (≤3)**: Direct sorting with minimal operations
- **Medium Lists (4-7)**: Optimized minimal sorting algorithm
- **Large Lists (>7)**: Advanced partitioning with LIS-based optimization
- **Complexity Target**: Achieves excellent performance benchmarks

## Project Structure
```
.
├── Makefile                     # Build configuration
├── includes/
│   ├── push_swap.h              # Main header file
│   └── checker.h                # Checker program header
├── srcs/                        # Core implementation
│   ├── push_swap.c              # Main program logic
│   ├── logic.c                  # Sorting algorithms
│   ├── operations.c             # Stack operations
│   ├── parsing.c                # Input validation and parsing
│   ├── stack_utils.c            # Stack manipulation utilities
│   └── utils.c                  # General utilities
├── bonus_srcs/                  # Bonus implementation
│   ├── checker.c                # Main checker logic
│   ├── operations.c             # Checker stack operations
│   ├── operations_utils.c       # Combined operations
│   ├── parsing.c                # Input parsing for checker
│   └── utils.c                  # Checker utilities
└── libft/                       # Custom C library (external)
```

## Compilation
### Prerequisites
- GCC or compatible C compiler
- Make build system
- Custom libft library (included)

### Build Commands
```bash
# Main program
make

# Checker program
make bonus

# Build both programs
make all bonus

# Clean object files
make clean

# Full cleanup
make fclean

# Rebuild everything
make re
```

## Usage
### Basic Usage (Sorting)
```bash
# Sort a list of integers
./push_swap 3 1 4 1 5 9 2 6

# Sort with quoted arguments
./push_swap "3 1 4" "1 5" "9 2 6"

# Mixed argument formats
./push_swap 42 "21 84" 168

# Example output:
pb
ra
pb
ra
pb
sa
pa
pa
pa
```

### Bonus Usage (Checker)
```bash
# Verify a sequence of operations
./push_swap 3 1 2 | ./checker 3 1 2
# Output: OK

# Manual verification
./checker 3 1 2
sa
rra
# Press Ctrl+D
# Output: OK

# Check invalid sequence
echo -e "sa\nrra\npb" | ./checker 3 1 2
# Output: KO
```

## Stack Operations
### Single Stack Operations
- **sa/sb**: Swap the first two elements of stack A/B
- **ra/rb**: Rotate stack A/B (move top element to bottom)
- **rra/rrb**: Reverse rotate stack A/B (move bottom element to top)

### Dual Stack Operations
- **ss**: Execute sa and sb simultaneously
- **rr**: Execute ra and rb simultaneously  
- **rrr**: Execute rra and rrb simultaneously
- **pa/pb**: Push top element from B to A / A to B

## Algorithm Details
### Sorting Strategies
```bash
# 2 elements: 1 operation maximum
./push_swap 2 1
# Output: sa

# 3 elements: 2-3 operations maximum
./push_swap 3 2 1
# Output: sa, rra

# 4-7 elements: Minimal sorting algorithm
./push_swap 5 3 1 4 2
# Uses optimized small-scale sorting

# 8+ elements: Advanced partitioning
./push_swap 8 3 5 1 9 2 7 4 6
# Uses chunk-based sorting with rotation optimization
```

### Performance Benchmarks
- **3 elements**: ≤ 3 operations
- **5 elements**: ≤ 12 operations
- **100 elements**: ≤ 700 operations (target: ~550)
- **500 elements**: ≤ 5500 operations (target: ~5000)

## Implementation Details
- **Memory Management**: Zero memory leaks with proper cleanup
- **Input Validation**: Comprehensive error checking for duplicates and invalid input
- **Integer Indexing**: Uses sorted indices for optimization
- **Rotation Optimization**: Calculates optimal rotation direction
- **Standards Compliance**: Follows 42 School coding standards (Norminette)

## Error Handling
```bash
# Duplicate numbers
./push_swap 1 2 3 2
# Output: Error

# Invalid input
./push_swap 1 2 abc
# Output: Error

# Integer overflow
./push_swap 2147483648
# Output: Error

# Empty input
./push_swap
# No output, exits successfully

# Single number
./push_swap 42
# No output (already sorted)
```

## Advanced Features
### Checker Program Validation
- Reads operations from standard input
- Executes operations on the provided stack
- Outputs "OK" if final state is sorted with empty stack B
- Outputs "KO" if operations are invalid or result is incorrect
- Handles malformed operation names gracefully

### Input Format Support
- **Space-separated**: `./push_swap 1 2 3`
- **Quoted groups**: `./push_swap "1 2" "3"`
- **Mixed formats**: `./push_swap 1 "2 3"`
- **Negative numbers**: `./push_swap -1 0 1`

## Performance Analysis
### Time Complexity
- **Best Case**: O(n) for already sorted input
- **Average Case**: O(n log n) for random input
- **Worst Case**: O(n²) for reverse sorted input

### Space Complexity
- **Stack Memory**: O(n) for input storage
- **Operation Output**: O(n log n) operations generated

## Testing Examples
```bash
# Generate random test
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Performance benchmark
./push_swap $(seq 1 500 | shuf | tr '\n' ' ') | wc -l
```

## Technical Specifications
- **Integer Range**: Handles full 32-bit signed integer range
- **Input Limit**: No artificial limit on number of elements
- **Operation Limit**: Optimized for competitive benchmarks
- **Memory Usage**: Efficient stack-based implementation
- **Error Codes**: Standard exit codes for different error types

## Author
**nweber** - 42 Heilbronn Student
