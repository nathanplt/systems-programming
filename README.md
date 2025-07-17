# Systems Programming

This repository contains exercises in systems-level programming, exploring OS primitives, memory behavior, and performance benchmarks using C.

## Overview

### `fork-tests/`
Experiments with process creation using `fork()`:
- `fork.c` to `fork8.c`: Various exercises demonstrating parent-child execution order, zombie processes, `wait()`, and process trees

### `latency-tests/`
Microbenchmarks for key system-level operations:
- `measure_ctxt_swtch.c`: Measures context switch latency via pipes between processes
- `measure_write.c`: Measures syscall latency of `write()` using timers

### `memory-api/`
Programs exploring dynamic memory and memory safety:
- `malloc.c`: Tests heap allocation patterns
- `null.c`: Attempts to dereference a null pointer
- `undefined.c`: Demonstrates effects of uninitialized memory

### `vector/`
Custom dynamic array (vector) implementation in C:
  - `vector.c`, `vector.h`: Core vector logic
  - `main.c`: Sample usage

## Learning goals

- Deepen understanding of OS-level primitives (processes, memory, I/O)
- Practice writing safe, low-level C code
- Benchmark and reason about system performance

## Future plans

- Add `Makefile`s for easier compilation in each directory
- Write signal handling tests (`sigaction`, `kill`, `alarm`)
- Build simple `malloc`/`free` allocator to understand heap internals
- Experimeent with multithreading using `pthreads`
- Include TCP/UDP socket communication demos
- Use CLI tools like `valgrind`, `gprof`, and `perf` for performance optimization and debugging

## How to run

To compile and run any of the C files, use `clang` or `gcc`:

```bash
clang your_file.c -o your_program
./your_program
```