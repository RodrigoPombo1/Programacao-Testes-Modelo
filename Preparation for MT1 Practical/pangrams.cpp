char check_and_convert_char_to_lowercase(char chr) {
    if ('A' <= chr && chr <= 'Z') {
        chr = 'a' + (chr - 'A');
    }
    return chr;
}
bool pangram(const char s[], char m[]) {
    // check for pangram
    int n_letters_in_pangram = 0;
    int alphabet_incomplete[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        char current_chr = check_and_convert_char_to_lowercase(s[i]);
        if ((s[i] != ' ') && (alphabet_incomplete[current_chr - 'a'] == 0)) {
            n_letters_in_pangram++;
            alphabet_incomplete[current_chr - 'a'] = 1;
        }
    } 
    if (n_letters_in_pangram == 26) {
        m[0] = '\0';
        return true;
    }
    // modify m
    int count_m = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabet_incomplete[i] == 0) {
            m[count_m] = 'a' + i;
            count_m++;
        }
    }
    m[count_m] = '\0';
    return false;
}

#include <iostream>
using namespace std;

int main() {

char s[] = "";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
     << boolalpha << r << " \"" << m << "\"\n";
    return 0;
}