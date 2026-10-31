# Map Analysis Laboratory

## Core goal
Students must implement a dictionary-like `Map` structure that stores key-value pairs and supports lookup, insertion, deletion, and updates.

## Required operations
Students must implement the following behavior:

- insert a new key-value pair;
- reject duplicate keys;
- find whether a key exists;
- update an existing value;
- remove an existing key;
- retrieve a value by key;
- list keys and values;
- maintain sorted order if appropriate for the design.

## Analysis expectations
Students should discuss:

- average-case time complexity of insertion, lookup, and deletion;
- best-case and worst-case behavior;
- why duplicate-key handling matters;
- the difference between a search by key and scanning all entries;
- trade-offs between sorted vectors and hash-based maps;
- memory overhead and performance of `keys()` and `values()`.

## Big-O focus
Students should explain the Big-O of:

- `insert`
- `contains`
- `update`
- `erase`
- `at`
- `keys`
- `values`

The expected design is a clear, well-explained mapping abstraction that makes trade-offs explicit.
