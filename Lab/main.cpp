#include<iostream>
#include <cstring>

class Student
{
	char* nume;
	int an;
	bool baiat = false;
public:
	Student(){}
	Student(const char* nume, const int& an, const bool& baiat);
	Student(const Student& other);
	Student operator=(const Student& other);
	friend std::istream& operator>>(std::istream& in, Student& obj);

	void set_nume(char* nume);

	inline const char* get_name() const { return this->nume; }
	inline const int get_an() const { return an; }
	inline const bool get_sex() const { return baiat; }

	~Student();
};

Student** duplicate(Student** arr, const int& size)
{
	Student** res = new Student * [size];
	for (int i = 0; i < size; i++)
	{
		res[i] = new Student(*arr[i]);
	}
	return res;
}

class OrganizatieStudenteasca {
	char* nume;
	int numarStudenti;
	int numarMaximStudenti;
	Student** membri;
public:
	OrganizatieStudenteasca(const char* nume, const int& nr_stud,
		const int& nr_max_stud, Student** studenti);
	OrganizatieStudenteasca(const OrganizatieStudenteasca& other);
	OrganizatieStudenteasca operator=(
		const OrganizatieStudenteasca& other
		);
	void addMembru(const Student&);
	//void removeMembru(const Student&);

	inline const char* get_nume() const { return this->nume; }
	inline const int get_mem_count() const 
	{ return numarStudenti; }
	inline Student** get_mem() const { return this->membri; }

	void set_nume(const char* nume);
	void set_membri(Student** membri, const int& size);

	friend std::ostream& operator<<(std::ostream& out,
		const OrganizatieStudenteasca& obj);

	~OrganizatieStudenteasca();
};

void print_stud(Student** v, const int& n)
{
	std::cout << "========\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i]->get_sex() << '\n';
	}
}

Student::Student(const char* nume, const int& an, const bool& baiat)
{
	this->nume = _strdup(nume);
	this->an = an;
	this->baiat = baiat;
}

Student::Student(const Student& other)
{
	this->nume = _strdup(other.nume);
	this->an = other.an;
	this->baiat = other.baiat;
}

Student Student::operator=(const Student& other)
{
	return Student(other.nume, other.an, other.baiat);
}

void Student::set_nume(char* nume)
{
	if (this->nume)
	{
		delete[] this->nume;
	}
	this->nume = _strdup(nume);
}

Student::~Student()
{
	if (this->nume)
	{
		delete[] this->nume;
	}
}

OrganizatieStudenteasca::OrganizatieStudenteasca(const char* nume,
	const int& nr_stud,
	const int& nr_max_stud, Student** studenti)
{
	this->nume = _strdup(nume);
	this->numarStudenti = nr_stud;
	this->numarMaximStudenti = nr_max_stud;
	this->membri = duplicate(studenti, nr_stud);
}

OrganizatieStudenteasca::OrganizatieStudenteasca(const OrganizatieStudenteasca& other)
{
	this->nume = _strdup(other.nume);
	this->numarStudenti = other.numarStudenti;
	this->numarMaximStudenti = other.numarMaximStudenti;
	this->membri = duplicate(other.membri, other.numarStudenti);
}

OrganizatieStudenteasca OrganizatieStudenteasca::operator=(const OrganizatieStudenteasca& other)
{
	this->set_nume(other.nume);
	this->numarStudenti = other.numarStudenti;
	this->numarMaximStudenti = other.numarMaximStudenti;
	this->set_membri(other.membri, other.numarStudenti);
	return *this;
}

void OrganizatieStudenteasca::addMembru(const Student& membru)
{
	Student** buffer = new Student * [this->numarStudenti + 1];
	for (int i = 0; i < this->numarStudenti; i++)
	{
		buffer[i] = this->membri[i];
	}
	buffer[this->numarStudenti] = new Student(membru);
	this->numarStudenti++;
}

void OrganizatieStudenteasca::set_nume(const char* nume)
{
	if (this->nume)
	{
		delete[] this->nume;
	}
	this->nume = _strdup(nume);
}

void OrganizatieStudenteasca::set_membri(Student** membri,
	const int& size)
{
	if (this->numarStudenti)
	{
		for (int i = 0; i < this->numarStudenti; i++)
		{
			delete this->membri[i];
		}
		delete[] membri;
		this->numarStudenti = 0;
	}
	this->membri = duplicate(membri, size);
}

OrganizatieStudenteasca::~OrganizatieStudenteasca()
{
	if (this->numarStudenti)
	{
		for (int i = 0; i < this->numarStudenti; i++)
		{
			delete this->membri[i];
		}
		delete[] this->membri;
	}
	if (nume)
	{
		delete[] nume;
	}
}

Student** citire_stud(const int& n)
{
	Student buffer;
	Student** res = new Student * [n];
	for (int i = 0; i < n; i++)
	{
		std::cin.ignore();
		std::cin >> buffer;
		/*std::cout << buffer.get_name() << 
			": " << buffer.get_sex() << '\n';*/
		res[i] = new Student(buffer);
	}
	return res;
}

OrganizatieStudenteasca** citire(const int& n)
{
	int nr_mem, nr_max;
	char s_buffer[128];	//asta e pt nume
	OrganizatieStudenteasca** res = new OrganizatieStudenteasca * [n];
	for (int i = 0; i < n; i++)
	{
		std::cin.getline(s_buffer, 127);
		std::cin >> nr_max;
		std::cin >> nr_mem;
		Student** mem = citire_stud(nr_mem);
		//print_stud(mem, nr_mem);
		res[i] = new OrganizatieStudenteasca(s_buffer, nr_mem, nr_max,
			mem);
		std::cin.ignore();
	}
	return res;
}

void afisare(OrganizatieStudenteasca** v, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i]->get_nume() << '\n';
	}
}



void foo(OrganizatieStudenteasca** v, int n)
{
	int pos = 0;
	int max = -1;
	int k;
	for (int i = 0; i < n; i++)
	{
		k = 0;
		//print_stud(v[i]->get_mem(), v[i]->get_mem_count());
		for (int j = 0; j < v[i]->get_mem_count(); j++)
		{
			if (v[i]->get_mem()[j]->get_sex() == 0)
			{
				k++;
			}
		}
		std::cout << k << '\n';
		if (k > max)
		{
			max = k;
			pos = i;
		}
	}
	std::cout << v[pos]->get_nume() << '\n';
}



int main()
{
	int n;
	std::cin >> n;
	std::cin.ignore();
	OrganizatieStudenteasca** v = citire(n);
	foo(v, n);
	//afisare(v, n);
}

std::istream& operator>>(std::istream& in, Student& obj)
{
	//std::cin.ignore();
	char buffer[128];
	std::cin.getline(buffer, 127);
	obj.set_nume(buffer);
	in >> obj.an;
	char sex;
	in >> sex;
	if (sex == 'M')
	{
		obj.baiat = true;
	}
	else if (sex == 'F')
	{
		obj.baiat = false;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out,
	const OrganizatieStudenteasca& obj)
{
	out << obj.nume << '\n' << obj.numarStudenti <<
		'\n' << obj.numarMaximStudenti;
	return out;
}
