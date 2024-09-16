// Variant 14

// Построить стягивающее дерево неориентированного графа методом
// поиска в ширину и вывести список рёбер дерева. Граф задан в текстовом
// файле матрицей инциденций.

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

// func to read incidence matix from file
std::vector<std::vector<int>> readIncidenceMatrix(std::string filename) {
    std::fstream infile(filename, std::ios_base::in);
    if (!infile.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        exit(EXIT_FAILURE);
    }
    int vertices, edges;

    infile >> vertices >> edges; // Чтение количества вершин и рёбер
    std::vector<std::vector<int>> incidenceMatrix(vertices, std::vector<int>(edges, 0));

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            int tmp;
            infile >> tmp;
            incidenceMatrix[i][j] = tmp;
        }
    }

    infile.close();
    return incidenceMatrix;
}

// func to get adjacent vertices
std::vector<int> getAdjacentVertices(const std::vector<std::vector<int>>& incidenceMatrix, int vertex, int edges) {
    std::vector<int> adjacent;
    for (int i = 0; i < edges; ++i) {
        if (incidenceMatrix[vertex][i] == 1) {
            for (int j = 0; j < incidenceMatrix.size(); ++j) {
                if (incidenceMatrix[j][i] == 1 && j != vertex) {
                    adjacent.push_back(j);
                }
            }
        }
    }
    return adjacent;
}

// func for constucting a spanning tree using the breadth-first search method
void buildSpanningTree(const std::vector<std::vector<int>>& incidenceMatrix) {
    int vertices = incidenceMatrix.size();
    int edges = incidenceMatrix[0].size();
    std::vector<bool> visited(vertices, false);
    std::vector<std::pair<int, int>> spanningTreeEdges;

    std::queue<int> q;
    visited[0] = true; // start from first vertex
    q.push(0);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        std::vector<int> adjacent = getAdjacentVertices(incidenceMatrix, currentVertex, edges);
        for (int neighbor : adjacent) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                spanningTreeEdges.push_back({currentVertex, neighbor});
                q.push(neighbor);
            }
        }
    }

    // print spanning tree edges
    std::cout << "Spanning tree edges:" << std::endl;
    for (const auto& edge : spanningTreeEdges) {
        std::cout << edge.first << " - " << edge.second << std::endl;
    }
}

int main() {
    std::string filename = "incidence_matrix.txt"; // filename of incidence matrix
    // int vertices, edges;

    // read incidence matrix
    std::vector<std::vector<int>> incidenceMatrix = readIncidenceMatrix(filename);

    // constucting a spanning tree
    buildSpanningTree(incidenceMatrix);

    return 0;
}
