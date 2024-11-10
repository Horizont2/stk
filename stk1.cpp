#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

void checkBrackets(const string& str) {
    stack<char> s;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                cout << "Помилка: Зайва закриваюча дужка " << ch << " на позиції " << i + 1 << endl;
                return;
            }
            char top = s.top();
            s.pop();
            if (!isMatchingPair(top, ch)) {
                cout << "Помилка: Невідповідна дужка " << ch << " на позиції " << i + 1 << endl;
                return;
            }
        }
    }

    if (!s.empty()) {
        cout << "Помилка: Відсутня закриваюча дужка для " << s.top() << endl;
    } else {
        cout << "Рядок коректний" << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input;
    cout << "Введіть рядок дужок: ";
    getline(cin, input);
    checkBrackets(input);
    return 0;
}
