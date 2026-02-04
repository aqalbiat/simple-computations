#include <iostream>
#include <vector>
#include <string>

#include "automaton.h"

using namespace std;

vector <string> test1;
vector <char> test2;

void init_tests() {
    // Test some strings
    test1.push_back("Hello, how are you?");
    test1.push_back("apple");
    test1.push_back("Simon!");
    test1.push_back("are");
    test1.push_back("hello");
    test1.push_back("how");
    test1.push_back("Tiber");
    test1.push_back("low");
    test1.push_back("stroke key");
    test1.push_back("milestone");
    // Test some characters
    test2.push_back('s');
    test2.push_back('f');
    test2.push_back('g');
    test2.push_back('k');
    test2.push_back('l');
    test2.push_back('p');
    test2.push_back('t');
    test2.push_back('r');
    test2.push_back('b');
    test2.push_back('a');
}

void RunTests(Edge e) {
    for (auto curr : test1) {
        cout << "Testing -> " << curr << "; result = ";
        cout << e.check_edge(curr) << "\n";
    }
    for (auto curr : test2) {
        cout << "Testing -> " << curr << "; result = ";
        cout << e.check_edge(curr) << "\n";
    }
}

int main() {
    init_tests();
    cout << "\n\n ============= Start the tests ============= \n\n";
    Edge e = Edge(Clause("hello"));
    e.add_clause(Clause("how"));
    e.add_clause(Clause("are"));
    e.add_clause(Clause('a', 'e'));
    e.add_clause(Clause('j'));
    e.add_clause(Clause('z'));
    RunTests(e);
    cout << "\n\n ============= FINISHED ============= \n\n";
    return 0;
}

