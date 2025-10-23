[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21244609&assignment_repo_type=AssignmentRepo)
# Week 10 Mon Lab

## Directions

You are going to implement the two elementary search algorithms (**sequential** and **binary**) as discussed in lecture. You will need to create two versions of each: one iterative and the other recursive. This program relies on the `Dictionary` ADT being implemented by using an array-based list as the underlying data structure.

There are 4 methods that you need to implement for the `ArrayListDictionary` class. One of these methods is being called by the `find` method. After you implement one of the algorithms, it is suggested that you adjust the `find` method to call the one you want to test, commenting out the others.

A working `main` function is already provided. Use this to test your various search algorithms.

## Notes

- The elements in the dictionary are stored in the `list` pointer attribute as `Record` objects
    + To access elements in `list`, you need to use the `getElement` method
    + If you want to access the key or value of a record, you need to use the `.` member of object operator
- If the search is unsuccessful, simply throw any exception (like -1, for example)
    + This will trigger the `catch` in the `find` method, which throws the proper error message
- Each search algorithm needs to keep track of how many key comparisons are being performed
    + There is already an attribute, `numComps`, for this purpose
    + Make sure that you're incrementing this as the algorithm proceeds
- For the binary search algorithm, you may assume the data is sorted in ascending order

## Sample Run

If you managed to implement these algorithms correctly, you should be able to match the following sample runs exactly, regardless if it's the iterative or recursive version.

### Sequential Search

```text
Enter a key to search my dictionary (or -1 to stop): graph
an awesome data structure!
Number of key comparisons: 4
Enter a key to search my dictionary (or -1 to stop): banana
a fruit that many like, or a phone
Number of key comparisons: 1
Enter a key to search my dictionary (or -1 to stop): igloo
a cool house
Number of key comparisons: 6
Enter a key to search my dictionary (or -1 to stop): zebra
find: error, unsuccessful search, target key not found
Number of key comparisons: 8
Enter a key to search my dictionary (or -1 to stop): apple
find: error, unsuccessful search, target key not found
Number of key comparisons: 8
Enter a key to search my dictionary (or -1 to stop): -1
```

### Binary Search

```text
Enter a key to search my dictionary (or -1 to stop): graph
an awesome data structure!
Number of key comparisons: 1
Enter a key to search my dictionary (or -1 to stop): banana
a fruit that many like, or a phone
Number of key comparisons: 5
Enter a key to search my dictionary (or -1 to stop): igloo
a cool house
Number of key comparisons: 3
Enter a key to search my dictionary (or -1 to stop): zebra
find: error, unsuccessful search, target key not found
Number of key comparisons: 8
Enter a key to search my dictionary (or -1 to stop): apple
find: error, unsuccessful search, target key not found
Number of key comparisons: 6
Enter a key to search my dictionary (or -1 to stop): -1
```

