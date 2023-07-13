#pragma once
#include <rbgo-types.h>

namespace rbgo {

/*
Sleep functions: slp_x.cpp
*/
#if RTD_Ti32
void slp_ns_u32(Tu32 s, Tu32 ns);
#endif
#if RTD_Tf32
void slp_us_f32(Tf32 s);
#endif
#if RTD_Tf64
void slp_ns_f64(Tf64 s);
#endif

/*
Time Stamp Counters: tsc_x.cpp
*/
#if RTD_Ti32
Tu32 tsc_us_u32();
Tu32 tsc_ns_u32();
#endif
#if RTD_Ti32 && RTD_Tf32
Tf32 tsc_us_f32(Tu32 *cnv=0);
#endif
#if RTD_Ti64
Tu64 tsc_ns_u64();
#endif
#if RTD_Ti64 && RTD_Tf64
Tf64 tsc_ns_f64(Tu64 *cnv=0);
#endif


/*
Stopwatches: Sw.cpp
*/
#if RTD_Ti32 && RTD_Tf32
class Sw32 {
	Tu32 us=0;
public:
	void start();
	Tf32 stop();
	void stopb(char* buf, const char *pfx="", const char *sfx="");
	void stopp(const char *pfx="", const char *sfx="");
};
#endif

#if RTD_Ti64 && RTD_Tf64
class Sw64 {
	Tu64 ns=0;
public:
	void start();
	Tf64 stop();
	void stopb(char* buf, const char *pfx="", const char *sfx="");
	void stopp(const char *pfx="", const char *sfx="");
};
#endif
}//ns
