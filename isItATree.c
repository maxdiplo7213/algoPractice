#include <stdio.h>
#define MAX 20000


int stack[MAX], top = -1;

void push(int value);
int pop();


int main()
{

	// Number of nodes 'n' and number of edges 'm' //
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	
	if (m == n - 1 && m != 0)
	{

		int adjMatrix[n + 1][n + 1];

		for (int i = 0; i < n + 1; i++)
			
			for (int j = 0; j < n + 1; j++)
			
				adjMatrix[i][j] = 0;


		// Input the edges present between their respective nodes //
		for (int i = 0; i < m; i++)
		{

			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);

			adjMatrix[x][y] = 1;
			adjMatrix[y][x] = 1;

		}

		// "flag" checks whether there's a cycle or not // 
		int flag = 0;

		push(1);
		int nodesVisited = 0, x;

		// While stack is not empty, keep on popping //
		while (top != -1)
		{
			
			x = pop();

			adjMatrix[x][0]++;

			// This checks whether it contains a cycle or not //
			if (adjMatrix[x][0] > 1)
			{

				flag = 1;
				break;

			}

			adjMatrix[0][x]++;

			for (int i = 1; i < n + 1; i++)
			{

				// Push only those nodes that have not been visited and are adjacent to the current popped node //
				if (adjMatrix[x][i] == 1 && adjMatrix[0][i] == 0)

					push(i);

			}

			nodesVisited++;

		}

		// Check if there was a cycle present in the graph, or if the graph was disconnected //
		if (flag == 1 || nodesVisited < n)

			printf("NO\n");

		else

			printf("YES\n");

	}

	else

		printf("NO\n");


	return 0;

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