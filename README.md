# Huffman coding | Data Structure
Project for compressing files using the Huffman Tree to compress them using data structures such as binary tree, hash table, queue and heap.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/204195385-acc6fcd4-05a7-4f25-87d1-cb7d5cc5c852.png" alt="animated" />
</p>

<center>

## Students
  - [Matheus Ryan da Silva Nascimento](https://github.com/TETEURYAN)
  
## What is Huffman's Compression?

Huffman compression is a way to shrink the size of digital files without losing any information. It's particularly useful for files where some characters appear more often than others, like text files or code.For example, the letter 'e' might be very common in English text, so it might get a code like '0'. The letter 'z', being much less common, might get a code like '1100'. By using shorter codes for frequent characters, Huffman coding reduces the overall file size

## Data Structure used in Huffman Coding

1. **Priority Queue**: The priority queue comes in to help us build the Huffman tree based on these frequencies of bits.
2. **Hash Table**: Hash tables store data using key-value pairs. The key acts like a unique identifier for a particular piece of information, which is the value.
3. **Binary Tree**: The binary tree will be used to store the bit frequency according to the highest appearance priority.

## How to execute?

The algorithm input is the file "data/encode.huff", which is of type string. The output of the algorithm will be "data/decode.huff", which will be the bits stored in Huffman compression.

1. Compile the program using make:

  ```make```
  
2. If you want help, fo any of the next things in your bash:

```
  -h : show help
  -f <file> : choose the input of algorithm
```
  
