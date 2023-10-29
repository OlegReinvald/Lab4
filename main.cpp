#include <iostream>
using namespace std;

const char* my_strpbrk(const char* str1, const char* str2) { // Function strpbrk
    const char* s1 = str1;
    while (*s1 != '\0') {
        const char* s2 = str2;
        while (*s2 != '\0') {
            if (*s1 == *s2) {
                return s1;
            }
            ++s2;
        }
        ++s1;
    }
    return nullptr  ;
}


int main() {
    char text[300];
    cout << "Enter string: " << "\n";
    cin.getline(text, 300, '\n');
    bool is_digit = true;
    int max_ones = 0;
    char temp_word[300];
    char word_max_ones[300];
    int counter = 0;
    int max_counter = 0;
    int temp_ones = 0;
    int num = 1;
    int pre_fin_num = -1;
    int fin_num = -1;
    for(int i = 0; text[i] != '\0'; i++){
        temp_word[counter] = text[i];
        if (text[i] == ' '){
            num ++;
            if (temp_ones > max_ones and temp_ones != 0 and is_digit){
                max_ones = temp_ones;
                fin_num = num - 1;
                for (int j = 0; j < counter + 1; j++) word_max_ones[j] = temp_word[j];
                max_counter = counter;
            }
            if (temp_ones == max_ones and temp_ones != 0 and is_digit){
                max_ones = temp_ones;
                pre_fin_num = fin_num;
                fin_num = num - 1;
                for (int j = 0; j < counter + 1; j++) word_max_ones[j] = temp_word[j];
                max_counter = counter;
            }
            is_digit = true;
            temp_ones = 0;
            for (int j = 0; j < size(text); j++) temp_word[j] = '\0';
            counter = 0;
            continue;
        }

        if (int('0') >= int(text[i]) or int('9') <= int(text[i]) and text[i] != ' '){
            is_digit = false;
        }
        if (text[i] == '1'){
            temp_ones ++;
        }
        counter++;
    }
    num++;
    if (temp_ones > max_ones and temp_ones != 0 and is_digit){
        max_ones = temp_ones;
        fin_num = num - 1;
        for (int j = 0; j < counter + 1; j++) word_max_ones[j] = temp_word[j];
        max_counter = counter;
    }
    if (temp_ones == max_ones and temp_ones != 0 and is_digit){
        max_ones = temp_ones;
        pre_fin_num = fin_num;
        fin_num = num - 1;
        for (int j = 0; j < counter + 1; j++) word_max_ones[j] = temp_word[j];
        max_counter = counter;
    }
    if (pre_fin_num == -1){
        pre_fin_num = fin_num;
    }
    if (fin_num == -1){
        cout << "No numbers with ones";
    } else {
        cout << "Word #" << pre_fin_num << "\n";
        for (int i = 0; i < max_counter + 1; i++) cout << word_max_ones[i];
    }
}