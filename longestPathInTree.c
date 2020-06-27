#include <stdio.h>
#include <stdlib.h>
#define MAX 10000


int stack[MAX], top = -1;

int n;

void push(int value);
int pop();
int compare(const void * a, const void * b);

int dfs(int nodeNumber, int adjMatrix[][n + 1]);


int main()
{

	// Number of nodes //
	int N;
	scanf("%d", &N);

	int *p = &n;
	*p = N;

	if (n == 1)

		printf("0\n");

	else
	{

		int adjMatrix[n + 1][n + 1];

		for (int i = 0; i < n + 1; i++)

			for (int j = 0; j < n + 1; j++)

				adjMatrix[i][j] = 0;


		// Take input for the edges //
		for (int i = 0; i < n - 1; i++)
		{

			int x, y;

			scanf("%d", &x);
			scanf("%d", &y);

			adjMatrix[x][y] = 1;
			adjMatrix[y][x] = 1;

		}

		// Start from node 1, i.e. consider it as the root node, and mark it as visited. //
		int l = 0;
		push(1);
		adjMatrix[0][1] = 1;
		adjMatrix[1][0] = 1;

		for (int i = 1; i < n + 1; i++)
		{

			if (adjMatrix[1][i] == 1)
			{
				l++;
				push(i);

				// Mark the node as visited //
				adjMatrix[0][i] = 1;
				adjMatrix[i][0] = 1;

			}

		}

		// Paths array of the subtrees of the node 1 (the root node) //
		int paths[l];

		// Get the paths for the subtrees of the node 1 using recursive dfs //
		for (int i = 0; i < l; i++)
		{

			int x = pop();

			paths[i] = dfs(x, adjMatrix);

		}

		// Sort the "paths" array and return the sum of the contents of the last and the second last index //

		int ans;

		if (l == 1)

			ans = paths[0];

		else
		{

			qsort(paths, l, sizeof(int), compare);

			ans = paths[l - 1] + paths[l - 2];

		}

		printf("%d\n", ans);

	}
	
	return 0;

}


int dfs(int nodeNumber, int adjMatrix[][n + 1])
{

	// Figure out how many unvisited adjacent nodes the "nodeNumber" node has //
	int x = 0;

	for (int i = 1; i < n + 1; i++)
	{

		// Push only that adjacent node which is unvisited //
		if (adjMatrix[nodeNumber][i] == 1 && adjMatrix[0][i] == 0)
		{

			x++;
			push(i);

			// Mark the node as visited //
			adjMatrix[0][i] = 1;
			adjMatrix[i][0] = 1;

		}

	}

	// If the node has no unvisited adjacent nodes, then we backtrack //
	if (x == 0)
	{

		adjMatrix[nodeNumber][0] = 1;
		adjMatrix[0][nodeNumber] = 1;

		return 1;

	}

	// Else we go in more depth //
	else
	{

		// Path lengths array for the the node "nodeNumber"s subtrees //
		int pArray[x];

		// Represents the max path length from the node "nodeNumber" to its subtrees //
		int max = 0;

		// Get the paths of the subtrees for the node "nodeNumber" using recursive dfs //
		for (int i = 0; i < x; i++)
		{

			int z = pop();

			pArray[i] = dfs(z, adjMatrix);

			if (max < pArray[i])

				max = pArray[i];
		
		}

		return (max + 1);

	}

}


int compare(const void * a, const void * b) 
{

    return ( *(int*)a - *(int*)b ); 

}

void push(int value)
{

	top++;
	stack[top] = value;

}

int pop()
{

	return stack[top--];

}