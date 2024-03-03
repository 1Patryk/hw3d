#pragma once
#include "Window.hpp"
#include "Timer.hpp"

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