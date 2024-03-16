#include "AppH.hpp"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow)
{
	try
	{
		return App{}.Go();
	}
	catch (const HandleException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknow Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
};

// 3D Programming Fundamentals 
// https://www.youtube.com/watch?v=uehGqieEbus&list=PLqCJpWy5Fohe8ucwhksiv9hTF5sfid8lA&ab_channel=ChiliTomatoNoodle
// next 
// https://www.youtube.com/watch?v=VELCxc0fmwY&list=PLqCJpWy5Fohd3S7ICFXwUomYW0Wv67pDD&index=20&ab_channel=ChiliTomatoNoodle

// The header file names are changed because visual create double object file if have the same name
