#include <string>
#include <vector>

using namespace std;

#define CLAUSE_EXACT_MATCH 11
#define CLAUSE_SINGLETON 22
#define CLAUSE_RANGE 33
#define CLAUSE_EMPTY 77

struct Clause {

    public:
        
        Clause() {
            this->clause_type = CLAUSE_EMPTY;
        }

        Clause(char single) {
            this->clause_type = CLAUSE_SINGLETON;
            this->clause_single = single;
        }

        Clause(pair <char, char> rng) {
            this->clause_type = CLAUSE_RANGE;
            this->clause_rng = rng;
        }

        Clause(string w) {
            this->clause_type = CLAUSE_EXACT_MATCH;
            this->clause_match = w;
        }

        bool check_clause(char inp) {
            bool check_result;
            switch (this->clause_type) {
                case CLAUSE_EXACT_MATCH: {
                    check_result = (this->clause_match.front() == inp && this->clause_match.size() == 1); 
                    break;
                }
                case CLAUSE_SINGLETON: {
                    check_result = (inp == this->clause_single);
                    break;
                }
                case CLAUSE_RANGE: {
                    check_result = (this->clause_rng.first <= inp && inp <= this->clause_rng.second);
                    break;
                }
                default: {
                    check_result = false;
                }
            }
            return check_result;
        }

        bool check_clause(string w) {
            bool check_result;
            switch (this->clause_type) {
                case CLAUSE_EXACT_MATCH: {
                    check_result = (this->clause_match == w); 
                    break;
                }
                case CLAUSE_SINGLETON: {
                    check_result = (w.front() == this->clause_single && w.size() == 1);
                    break;
                }
                case CLAUSE_RANGE: {
                    check_result = (this->clause_rng.first <= w.front() && w.front() <= this->clause_rng.second);
                    check_result = (check_result && (w.size() == 1));
                    break;
                }
                default: {
                    check_result = false;
                }
            }
            return check_result;
        }

    private:
        int clause_type;
        pair <char, char> clause_rng;
        char clause_single;
        string clause_match;

};

