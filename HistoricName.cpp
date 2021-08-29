#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string name;
		getline(cin, name);
		int j = 0;
		string correct = "";
		string a = ". ";
		if (name[0] >= 'a')
			name[0] -= 32;
		for (int i = 1; i < name.size(); ++i)
		{
			if (name[i] == ' ')
			{
				correct += name[j];
				correct += a;
				i++;
				j = i;
				if (name[i] >= 'a')
					name[i] -= 32;
			}
			else
			{
				if (name[i] <= 'Z')
				{
					name[i] += 32;
				}
			}
		}
		correct += name.substr(j);

		cout << correct << endl;
	}
	return 0;
}
