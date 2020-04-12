/********************************************************\
File Name: main.c
Author: Liri (12/4/2020)
Purpose: This file run the program that check which person
		 is leagal to drive
\********************************************************/

#include <stdio.h>
#include <stdbool.h>

#define INITIAL_INDEX (0)
#define STRING_OLD_ENOUGH_TO_DDRIVE ("%s is old enough to drive!, ")
#define ENTER ("\n")
#define LIMIT_AGE_FOR_DRIVING (17)

bool is_old_enough_to_drive(int age);

bool is_old_enough_to_drive(int age) {
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
	if (age < LIMIT_AGE_FOR_DRIVING) {
		return false;
	}
	return true;
}

void filterDriver(char* names[],
	int* ages,
	int size,
	bool(*function_pointer)(int age)) {
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

		result = (*function_pointer)(ages[index]);

		if (true == result)
		{
			printf(STRING_OLD_ENOUGH_TO_DDRIVE, names[index]);
		}
	}
	printf(ENTER);
}