/********************************************************\
File Name: main.c
Author: Liri (12/4/2020)
Purpose: This file run the program that check which person
		 is leagal to drive in every country
\********************************************************/

#include <stdio.h>
#include <stdbool.h>

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