#include <string>
#include <vector>
#include <algorithm>

#include "edge.h"

using namespace std;

struct Automaton {

    public:

        Automaton() {}

        Automaton(int init_size) {
            this->g.resize(2 * init_size + 3);
            this->terminals.resize(2 * init_size + 3);
            fill(this->terminals.begin(), this->terminals.end(), false);
        }

        void add_edge(int x, int y, Edge e) {
            g[x].push_back(make_pair(e, y));
            g[y].push_back(make_pair(e, x));
        }

        void select_finish(int v) {
            this->terminals[v] = true;
        }

        bool check_input(string w) {
            return this->run_DFS(w);
        }

    private:
        vector < vector < pair <Edge, int> > > g;
        vector <bool> terminals;

        string current_w;
        int DFS(int pos) {
            return 0;
        }

        bool run_DFS(string init_w) {
            current_w = init_w;
            int last = DFS(0);
            return terminals[last];
        }

};
