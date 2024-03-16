#include "AppH.hpp"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, "Main Box")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quiting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	/*
	const float t = Timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
	*/

	const float c = sin(Timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().DrawTestTriangle
	(
		Timer.Peek(),
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f
	);
	wnd.Gfx().EndFrame();
}