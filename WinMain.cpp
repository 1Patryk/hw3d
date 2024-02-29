#include "Window.hpp"

int CALLBACK WinMain(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR	  lpCmdLine,
		int		  nCmdShow)
{
	Window wnd1(800, 300, "Fart Box 1");
	Window wnd2(300, 800, "Fart Box 2");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}

	return msg.wParam;
}

// next: https://www.youtube.com/watch?v=QYGLXhulvVQ&list=PLqCJpWy5Fohd3S7ICFXwUomYW0Wv67pDD&index=8&ab_channel=ChiliTomatoNoodle

