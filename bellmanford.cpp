#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <time.h>


using namespace std;

struct Edge
{

	int src, dest, weight;
};

struct Graph
{
	//V-> #Vertices E-> #Edges
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new struct Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new struct Edge [E];

	return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
//	clock_t t;
//	t = clock();

	int V = graph->V;
	int E = graph->E;
	int dist[V];

	//initialise distance from src->all vertices as infinite
	for(int i=0; i<V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	//iterate v-1 times

	for(int i=1; i<= V-1; i++)
	{
		//for every edge
		for(int j=0; j< E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;

			if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	//check for negative-weight cycles
	for(int i=0; i<E; i++)
	{
		int u=graph->edge[i].src;
		int v=graph->edge[i].dest;
		int weight = graph->edge[i].weight;

		if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
			cout << "Graph contains negative weight cycle" << endl;

	}

	cout << "V: " << V << endl;
	for(int i=0; i<V; i++)
	cout << i << "    " << dist[i] << endl;


}

void graph1(int n);
void graph2(int n);

int main()
{

	int V = 6;
	int E = 8;
	struct Graph* graph = createGraph(V, E);
 	 graph->edge[0].src = 0;
    graph->edge[0].dest = 5;
    graph->edge[0].weight = 8;
 
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 1;
    graph->edge[1].weight = 10;
 
 
    graph->edge[2].src = 5;
    graph->edge[2].dest = 4;
    graph->edge[2].weight = 1;
 
   
    graph->edge[3].src = 4;
    graph->edge[3].dest = 1;
    graph->edge[3].weight = -4;
 
 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 2;
 
  
    graph->edge[5].src = 2;
    graph->edge[5].dest = 1;
    graph->edge[5].weight = 1;
 
    graph->edge[6].src = 4;
    graph->edge[6].dest = 3;
    graph->edge[6].weight = -1;
 
   
    graph->edge[7].src = 3;
    graph->edge[7].dest = 2;
    graph->edge[7].weight = -2;

   
    BellmanFord(graph, 0);
 
    return 0;
}

