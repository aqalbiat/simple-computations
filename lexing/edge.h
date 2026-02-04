#include <string>
#include <algorithm>

#include "clause.h"

using namespace std;

struct Edge {

    public:

        Edge() {}

        Edge(Clause cl) {
            this->list_clauses.push_back(cl);
        }

        void add_clause(Clause cl) {
            this->list_clauses.push_back(cl);
        }

        bool check_edge(char c) {
            for (auto cl : this->list_clauses) {
                if (cl.check_clause(c)) {
                    return true;
                }
            }
            return false;
        }

        bool check_edge(string w) {
            for (auto cl : this->list_clauses) {
                if (cl.check_clause(w)) {
                    return true;
                }
            }
            return false;
        }

    private:
        vector <Clause> list_clauses;

};