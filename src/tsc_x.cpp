#include <time.h>

#include <rbgo-time.h>

namespace rbgo {

#if RBGOTIME64 /////////////////////////////////////////////////////////////////

Tu64 tsc_ns_u64(){

	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return (ts.tv_sec * 1000000000) + ts.tv_nsec;
}

Tf64 tsc_ns_f64(Tu64 *cnv){

	return ((cnv) ? *cnv : tsc_ns_u64()) * 0.000000001;
}

#endif /////////////////////////////////////////////////////////////////////////

#if RBGOTIME32 /////////////////////////////////////////////////////////////////

Tu32 tsc_ns_u32(){

	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return ((ts.tv_sec * 1000000000) + ts.tv_nsec) & 0xFFFFFFFF;
}

Tu32 tsc_us_u32(){

	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return ((ts.tv_sec * 1000000) + (ts.tv_nsec / 1000)) & 0xFFFFFFFF;
}

Tf32 tsc_us_f32(Tu32 *cnv){

	return ((cnv) ? *cnv : tsc_us_u32()) * 0.000001;
}

#endif /////////////////////////////////////////////////////////////////////////

}//ns
