//LCS - longest comimon susequence.

#include <iostream>
#include < string>
#include <vector>

using namespace std;

int LCMDynamic(const string &s1, const string &s2)
{
	int strSize1 = s1.size();
	int strSize2 = s2.size();

	vector<vector<int>> K (strSize1+1, vector<int> (strSize2+1));

	int maxm = 0;
	for( int i = 1; i <= strSize1; ++i )
		for (int j = 1; j <= strSize2; ++j)
		{
			if(s1[i-1] == s2[j-1] )
				K[i][j] = 1 + K[i-1][j-1];
			else
				K[i][j] = max(K[i-1][j], K[i][j-1]); // checking diagonally 


		}//end for

	return K[strSize1][strSize2];
}//end LCMDynamic


int LCMRecursive(const string &s1, const string &s2, int i , int j )
{
	if(s1[i] == '\0' || s2[j] == '\0')
		return 0;
	else if(s1[i] == s2[j])
		return 1 + (LCMRecursive(s1, s2, i+1 , j+1 ));
	else
		return max(LCMRecursive(s1, s2, i+1 , j),LCMRecursive(s1, s2, i , j+1));  

}
int main(void)
{
	string s1 = "abcdaf";
	string s2 = "acbcf";

	cout<<"Longest common sub seq :- "<<LCMDynamic(s1,s2)<<endl;

	cout<<"Longest common sub seq recursive solution "<<LCMRecursive(s1,s2, 0, 0)<<endl;
}
