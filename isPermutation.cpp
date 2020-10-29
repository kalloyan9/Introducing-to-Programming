#include<iostream>
using namespace std;
bool isPermutation(int* A, int sizeA, int* B, int sizeB)
{
    if(sizeA!=sizeB)    return false;
    bool used[sizeA];
    for(int i=0;i<sizeA;++i) used[i]=0;

	for (int i = 0; i < sizeA; ++i)
	{
		int currentElement = A[i];
		bool foundCurr = false;
		for (int j = 0; j < sizeB; ++j)
		{
		    cout<<currentElement << " " << B[j] << " " << used[j] << endl;
		    if(!used[j])
            {
                if (B[j] == currentElement)
                {
                    used[j] = true;
                    foundCurr = true;
                    break;
                }
            }
		}
		if (!foundCurr) return false;
	}
	return true;
}


int main()
{
    int n, m;
    cin >> n;
    int A[n];
    for(int i=0;i<n;++i) cin >>A[i];
    cin >> m;
    int B[m];
    for(int i=0;i<m;++i) cin >>B[i];

    cout<<isPermutation(A,n, B,m);


    return 0;
}
/*
3
2 2 9
3
2 9 7

3
2 9 7
3
2 2 9
*/
