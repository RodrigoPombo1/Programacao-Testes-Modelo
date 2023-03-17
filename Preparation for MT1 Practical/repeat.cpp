int get_length_str(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        continue;
    }
    return i;
}

char* repeat(const char str[], int n) {
    int length_original_str = get_length_str(str);
    int length_res_str = length_original_str * n;
    char* res = new char[length_res_str + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < length_original_str; j++) {
            res[(i*length_original_str) + j] = str[j];
        }
    }
    res[length_res_str] = '\0';
    return res; 
}