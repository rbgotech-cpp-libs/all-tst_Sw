#include <time.h>

#include <rbgo-time.h>

namespace rbgo {

#if RTD_Ti32
void slp_ns_u32(Tu32 s, Tu32 ns){

	timespec ts = { s, ns };
	nanosleep(&ts, 0);
}
#endif

#if RTD_Tf32
void slp_us_f32(Tf32 s){

	timespec ts;
//	ts.tv_sec = (Tu32)s;
//	ts.tv_nsec = (Tu32)((s - ts.tv_sec) * 1000000000);
	ts.tv_sec = s;
	ts.tv_nsec = (s - ts.tv_sec) * 1000000000;
	nanosleep(&ts, 0);
}
#endif

#if RTD_Tf64
void slp_ns_f64(Tf64 s){

	timespec ts;
//	ts.tv_sec = (Tu32)s;
//	ts.tv_nsec = (Tu32)((s - ts.tv_sec) * 1000000000);
	ts.tv_sec = s;
	ts.tv_nsec = (s - ts.tv_sec) * 1000000000;
	nanosleep(&ts, 0);
}
#endif

}//ns
