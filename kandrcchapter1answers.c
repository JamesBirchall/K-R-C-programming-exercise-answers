/*
 ============================================================================
 Name        : kandrbooktestsChapter1.c
 Author      : James Birchall
 Version     : 1.0
 Copyright   : James Birchall Nov 2012
 Description : A complete solution project for the K&R C, second edition
 questions.  Please note that these answers were just my way and not
 necessarily the best way to complete them.
 ============================================================================
 */

#include "kandrcchapter1answers.h"

void ex1_1(){
	printf("hello, world\n");
}

void ex1_2(){
	//printf("test incorrect escape character \c");	// compiler throws warning message but allows compile
}

void ex1_3(){
	//temperature conversion table
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 10;

	fahr = lower;

	printf("Fahrenheit\tCelsius\n");

	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f \t\t%6.1f\n", fahr, celsius);
		fahr += step;
	}
}

void ex1_4(){
	//same as 1_3 but using celsius as base and steps
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 10;

	celsius = lower;

	printf("Celsius\nFahrenheit\n");

	while(celsius <= upper){
		fahr = ((celsius*9) / 5) +32;
		printf("%3.0f \t\t%6.1f\n", celsius, fahr);
		celsius += step;
	}
}

void ex1_5(){
	//temperature conversion table
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 10;

	fahr = upper;

	printf("Fahrenheit\tCelsius\n");

	while(fahr >= lower){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f \t\t%6.1f\n", fahr, celsius);
		fahr -= step;
	}
}

void ex1_6and1_7(){
	//verifies EOF is 0 or 1 and prints it's value
	int a;

	while(a = (getchar() != EOF)){
		if(a == 1)
			putchar('1');

	}
	if(a == 0)
		putchar('0');
}

void ex1_8(){
	char a;

	int blanks, tabs, newlines;
	blanks = 0;
	tabs = 0;
	newlines = 0;

	while((a = getchar()) != EOF){
		if(a == '\n')
			newlines++;
		if(a == '\t')
			tabs++;
		if(a == ' ')
			blanks++;
	}
	printf("Input before EOF contained: %d blanks, %d tabs and %d newlines.\n", blanks, tabs, newlines);
}

void ex1_9(){
	char a;

	while((a = getchar()) != EOF){
		switch(a){
		case '\t':
			putchar(' ');
			break;
		case '\n':
			putchar(' ');
			break;
		default:
			putchar(a);
		}
	}

}

void ex1_10(){
	char a;


	while((a = getchar()) != EOF){
		switch(a){
		case '\t':
			putchar('\\');
			putchar('t');
			break;
		case '\n':
			putchar('\\');
			putchar('n');
			break;
		case '\b':
			putchar('\\');
			putchar('b');
			break;
		case '\\':
			putchar('\\');
			break;
		default:
			putchar(a);
		}
	}

}

void ex1_12(){
	int character;

	while((character = getchar()) != EOF){
		if((character == ' ') || (character == '\t') || (character == '\n'))
			putchar('\n');
		else
			putchar(character);
	}

}

void ex1_13(){
	//prints length of each word entered in histogram way - horizontally

	const int MAXSIZE = 50;

	int wordsSizes[MAXSIZE];	//max 50 words will be processed

	int i;

	for(i = 0; i < MAXSIZE; i++){
		wordsSizes[i] = 0;
	}

	for(i = 0; i < MAXSIZE; i++){
		int character;

		while(((character = getchar()) != EOF) && character != ' ' && character != '\t' && character != '\n'){
				wordsSizes[i]++;
		}

		if(character == EOF){
			break;
		}
	}

	printf("\n");

	for(i = 0; i < MAXSIZE; i++){
		int j = wordsSizes[i];
		int k;

		printf("Element[%d]: \t", i);

		for(k = 0; k < j; k++){
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
}

void ex1_14(){
	//loop through file and counts alphabet characters only, printing them after
	const int MAXSIZE = 26;

	int alphabetCount[MAXSIZE];
	char alphabet[MAXSIZE];


	int i;

	for(i = 0; i < MAXSIZE; i++){
		alphabetCount[i] = 0;
	}

	char c = 65;

	for(i = 0; i < MAXSIZE; i++, c++){
		alphabet[i] = c;
	}

	//read in file and count characters here
	char character;
	while((character = getchar()) != EOF){
		for(i = 0; i < MAXSIZE; i++){
			if(tolower(character) == tolower(alphabet[i])){
				alphabetCount[i]++;
				break;	//break early
			}
		}
	}


	for(i = 0; i < MAXSIZE; i++){
		printf("Letter[%c]:\t", alphabet[i]);
		int j;
		for(j = 0; j < alphabetCount[i]; j++){
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
}

void ex1_15(float fahr){
	//temperature conversion table
	float celsius;

	printf("Fahrenheit\tCelsius\n");

	celsius = (5.0/9.0) * (fahr-32.0);

	printf("%3.0f \t\t%6.1f\n", fahr, celsius);

}

void ex1_16(){

	int MAXLINE = 1000;
	int len, max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while((len = getstringline(line, MAXLINE)) > 0){
		printf("Length:%d, Text:%s",len,line);
		if(len > max){
			max = len;
			copyString(longest, line);
		}
	}
	if(max > 0)
		printf("%s", longest);

}

void ex1_17(){
	int MAXLINE = 1000;
	int len;
	char line[MAXLINE];

	while((len = getstringline(line, MAXLINE)) > 0){
		if(len > 80){
			printf("Length:%d, Text:%s",len,line);
		}
	}
}

void ex1_18(){
	int MAXLINE = 1000;
	int len;
	char line[MAXLINE];

	while((len = getstringlineremovetrail(line, MAXLINE)) > 0){
		if(len == 1){
			//remove empty lines
			if(line[0] == '\n');
			continue;
		}

		printf("Length:%d, Text:%s",len-1,line);
	}
}

void ex1_19(){
	char string1[50] = "Hello Jimmers";
	char string2[50] = "Hello Limmers";

	copyStringReverse(string2, string1, 12);

	printf("%s", string1);
	printf("\n");
	printf("%s", string2);
	printf("\n");
}

void ex1_20(){
	char string1[50] = "James\tAwesome";
	char string2[50];

	int i;
	for(i = 0; i < 50; i++)
		string2[i] = ' ';

	detab(string2, string1, 10);

	printf("%s", string1);
	printf("\n");
	printf("%s", string2);
	printf("\n");
}

void ex1_21(){
	char string1[50] = "James     Awesome";
	char string2[50];

	int i;
	for(i = 0; i < 50; i++)
		string2[i] = ' ';

	entab(string2, string1, 4);
	for(i = 0; i < 50; i++)
		string2[i] = ' ';
	detab(string2, string1, 4);

	printf("%s", string1);
	printf("\n");
	printf("%s", string2);
	printf("\n");
}

void ex1_22(){
	//doesn't handle words over wrap width
	int MAXLENGTH = 2000;
	int WRAPWIDTH = 13;
	
	char input[MAXLENGTH];
	
	int length;
	int lastSpace;
	int currentLocation;
	int line;
	int updatedLocation;	// this will hold current+= difference when line wraps early
	
	while((length = getstringline(input, MAXLENGTH)) > 0){
		
		if(length > WRAPWIDTH){
			line = 1;
			lastSpace = 0;
			currentLocation = 0;
			updatedLocation = 0;
			
			while(currentLocation < length){
								
				if(input[currentLocation] == ' '){
					lastSpace = currentLocation;
				}

				
				if(updatedLocation == WRAPWIDTH*line && lastSpace != 0){
					input[lastSpace] = '\n';
					updatedLocation = currentLocation + (WRAPWIDTH*line) - lastSpace;
					lastSpace = 0;
				 	line++;					
				}
				currentLocation++;
				updatedLocation++;
			}
		}
		puts(input);
	}	
}

void ex1_23(){
	
	char input, nextInput;
	int insideComment = 0;
	
	while((input = getchar()) != EOF){
		if(insideComment == 0){
			if(input == '/'){
				if((nextInput = getchar()) == '*'){
					insideComment = 1;
					continue;
				} else if(nextInput == '/'){
					insideComment = 2;
					continue;
				} else {
					putchar(input);
					putchar(nextInput);
					continue;
				}
			}
		} else if (insideComment == 1){
			if(input == '*'){
				if((nextInput = getchar()) == '/'){
					insideComment = 0;
					continue;
				} else{
					//putchar(input);
					//putchar(nextInput);
				}
			}
		} else if (insideComment == 2){
			if(input == '\n'){
				putchar(input);
				insideComment = 0;
				continue;
			}
		}
		
		if(insideComment == 0){
			putchar(input);
		}
	}
}

void ex1_24(){
	/*
	 * Programs looks for syntax errors in a C file and produces error reports for them
	 * Will look for:
	 * 	Unbalanced - Parenthesis(), brackets[], braces{}, single quotes'', double quotes""
	 * 	Escape sequences - Inside string that \ is never alone and contains one of expected values
	 * 	Quotes - Looks for quotes inside quotes which is an error
	 */ 
	 
	int leftParenthesis = 0;
	int rightParenthesis = 0;
	int leftBrackets = 0;
	int rightBrackets = 0;
	int leftBraces = 0;
	int rightBraces = 0;
	int singleQuotes = 0;
	int doubleQuotes = 0;
	int line = 1;
	int escapeSequence = 0;
	
	int insideCharacter = 0;
	int insideString = 0;
	int insideComment = 0;
	 
	char input, nextInput;
	 
	while((input = getchar()) != EOF){
		
		if(input == '\n')
			line++;
		
		if(insideComment == 0){
			if(input == '/' && (!insideCharacter && !insideString)){
				nextInput = getchar();
				if(nextInput == '*'){
					insideComment = 1;
					continue;
				}
				if(nextInput == '/'){
					insideComment = 2;
					continue;
				}
			}
		} else if(insideComment == 1){
			if(input == '*'){
				if((nextInput = getchar()) == '/'){
					insideComment = 0;
					continue;
				}	
			}	
		} else if(insideComment == 2){
			if(input == '\n'){
				insideComment = 0;
				continue;
			}
		}
	

		
		if(insideComment == 0){		

			if(insideCharacter == 0){
				if(input == '\''){
					insideCharacter = 1;
					singleQuotes++;
					continue;
				}
			} else if(insideCharacter == 1){
				if(escapeSequence == 0){
					if(input == '\\'){
						escapeSequence = 1;
						continue;
					}
				} else{
					if(input == '\\' || input == 't'|| input == 'b'|| input == 'n'|| input == 'a' || input == '\'' || input == '0'){
						escapeSequence = 0;
						continue;
					}
				}
				
				if(input == '\'' && escapeSequence == 0){
						insideCharacter = 0;
						singleQuotes++;
						continue;
				}
			}

			if(insideString == 0){
				if(input == '"' && !insideCharacter){
					insideString = 1;
					doubleQuotes++;
					continue;
				}
			} else if(insideString == 1){
				if(input == '"'){
					insideString = 0;
					doubleQuotes++;
					continue;
				}
			}

			if(insideCharacter == 0 && insideString == 0){
				switch(input){
					case '(':
						leftParenthesis++;
						break;
					case ')':
						rightParenthesis++;
						break;
					case '[':
						leftBrackets++;
						break;
					case ']':
						rightBrackets++;
						break;
					case '{':
						leftBraces++;
						break;
					case '}':
						rightBraces++;
						break;
					default:
						break;
				}			
			}			
		}
		
		
	}

	 
	if(leftParenthesis == rightParenthesis)
		printf("%d Pathenthesis matched...FINE\n", leftParenthesis);
	else
		printf("%d Left Parethesis: %d Right Parenthesis...ERROR\n", leftParenthesis, rightParenthesis);

	if(leftBrackets == rightBrackets)
		printf("%d Brackets matched...FINE\n", leftBrackets);
	else
		printf("%d Left Brackets: %d Right Brackets...ERROR\n", leftBrackets, rightBrackets);
		
	if(leftBraces == rightBraces)
		printf("%d Braces matched...FINE\n", leftBraces);
	else
		printf("%d Left Braces: %d Right Braces...ERROR\n", leftBraces, rightBraces);

	if((singleQuotes % 2) == 0)
		printf("%d Single Quotes matched...FINE\n", singleQuotes/2);
	else
		printf("%d Single Quotes...ERROR\n", singleQuotes);

	if((doubleQuotes % 2) == 0)
		printf("%d Double Quotes matched...FINE\n", doubleQuotes/2);
	else
		printf("%d Double Quotes...ERROR\n", doubleQuotes);

}

int getstringline(char charArray[], int limit){
	/*
	 * Read a line of characters into string with limit as max values
	 */
	int character;
	int i;

	for(i = 0; i < limit-1 && (character = getchar()) != EOF && character !='\n'; i++)
		charArray[i] = character;
	if(character == '\n'){
		charArray[i] = character;
		++i;
	}
	charArray[i] = '\0';
	return i;	//returns length of read line
}

int getstringlineremovetrail(char charArray[], int limit){
	/*
	 * Read a line of characters into string with limit as max values
	 */
	int character;
	int i;

	for(i = 0; i < limit-1 && (character = getchar()) != EOF && character !='\n'; i++)
		charArray[i] = character;

	//remove trailing space or tabs before appending end
	//i current equals end of line
	int j = i;

	while(charArray[j-1] == ' ' || charArray[j-1] == '\t'){
		--j;
	}

	i = j;

	if(character == '\n'){
		charArray[i] = character;
		++i;
	}

	charArray[i] = '\0';
	return i;	//returns length of read line
}

void copyString(char to[], char from[]){
	/* Copies string from one character array to another
	 * Uses EOF to signify end of from string
	 */
	int i = 0;

	while((to[i] = from[i]) != '\0')
		++i;
}

void copyStringReverse(char to[], char from[], int len){

	int i = 0;

	while(len >= 0){
		to[i] = from[len];
		len--;
		i++;
	}

}

void detab(char to[], char from[], int tabsize){

	int i = 0;
	while(from[i] != '\0'){
		i++;
	}

	if(i > 0){
		int j = 0;
		int newj = 0;

		while(j < i){
			if(from[j] == '\t'){
				int remainder = tabsize - (newj % tabsize);
				while(remainder > 0){
					to[newj] = ' ';
					remainder--;
					newj++;
				}
				j++;
			} else {
				to[newj] = from[j];
				j++;
				newj++;
			}
		}
	}
}

void entab(char to[], char from[], int tabsize){

	/*
 	 *	Function was supposed to take a string with whitespace,
 	 *	then for spaces mix in tabs as appropriate to make string smaller
 	 */

	int i = 0;
	while(from[i] != '\0'){
		i++;
	}

	if(i > 0){
		int j = 0;
		int newj = 0;

		while(j < i){
			if(from[j] == ' '){

				int remainder = tabsize - (newj % tabsize);
				if(remainder > 0){
					to[newj] = '\t';
					newj++;
				}
				j++;
			}
			else {
				to[newj] = from[j];
				j++;
				newj++;
			}
		}
	}
}
