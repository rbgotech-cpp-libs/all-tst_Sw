#include <Sw.h>

namespace rbgo {

Sw::Sw(){

	tv = new timeval();
	mts = 0;
}

Sw::~Sw(){
	delete tv;
}

void Sw::start(){
	mts = get();
}

Tf64 Sw::stop(){

	return  get() - mts;
}

void Sw::stopp(const char *pfx, const char *sfx){

	//stick to %.6f; anything beyond that is random.
	printf("%s%.6f%s", pfx, get()-mts, sfx);
}

Tf64 Sw::get(){

	gettimeofday(tv, 0);
	//usec is integer sub div of a sec (0...9999999);
	//div by 1 million, to get the floating point where we want.
	return tv->tv_sec + (tv->tv_usec * 0.000001);
}

}//ns
