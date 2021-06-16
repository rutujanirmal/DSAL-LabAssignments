/*
Lab Assignment 8
Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each key ki.
Build the Binary search tree that has the least search cost given the access probability for each key.
*/
#include <iostream>
#include <limits.h>
using namespace std;


int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
		s += freq[k];
	return s;
}


int optCost(int keys[], int freq[], int n) {
	int cost[n][n];
	for (int i = 0; i < n; i++)   
		cost[i][i] = freq[i];

	for (int length=2; length<=n; length++) 
	{
		for (int i=0; i<=n-length+1; i++) 
		{    
			int j = i+length-1;
			cost[i][j] = INT_MAX; 

			for (int r=i; r<=j; r++) 
			{
				int c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+sum(freq, i, j);
				if (c < cost[i][j])
				cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}


int main()
{
    int n;
    cout<<"Enter the number of keys :: ";
    cin>>n;
	int keys[10],freq[10];
    for(int i=0;i<n;i++){
        cout<<"Key["<<i<<"] :: ";
        cin>>keys[i];
		cout<<"Freq["<<i<<"] :: ";
		cin>>freq[i];
    }
	cout << "Cost of Optimal BST is "
		<< optCost(keys, freq, n);
	return 0;
}

//Input
//10 - 34
//12 -  8
//20 - 50

//Expected output
//142

