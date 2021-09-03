#include <bits/stdc++.h>

using namespace std;

string remove_dup(string s)
{
	if (s.size() == 1)
	{
		return "";
	}
	string valid = remove_dup(s.substr(1));
	if (s[0] == valid[0])
	{
		return valid;
	}
	return (s[0] + valid);
}

int main()
{
	cout << remove_dup("aaaabbbbccdddddddeeeeeeeee") << endl;
	return 0;
}
