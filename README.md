# push_swap

## Description
push_swap is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations. It implements the push_swap algorithm, which is designed to minimize the number of operations required to sort the stack efficiently.

The project is written in C and consists of two programs: push_swap and checker. The push_swap program generates a series of instructions to sort the stack, while the checker program verifies if the stack is indeed sorted. The goal is to achieve sorting with the minimum number of instructions.

## Features
- Sorting a stack of integers using a limited set of operations.
- Visualization of the sorting process (optional).
- Efficiency optimization to minimize the number of operations required.
- Error handling and validation of input data.
- Detailed statistics and analysis of the sorting process.

## Installation
1. Clone the repository:

git clone https://github.com/bbenidar/push_swap.git

2. Navigate to the project directory:

```➜  ~ ✗ cd push_swap```

3. Build the push_swap and checker programs:

```➜  ~/push_swap ✗ make```



4. The push_swap and checker executables will be created.

## Usage
1. To sort a stack of integers, run the push_swap program followed by the integers as arguments:

```➜  ~/push_swap ✗ ./push_swap 5 3 8 1 2```


2. The program will output a series of instructions to sort the stack.

3. To verify if the stack is sorted, you can run the

```➜  ~/push_swap ✗ ./push_swap 5 3 8 1 2 | ./checker 5 3 8 1 2```


4. The checker program will output "OK" if the stack is sorted, or "KO" otherwise.

## Algorithm
The push_swap algorithm utilizes a combination of various sorting techniques, including divide-and-conquer, insertion sort, and a chunk-based approach, to achieve efficient sorting with a limited set of operations.

The chunk-based approach involves dividing the stack into chunks and performing sorting operations on each chunk separately. This allows for the efficient handling of larger stacks by reducing the number of required instructions. The algorithm identifies the maximum and minimum values in each chunk and performs operations to move these values to their correct positions.

The exact chunk size and strategies for dividing and sorting chunks can vary based on the specific implementation and the number of elements in the stack.

## Contributing
Contributions to push_swap are welcome! If you find any issues or have suggestions for improvements, please submit a pull request or open an issue on the project's GitHub repository.
