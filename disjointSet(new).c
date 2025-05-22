#include <stdio.h>

#define N 10000

int parent[N];  // declare the parent array
int rank[N];    // declare the rank array

void makeSet(int v) {
    parent[v] = v;
    rank[v] = 0;
}

// Using Path Compression
/*int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
} */    

// Without Path Compression
int findSet(int v) {
    if (v == parent[v]) 
        return v;
    return findSet(parent[v]);
} 

// -- UNION BY RANK -- //
void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) { 
        if (rank[a] < rank[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

// -- NORMAL UNION -- //
// void unionSet(int a, int b) {
//     a = findSet(a);
//     b = findSet(b);
//     if(a != b) {
//         parent[b] = a;
//     }
// }


int main() {
    // Initialize sets
    for (int i = 0; i < N; i++) {
        makeSet(i);
    }

    // Perform some unions
    for (int i = 0; i < N - 1; i++) {
        unionSet(i, i + 1);
    }

    // Print the parent of each element
    printf("Element : Set Representative\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d : Parent %d\n", i, findSet(i));
    }

    return 0;
}
