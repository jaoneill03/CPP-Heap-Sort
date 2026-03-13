# C++ Heapsort

A C++ program that reads long integers from a file, sorts them using
heapsort, and writes the sorted results to an output file.

## How to compile & run

**Compile:**
```bash
g++ heapsort.cpp -o heapsort
```

**Run:**
```bash
./heapsort inputfile.txt outputfile.txt
```

## Usage

The program takes two command-line arguments — an input file and an output file:
- **Input file** — a text file containing one long integer per line
- **Output file** — where the sorted numbers will be written

**Example:**
```
./heapsort numbers.txt sorted.txt
```

## How it works

- Reads integers into a vector starting at index 1
- Builds a max heap using a bottom-up `buildMaxHeap` call
- Repeatedly swaps the root with the last unsorted element
  and calls `heapify` to restore the heap property
- Time complexity: O(n log n)

## Technologies
- C++
- STL vectors
- File I/O (ifstream / ofstream)
