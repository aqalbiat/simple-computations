#include <iostream>
#include <vector>
#include <string>

#include "automaton.h"

using namespace std;

vector <string> test1;
vector <char> test2;

int build_mask(string ptrn) {
    int res = 0;
    for (int i = 0; i < 24; i++) {
        int digit = (int)(ptrn[i] - '0');
        res = (res + (digit << i));
    }
    return res;
}

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
    test1.push_back("c");
    test1.push_back("d");
    test1.push_back("lololo");
    test1.push_back("cropsfield");
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

void RunTests(Edge e, int mask) {
    int ok_count = 0;
    for (auto curr : test1) {
        bool need = (mask & 1);
        mask >>= 1;
        bool curr_result = e.check_edge(curr); 
        cout << "Testing -> " << curr << "; result = ";
        cout << curr_result << "\n";
        cout << "Needed result: " << need << " : " << (need == curr_result ? "OK" : "Bad") << "\n";
        ok_count += (need == curr_result ? 1 : 0);
    }
    for (auto curr : test2) {
        bool need = (mask & 1);
        mask >>= 1;
        bool curr_result = e.check_edge(curr); 
        cout << "Testing -> " << curr << "; result = ";
        cout << curr_result << "\n";
        cout << "Needed result: " << need << " : " << (need == curr_result ? "OK" : "Bad") << "\n";
        ok_count += (need == curr_result ? 1 : 0);
    }
    cout << "Number of successful runs: " << ok_count << "/" << test1.size() + test2.size() << "\n";
}

void RunEdgeCheckers() {
    Edge e = Edge(Clause("hello"));
    e.add_clause(Clause("how"));
    e.add_clause(Clause("are"));
    e.add_clause(Clause('a', 'e'));
    e.add_clause(Clause('j'));
    e.add_clause(Clause('z'));
    int curr_mask = build_mask("000111000011000000000011");
    RunTests(e, curr_mask);
}

void RunAutomatonCheckers() {
    cout << "Automaton test\n";
    Automaton ident = Automaton(3);
    Edge e1 = Edge(Clause('a', 'z'));
    e1.add_clause(Clause('A', 'Z'));
    e1.add_clause(Clause('_'));
    Edge e2 = Edge(Clause('a', 'z'));
    e2.add_clause(Clause('A', 'Z'));
    e2.add_clause(Clause('0', '9'));
    e2.add_clause(Clause('_'));
    Edge e3 = Edge(Clause('a', 'z'));
    e3.add_clause(Clause('A', 'Z'));
    e3.add_clause(Clause('0', '9'));
    e3.add_clause(Clause('_'));
    ident.add_edge(1, 2, e1);
    ident.add_edge(2, 3, e2);
    ident.add_edge(3, 2, e3);
    ident.select_finish(2);
    ident.select_finish(3);
    vector <string> test_ident;
    test_ident.push_back("_0012gh3");
    test_ident.push_back("lok0023_");
    test_ident.push_back("ppoi09");
    test_ident.push_back("%##430");
    test_ident.push_back("009ssd");
    test_ident.push_back("--++====");
    test_ident.push_back("x+y=g+h");
    test_ident.push_back("x+34=y");
    test_ident.push_back("ggjkhd+rty");
    test_ident.push_back("99+34=ty");
    test_ident.push_back("r");
    test_ident.push_back("l");
    test_ident.push_back("0");
    test_ident.push_back("7");
    test_ident.push_back("_");
    for (string curr : test_ident) {
        cout << "Try test -> " << curr << ": ";
        cout << ident.check_input(curr) << "\n";
    }
}

int main() {
    init_tests();
    cout << "\n\n ============= Start the tests ============= \n\n";
    RunEdgeCheckers();
    RunAutomatonCheckers();
    cout << "\n\n ============= FINISHED ============= \n\n";
    return 0;
}

