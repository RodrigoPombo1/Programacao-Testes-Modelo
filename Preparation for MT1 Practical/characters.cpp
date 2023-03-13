#include <iostream>
using namespace std;

int student_main() {
    char chr;
    cin >> chr;
    if (('a' <= chr && 'z' >= chr) || ('A' <= chr && 'Z' >= chr)) {
        cout << "LETTER";
    }
    else if ('0' <= chr && '9' >= chr) {
        cout << "DIGIT";
    }
    else {
        cout << "OTHER";
    }
    return 0;
}