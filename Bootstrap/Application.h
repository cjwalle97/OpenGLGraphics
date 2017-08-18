#pragma once
struct GLFWwindow;
class Application
{
public:
	Application();
	virtual ~Application();
protected:
	virtual void startup() = 0;
	virtual void shutdown() = 0;
	virtual void update(float) = 0;
	virtual void draw() = 0;
	/*
	runs our Application.
	@param title the name of the window.
	@param
	*/
	void run();
private:
	void gameover();
};

