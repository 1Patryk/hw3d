#include "Window.hpp"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow)
{
	try
	{
		Window wnd1(800, 300, "Fart Box 1");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			
			// test code
			while (!wnd1.mouse.IsEmpty())
			{
				const auto e = wnd1.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
				{
					wnd1.SetTitle("Gone!");
					break;
				}
				case Mouse::Event::Type::Move:
				{
					std::ostringstream oss;
					oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
					wnd1.SetTitle(oss.str());
					break;
				}
				}
			}
		}

		if (gResult == -1)
		{
			return -1;
		}

		return msg.wParam;
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

// next: https://www.youtube.com/watch?v=zZZoqEcMfwQ&list=PLqCJpWy5Fohd3S7ICFXwUomYW0Wv67pDD&index=11&t=438s&ab_channel=ChiliTomatoNoodle
