#include "Exception.hpp"

HandleException::HandleException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* HandleException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}