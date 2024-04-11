#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
public:
    int source;
    int dest;
    int weight;
};

// Comparator function to sort edges according to their weights
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent of a node in the disjoint-set (union-find)
int findParent(int v, int *parent) {
    if (parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent); // Path compression can be added here for optimization
}

// Kruskal's algorithm to find the MST of a graph
void kruskals(Edge *input, int n, int E) {
    sort(input, input + E, compare);

    Edge *output = new Edge[n - 1];
    int *parent = new int[n];

    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each vertex is its own parent initially
    }

    int count = 0; // Number of edges added to the MST
    int i = 0;     // Current edge index

    while (count < n - 1) {
        Edge currentEdge = input[i];

        // Finding the top-most parent of the source and destination vertices of the current edge
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        // If adding the current edge doesn't form a cycle
        if (sourceParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent; // Union operation
        }
        i++;
    }

    cout << "Final output:" << endl;
    for (int i = 0; i < n - 1; i++) {
        if (output[i].source < output[i].dest) {
            cout << output[i].source << "  " << output[i].dest << "  " << output[i].weight << endl;
        } else {
            cout << output[i].dest << "  " << output[i].source << "  " << output[i].weight << endl;
        }
    }

    delete[] output;
    delete[] parent;
}

int main() {
    int n, E;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> E;
    Edge *input = new Edge[E];

    cout << "Enter data of edges (source destination weight, in that order):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> input[i].source >> input[i].dest >> input[i].weight;
        // Adjusting for 0-based indexing if necessary
        input[i].source--;
        input[i].dest--;
    }

    kruskals(input, n, E);

    delete[] input;
    return 0;
}
