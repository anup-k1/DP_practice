#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int p[] = {0,1,2,5,6};
	int wt[] = {0,2,3,4,5};

	int m = 8;
	int n = 4;
	int row = 0, col = 0;
	row = n;
	//int K[5][9];

	//Create row and col with 1 extra space 

	vector<vector<int>> K(n+1, vector<int>(m+1,0));	//K[5][9]

	for(int i = 0; i <= n; i++)
	{
		for(int w = 0 ; w <= m; w++)
		{
			if( i == 0 || w == 0)
			{
				K[i][w] = 0;
				continue;
			}
			else if( wt[i] <= w )
			{
				K[i][w] = max(p[i] + K[i-1][w - wt[i]], K[i-1][w]);
				//K[i-1][w] --> previous row
				//p[i] --> profit value at i --> weight
				// K[i-1][w - wt[i] --> if any wt is remaining, will trave back in 2d array
			}
			else 
			{
				K[i][w] =K[i-1][w];
				//this is simple carraying above value --> this is the best we can select.
			}

		}
	}
	cout<<K[n][m]<<endl<<endl;

	//Printing the array.
	for (int i = 0; i < K.size(); i++)
	{
		for (int j = 0; j < K[i].size(); j++)
		{
			cout << K[i][j] << " ";
		}    
		cout << endl;
	}

	//Which rows are selected

	int i = n, j = m;

	while( i > 0 && j >0)
	{
		if(K[i][j] == K[i-1][j])
		{
			cout<<i<<"= 0"<<endl;
			i--;
		}
		else
		{
			cout<<i<< "= 1 "<<endl;

			j = j - wt[i];
			i--;
		}


	}



}


