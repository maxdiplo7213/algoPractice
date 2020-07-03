#include <bits/stdc++.h>

using namespace std;


void divide(long long int A[], int l, int r);
void merge(long long int A[], int l, int m, int r);
int in();

int inversions = 0;


int main()
{

	int t;
	t = in();

	while (t--)
	{

		int n;
		n = in();

		long long int arr[n];

		for (int i = 0; i < n; i++)

			arr[i] = in();


		divide(arr, 0, n - 1);

		cout << inversions << "\n";

		inversions = 0;

	}

	return 0;

}


void divide(long long int A[], int l, int r)
{

	if (l != r)
	{

		int m = l + ((r - l) / 2);

		divide(A, l, m);
		divide(A, m + 1, r);

		merge(A, l, m, r);

	}

}

void merge(long long int arr[], int l, int m, int r)
{

	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    long long int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
     
        L[i] = arr[l + i]; 
    
    for (j = 0; j < n2; j++) 
    
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    
    while (i < n1 && j < n2) 
    { 
    
        if (L[i] <= R[j]) 
        { 
        
            arr[k] = L[i]; 
            i++; 
        
        } 
        else 
        { 
        
            arr[k] = R[j]; 
            j++;
            inversions += n1 - i;
        
        } 
        
        k++; 
    }
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
    
        arr[k] = L[i]; 
        i++; 
        k++; 
    
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
    
        arr[k] = R[j]; 
        j++; 
        k++; 
    
    }

}

int in()
{
    
    char c;
    
    do
	{

		c = getchar_unlocked();
	
	}while (c <= 32);
    
    int res=0;
    
    do
    {

		res = (res<<1)+(res<<3)+c-'0';
		c = getchar_unlocked();
 
    }while (c > 32);
 
    return res;
}