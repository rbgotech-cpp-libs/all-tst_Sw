#pragma once

#include <stdio.h>
#include <sys/time.h>

#include <rbgo-types.h>

namespace rbgo{

class Sw {

	timeval *tv;
	Tf64 mts;

public:
	Sw();
	~Sw();
	void start();
	Tf64 stop();
	void stopp(const char *pfx="", const char *sfx="s\n");

private:
	Tf64 get();
};

}//ns
