#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ostream>

using namespace std;

struct point2d
{
	int x, y;
	point2d(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	friend std::ostream& operator<<(ostream& os, const point2d& obj)
	{
		os << '(' << obj.x << ", " << obj.y << ')';
		return os;
	}
};

struct point3d
{
	int x, y, z;
	point3d(const int& x = 0, const int& y = 0, const int& z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend std::ostream& operator<<(ostream& os, const point3d& obj)
	{
		os << '(' << obj.x << ", " << obj.y << ", " << obj.z << ')';
		return os;
	}
};

double get_distance(const point2d& p1, const point2d& p2)
{
	return sqrt(powl(abs(p2.y - p1.y), 2) + powl(abs(p2.x - p1.x), 2));
}

double get_distance(const point3d& p1, const point3d& p2)
{
	return sqrt(powl(abs(p2.y - p1.y), 2) + powl(abs(p2.x - p1.x), 2) + powl(abs(p2.z - p1.z), 2));
}

int main()
{
	cout << get_distance(point3d(5, 6, 2), point3d(-7, 11, -13)) << ' ' << point3d(3, 1, 2);
}