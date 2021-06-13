#include <iostream>
using namespace std;
string format(double size)
{
	string a[] =
		{"B", "Kb", "Mb", "Gb", "Tb", "Bb"};
	int i;
	for (i = 0; size >= 1024; i++)
	{
		size /= 1024;
	}
	string r(to_string(size));
	/*
	for (int i = 0; r.find('.') < r.length(); i++)
	{
		if (r[r.length() - 2] == '0')
		{
			r.pop_back();
		}
		else
			break;
	}*/
	while (r[r.length() - 3] != '.')
	{
		r.pop_back();
	}
	return (r + " " + a[i]);
}
int main(int argc, char *argv[])
{
	string b = "";
	for (double i = 0; 4; i += 100000000000)
	{
		cout << format(i) << endl;
		b += " ";
	}
}