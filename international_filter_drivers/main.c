/********************************************************\
File Name: main.c
Author: Liri (12/4/2020)
Purpose: This file run the program that check which person
		 is leagal to drive in every country
\********************************************************/

#include <stdio.h>
#include <stdbool.h>

#define INITIAL_INDEX (0)
#define STRING_OLD_ENOUGH_TO_DDRIVE ("%s is old enough to drive!, ")
#define ENTER ("\n")
#define PRINT_CUNTRIES ("In %s: ")
#define SIZE_OF_ARRAY_NAMES_AND_AGES (5)

#define LIMIT_AGE_IN_ISRAEL (17)
#define LIMIT_AGE_IN_FRANCE (15)
#define LIMIT_AGE_IN_EGYPT (18)
#define LIMIT_AGE_IN_ATLANTIS (30)

#define NUMBER_OF_CUNTRIES (4)

#define ISRAEL ("Israel")
#define FRANCE ("France")
#define EGYPT ("Egypt")
#define ATLANTIS ("Atlantis")

bool is_old_enough_to_drive(int age,
							int limit_age);

bool is_old_enough_to_drive(int age, 
							int limit_age) {
	/********************************************************\
	* Function name - is_old_enough_to_drive
	*
	* Function Purpose - check if the person is old enough to drive
	*
	* Parameters - IN int age - the age of the person,
	*			   IN int limit_age - the smallest age for driving
	*
	* Return Value - if the person is old enough to drive - return true,
	*				  otherwise - return false
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function check if the age of the person is bigger than
	*		      the limit age
	*
	* Author - Liri
	\********************************************************/
	if (age < limit_age) {
		return false;
	}
	return true;
}

void filterDriver(char* names[],
					int* ages,
					int size,
					bool(*function_pointer)(int age, int limit_age),
					int limit_age) {
	/********************************************************\
	* Function name - filterDriver
	*
	* Function Purpose - go through the array of the names and ages,
	*					 and check if the person is legal to drive according
	*					 to his/her age
	*
	* Parameters - IN char* names[] - array of names,
	*			   IN int* ages - array of ages,
	*			   IN int size - size of arrays,
	*			   IN bool(*function_pointer)(int age, int limit_age) - pointer
	*				to function that get age and limit age, and return bool
	*			   IN limit_age - the limit age to drive
	*
	* Return Value - this function has no return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - go through the array of the names and ages,
	*			  and for each one run function that check if the person
	*			  is leagal to drive by function pointer
	*
	* Author - Liri
	\********************************************************/
	int index = INITIAL_INDEX;
	bool result = false;

	for (index = INITIAL_INDEX; index < size; ++index) {

		result = (*function_pointer)(ages[index], limit_age);

		if (true == result)
		{
			printf(STRING_OLD_ENOUGH_TO_DDRIVE, names[index]);
		}
	}
	printf(ENTER);
}

void internationalFilterDrivers(char* names[],
	int* ages,
	int size) {
	/********************************************************\
	* Function name - internationalFilterDrivers
	*
	* Function Purpose - go through the array of cuntries, and for each
	*					 cuntry check if the people are legal
	*
	* Parameters - IN char* names[] - array of names,
	*			   IN int* ages - array of ages,
	*			   IN int size - size of arrays
	*
	* Return Value - this function has no return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function go through the array of cuntries, and for each
	*			  cuntry call function filterDriver() and check if the people
	*			  are legal
	*
	* Author - Liri
	\********************************************************/
	int limit_ages[] = { LIMIT_AGE_IN_ISRAEL ,
							LIMIT_AGE_IN_FRANCE,
							LIMIT_AGE_IN_EGYPT,
							LIMIT_AGE_IN_ATLANTIS };
	char *cuntries[] = { ISRAEL,
							FRANCE,
							EGYPT,
							ATLANTIS };
	int index = INITIAL_INDEX;
	bool(*function_pointer)(int age, int limit_age);

	for (index = INITIAL_INDEX; index < NUMBER_OF_CUNTRIES; ++index) {
		printf(PRINT_CUNTRIES, cuntries[index]);

		function_pointer = is_old_enough_to_drive;

		filterDriver(names,
						ages,
						size,
						function_pointer,
						limit_ages[index]);
	}
}

void main() {
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - run function that check if people are
	*					 old enough to drive
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function check if the people in array are
	*			  old enough to drive by call to filterDriver
	*
	* Author - Liri
	\********************************************************/
	char *names[] = { "Liri",
						"Ofek",
						"Nir",
						"Oree",
						"Dan" };

	int ages[] = { 17,
					15,
					18,
					30,
					5 };
	int size = SIZE_OF_ARRAY_NAMES_AND_AGES;

	bool(*function_pointer)(int age, 
							int limit_age);

	function_pointer = is_old_enough_to_drive;

	internationalFilterDrivers(names,
								ages,
								size);
}
