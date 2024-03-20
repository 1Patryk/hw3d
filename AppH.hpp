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
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	Timer Timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};