#include <iostream>

using namespace std;

class NrComplex {
    int re, im;
public:
    NrComplex() {}
    NrComplex(const int& a, const int& b);
    friend istream& operator>>(istream& in, NrComplex& obj);
    friend ostream& operator<<(ostream& out, const NrComplex& obj);
    NrComplex& operator=(char* string);
    operator char*();
};

char* int_to_string(int x)
{
    char buffer[21] = "";
    while (x)
    {
        buffer[strlen(buffer)] = (x % 10) + '0';
        buffer[strlen(buffer) + 1] = '\0';
        x /= 10;
    }
    char* r = new char[strlen(buffer) + 1];
    r[strlen(buffer)] = '\0';
    for (int i = 0; i < strlen(buffer); i++)
    {
        r[strlen(buffer) - i - 1] = buffer[i];
    }
    return r;
}

int main() {
    NrComplex a;
    cin >> a;
    char x[20];
    scanf("%s", x);
    char* c = a;
    cout << c << endl;
    a = x;
    cout << a << endl;
    return 0;
}

NrComplex::NrComplex(const int& a, const int& b)
{
    this->re = a;
    this->im = b;
}

NrComplex& NrComplex::operator=(char* string)
{
    int i;
    this->re = 0;
    for (i = 0; string[i] != '+' && string[i] != '-'; i++)
    {
        this->re = this->re * 10 + (string[i] - '0');
    }
    i++;
    this->im = 0;
    while (string[i] != 'i')
    {
        this->im = this->im * 10 + (string[i] - '0');
        i++;
    }
    return *this;
}

NrComplex::operator char* ()
{
    char* res = new char[23];
    strcpy(res, "");
    char* tmp = new char[11];
    //_itoa(this->re, res, 10);
    tmp = int_to_string(this->re);
    strcat(res, tmp);
    delete[] tmp;
    tmp = int_to_string(this->im);
    strcat(res, "+");
    strcat(res, tmp);
    strcat(res, "i");
    delete[] tmp;
    return res;
}

istream& operator>>(istream& in, NrComplex& obj)
{
    in >> obj.re >> obj.im;
    return in;
}

ostream& operator<<(ostream& out, const NrComplex& obj)
{
    if (obj.im)
    {
        out << obj.re << "+" << obj.im << "i";
        return out;
    }
    out << obj.re;
    return out;
}
