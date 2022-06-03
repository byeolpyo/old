//convert between ascii and hex STRING
#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* hex_to_ascii(const char*);
char* ascii_to_hex(const char*);

char* hex_to_ascii(const char* inp) {
	if(!strlen(inp)%2) {
		fprintf(stderr, "Invalid hex format!");
		char* ret = (char*) malloc(sizeof(char) * strlen(inp));
		strcpy(ret, inp);
		return ret;
	}
	char* out = (char*) malloc(sizeof(char) * strlen(inp) / 2);	

	int i = 0, k = 0;
	char c;
	char buf[3];
	buf[3] = '\0';
	while(inp[i] != '\0' && inp[i+1] != '\0') {
		memcpy(buf, inp+i, 2);
		c = (int) strtol(buf, NULL, 16);
		strncpy(out+k, &c, 1);
		k++;
		i+=2;
	}
	out[k] = '\0';
	return out;
}

char* ascii_to_hex(const char* inp) {
	char* out = (char*) malloc (sizeof(char) * strlen(inp) * 2 - 1);
	int k = 0, i = 0;
	while(inp[k] != '\0') {
		sprintf((char*)(out+i), "%02x", inp[k++]);
		i+=2;
	}
	out[i+1] = '\0';
	return out;
}

#endif /* CONVERT_H */
