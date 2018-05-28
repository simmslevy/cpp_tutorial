#include "stdafx.h"
#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

void Vector3d::print()
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}