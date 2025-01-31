#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> A)
{
	int n = A.size();
	if (n <= 1) return 0; //single element array

	int i = 0, count = 0;
	int min, p;
	//p - position to jump to
	while (i != (n - 1))
	{
		//we will stop jumping once we reach the end
		if (A[i] == 0)
		{
			//if we get stuck in a position where we can't jump forward
			return -1;
		}
		min = n - (i + 1) - A[i + 1];
		p = i + 1;
		for (int j = i + 1; j <= (i + A[i]); ++j)
		{
			if (j >= n)
				break;
			if ((n - j - A[j]) < min)
			{
				p = j;
				min = n - j - A[j];
			}
		}
		i = p;
		count++; //counting the number of jumps
	}
	return count;
}

int main()
{
	cout << "20001\t Donald Knuth\t";
	int t;
	cin >> t;
	cin.ignore();

	while (t--)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);

		vector<int> arr;
		int num;

		while (ss >> num)
			arr.push_back(num);

		int num_of_jumps = jump(arr);
		cout << num_of_jumps << "\n";
	}
	cout << endl;
	return 0;
}