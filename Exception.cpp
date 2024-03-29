#include "ExceptionH.hpp"

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

const char* HandleException::GetType() const noexcept
{
	return "My Exception";
}

int HandleException::GetLine() const noexcept
{
	return line;
}

const std::string& HandleException::GetFile() const noexcept
{
	return file;
}

std::string HandleException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}