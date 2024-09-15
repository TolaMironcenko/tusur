# This program writed on Linux for Linux
# Variant 3

```txt
Дана последовательность чисел. Построить бинарное дерево, содержащее эти числа. Произвести обход дерева справа налево и вывести результаты на экран. После выполнения программы очистить память, занятую древовидной структурой.
```

## to build

```shell
cd /path/to/project/dir
make
./bin/main
```

## example input

```cpp
std::vector<int> nums = {40, 20, 60, 10, 11, 24, 46, 80, 456, 123}; // example input
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
                     /
                    123 
```

## example output

```shell
❯ make
g++ -o bin/main src/main.cpp -Wall
❯ ./bin/main
go tree from right to left: 456 123 80 60 46 40 24 20 11 10 
```
