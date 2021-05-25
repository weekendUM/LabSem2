#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

int main()
{
	std::vector<std::string> persoane;
	int n;
	std::cin >> n;
	std::string buffer;
	std::cin.ignore();
	while (n)
	{
		std::getline(std::cin, buffer);
		persoane.push_back(buffer);
		n--;
	}
	std::cout << "Cerinta 1:\n";
	for (auto it = persoane.begin(); it != persoane.end(); it++)
	{
		std::cout << *it << '\n';
	}
	std::cout << "Cerinta 2:\n";
	std::ostream_iterator<std::string> out(std::cout, "\n");
	std::copy(persoane.begin(), persoane.end(), out);
	std::cout << "Cerinta 3:\n";
	std::cout << persoane.size() << '\n';
	std::cout << "Cerinta 4:\n";
	sort(persoane.rbegin(), persoane.rend());
	for (auto it = persoane.begin(); it != persoane.end(); it++)
	{
		std::cout << *it << '\n';
	}
	std::cout << "Cerinta 5:\n";
	std::reverse(persoane.begin(), persoane.end());
	for (auto el : persoane)
	{
		std::cout << el << '\n';
	}
	std::cout << "Cerinta 6:\n";
	std::string prenume;
	std::getline(std::cin, prenume);
	auto k = 0;
	for (auto el : persoane)
	{
		std::string buffer = el.substr(el.find_first_of(" ") + 1);
		if (prenume == buffer)
		{
			k++;
		}
	}
	std::cout << k << '\n';
	std::cout << "Cerinta 7:\n";
	std::map<std::string, int> prenume_unice;
	for (auto el : persoane)
	{
		std::string buffer = el.substr(el.find_first_of(" ") + 1);
		if (prenume_unice.find(buffer) != prenume_unice.end())
		{
			prenume_unice[buffer]++;
		}
		else
		{
			prenume_unice[buffer] = 1;
		}
	}
	for (auto el : prenume_unice)
	{
		std::cout << el.first << " " << el.second << '\n';
	}
}