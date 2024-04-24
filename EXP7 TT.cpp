#include <iostream>
#include <string>

using namespace std;

long repeatedString(string s, long n) {
    long count_a = 0;
    int len = s.length();

    for (char c : s) {
        if (c == 'a') {
            count_a++;
        }
    }

    long complete_repetitions = n / len;

    long total_count_a = count_a * complete_repetitions;

    long remaining_chars = n % len;
    for (int i = 0; i < remaining_chars; i++) {
        if (s[i] == 'a') {
            total_count_a++;
        }
    }

    return total_count_a;
}

int main() {
    string s;
    long n;
    cin >> s >> n;

    long result = repeatedString(s, n);
    cout << "Frequency of 'a' in the substring: "<< result << endl;

    return 0;
}
