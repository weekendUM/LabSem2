#include <iostream>
#include <algorithm>

class game
{
protected:
	int year;
	char* name;
	float price;
public:
	game() {}
	game(const int& year, const char* name, const float& price);

	//getters
	inline const int get_year() const { return this->year; }
	inline const char* get_name() const { return this->name; }
	inline const float get_price() const { return this->price; }

	//setters
	void set_year(const int& year) { this->year = year; }
	void set_name(const char* name);
	void set_price(const float& price) { this->price = price; }

	//operators
	friend std::ostream& operator<<(std::ostream& out, const game& obj);
	friend std::ostream& operator<<(std::ostream& out, game* obj);

	//functions
	virtual void print();

};

class strategy : public game
{
protected:
	char* theme;
public:
	strategy() {}
	strategy(const int& year, const char* name, const float& price,
		const char* theme) : game(year, name, price)
	{
		this->theme = _strdup(theme);
	}

	//getters
	inline const char* get_theme() const { return this->theme; }

	//setters
	void set_theme(const char* theme);

	//functions
	virtual void print();

	//operators
	friend std::ostream& operator<<(std::ostream& out, const strategy& obj);
	friend std::ostream& operator<<(std::ostream& out, strategy* obj);
};

class arcade : public game
{
protected:
	char* producer;
public:
	arcade() {}
	arcade(const int& year, const char* name, const float& price,
		const char* producer) : game(year, name, price)
	{
		this->producer = _strdup(producer);
	}

	void print();
};

class warcraft : public strategy
{
	float version;
	int release_year;
	char* characteristics;
public:
	warcraft() {}
	warcraft(const int& year, const char* name, const float& price, const char* theme,
		const float& version, const int& release_year) : strategy(year, name, price, theme)
	{
		this->version = version;
		this->release_year = release_year;
	}

	//getters
	inline const float get_version() const { return this->version; }
	inline const int get_release_year() const { return this->release_year; }
	inline const char* get_characteristics() const { return this->characteristics; }

	//setters
	void set_version(const float& version) { this->version = version; }
	void set_release_year(const int& year) { this->release_year = year; }
	void set_characteristics(const char* in_string);

	//functions
	void print();

};

game::game(const int& year, const char* name, const float& price)
{
	this->year = year;
	this->name = _strdup(name);
	this->price = price;
}

void game::set_name(const char* name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = _strdup(name);
}

void strategy::set_theme(const char* theme)
{
	if (this->theme)
	{
		delete[] this->theme;
		this->theme = 0;
	}
	this->theme = _strdup(theme);
}

void warcraft::set_characteristics(const char* in_string)
{
	if (this->characteristics)
	{
		delete[] this->characteristics;
		this->characteristics = nullptr;
	}
	this->characteristics = _strdup(in_string);
}


//void read_games(game** games, const int& n);
void print_games(game** games, const int& n);
void by_year(game** games, const int& n);

int main()
{
	int n{ 4 };
	//std::cin >> n;
	game** v = new game * [n];
	v[0] = new game(1993, "Doom", 20);
	v[1] = new arcade(1991, "Sonic", 50, "SEGA");
	v[2] = new strategy(1997, "Age Of Empires", 35, "Colonization");
	v[3] = new warcraft(1993, "Warcraft", 50, "Fantasy", 1.12, 1994);
	print_games(v, n);
	by_year(v, n);
	std::sort(v, v + n, [](game* x, game* y)
		{
			return x->get_price() < y->get_price() ||
				(x->get_price() == y->get_price() &&
					strcmp(x->get_name(), y->get_name()) < 0);
		});
	print_games(v, n);
}

//void read_games(game** games, const int& n)
//{
//	/*for (int i = 0; i < n; i++)
//	{
//		
//	}*/
//}

void print_games(game** games, const int& n)
{
	for (int i = 0; i < n; i++)
	{
		games[i]->print();
		std::cout << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, const game& obj)
{
	out << "Nume: " << obj.name << '\n' <<
		"An: " << obj.year << '\n' <<
		"Pret: " << obj.price << "\n\n";
	return out;
}

std::ostream& operator<<(std::ostream& out, game* obj)
{
	out << *obj;
	return out;
}

std::ostream& operator<<(std::ostream& out, const strategy& obj)
{
	out << "Nume: " << obj.name << '\n' <<
		"An: " << obj.year << '\n' <<
		"Pret: " << obj.price << '\n' <<
		"Tematica: " << obj.theme << "\n\n";
	return out;
}
std::ostream& operator<<(std::ostream& out, strategy* obj)
{
	out << *obj;
	return out;
}

void game::print()
{
	std::cout << "Nume: " << name << '\n' <<
		"An: " << year << '\n' <<
		"Pret: " << price << "\n";
}

void strategy::print()
{
	game::print();
	std::cout << "Tematica: " << theme << "\n";
}

void warcraft::print()
{
	strategy::print();
	if (this->characteristics)
	{
		std::cout << "Versiune: " << this->version << '\n' <<
			"An lansare: " << this->release_year << '\n' <<
			"Caracteristici:\n" << this->characteristics;
		return;
	}
	std::cout << "Versiune: " << this->version << '\n' <<
		"An lansare: " << this->release_year << '\n';
}

void arcade::print()
{
	game::print();
	std::cout << this->producer << '\n';
}

void by_year(game** games, const int& n)
{
	bool* checked = new bool[n];
	for (int i = 0; i < n; i++)
	{
		checked[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (!checked[i])
		{
			int counter = 1;
			std::cout << games[i]->get_year() << ": ";
			checked[i] = true;
			for (int j = 0; j < n; j++)
			{
				if (!checked[j] and (games[i]->get_year() == games[j]->get_year()))
				{
					counter++;
					checked[j] = true;
				}
				
			}
			std::cout << counter << '\n';
		}
	}
}

