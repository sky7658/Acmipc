#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void Insert_Word(queue<string>& q, string str)
{
	string buffer;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			q.push(buffer);
			buffer = "";
			continue;
		}
		buffer += str[i];
	}
	q.push(buffer);
}

int main()
{
	int n;
	string l;
	cin >> n;
	vector<queue<string>> birds(n);

	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		getline(cin, l);
		Insert_Word(birds[i], l);
	}

	getline(cin, l);
	queue<string> write;
	Insert_Word(write, l);

	bool check = false;

	while (!write.empty())
	{
		for (int j = 0; j < birds.size(); j++)
		{
			if (!birds[j].empty() && write.front() == birds[j].front())
			{
				birds[j].pop();
				write.pop();
				check = true;
				break;
			}
		}
		if (!check)
		{
			cout << "Impossible";
			return 0;
		}
		check = false;
	}
		

	for (int i = 0; i < birds.size(); i++)
	{
		if (!birds[i].empty())
		{
			cout << "Impossible";
			return 0;
		}
	}
	cout << "Possible";
	return 0;
}