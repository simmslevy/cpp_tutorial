#ifndef PAIR1_H
#define PAIR1_H

template <class T> // This is a template class, the user will provide the data type for T
class Pair1
{
private:
	T m_p1;
	T m_p2;

public:
	Pair1( const T& t1, const T& t2) : m_p1{ t1 }, m_p2{ t2 } {}

	T& first() { return m_p1; }
	T& second() { return m_p2; }
	const T& first() const { return m_p1; }
	const T& second() const { return m_p2; }

};


#endif