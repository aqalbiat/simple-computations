#include <string>
#include <algorithm>

using namespace std;

struct Edge {

    public:

        Edge() {}

        Edge(char initial_l, char initial_r) {
            this->ranges.push_back(make_pair(initial_l, initial_r));
        }

        Edge(string initial_exact_match) {
            this->exact_match.push_back(initial_exact_match);
        } 

        Edge(char init_singleton) {
            this->singletons.push_back(init_singleton);
        }

        void add_range(char l, char r) {
            this->ranges.push_back(make_pair(l, r));
        }

        void add_exact_match(string match) {
            this->exact_match.push_back(match);
        }

        void add_singleton(char c) {
            this->singletons.push_back(c);
        }

        bool check_edge(char c) {
            return this->verify_input_character(c);
        }

        bool check_edge(string w) {
            return this->verify_input_string(w);
        }

    private:
        vector < pair <char, char> > ranges;
        vector <string> exact_match;
        vector <char> singletons;

        bool verify_input_character(char c) {
            for (auto rng : this->ranges) {
                if (rng.first <= c && c <= rng.second) {
                    return true;
                }
            }
            for (auto curr : singletons) {
                if (curr == c) {
                    return true;
                }
            }
            return false;
        }

        bool verify_input_string(string w) {
            for (string curr : this->exact_match) {
                if (w == curr) {
                    return true;
                }
            }
            if (w.size() > 1) return false;
            return verify_input_character(w.front());
        }

};