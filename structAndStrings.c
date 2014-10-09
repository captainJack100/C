/*
 *	Personal reminder on structs and strings.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Person struct
typedef struct 
{
	char Name[10];
	int age;
} Person;

// Animal struct
typedef struct animal
{
	int age;
	void (*makeSound)();
	void (*changeAge)(struct animal *);
} Animal;

void makeQuack()
{
	printf("Quack\n");
}

void age10(struct animal *a)
{
	a->age = 10;
}

int main(void) 
{

	/************
 	* Structs
 	***************/ 
	// Intiliaze a struct to 0. Standard will implictly 
	// use whatever is in brace.
	// using memset can be dangerous when types are mixed in struct.
	Person Al = {0};
	
	// C99
	// memcpy -- no. don't. bad. 
	Person Tim = {.Name="Tim" , .age=45};
	printf("%s %d \n", Tim.Name, Tim.age);

	// function pointers in structs
	// cheap OO.
	Animal Duck = {.age=2, .makeSound=makeQuack, .changeAge=age10};
	Duck.makeSound();
	Duck.changeAge(&Duck);
	printf("New Age: %d\n", Duck.age);

	/******************
 	* Strings
 	*
 	***********************/ 
	// string literals are imlictly null terminated.
	// str1[2] == '\0' is true.
	char str1[3] = "ab";
	printf("str1: %s %d %d\n", str1, (int)sizeof(str1), (int)strlen(str1));

	// initialize a string
	char str2[3] = {0};
	printf("str2: %s %d %d\n", str2, (int)sizeof(str2), (int)strlen(str2));

	// strncpy was designed for splicing strings into bigger ones.
	// Not null terminated.
	char str3[3] = {0};
	strncpy(str3, str1, sizeof(str3));
	printf("str3: %s %d %d\n", str3, (int)sizeof(str3), (int)strlen(str3));
	if (str3[2] == '\0')
		printf("yes, it copied the null from str3\n");	

	char str4[3] = {0};
	strncpy(str4, "12", sizeof(str4));
	printf("str4: %s %d %d\n", str4, (int)sizeof(str4), (int)strlen(str4));
	if (str4[2] == '\0')
		printf("yes it copied the null from the literal\n");

	return 0;
}	

