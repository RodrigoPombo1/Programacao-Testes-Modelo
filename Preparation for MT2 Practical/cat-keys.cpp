#include <iostream>
#include <list>
#include <map>
#include <string>
#include <climits>
#include <sstream>

using namespace std;

string cat_keys(list<map<string, unsigned>> lst) {
    unsigned minimum_value = UINT_MAX;
    size_t list_position_of_map_with_minimum_value = 0;
    size_t counter_position = 0;
    for (map<string, unsigned> element : lst) {
        for (pair<string, unsigned> pair : element) {
            if (pair.second <= minimum_value) {
                minimum_value = pair.second;
                list_position_of_map_with_minimum_value = counter_position;
            }
        }
        counter_position++;
    }
    size_t counter = 0;
    ostringstream res;
    for (map<string, unsigned> element : lst) {
        if (counter != list_position_of_map_with_minimum_value) {
            counter++;
            continue;
        }
        for (pair<string, unsigned> pair : element) {
            res << pair.first;
        }
        counter++;
    }
    return res.str();
}


int main() {
{ list<map<string, unsigned>> m4 = {
    { {"s1", 13}, {"s2", 4} }, { {"s3", 3}, {"s4", 4} } };
  cout << cat_keys(m4) << endl; }
    return 0;
}