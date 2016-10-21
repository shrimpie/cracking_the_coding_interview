// 4.2 Given a directed graph, design an algorithm to find out whether there is
//     a route between two nodes.

#include <iostream>
#include <set>
#include <vector>

using namespace std;

enum State {
	Unvisited, Visited, Visiting
};

class Graph
{
	set<int>* vertices;
	set<pair<int, int> >* edges;

public:
	Graph(set<int>* vs, set<pair<int, int> >* es)
	{
		vertices = vs;
		edges = es;
	}


	set<int>* get_nodes()
	{
		return vertices;
	}

	set<pair<int, int> >* get_edges()
	{
		return edges;
	}

	set<int>* get_adjacent(int node)
	{
		set<int>* res = new set<int>();
		for(auto i : *edges)
			if(i.first == node)
				res->insert(i.second);
		return res;
	}

	bool search_route(int start, int end)
	{
		vector<int> q;
		vector<State> ns; // node state
		for(auto i : *vertices)
			ns.push_back(Unvisited);

		ns[start] = Visiting;
		q.push_back(start);
		int cur;
		while(q.size() > 0)
		{
			cur = q.back();
			q.pop_back();
			set<int>* adj = get_adjacent(cur);

			for(auto i : *adj)
			{
				if(ns[i] == Unvisited)
				{
					if(i == end)
						return true;
					else
					{
						ns[i] = Visiting;
						q.push_back(i);
					}
				} 
			}
			ns[cur] = Visited;
		}
		return false;
	}
};




int main()
{
	int verts[] = { 0, 1, 2, 3 };
	int from[] = { 0, 2, 3, 0 };
	int to[] = { 2, 3, 1, 1 };

	set<int> vs(verts, verts + 4);

	set<pair<int, int> > es;
	for(int i = 0; i < sizeof(from) / sizeof(from[0]); ++i)
		es.insert(make_pair(from[i], to[i]));

	Graph g(&vs, &es);

	set<int> * nodes = g.get_nodes();
	cout << "vertices: ";
	for(auto v : *nodes)
		cout << (v) << " ";
	cout << endl;

	set<pair<int, int> >* edges = g.get_edges();
	cout << "edges: ";
	for(auto e : *edges)
		cout << "<" << e.first << ", " << e.second <<  "> ";
	cout << endl;

	cout << "adjacent of 2: ";
	nodes = g.get_adjacent(2);
	for(auto n : *nodes)
		cout << n << " ";
	cout << endl;

	cout << "0 and 2 has a route? " << (g.search_route(0, 2) ? "Yes" : "No") << endl;
	cout << "0 and 3 has a route? " << (g.search_route(0, 3) ? "Yes" : "No") << endl;
	cout << "1 and 0 has a route? " << (g.search_route(1, 0) ? "Yes" : "No") << endl;

	return 0;
}