// 9.7 A circus is designing a tower routine consisting of people standing atop
//     one another's shoulders. For practical and aesthetic reasons, each 
//     person must be both shorter and lighter than the person below him or her
//     . Given the heights and weights of each person in the circus, write a 
//     method to compute the largest possible number of people in such a tower.

//     Example:
//     Input (ht, wt): (65, 100), (70, 150), (56, 90), (75, 190), (60, 95), 
//     (68, 110)
//     Output: The longest tower is length 6 and includes from top to bottom: 
//     (56, 90), (60,95), (65,100), (68,110), (70,150), (75,190).

#include <iostream>
#include <vector>

using namespace std;

struct HtWt
{
	int height;
	int weight;
	HtWt(int h, int w) : height(h), weight(w) {}

	bool is_before(HtWt hw)
	{
		if(height <= hw.height && weight <= hw.weight)
			return true;
		return false;
	}

};

bool height_less_than(HtWt a, HtWt b)
{
	return a.height < b.height;
}

bool weight_less_than(HtWt a, HtWt b)
{
	return a.weight < b.weight;
}


class LongestManTower
{
	vector<HtWt>* items;
	vector<HtWt>* last_found_seq;
	vector<HtWt>* max_seq;

public:

	LongestManTower(vector<HtWt>& input)
	{
		items = new vector<HtWt>();
		for(auto i : input)
			items->push_back(i);
		last_found_seq = new vector<HtWt>();
		max_seq = new vector<HtWt>();
	}

	vector<HtWt>* seq_with_max_length(vector<HtWt>* seq1, vector<HtWt>* seq2)
	{
		return seq1->size() > seq2->size() ? seq1 : seq2;
	}

	int fill_next_seq(int start, vector<HtWt>* seq)
	{
		cout << "start: " << start << endl;
		int first_unfit = start;
		int found_first_unfit = false;
		if(start < items->size())
		{
			for(int i = start; i < items->size(); ++i)
			{
				HtWt item = (*items)[i];
				if(i == start || (*items)[i-1].is_before(item))
				{
					seq->push_back(item);
					// cout << "pushed: " << i << endl;
				}
				else if(!found_first_unfit)
				{
					// cout << "set first_unfit to " << i << endl;
					first_unfit = i;
					found_first_unfit = true;
				}
			}
		}
		return first_unfit;
	}

	void find_max_seq()
	{
		sort(items->begin(), items->end(), height_less_than);
		sort(items->begin(), items->end(), weight_less_than);

		print_items();

		int cur_unfit = 0;
		while(cur_unfit < items->size())
		{
			vector<HtWt>* next_seq = new vector<HtWt>();
			int next_unfit = fill_next_seq(cur_unfit, next_seq);

			max_seq = seq_with_max_length(max_seq, next_seq);
			if(next_unfit == cur_unfit) // Found the last possible seq
				break;
			else
				cur_unfit = next_unfit;
		}
	}

	void print_seq(vector<HtWt>* seq, string msg)
	{
		cout << msg;
		for(auto item : *seq)
			cout << "(" << item.height << ", " << item.weight << "), ";
		cout << endl;
	}

	void print_max_seq()
	{
		string msg = "Max seq: ";
		print_seq(max_seq, msg);
	}

	void print_items()
	{
		string msg = "Items: ";
		print_seq(items, msg);
	}
};


int main()
{
	// (65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110)
	int heights[] = { 65, 70, 56, 75, 60, 68, 60, 70 };
	int weigths[] = { 100, 150, 90, 190, 95, 110, 80, 100 };

	vector<HtWt> input;
	for(int i = 0; i < sizeof(heights) / sizeof(heights[0]); ++i)
		input.push_back(HtWt(heights[i], weigths[i]));

	LongestManTower lmt(input);

	lmt.find_max_seq();

	lmt.print_max_seq();

	return 0;
}


















