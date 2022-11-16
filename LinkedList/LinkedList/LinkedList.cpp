#include "linkedList.h"
#include <iostream>
#include <numeric>
using namespace std;
void print_list(const LinkedList<char>& l) {
    for (int i = 0; i < l.size(); i++) {
        cout << ((i != 0) ? " -> " : "") << l[i];
    }
    cout << endl;
}

int main() {
    LinkedList<char> lst;
    cout << boolalpha << lst.empty() << endl;

    for (int i = 0; i < 5; i++)
        lst.push_back(char('f' + i));

    print_list(lst);

    for (int i = 0; i < 5; i++)
        lst.insert(0, char('s' - i));

    print_list(lst);

    for (size_t i = 0; i != lst.size(); i++)
        lst[i] = char('t' + i);

    print_list(lst);

    lst.pop_back();
    lst.pop_front();

    print_list(lst);

    lst.remove_at(5);
    lst.insert(3, 'o');

    print_list(lst);

    lst.clear();

    lst.push_back('q');
    lst.push_back('w');

    cout << lst.size() << ' ' << boolalpha << lst.empty()
        << endl;

    // итератор
    LinkedList<int> l;
    l.push_back(3);
    l.push_back(5);
    l.push_back(2);
    l.push_back(7);
    for (auto& i : l)
        i += 2;
    auto lambda = [&l](int a, int b) { return a + b * 10; };
    cout << accumulate(l.begin(), l.end(), 0, lambda) << "\n"; // 250
}
