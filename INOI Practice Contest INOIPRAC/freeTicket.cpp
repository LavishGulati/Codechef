#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

struct node{
    int vertex;
    int weight;
    node *next;
};

struct adjList{
    node *head;
};

struct graph{
    int num;
    adjList *array;
};

struct heapNode{
    int vertex;
    int weight;
};

struct heap{
    int size;
    int capacity;
    int *pos;
    heapNode **array;
};

node *createNode(int v, int w){
    node *newNode = new node;
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(int n){
    graph *newGraph = new graph;
    newGraph->num = n;
    newGraph->array = new adjList[n];
    for(int i = 0; i < n; i++){
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

void addEdge(graph *newGraph, int source, int dest, int weight){
    node *newNode = createNode(dest, weight);
    newNode->next = newGraph->array[source].head;
    newGraph->array[source].head = newNode;
}

heapNode *createHeapNode(int v, int w){
    heapNode *newNode = new heapNode;
    newNode->vertex = v;
    newNode->weight = w;
    return newNode;
}

heap *createHeap(int c){
    heap *newHeap = new heap;
    newHeap->pos = new int[c];
    newHeap->size = 0;
    newHeap->capacity = c;
    newHeap->array = new heapNode *[c];
    return newHeap;
}

void swapHeapNode(heapNode **a, heapNode **b){
    heapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(heap *minHeap, int id){
    int smallest, left, right;
    smallest = id;
    left = 2*id+1;
    right = 2*id+2;

    if(left < minHeap->size && minHeap->array[left]->weight < minHeap->array[smallest]->weight){
        smallest = left;
    }

    if(right < minHeap->size && minHeap->array[right]->weight < minHeap->array[smallest]->weight){
        smallest = right;
    }

    if(smallest != id){
        heapNode *smallestNode = minHeap->array[smallest];
        heapNode *idNode = minHeap->array[id];

        minHeap->pos[smallestNode->vertex] = id;
        minHeap->pos[idNode->vertex] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[id]);
        minHeapify(minHeap, smallest);
    }
}

bool isEmpty(heap *newHeap){
    return newHeap->size == 0;
}

heapNode *extractMin(heap *minHeap){
    if(isEmpty(minHeap)) return NULL;

    heapNode *root = minHeap->array[0];
    heapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(heap *minHeap, int v, int w){
    int i = minHeap->pos[v];
    minHeap->array[i]->weight = w;

    while(i && minHeap->array[i]->weight < minHeap->array[(i-1)/2]->weight){
        minHeap->pos[minHeap->array[i]->vertex] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->vertex] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);

        i = (i-1)/2;
    }
}

bool isInMinHeap(heap *minHeap, int v){
    if(minHeap->pos[v] < minHeap->size) return true;
    else return false;
}

int *dijkstra(graph *newGraph, int source){
    int n = newGraph->num;
    int *distance = new int[n];

    heap *minHeap = createHeap(n);
    for(int v = 0; v < n; v++){
        distance[v] = INT_MAX;
        minHeap->array[v] = createHeapNode(v, distance[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[source] = createHeapNode(source, distance[source]);
    minHeap->pos[source] = source;
    distance[source] = 0;
    decreaseKey(minHeap, source, distance[source]);

    minHeap->size = n;

    while(!isEmpty(minHeap)){
        heapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->vertex;

        node *temp = newGraph->array[u].head;
        while(temp != NULL){
            int v = temp->vertex;
            if(isInMinHeap(minHeap, v) && distance[u] != INT_MAX && temp->weight + distance[u] < distance[v]){
                distance[v] = temp->weight + distance[u];
                decreaseKey(minHeap, v, distance[v]);
            }
            temp = temp->next;
        }
    }

    return distance;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    graph *newGraph = createGraph(n);
    int u, v, p;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> p;
        addEdge(newGraph, u-1, v-1, p);
        addEdge(newGraph, v-1, u-1, p);
    }

    int **shortestPath = new int *[n];
    for(int i = 0; i < n; i++){
        shortestPath[i] = dijkstra(newGraph, i);
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(shortestPath[i][j] > max) max = shortestPath[i][j];
        }
    }

    cout << max << endl;
}
