#include <vector>
using namespace std;

vector<int> insert(vector<int> vec, int elem, int index)
{
	
}

vector<int> erase(vector<int> vec, int index)
{
	
}

long long sum(vector<int> vec)
{
	
}

double mean(vector<int> vec)
{
	
}

int min(vector<int> vec)
{
	int min = 2e9;
	for (int el : vec)
	{
		if (el < min)
			min = el;
	}
	return min;
}

int max(vector<int> vec)
{
	int max = -2e9;
	for (int el : vec)
	{
		if (el > max)
			max = el;
	}
	return max;
}

int sum_of_digit(int num)
{
	
}
