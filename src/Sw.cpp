#include <stdio.h>

#include <rbgo-time.h>

namespace rbgo {

#if RBGOTIME64 /////////////////////////////////////////////////////////////////

void Sw64::start(){
	ns = tsc_ns_u64();
}

Tf64 Sw64::stop(){

	Tu64 el = tsc_ns_u64() - ns;
	return  tsc_ns_f64(&el);
}

void Sw64::stopb(char* buf, const char *pfx, const char *sfx){

	sprintf(buf, "%s%.9f%s", pfx, stop(), sfx);
}

void Sw64::stopp(const char *pfx, const char *sfx){

	//stick to %.9f; anything beyond that is random.
	printf("%s%.9f%s", pfx, stop(), sfx);
}

#endif /////////////////////////////////////////////////////////////////////////

#if RBGOTIME32 /////////////////////////////////////////////////////////////////


void Sw32::start(){
	us = tsc_us_u32();
}

Tf32 Sw32::stop(){

	Tu32 el = tsc_us_u32() - us;
	return  tsc_us_f32(&el);
}

void Sw32::stopb(char* buf, const char *pfx, const char *sfx){

	sprintf(buf, "%s%.6f%s", pfx, stop(), sfx);
}

void Sw32::stopp(const char *pfx, const char *sfx){

	//stick to %.9f; anything beyond that is random.
	printf("%s%.6f%s", pfx, stop(), sfx);
}

#endif /////////////////////////////////////////////////////////////////////////

}//ns
