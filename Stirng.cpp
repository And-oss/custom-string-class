#include <iostream>
#include <cstring>
using namespace std;

class String {
protected:
    char* str;
    int len;
public:
    String() {
        len = 0;
        str = new char[len+1];
        str[0] = '\0';
    }

    String(char* s) {
        len = strlen(s);
        str = new char[len+1];
        for (int i = 0; i < len; i++) {
            str[i] = s[i];
        }
        str[len] = '\0';
    }

    String(const String& s) {
        len = s.len;
        str = new char[len+1];
        for (int i = 0; i < len; i++) {
            str[i] = s.str[i];
        }
        str[len] = '\0';
    }

    ~String() {
        delete[] str;
    }

    friend ostream& operator<<(ostream& out, const String& s);
    friend istream& operator>>(istream& is, String& s);
    char& operator[](int index) {
        return str[index];
    }

    String operator+(String& s) const {
        int newLen = len + s.len;
        char* newStr = new char[newLen + 1];
        strcpy(newStr, str);
        strcat(newStr, s.str);
        String result(newStr);
        delete[] newStr;
        return result;
    }

    String& operator+=(const String& other) {
        char* new_data = new char[length() + other.length() + 1];
        strcpy(new_data, str);
        strcat(new_data, other.str);

        delete[] str;
        str = new_data;
        len += other.len;

        return *this;
    }

    bool operator==(const String& other) const {
        if(len == other.len){
            for(int i = 0;i<len;i++){
                if(str[i] != other.str[i]) return false;
            }
            return true;
        }
        return false;
    }

    bool operator!=(const String& other) const {
        if(len != other.len){
            return true;
        }else{
            for(int i = 0;i<len;i++){
                if(str[i] != other.str[i]) return true;
            }
            return false;
        }
    }

    bool operator<(const String& other) const {
        int minLength = min(length(), other.length());
        for (int i = 0; i < minLength; ++i) {
            if (str[i] < other.str[i]) {
                return true;
            } else if (str[i] > other.str[i]) {
                return false;
            }
        }
        return length() < other.length();
    }

    bool operator>(const String& other) const {
        int minLength = min(length(), other.length());
        for (int i = 0; i < minLength; ++i) {
            if (str[i] < other.str[i]) {
                return false;
            } else if (str[i] > other.str[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator<=(const String& other) const {
        int minLength = min(length(), other.length());
        for (int i = 0; i < minLength; ++i) {
            if (str[i] <= other.str[i]) {
                return true;
            } else if (str[i] > other.str[i]) {
                return false;
            }
        }
    }

    bool operator>=(const String& other) const {
        int minLength = min(length(), other.length());
        for (int i = 0; i < minLength; ++i) {
            if (str[i] < other.str[i]) {
                return false;
            } else if (str[i] >= other.str[i]) {
                return true;
            }
        }
    }




    int length() const {
       return len;
    }

    char* word() const{
        return str;
    }

    void to_upper(){
        for(int i = 0;i<length();i++){
            if(int(str[i]) >96 && int(str[i]) < 123){
                str[i] = char(int(str[i] - 32));
            }
        }
    }

    void to_lower(){
        for(int i = 0;i<length();i++){
            if(int(str[i]) >64 && int(str[i]) < 91){
                str[i] = char(int(str[i] + 32));
            }
        }
    }

    void push_back(char c){
        len += 1;
        str[len-1] = c;
    }

    void insert(int index, char c) {
        if (index < 0 || index > len) {
            return;
        }

        char* newStr = new char[len + 2];
        strncpy(newStr, str, index);
        newStr[index] = c;
        strncpy(newStr + index + 1, str + index, len - index + 1);

        delete[] str;
        str = newStr;
        len++;
    }

    void reverse(int ln){
        int n = ln;
        while(n != 0) {
            for (int i = 0; i < ln - 1; i++) {
                swap(str[i], str[i + 1]);
            }
            n--;
        }
        cout << str;
    }
};

ostream& operator<<(ostream& out, const String& s) {
    for(int i=0;i<s.len;++i){
        if (s.str[i]!='\n'||s.str[i]!='\r') cout<<s.str[i];
    }
    return out;
}

istream& operator>>(istream& in, String& s) {
    char c[100001]={};
    in>> (c);
    s.len=strlen (c);
    if (c[s.len-2]='\n')c[s.len-2]=0;
    if (s.str!=NULL) delete [] s.str;
    s.str=new char[s.len];
    strcpy(s.str,c);
    return in;
}
