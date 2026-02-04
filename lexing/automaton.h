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
        vector <int> DFS(int v, int pos) {
            vector <int> curr_list;
            if (pos >= current_w.size()) {
                curr_list.push_back(v);
            } else {
                int len = current_w.size() - pos;
                for (int sz = len; sz >= 1; sz--) {
                    string curr = current_w.substr(pos, sz);
                    for (auto e : g[v]) {
                        auto checker = e.first;
                        int to = e.second;
                        if (checker.check_edge(curr)) {
                            vector <int> children = DFS(to, pos + curr.size());
                            for (int r_ch : children) {
                                curr_list.push_back(r_ch);
                            }
                        }    
                    }
                }
            }
            return curr_list;
        }

        bool run_DFS(string init_w) {
            current_w = init_w;
            vector <int> list_last = DFS(1, 0);
            bool result = false;
            for (int curr_v : list_last) {
                if (0 < curr_v && curr_v < terminals.size()) {
                    result |= terminals[curr_v];
                }
            }
            return result;
        }

};
