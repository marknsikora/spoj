#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
    int c;

    while (cin >> c && c != 42) {
        cout << c << endl;
    }

    return (EXIT_SUCCESS);
} 
