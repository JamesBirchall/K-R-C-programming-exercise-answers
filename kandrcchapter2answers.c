#include "kandrcchapter2answers.h"

int binsearch(int tofind, int values[], int max){
  int low, mid, high;

  low = 0;
  high = max-1;

  while(low <= high){
    mid = (low+high) / 2; // get mid point

    if(tofind < values[mid])
      high = mid - 1;
    else if(tofind > values[mid])
      low = mid + 1;
    else
      return mid;      
  }

  return -1;
}

void ex2_10(){
	char word[] = "JAMES IN UPPERCASE\n";
	printf("%s", word);
	lowerString(word);
	printf("%s", word);
}

void lowerString(char word[]){
	int i = 0;
	while(word[i] != '\0'){
		word[i] = (word[i] >= 'A' && word[i] <= 'Z') ? word[i] + 'a'-'A' : word[i];
		i++;
	}
}

void ex2_9(){
	unsigned int first = bitCountOriginal(0xFFFFFFF);
	unsigned int second = bitCountOriginal(0xFFFFFFF);
	printf("First value %d, Second value %d\n", first, second);
}

int bitCountOriginal(unsigned x){
	int b;
	for(b = 0; x != 0; x >>= 1)
		if(x & 01)
			b++;
	return b;
}

int bitCountNew(unsigned x){
	/*
	 *	x &= (x-1) - Say x = 1111 -1 = 1110, anding
	 *	produces 1110
	 */

	int b;
	for(b = 0; x != 0; x &= (x-1))
		b++;
	
	return b;
}

void ex2_8(){
	/*
	 * Function will call rightRotate function defined below
	 */
	unsigned int value = 8;
	printBinary(value);
	value = rightRotate(value, 2);
	printBinary(value);
}


unsigned int rightRotate(unsigned int x, int number){
	return x >> number;
}


void ex2_7(){
	/*
	 * Function will call inverBits funtion defined below
	 */
	unsigned int value = 0xF;

	printBinary(value);
	value =	invertBits(value, 3, 2);
	printBinary(value);

}

unsigned int invertBits(unsigned int x, int position, int number){

	// this function will act similar to setbits but just invert
	// the set bits and actually use copy of x as values

	unsigned int xValue = x;


	x = x & (~0 << position);	// mask upper bits with 1's
	x = x | ~(~0 << (position - number)); //mask lower bits with 1's

	xValue = (~xValue & ~(~0 << number));
	xValue = xValue << (position - number);
	//the negation does the job!

	return x | xValue;
}

void ex2_6(){
	/*
 	 * Function will call setbits function defined below	
 	 */ 
	unsigned int value = 0xF;
	unsigned int value2 = 2;
	printBinary(value);
	value = setBits(value, 4, 2, value2);
	printBinary(value);
}

unsigned int setBits(unsigned int x, int position, int number, unsigned int value){
	/*
	 * To set bits, take bits from 'number' of lowest bits
	 * 
	 */

	x = x & (~0 << position);	// mask upper bits with 1's
	x = x | ~(~0 << (position - number)); //mask lower bits with 1's

	value = value & ~(~0 << number); //set value up
	value = value << (position - number);	//set value to position
	
	return x | value;
}

unsigned int getBits(unsigned int x, int position, int number){
	
	return ( x >> ( position - number )) & ~ ( ~ 0 << number);

}

void printBinary(unsigned int input){
	/*
 	 *	Used for binary function exercises so we can see start / end values
 	 */ 
	int MAXLENGTH = 256;
	char binaryString[MAXLENGTH];
	int i;
	//zero out string array
	for(i = 0; i < MAXLENGTH; i++)
		binaryString[i] = '\0';
	//tests bits and shifts inpur right 1
	i = 0;
	while(input){
		binaryString[i] = '0' + (input & 1);
		input >>= 1;
		i++;
	}
	//find end of binary string
	i = 0;
	while(binaryString[i] != '\0'){
		i++;
	}
	//prints in reverse order the binary representation - so high order first
	while(--i >= 0){
		printf("%c", binaryString[i]);
	}
	printf("\n");
}


int ex2_5(char s1[], char s2[]){
	/*
 	 * Match any character in s2 in s1, return position
 	 */ 	
	int position = -1;

	char temp, temp2;
	int i, j;

	for(i = 0; (temp = s1[i]) && temp != '\0'; i++){
		for(j = 0; (temp2 = s2[j]) && temp2 != '\0'; j++){
			if(temp == temp2)
				return position = i;
		}
	}
	
	return position;	
}

void ex2_4(char s1[], char s2[]){
	/*
 	 * Delete any character that is in s2 in s1 	 *
 	 */ 

	char temp, temp2;
	int count;

	int i, j;
	for(i = 0; (temp = s2[i]) && temp != '\0'; i++){
		for(j = 0; (temp2 = s1[j]) && temp2 != '\0'; j++){
			if(temp == temp2){
				s1[j] = '-';
			}
		}
	}


	count = 0;
	for(i = 0; (temp2 = s1[i]) && temp2 != '\0'; i++){
		if(temp2 != '-'){
			s1[count] = temp2;
			count++;
		} else{
		}
	}
	s1[count] = '\0';
}

void ex2_3(char myString[]){

	/*
 	 *	Write a function htoi(s) which converts a string of hex values including
 	 *	a leading 0x or 0X into its integer equivalent.  
 	 *	Allow upper case and lowercase values to be used (0-9,a-f,A-F)
 	 *	For sake of ease I am going to accept '\0' as end of string
 	 */ 
	
	char hexDigits[] = "0123456789ABCDEF";
	float result = 0.0f;
	
	int counter = 0;
	while(myString[counter++] != '\0'){}
	counter--;
	
	int i;
	for(i = 0; counter-- > 0; i++){
		int j;
		//check for 0X or 0x - well in a basic way...lets just find an x if used and break early
		if(myString[counter] == 'x' || myString[counter] == 'X')
			break;

		for(j = 0; j <= 16; j++){			
			if(tolower(hexDigits[j]) == tolower(myString[counter])){
				float base = pow(16, i);
				if(base)
					result += base*j;
				else
					result += j;		
			}
		}
	}
	printf("Result: %f\n", result);
}

void ex2_2(){
	/*
 	 * re-write this:
 	 * 	int i;
 	 * 	char c;
 	 * 	int lim = 10;
 	 * 	for(i = 0; i < lim-1 && (c = getchar()) != '\n' && c!= EOF; ++i)
 	 * 		s[i] = c;
 	 *
 	 * 	without using && or ||
 	 *
 	 * 	So we have a loop, each iteration getting increased by 1
 	 * 	we are checking each loop that we have 1 space left in the limit variable
 	 * 	we are also getting a character each loop and making sure its not a newline or EOF
 	 *
 	 */ 

	int lim = 10;
	char myString[lim];
	int i;
	char c;

	for(i = 0; i < lim; i++)
		myString[i] = '\0';	//zero out alements in the string

	//new loop
	for(i = 0; i < lim-1; ++i){
		if((c = getchar()) != '\n'){
			if(c != EOF)
				myString[i] = c;
		}
	}
	//end new loop without 

	for(i = 0; i < lim; i++)
		printf("%c",myString[i]);

	printf("\n");

}

void ex2_1(){
	/*
 	 * Determine ranges of char, short, int, long
 	 * both signed and unsigned by standard headers then
 	 * computationally
 	 * Do same for floating point types
 	 */ 	

	/*
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
	*/

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

	/*while(char1 != 0){
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
	*/

	printf("Float MIN:%E\tMAX:%E\n", FLT_MIN, FLT_MAX);
}
