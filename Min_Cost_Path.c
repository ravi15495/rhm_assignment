#include<stdio.h>
#include<limits.h> 
#define R 3 
#define C 3
int min(int x, int y, int z); 

/* Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]*/
int minCost(int cost[R][C], int m, int n) 
{ 
	if (n < 0 || m < 0) 
		return INT_MAX; 
	else if (m == 0 && n == 0) 
		return cost[m][n]; 
	else
		return cost[m][n] + min( minCost(cost, m-1, n-1), 
				minCost(cost, m-1, n),  
				minCost(cost, m, n-1) ); 
} 

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z) 
{ 
	if (x < y) 
		return (x < z)? x : z; 
	else
		return (y < z)? y : z; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int n;
	int a;
	n=R;
	int cost[n+1][n+1];
	printf("\nEnter the matrix=");
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			scanf("%d", &a);
			cost[i][j]=a;
		}
	}

	int c,d;
	printf("\nEnter the path=");
	scanf("%d%d",&c,&d);
	printf("Minimum path is= %d ", minCost(cost, c, d)); 
	return 0; 
}
