#include <reg52.h>
#include <intrins.h>
#include <lcd.h>
#include <mkd51sim.h>

unsigned char xdata PTWE _at_ 0x8008;
unsigned char xdata PTWY _at_ 0x8009;
unsigned char xdata POT2 _at_ 0x8007;
int odczyt;
int fejk;
int delay;
int lewo = 1;
int wcisniety = 0;
int dummy;
void main(void) {

	while (1) {
		POT2 = 0;
		for (delay = 0; delay < 10; delay++) {
			odczyt = POT2;
			fejk = (odczyt * 7 + 128) / 256;

			switch (fejk) {
			case 0:
				PTWY = 1;
				dummy = 0;
				break;
			case 1:
				dummy = 1;
				PTWY = 2;
				break;
			case 2:
				dummy = 2;
				PTWY = 4;
				break;
			case 3:
				dummy = 3;
				PTWY = 8;
				break;
			case 4:
				dummy = 4;
				PTWY = 16;
				break;
			case 5:
				dummy = 5;
				PTWY = 32;
				break;
			case 6:
				dummy = 6;
				PTWY = 64;
				break;
			case 7:
				dummy = 7;
				PTWY = 128;
				break;
			default: break;
			}
		}

		if (!(PTWE & 32)) wcisniety = 1;
		if ((PTWE & 32) && wcisniety == 1) {

			while (1) {

				switch (dummy) {
				case 0:

					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							PTWY = 2;
							dummy = 1;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							lewo = 1;
							PTWY = 2;
							dummy = 1;
						}
					}
					break;
				case 1:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							PTWY = 4;
							dummy = 2;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							PTWY = 1;
							dummy = 0;
						}
					}
					break;
				case 2:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							PTWY = 8;
							dummy = 3;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 1;
							PTWY = 2;
						}
					}
					break;
				case 3:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 4;
							PTWY = 16;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 2;
							PTWY = 4;
						}
					}
					break;
				case 4:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 5;
							PTWY = 32;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 3;
							PTWY = 8;
						}
					}
					break;
				case 5:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 6;
							PTWY = 64;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 4;
							PTWY = 16;
						}
					}
					break;
				case 6:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 7;
							PTWY = 128;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 5;
							PTWY = 32;
						}
					}
					break;
				case 7:
					if (lewo == 1) {
						for (delay = 0; delay < 2000; delay++) {
							lewo = 0;
							PTWY = 64;
							dummy = 6;
						}
					}
					else {
						for (delay = 0; delay < 2000; delay++) {
							dummy = 6;
							PTWY = 64;
						}
					}
					break;
				}
			}

		}
	}
}
