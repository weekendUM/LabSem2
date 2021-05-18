#include <iostream>
#include <math.h>

//Definiţi o clasă generică dreaptă care conţine metode care ne permit 
//să aflam dacă : 2 drepte se intersectează sa nu, un punct aparţine dreptei,
//unghiul dintre două drepte, etc.Trataţi excepţiile care pot apărea.

template<class T>
struct punct
{
	T x, y;
	punct() {}
	punct(const T& x, const T& y)
	{
		this->x = x;
		this->y = y;
	}
	punct(const punct<T>& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
};

template<class T>
class dreapta
{
	punct<T> p1, p2;
public:
	dreapta(const T& x1, const T& x2,
		const T& y1, const T& y2);

	float get_m();

	template<class Q>
	bool intersects(dreapta<Q>& obj);

	template<class Q>
	bool has_point(const punct<Q>& pct);

	template<class Q>
	float angle_to(dreapta<Q>& other);
};

template<class T>
dreapta<T>::dreapta(const T& x1, const T& y1,
	const T& x2, const T& y2)
{
	this->p1.x = x1;
	this->p1.y = y1;
	this->p2.x = x2;
	this->p2.y = y2;
}

template<class T>
float dreapta<T>::get_m()
{
	return float(this->p2.y - this->p1.y) /
		(this->p2.x - this->p1.x);
}

int main()
{
	dreapta d1(1, 1, 3, 3);
	dreapta d2(4, 3, 4, 5);
	std::cout << d1.intersects(d2) << '\n';
	std::cout << d1.has_point(punct(2, 2)) << '\n';
	std::cout << (d1.angle_to(d2) * 180) / 3.14;
}

template<class T>
template<class Q>
bool dreapta<T>::intersects(dreapta<Q>& obj)
{
	float m1 = this->get_m();
	float m2 = obj.get_m();
	return m1 != m2;
}

template<class T>
template<class Q>
bool dreapta<T>::has_point(const punct<Q>& pct)
{
	float m = float(pct.y - this->p1.y) /
		(pct.x - this->p1.x);
	float m1 = this->get_m();
	return m == m1;
}

template<class T>
template<class Q>
float dreapta<T>::angle_to(dreapta<Q>& other)
{
	//std::cout << this->get_m() << " vs " << other.get_m() << '\n';
	if (this->get_m() == INFINITY)
	{
		return atan(other.get_m());
	}
	if (other.get_m() == INFINITY)
	{
		return atan(this->get_m());
	}
	float res = atan(
		abs(
			this->get_m() - other.get_m() /
			(1 + this->get_m() * other.get_m()))
	);
	return res;
}
