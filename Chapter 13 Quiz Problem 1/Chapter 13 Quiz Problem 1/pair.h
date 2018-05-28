#ifndef PAIR_H
#define PAIR_H

template <class T1, class T2> // This is a template class, the user will provide the data type for T
class Pair
{
private:
	T1 m_p1;
	T2 m_p2;

public:
	Pair(const T1& t1, const T2& t2) : m_p1{ t1 }, m_p2{ t2 } {}

	T1& first() { return m_p1; }
	T2& second() { return m_p2; }
	const T1& first() const { return m_p1; }
	const T2& second() const { return m_p2; }

};


#endif