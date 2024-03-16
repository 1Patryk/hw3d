#pragma once
#include "windowsh_includeH.hpp"
#include "WindowH.hpp"
#include "TimerH.hpp"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	Timer Timer;
};