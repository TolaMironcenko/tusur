# This program writed on Linux for Linux
# Variant 14

```txt
Задать последовательность чисел. Написать программу, выполняющую построение и вывод бинарного дерева на экран. Для построенного дерева найти все вершины, имеющие поддеревья одинаковой высоты, и для
каждой из этих вершин вывести список потомков. После выполнения программы очистить память, занятую древовидной структурой
```

## to build

```shell
cd /path/to/project/dir
make
./bin/main
```

## example input

```cpp
std::vector<int> nums = {40, 20, 60, 10, 11, 24, 46, 80, 456, 123, 789}; // example input
```

## example tree

```txt
               40
            /      \
           20      60
          /  \    /  \
         10  24  46  80
          \            \
          11          456
                     /   \
                    123  789
```

## example output

```shell
❯ make
g++ -o bin/main src/main.cpp -Wall
❯ ./bin/main
Order tree: 10 11 20 24 40 46 60 80 123 456 789 
Node: 11 have subtrees height: 0
Subtrees: 
Node: 24 have subtrees height: 0
Subtrees: 
Node: 46 have subtrees height: 0
Subtrees: 
Node: 456 have subtrees height: 1
Subtrees: 123 789 
Node: 123 have subtrees height: 0
Subtrees: 
Node: 789 have subtrees height: 0
Subtrees: 
```
