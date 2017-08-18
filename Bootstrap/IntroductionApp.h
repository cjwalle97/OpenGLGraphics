#pragma once
#include "Application.h"
class IntroductionApp :
	public Application
{
public:
	IntroductionApp();
	~IntroductionApp();

	// Inherited via Application
	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float) override;
	virtual void draw() override;
};

