*This project has been created as part of the 42 curriculum by nweber.*

# push_swap

## Description

`push_swap` sorts a stack of unique integers using a second stack and a fixed set of 11 instructions (`sa sb ss pa pb ra rb rr rra rrb rrr`), printing the instruction list to stdout. The goal is to sort with as few instructions as possible.

The optional `checker` program (bonus) reads instructions from stdin, applies them to the given stack and prints `OK` or `KO`.

### Algorithm

| Size | Strategy |
|------|----------|
| sorted / 0-1 elements | nothing printed |
| 2 | `sa` |
| 3 | hard-coded case analysis (≤ 2 operations) |
| 4-7 | selection sort: push the smallest element to `b` (rotating the cheaper way), sort the last 3, push everything back |
| 8+ | **chunked push to `b`**: values are replaced by their sorted index; indices within a sliding window (`sqrt(n) * 1.4`) are pushed to `b`, small ones are rotated to the bottom of `b`, the rest of `a` is rotated. Then the largest remaining element is repeatedly brought to the top of `b` (`rb` or `rrb`, whichever is shorter) and pushed back with `pa` |

Measured over random inputs: 100 numbers ≈ 580 operations (worst seen 629), 500 numbers ≈ 5070 operations (worst seen 5345).

### Error handling

`Error\n` on stderr (exit code 1) for: non-integers, values outside `int` range, duplicates, empty-string arguments, stray signs (`-`, `--1`, `1-2`). Arguments can be given separately (`1 2 3`) or quoted (`"1 2 3"`) or mixed. A leading `+`/`-` sign is accepted, as are leading zeros.

## Instructions

```bash
make          # builds push_swap
make bonus    # builds checker
make clean | fclean | re
```

```bash
./push_swap 2 1 3 6 5 8
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG     # OK
./checker 3 2 1 0                                          # then type instructions, one per line, Ctrl+D
```

Checker behaviour: no argument → no output; every instruction must end with `\n`; unknown / malformed instruction, blank line or invalid argument → `Error` on stderr; otherwise `OK` (sorted and `b` empty) or `KO` on stdout.

Quick benchmark:

```bash
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

## Project structure

```
Makefile
includes/   push_swap.h  checker_bonus.h
srcs/       push_swap.c (main) parsing.c sort.c logic.c utils.c operations.c stack_utils.c
bonus_srcs/ checker_bonus.c input_bonus.c parsing_bonus.c operations_bonus.c operations_utils_bonus.c utils_bonus.c
libft/      libft (used for ft_split, ft_isdigit, ft_sqrt, ...)
```

## Resources

- 42 subject: *push_swap* (v10.1)
- [Push_swap: the least amount of moves with two stacks (Medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Sorting algorithm complexity - Big-O cheat sheet](https://www.bigocheatsheet.com/)
- [Insertion sort / selection sort - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- `valgrind`, `norminette` for leak and norm checks

### Use of AI

AI (Claude Code) was used to review the finished project, find edge-case bugs (parsing, error codes, a double free in the checker, memory handling), write throw-away test scripts (exhaustive permutation tests for n ≤ 8, random benchmarks, valgrind runs), rename the bonus files to the `_bonus` convention and draft this README. The sorting algorithm itself was designed and written by the author; all AI-suggested changes were read, compiled and tested before being kept.
