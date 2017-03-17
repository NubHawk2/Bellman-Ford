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

	//cout << "V: " << V << endl;
	//for(int i=0; i<V; i++)
	//	cout << i << "    " << dist[i] << endl;

//	t = clock() - t;
//	double timeTaken = (double)(t)/CLOCKS_PER_SEC;
//	cout << "Time Taken: " << timeTaken << endl;
}

void graph1(int n);
void graph2(int n);

int main()
{
/*
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 (or B-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 */

	int V = 6;
	int E = 8;
	struct Graph* graph = createGraph(V, E);
 	 graph->edge[0].src = 0;
    graph->edge[0].dest = 5;
    graph->edge[0].weight = 8;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 1;
    graph->edge[1].weight = 10;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 5;
    graph->edge[2].dest = 4;
    graph->edge[2].weight = 1;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 4;
    graph->edge[3].dest = 1;
    graph->edge[3].weight = -4;
 
    // add edge 1-4 (or B-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 2;
    graph->edge[5].dest = 1;
    graph->edge[5].weight = 1;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 4;
    graph->edge[6].dest = 3;
    graph->edge[6].weight = -1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 3;
    graph->edge[7].dest = 2;
    graph->edge[7].weight = -2;

   //	tStart = clock();
    BellmanFord(graph, 0);
  //  tEnd = clock();
  //  cout << "Time Taken: " <<  ((double)(tEnd-tStart)/(double)CLOCKS_PER_SEC) << endl;
   for(int i=100; i<=1000; i+= 100)
   {
   		graph1(i);
   		cout << endl;
   		graph2(i);
   		cout << endl;
   }

    return 0;
}


void graph1(int n)
{
	clock_t t;
	

	int V= n;
	int E = n;
	struct Graph* graph = createGraph(V, E);
	for(int i=0; i< n; i++)
	{
		graph->edge[i].src = i;
		graph->edge[i].dest = (i+1)%n;
		graph->edge[i].weight = rand()%10 + 1;
	}
	t=clock();
	BellmanFord(graph,0);


	t = clock() - t;
	double timeTaken = (double)(t)/CLOCKS_PER_SEC;
	cout << "Time Taken for V=" << V << " and E=" << E << " is " << timeTaken << " seconds" << endl;
}

void graph2(int n)
{
	clock_t t;

	int V = n;
	int E = n*(n-1);

struct Graph* graph = createGraph(V, E);

	int edgeCount = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			graph->edge[edgeCount].src = i;
			graph->edge[edgeCount].dest = j;
			graph->edge[edgeCount].weight = rand()%10 + 1;
			//cout << "src: " << i << " dest: " << j << " weight: " << graph->edge[edgeCount].weight << endl; 
			edgeCount++;

			graph->edge[edgeCount].src = j;
			graph->edge[edgeCount].dest = i;
			graph->edge[edgeCount].weight = rand()%10 + 1;
			//cout << "src: " << j << " dest: " << i << " weight: " << graph->edge[edgeCount].weight << endl; 
			edgeCount++;
		}
	}
	t=clock();
	BellmanFord(graph,0);
	t = clock() - t;
	double timeTaken = (double)(t)/CLOCKS_PER_SEC;
	cout << "Time Taken for V=" << V << " and E=" << E << " is " << timeTaken << " seconds" << endl;
}