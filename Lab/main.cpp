#include <iostream>
#include <algorithm>

class rational
{
	int numarator;
	int numitor;
public:
	rational(const int& numarator, const int& numitor)
	{
		if (numitor == 0)
		{
			throw "Numitorul nu poate fi 0";
		}
		this->numarator = numarator;
		this->numitor = numitor;
	}
	friend bool operator<(const rational& self, const rational& other);
	friend bool operator==(const rational& self, const rational& other);
	friend bool operator>(const rational& self, const rational& other);
	friend std::ostream& operator<<(std::ostream& out, const rational& obj);
};

template<class T>
T maxim(const T& a, const T& b, const T& c)
{
	return std::max(std::max(a, b), c);
}

int main()
{
	rational a(2, 3), b(1, 2), c(3, 5);
	std::cout << "max int " << maxim(a, b, c) << std::endl;
}

bool operator<(const rational& self, const rational& other)
{
	return self.numarator / float(self.numitor) <
		other.numarator / float(other.numitor);
}

bool operator==(const rational& self, const rational& other)
{
	return self.numarator / float(self.numitor) ==
		other.numarator / float(other.numitor);
}

bool operator>(const rational& self, const rational& other)
{
	return self.numarator / float(self.numitor) >
		other.numarator / float(other.numitor);
}

std::ostream& operator<<(std::ostream& out, const rational& obj)
{
	out << obj.numarator << '/' << obj.numitor << '\n';
	return out;
}
