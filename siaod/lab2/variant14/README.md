# This program writed on Linux for Linux
# Variant 14

```txt
Построить стягивающее дерево неориентированного графа методом
поиска в ширину и вывести список рёбер дерева. Граф задан в текстовом
файле матрицей инциденций.
```

## to build

```shell
cd /path/to/project/dir
make
./bin/main
```

## example input

```txt
4 5
1 0 0 1 0
1 1 0 0 1
0 1 1 1 0
0 0 1 0 1
```

## example graph

```txt
0  3
|\/|
|/\|
1--2
```

## example output

```shell
❯ make
g++ -o bin/main src/main.cpp -Wall -std=c++11
❯ ./bin/main
Spanning tree edges:
0 - 3
0 - 1
3 - 2
```
