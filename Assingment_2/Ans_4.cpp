#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    string result = str1 + str2;
    cout << "Concatenated string: " << result << endl;

    return 0;
}

//2nd
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;
    return 0;
}
//3
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";
    for (char c : str) {
        char lower = tolower(c);
        if (lower!='a' && lower!='e' && lower!='i' && lower!='o' && lower!='u') {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}
//4
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // to clear newline

    string arr[100];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(arr, arr + n);

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
//
