#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = ((num - 1) - i); j > 0; j--)
		{
			cout << " ";
		}

		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}

		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}