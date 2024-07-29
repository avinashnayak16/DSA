#include <stdio.h>
#include <limits.h>

#define V 26

void printGraph(int graph[V][V])
{
    printf("Graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

void printSolution(int dist[], int parent[])
{
    printf("\nShortest Paths from Source (0) to other vertices:\n");
    for (int i = 1; i < V; i++)
    {
        printf("Path to vertex %d: 0 ", i);
        printPath(parent, i);
        printf("   Distance: %d\n", dist[i]);
    }
}

void dijkstra(int graph[V][V])
{
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent);
}

int main()
{
   int graph[V][V] = {
    {0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 3, 0, 6, 3, 6, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 7, 0, 0, 0, 0, 4, 8, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1},
    {0, 7, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1, 0, 0, 8, 0, 6, 0, 0, 0, 0},
    {0, 0, 0, 0, 5, 0, 3, 6, 2, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0},
    {0, 0, 0, 5, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 6, 0},
    {9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 3, 0},
    {8, 0, 0, 3, 8, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 0, 4, 0, 0},
    {0, 4, 0, 6, 0, 0, 0, 0, 0, 0, 7, 0, 0, 9, 10, 0, 0, 6, 5, 0, 0, 0, 0, 0, 4, 10},
    {0, 8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 10, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, 6, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 0, 0, 0, 8, 5, 7, 0, 0, 0, 0, 0, 4, 0, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0},
    {0, 5, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 5, 0, 0, 10, 0, 1, 9, 0, 0, 7, 0, 2, 0, 0},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 10, 0, 3, 0, 0, 0, 0, 7, 5, 0, 0, 0},
    {3, 0, 0, 0, 7, 0, 0, 9, 0, 1, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 6, 0},
    {6, 0, 9, 0, 0, 0, 5, 10, 1, 6, 0, 0, 10, 0, 0, 0, 4, 3, 0, 0, 0, 3, 0, 0, 8, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
    {5, 0, 1, 0, 0, 0, 0, 0, 8, 6, 6, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 7, 7},
    {0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 2, 7, 7, 2, 3, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 6},
    {0, 4, 0, 6, 1, 0, 0, 0, 10, 0, 8, 0, 5, 0, 0, 0, 8, 0, 0, 0, 10, 0, 0, 0, 0, 7},
    {0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 3, 0},
    {0, 0, 0, 0, 6, 3, 0, 4, 0, 0, 0, 0, 0, 6, 8, 3, 0, 0, 0, 0, 7, 0, 0, 3, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 10, 3, 0, 0, 0, 0, 0, 0, 3, 4, 0, 9, 0, 7, 6, 7, 0, 0, 0}
};

    //printGraph(graph);
    dijkstra(graph);

    return 0;
}
/*#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>
#define MAX_LOCATIONS 26
#define V 26

struct Location
{
    char name[100];
    int distance;
    bool isHotel; // New field to indicate if it's a hotel
};

void printGraph(int graph[V][V])
{
    printf("Graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(struct Location locations[], int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(locations, parent, parent[j]);
    printf("-> %s ", locations[j].name);
}

void printSolution(struct Location locations[], int dist[], int parent[])
{
    printf("\nShortest Paths from Source (0) to other vertices:\n");
    for (int i = 1; i < V; i++)
    {
        printf("Path to vertex %d: 0 ", i);
        printPath(locations, parent, i);
        printf("   Distance: %d\n", dist[i]);
    }
}

void dijkstra(struct Location locations[], int graph[V][V], int source)
{
    // Modified to take the source as an argument
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(locations, dist, parent);
}

int main()
{
     struct Location locations[MAX_LOCATIONS] = {
        {"Anand Nagar", 0, true},
        {"Akshay colony", 0, false},
        {"Siddaroodha Swami Matha", 0, true},
        {"Krupa Nagar", 0, false},
        {"Unkal Lake", 0, true},
        {"Nrupatunga Hill", 0, true},
        {"Airpot Hubballi", 0, false},
        {"Kletech univercity", 0, false},
        {"Keshawapur", 0, false},
        {"Deshpande Nagr", 0, false},
        {"Railway station", 0, false},
        {"Urban Oasis mall", 0, false},
        {"Gobbur", 0, false},
        {"Old Hubballi", 0, true},
        {"Raynal", 0, false},
        {"Rajendra Nagar", 0, true},
        {"Tolakere", 0, false},
        {"Rajnagar", 0, true},
        {"Durgad Bail", 0, false},
        {"Yellapura", 0, false},
        {"Mavanur", 0, false},
        {"Nuggikeri", 0, false},
        {"Dharwad", 0, true},
        {"Mansur", 0, false},
        {"Belligatti", 0, true},
        {"Amargol", 0, true}};

    // Example adjacency matrix representing connections between locations
    int adjacencyMatrix[MAX_LOCATIONS][MAX_LOCATIONS] = {
        {0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 3, 0, 6, 3, 6, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 0, 4, 8, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1},
        {0, 7, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1, 0, 0, 8, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 3, 6, 2, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 6, 0},
        {9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 3, 0},
        {8, 0, 0, 3, 8, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 0, 4, 0, 0},
        {0, 4, 0, 6, 0, 0, 0, 0, 0, 0, 7, 0, 0, 9, 10, 0, 0, 6, 5, 0, 0, 0, 0, 0, 4, 10},
        {0, 8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 10, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, 6, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 8, 5, 7, 0, 0, 0, 0, 0, 4, 0, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 5, 0, 0, 10, 0, 1, 9, 0, 0, 7, 0, 2, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 10, 0, 3, 0, 0, 0, 0, 7, 5, 0, 0, 0},
        {3, 0, 0, 0, 7, 0, 0, 9, 0, 1, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 6, 0},
        {6, 0, 9, 0, 0, 0, 5, 10, 1, 6, 0, 0, 10, 0, 0, 0, 4, 3, 0, 0, 0, 3, 0, 0, 8, 0},
        {0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
        {5, 0, 1, 0, 0, 0, 0, 0, 8, 6, 6, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
        {0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 7, 7},
        {0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 2, 7, 7, 2, 3, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 6},
        {0, 4, 0, 6, 1, 0, 0, 0, 10, 0, 8, 0, 5, 0, 0, 0, 8, 0, 0, 0, 10, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 3, 0},
        {0, 0, 0, 0, 6, 3, 0, 4, 0, 0, 0, 0, 0, 6, 8, 3, 0, 0, 0, 0, 7, 0, 0, 3, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 10, 3, 0, 0, 0, 0, 0, 0, 3, 4, 0, 9, 0, 7, 6, 7, 0, 0, 0}};
    //printGraph(adjacencyMatrix);

   int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);

    if (source >= 0 && source < V)
    {
        dijkstra(locations, adjacencyMatrix, source);
    }
    else
    {
        printf("Invalid source vertex.\n");
        return 1; // Exit with an error code
    }

    return 0;
}*/
/*#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_LOCATIONS 26
#define V 26

struct Location
{
    char name[100];
    int distance;
    bool isHotel; // New field to indicate if it's a hotel
};

void printGraph(int graph[V][V])
{
    printf("Graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(struct Location locations[], int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(locations, parent, parent[j]);
    printf("-> %s ", locations[j].name);
}

void printSolution(struct Location locations[], int dist[], int parent[], int hotels[], int numHotels)
{
    printf("\nShortest Paths from Source to Hotels:\n");
    for (int i = 0; i < numHotels; i++)
    {
        int hotelIndex = hotels[i];
        printf("To Hotel %s: 0 ", locations[hotelIndex].name);
        printPath(locations, parent, hotelIndex);
        printf("   Distance: %d\n", dist[hotelIndex]);
    }
}

void dijkstra(struct Location locations[], int graph[V][V], int source, int hotels[], int numHotels)
{
    // Modified to take the source as an argument
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(locations, dist, parent, hotels, numHotels);
}

int findLocationIndex(struct Location locations[], char target[])
{
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        if (strcmp(locations[i].name, target) == 0)
            return i;
    }

    return -1; // Not found
}

int main()
{
    struct Location locations[MAX_LOCATIONS] = {
        {"Anand Nagar", 0, true},
        {"Akshay colony", 0, false},
        {"Siddaroodha Swami Matha", 0, true},
        {"Krupa Nagar", 0, false},
        {"Unkal Lake", 0, true},
        {"Nrupatunga Hill", 0, true},
        {"Airpot Hubballi", 0, false},
        {"Kletech univercity", 0, false},
        {"Keshawapur", 0, false},
        {"Deshpande Nagr", 0, false},
        {"Railway station", 0, false},
        {"Urban Oasis mall", 0, false},
        {"Gobbur", 0, false},
        {"Old Hubballi", 0, true},
        {"Raynal", 0, false},
        {"Rajendra Nagar", 0, true},
        {"Tolakere", 0, false},
        {"Rajnagar", 0, true},
        {"Durgad Bail", 0, false},
        {"Yellapura", 0, false},
        {"Mavanur", 0, false},
        {"Nuggikeri", 0, false},
        {"Dharwad", 0, true},
        {"Mansur", 0, false},
        {"Belligatti", 0, true},
        {"Amargol", 0, true}};

    // Example adjacency matrix representing connections between locations
    int adjacencyMatrix[MAX_LOCATIONS][MAX_LOCATIONS] = {
        {0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 3, 0, 6, 3, 6, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 0, 4, 8, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1},
        {0, 7, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1, 0, 0, 8, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 3, 6, 2, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 6, 0},
        {9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 3, 0},
        {8, 0, 0, 3, 8, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 0, 4, 0, 0},
        {0, 4, 0, 6, 0, 0, 0, 0, 0, 0, 7, 0, 0, 9, 10, 0, 0, 6, 5, 0, 0, 0, 0, 0, 4, 10},
        {0, 8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 10, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, 6, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 8, 5, 7, 0, 0, 0, 0, 0, 4, 0, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 5, 0, 0, 10, 0, 1, 9, 0, 0, 7, 0, 2, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 10, 0, 3, 0, 0, 0, 0, 7, 5, 0, 0, 0},
        {3, 0, 0, 0, 7, 0, 0, 9, 0, 1, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 6, 0},
        {6, 0, 9, 0, 0, 0, 5, 10, 1, 6, 0, 0, 10, 0, 0, 0, 4, 3, 0, 0, 0, 3, 0, 0, 8, 0},
        {0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
        {5, 0, 1, 0, 0, 0, 0, 0, 8, 6, 6, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
        {0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 7, 7},
        {0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 2, 7, 7, 2, 3, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 6},
        {0, 4, 0, 6, 1, 0, 0, 0, 10, 0, 8, 0, 5, 0, 0, 0, 8, 0, 0, 0, 10, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 3, 0},
        {0, 0, 0, 0, 6, 3, 0, 4, 0, 0, 0, 0, 0, 6, 8, 3, 0, 0, 0, 0, 7, 0, 0, 3, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 10, 3, 0, 0, 0, 0, 0, 0, 3, 4, 0, 9, 0, 7, 6, 7, 0, 0, 0}};

    // Set 10 locations as hotels
    int hotels[10] = {5, 8, 13, 14, 16, 18, 22, 23, 24, 25};

    char userLocation[100];
    printf("Enter your current location: ");
    scanf("%s", userLocation);

    int source = findLocationIndex(locations, userLocation);

    if (source != -1)
    {
        // Considering only hotels that are within a certain distance (e.g., 10)
        int nearbyHotels[10];
        int numNearbyHotels = 0;

        for (int i = 0; i < 10; i++)
        {
            if (adjacencyMatrix[source][hotels[i]] <= 10)  // Modify the distance threshold as needed
            {
                nearbyHotels[numNearbyHotels++] = hotels[i];
            }
        }

        if (numNearbyHotels > 0)
        {
            dijkstra(locations, adjacencyMatrix, source, nearbyHotels, numNearbyHotels);
        }
        else
        {
            printf("No nearby hotels found.\n");
        }
    }
    else
    {
        printf("Invalid source location.\n");
        return 1; // Exit with an error code
    }

    return 0;
}
*/