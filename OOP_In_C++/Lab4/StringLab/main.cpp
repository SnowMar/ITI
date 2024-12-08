#include <iostream>
using namespace std;

int custom_strlen(const char* str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

void custom_strcpy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

class MyString {
private:
    char* str;
    int length;

public:
    MyString() : str(), length(0) {}

    MyString(const char* input) {
        length = custom_strlen(input);
        str = new char[length + 1];
        custom_strcpy(str, input);
    }

    MyString(const MyString& secondLen) {
        length = secondLen.length;
        str = new char[length + 1];
        custom_strcpy(str, secondLen.str);
    }

    MyString& operator=(const MyString& secondLen) {
        if (this != &secondLen) {
            delete[] str;
            length = secondLen.length;
            str = new char[length + 1];
            custom_strcpy(str, secondLen.str);
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    MyString operator+(const MyString& secondLen) const {
        char* newStr = new char[length + secondLen.length + 1];
        custom_strcpy(newStr, str);
        custom_strcpy(newStr + length, secondLen.str);
        MyString result(newStr);
        delete[] newStr;
        return result;
    }

    int operator==(const MyString& secondLen) const {
        int i = 0;
        while (str[i] != '\0' && secondLen.str[i] != '\0') {
            if (str[i] != secondLen.str[i]) return 0;
            i++;
        }
        return (str[i] == secondLen.str[i]) ? 1 : 0;
    }

    char& operator[](int index) {
        return str[index];
    }

    const char& operator[](int index) const {
        return str[index];
    }

    int size() const {
        return length;
    }

    void display() const {
        if (str) cout << str;
    }
};

int main() {
    MyString str1("Test");
    MyString str2("Test2");
    MyString str3 = str1 + str2;

    str3.display();
    cout << endl;

    cout << ((str1 == str2) ? "Equal" : "Not Equal") << endl;
    cout << str3[1] << endl;
    cout << str3.size() << endl;

    return 0;
}
