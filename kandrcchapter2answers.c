#include "kandrcchapter2answers.h"

void ex2_1(){
	/*
 	 * Determine ranges of char, short, int, long
 	 * both signed and unsigned by standard headers then
 	 * computationally
 	 * Do same for floating point types
 	 */ 	

	unsigned char char1 = 1;
	unsigned char char1previous = 0;
	signed char char2 = 1;
	signed char char2previous = 0;

	unsigned int integer1 = 1;
	unsigned int integer1previous = 0;
	signed int integer2 = 1;
	signed int integer2previous = 0;

	unsigned short short1 = 1;
	unsigned short short1previous = 0;
	signed short short2 = 1;
	signed short short2previous = 0;

	unsigned long long1 = 1;
	unsigned long long1previous = 0;
	signed long long2 = 1;
	signed long long2previous = 0;

	printf("Unsigned char\tMax:%hhu\n",UCHAR_MAX);
	printf("Signed char\tMin:%hhd\tMax:%hhd\n", CHAR_MIN, CHAR_MAX);
	printf("Unsigned int\tMax:%u\n", UINT_MAX);
	printf("Signed int\tMin:%u\tMax:%d\n", INT_MIN, INT_MAX);
	printf("Unsigned short\tMax:%hu\n", USHRT_MAX);
	printf("Signed short\tMin:%hd\tMax:%hd\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned long\tMax:%lu\n", ULONG_MAX);
	printf("Signed long\tMin:%ld\tMax:%ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long long\tMax:%llu\n", ULLONG_MAX);
	printf("Signed long long\tMin:%lld\tMax:%lld\n", LLONG_MIN, LLONG_MAX);

	while(char1 != 0){
		char1previous = char1;
		char1++;
	}	
	printf("Computed unsigned char MAX:%u\n", char1previous);

	while(char2 != 0){
		if(char2 > char2previous){
			char2previous = char2;
		}
		char2++;
	}
	printf("Computed signed char MAX:%d\n", char2previous);

	char2 = -1;
	char2previous = 0;
	while(char2 != 0){
		if(char2 < char2previous){
			char2previous = char2;
		}
		char2--;
	}
	printf("Computed signed char MIN:%d\n", char2previous);

	short1 = 1;
	short1previous = 0;

	while(short1 != 0){
		short1previous = short1;
		short1++;
	}
	printf("Computed unsigned short MAX:%hu\n", short1previous);

	short2 = -1;
	short2previous = 0;

	while(short2 !=0){
		if(short2 < short2previous){
			short2previous = short2;
		}
		short2--;
	}
	printf("Computed signed short MIN:%hd\n", short2previous);

	short2 = 1;
	short2previous = 0;

	while(short2 != 0){
		if(short2 > short2previous){
			short2previous = short2;
		}
		short2++;
	}
	printf("Computed signed short MAX:%hd\n", short2previous);

	integer1 = 1;
	integer1previous = 0;

	while(integer1 != 0){
		integer1previous = integer1;
		integer1++;
	}
	printf("Computer unsigned int MAX:%u\n", integer1previous);
	
	integer2 = -1;
	integer2previous = 0;

	while(integer2 != 0){
		if(integer2 < integer2previous){
			integer2previous = integer2;
		}
		integer2--;
	}
	printf("Computed signed int MIN:%d\n", integer2previous);

	integer2 = 1;
	integer2previous = 0;
	while(integer2 != 0){
		if(integer2 > integer2previous){
			integer2previous = integer2;
		}
		integer2++;
	}
	printf("Computed signed int MAX:%d\n", integer2previous);
}
