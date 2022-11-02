#include "String.h"

std::ostream& operator<<(std::ostream& out, String s)
{
	out << s.array;
	return out;
}
