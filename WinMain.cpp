#include <Windows.h>
#include <sstream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(1);
		break;

	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "Respects");
		}
		break;
	case WM_LBUTTONDOWN:
		{
			POINTS pt = MAKEPOINTS(lParam);
			std::ostringstream oss;
			oss << "(" << pt.x << "," << pt.y << ")";
			SetWindowText(hWnd, oss.str().c_str());
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR	  lpCmdLine,
		int		  nCmdShow)
{
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = "3Dclass";
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	// create window instance
	HWND hWnd = CreateWindowExW(
		0,
		L"3Dclass",
		L"First Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,
		200,
		640,
		480,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	ShowWindow(hWnd, SW_SHOW);
	
	// message 
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}

	return 0;
}


// 5 lesson next https://www.youtube.com/watch?v=UUbXK4G_NCM&list=PLqCJpWy5Fohd3S7ICFXwUomYW0Wv67pDD&index=5&ab_channel=ChiliTomatoNoodle