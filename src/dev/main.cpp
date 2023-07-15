#ifdef RBGOTIME_DEVMAIN
#include <stdlib.h>//setbuf, system, exit, atoi
#include <stdio.h>//puts, printf, scanf, fgetc

#include <rbgo-time.h>
#include <rbgo-cli.h>





#define MENU_LENGTH 10
const char* menuStrings[MENU_LENGTH] = {
	"0	quit",
	"1	menu",
	"2	clear screen",

	"3	sw64->start; slp_ns_f64(0.1s); sw64->stop: ",
	"4	sw64->start; slp_ns_u32(1s,250Mns); sw64->stopb: ",
	"5	sw64->start; slp_us_f32(0.75s); sw64->stopp: ",

	"6	sw32->start; slp_ns_f64(0.1s); sw32->stop: ",
	"7	sw32->start; slp_ns_u32(1s,250Mns); sw32->stopb: ",
	"8	sw32->start; slp_us_f32(0.75s); sw32->stopp: ",

	"9	tsc_ns_u64() tsc_ns_f64(), tsc_ns_u32(), tsc_us_u32(), tsc_us_f32()"
};

int main(){

	char input[16] = {0};
	rbgo::Tu32 mc=1;

	rbgo::CliMode::initialize();
	rbgo::CliMode::outputNoBuf();

//---
	rbgo::Sw64 *sw64 = new rbgo::Sw64();
	rbgo::Sw32 *sw32 = new rbgo::Sw32();
	char *sElapsed = new char[128];
	rbgo::Tf64 f64Itv, nsf;
	rbgo::Tu64 ns;
	rbgo::Tu32 i=0, ns32, us;
	rbgo::Tf32 usf, f32Itv;
	char backspaces[100] = {0};
	while(i < 99)backspaces[i++]='\b';


	while(1){

		if(mc){
			printf("'0' to quit...\n");
			rbgo::CliMode::inputNoBlockNoEcho();
		}

		switch(mc){
		case 0: goto break2;
		case 1: mc=0; while(mc < MENU_LENGTH) puts(menuStrings[mc++]); break;
		case 2: system("cls | clear"); break;

		//Test cases...

//--- TEST: Stopwatch Nano, Sleep Funcs 3x
		case 3:
			while(1){
				if(getchar() == '0') break;
				sw64->start();
				rbgo::slp_ns_f64(0.1);
				printf(backspaces);
				f64Itv = sw64->stop();
				printf("%s%.9f", menuStrings[mc], f64Itv);
			}
		break;
		case 4:
			while(1){
				if(getchar() == '0') break;
				sw64->start();
				rbgo::slp_ns_u32(1, 250*1000*1000);
				printf(backspaces);
				sw64->stopb(sElapsed, menuStrings[mc]);
				printf(sElapsed);
			}
		break;
		case 5:
			while(1){
				if(getchar() == '0') break;
				sw64->start();
				rbgo::slp_us_f32(0.75);
				printf(backspaces);
				sw64->stopp(menuStrings[mc]);
			}
		break;

//--- TEST: Stopwatch Micro, Sleep Funcs 3x
		case 6:
			while(1){
				if(getchar() == '0') break;
				sw32->start();
				rbgo::slp_ns_f64(0.1);
				f32Itv = sw32->stop();
				printf(backspaces);
				printf("%s%.6f", menuStrings[mc], f32Itv);
			}
		break;
		case 7:
			while(1){
				if(getchar() == '0') break;
				sw32->start();
				rbgo::slp_ns_u32(1, 250*1000*1000);
				printf(backspaces);
				sw32->stopb(sElapsed, menuStrings[mc]);
				printf(sElapsed);
			}
		break;
		case 8:
			while(1){
				if(getchar() == '0') break;
				sw32->start();
				rbgo::slp_us_f32(0.75);
				printf(backspaces);
				sw32->stopp(menuStrings[mc]);
			}
		break;

//--- TEST: Time Stamp Counters 5x
		case 9:
			printf("tsc_ns_u64()         tsc_ns_f64()          tsc_ns_u32() tsc_us_u32() tsc_us_f32()   @10Hz\n");
			while(1){
				if(getchar() == '0') break;
				printf(backspaces);

				ns = rbgo::tsc_ns_u64();
				nsf = rbgo::tsc_ns_f64();
				ns32 = rbgo::tsc_ns_u32();

				us = rbgo::tsc_us_u32();
				usf = rbgo::tsc_us_f32();

				printf("%020zu %021.9f %010zu   %010zu   %011.6f", ns, nsf, ns32, us, usf);
				rbgo::slp_ns_f64(0.1);
			}
		break;
		}

		puts("");
		rbgo::CliMode::inputBlockEcho();
		printf("choice: ");
		scanf("%2s", input);
		mc = atoi(input);
	}

break2:
	rbgo::CliMode::restore();
	delete sw64;
	delete sw32;
	delete sElapsed;
}

#endif//RBGOTIME_DEVMAIN
