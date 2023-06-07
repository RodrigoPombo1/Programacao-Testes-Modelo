#include "show_file.h"

double compute_average_vector(const vector<double> numbers) {
    double res;
    for (double num : numbers) {
        res += num;
    }
    res /= numbers.size();
    return res;
}

bool average(const string& input_fname, const string& output_fname) {
    ifstream input_file(input_fname);
    if (!input_file.is_open()) {
        return false;
    }
    int line_counter = 0;
    ofstream output_file(output_fname);
    for (string line; getline(input_file, line);) {
        vector<double> numbers;
        istringstream iss_line(line);
        double current_num;
        while (iss_line >> current_num) {
            numbers.push_back(current_num);
        }
        output_file << fixed << setprecision(3) << compute_average_vector(numbers) << endl;
        line_counter++;
    }
    output_file << "lines=" << line_counter << endl; 
    return true;
}

int main() {
    { if (average("p1a-1.txt", "p1a-1_out.txt"))
    show_file("p1a-1_out.txt"); }
    { if (average("p1a-2.txt", "p1a-2_out.txt"))
    show_file("p1a-2_out.txt"); }
    return 0;
}