/*******************************************************************************
Description: MIDInfc convert MIDI note to frequency, using command line argument
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
	double c5, c0, semitoneRatio;
	double frequency;
	int midinote;

	// initial calculations
	semitoneRatio = pow(2, 1.0 / 12);
	c5 = 220.0 * pow(semitoneRatio, 3);
	c0 = c5 * pow(0.5, 5);

	if (argc != 2) {
		printf("MIDInfc: converts MIDI note to frequency.\n");
		printf("usage: MIDInfc MIDInote\n");
		printf("range: 0 <= MIDInote <= 127 \n");
		return 1;
	}

	midinote = atoi(argv[1]);

	// use argv[1] to echo a bad argument string to the user
	if (midinote < 0) {
		printf("Bad MIDI note value: %s\n", argv[1]);
		return 1;
	}
	if (midinote > 127) {
		printf("%s is beyond the MIDI range!\n", argv[1]);
		return 1;
	}

	frequency = c0 * pow(semitoneRatio, midinote);
	printf("Frequency of MIDI note %d = %.2f Hz\n", midinote, frequency);

	return 0;
}