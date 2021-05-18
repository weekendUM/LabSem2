#include <iostream>
#include <cstring>
#include <string>
#include <vector>

class promotie
{
	std::string nume;
	int durata;
	int zi, luna, an;
	int suma;
public:
	promotie(std::string nume, const int& durata = 1,
		const int& zi = 1, const int& luna = 1, const int& an = 2000,
		const int& suma = 1000);
	friend std::ostream& operator<<(std::ostream& out, const promotie& obj);
	promotie operator++(int);

	inline const int get_suma() const { return this->suma; }

	friend void change_date(promotie& obj,
		int zi, int luna, int an);

	~promotie();
};

promotie::promotie(std::string nume, const int& durata, const int& zi, const int& luna, const int& an, const int& suma)
{
	this->nume = nume;
	this->durata = durata;
	this->zi = zi;
	this->luna = luna;
	this->an = an;
	this->suma = suma;
}

promotie promotie::operator++(int)
{
	this->durata++;
	return *this;
}

promotie::~promotie()
{
	
}

void read(const int& n, promotie** objs)
{
	std::string nume;
	int durata;
	int zi, luna, an;
	int suma;
	for (int i = 0; i < n; i++)
	{
		std::cin.ignore();
		std::getline(std::cin, nume);
		std::cin >> durata;
		std::cin >> zi >> luna >> an;
		std::cin >> suma;
		objs[i] = new promotie(nume, durata, zi, luna, an, suma);
	}
}

void print_mins(int n, promotie** objs)
{
	int min = 1000000; //ma indoiesc ca suma poate fi negativa
	std::vector<promotie> res;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (objs[i]->get_suma() < min)
		{
			min = objs[i]->get_suma();
			res.clear();
			res.push_back(*objs[i]);
		}
		else if (objs[i]->get_suma() == min)
		{
			res.push_back(*objs[i]);
		}
	}
	for (auto el : res)
	{
		std::cout << el << '\n';
	}
}

int main()
{
	int n;
	std::cin >> n;
	promotie** objs = new promotie * [n];
	read(n, objs);
	print_mins(n, objs);
	/*std::string nume;
	int durata;
	int zi, luna, an;
	int suma;
	std::getline(std::cin, nume);
	std::cin >> durata;
	std::cin >> zi >> luna >> an;
	std::cin >> suma;
	promotie obj = promotie(nume, durata, zi, luna, an, suma);
	std::cout << obj;*/
}

std::ostream& operator<<(std::ostream& out, const promotie& obj)
{
	out << obj.nume << " a inceput in " << obj.zi << '/' <<
		obj.luna << '/' << obj.an << " si a durat " << obj.durata<<
		" zile, castig=" << obj.suma;
	return out;
}

void change_date(promotie& obj, int zi, int luna, int an)
{
	obj.zi = zi;
	obj.luna = luna;
	obj.an = an;
}
