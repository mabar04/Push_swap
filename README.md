
*This project has been created as part of the 42 curriculum by mabar.*

# 📦 Push_swap

## Description
`push_swap` is a sorting program whose objective is to sort a list of integers using a minimal set of stack operations.  
The program uses two stacks (`a` and `b`) and a constrained instruction set (`sa`, `pb`, `ra`, etc.).  
The goal is not only to produce a correct result, but also to optimize for performance by minimizing the number of moves.

This project focuses on:
- algorithmic thinking
- optimization strategies
- data structures (linked lists, stacks)
- low-level problem solving in C

---

## Instructions

This produces the `push_swap` binary at the root of the repository.
To compile the program use `make` command 
To compile the bonus part use `make bonus`
To remove the object files and leave the program use `make clean`
To remove the program with object files use `make fclean`
To clean all and rebuild the program use `make re`

To execute the program you need to write `./push_swap` and the arguments (list that you want to sort)

### Example 
./push_swap 1 5 9 3 2 0

## Resources

### 📚 Documentation & References
- Sorting Algorithms (Quick Sort, Merge Sort, Insertion Sort, etc.)
- Data Structures (Stacks & Linked Lists)
- 42 Subject PDF & Evaluation Guides

### 🤖 Use of AI During Development
AI assistance was used for:
- clarifying C language behavior (pointer semantics, lists, memory)
- debugging specific segmentation faults and logic errors
- rewriting buggy indexing logic for the compressed sorting stage
- improving code readability (variable naming, loop structures)
- producing this README formatting

All implementations, algorithms, and architectural decisions were written and validated manually.

---

### Features
- handles positive/negative integers
- checks for duplicates & invalid input
- assigns compressed indexes for faster sorting
- chunk-based logic for larger inputs
- optimized small cases (3 & 5 elements)

### Technical Choices
- doubly linked list for O(1) rotate & reverse rotate
- index compression to avoid manipulating raw values
- Turc strategie + some chunk to get the best moves
- custom checker for debugging

---

## Authors
42 login: `mabar`
Language: C

