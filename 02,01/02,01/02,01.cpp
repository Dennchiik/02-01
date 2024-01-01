#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    int length;

public:
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator++() {
        char* newStr = new char[length + 2];
        strcpy(newStr, str);
        newStr[length] = 'x';
        newStr[length + 1] = '\0';

        delete[] str;
        str = newStr;
        length++;

        return *this;
    }

    MyString& operator--() {
        if (length > 0) {
            char* newStr = new char[length];
            strncpy(newStr, str, length - 1);
            newStr[length - 1] = '\0';

            delete[] str;
            str = newStr;
            length--;
        }

        return *this;
    }

    MyString operator+(int count) const {
        MyString result(*this);

        for (int i = 0; i < count; ++i) {
            char* newStr = new char[result.length + 2];
            strcpy(newStr, result.str);
            newStr[result.length] = 'x';
            newStr[result.length + 1] = '\0';

            delete[] result.str;
            result.str = newStr;
            result.length++;
        }

        return result;
    }

    MyString operator-(int count) const {
        MyString result(*this);

        for (int i = 0; i < count && result.length > 0; ++i) {
            char* newStr = new char[result.length];
            strncpy(newStr, result.str, result.length - 1);
            newStr[result.length - 1] = '\0';

            delete[] result.str;
            result.str = newStr;
            result.length--;
        }

        return result;
    }

    void print() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString str("Hello");

    ++str;
    str.print(); 

    --str;
    str.print(); 

    MyString str2 = str + 3;
    str2.print(); 

    MyString str3 = str2 - 2;
    str3.print(); 

    return 0;
}
