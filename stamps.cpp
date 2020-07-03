#include <bits/stdc++.h>

using namespace std;


int main()
{

	int t;
	cin >> t;

	int s = 1;

	while (s <= t)
	{

		int w, n;
		cin >> w;
		cin >> n;

		int arr[n];

		for (int i = 0; i < n; i++)

			cin >> arr[i];

		sort(arr, arr + n, greater<int>());

		int sum = 0, b = 0, i = 0;

		while (sum < w && i < n)
		{

			sum += arr[i++];
			b++;

		}

		cout << "Scenario #" << s << ":\n";

		if (sum < w)

			cout << "impossible\n\n";

		else

			cout << b << endl << endl;

		s++;

	}

	return 0;

}