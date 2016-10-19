// 8.3 Write a method that returns all subsets of a set.

// Idea:
// Map each element in the subset as a bit, then print according the bit 
// bit patten.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<vector<int> >* subsets(vector<int> s)
{
	int num = pow(2, s.size());
	vector<vector<int> >* res = new vector<vector<int> >();
	for(int i = 0; i < num; ++i)
	{
		vector<int>* tmp = new vector<int>();
		for(int j = 0; j < s.size(); ++j)
		{
			if((1 << j & i) > 0)
				tmp->push_back(s[j]);
		}
		res->push_back(*tmp);
	}

	return res;
}

void print_vv(vector<vector<int> >& vv)
{
	for(int i = 0; i < vv.size(); ++i)
	{
		cout << "{ ";
		for(int j = 0; j < vv[i].size(); ++j)
			cout << vv[i][j] << ", ";
		cout << "},\n";
	}

}

int main()
{
	int size = 4;
	vector<int> v;
	for(int i = 0; i < 4; ++i)
		v.push_back(i);

	vector<vector<int> >* res = subsets(v);

	sort(res->begin(), res->end(), [](vector<int> a, vector<int> b){ 
		return a.size() < b.size(); });
	print_vv(*res);

	return 0;
}






