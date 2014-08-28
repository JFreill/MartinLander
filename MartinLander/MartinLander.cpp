#include "MartinLander.h"
/***********************************************************************************
•       Filename:				Name.cpp
•       Version:				100.02
•       Author:					James Freill
•       Student Number:			040 590 657
•       Course Name/Number:		13W_CST8219_400 C++ Programming
•       Lab Section:			010
•       Assignment #:			0
•       Assignment Name:		Ass0_Freill1
•       Due Date:				22nd March 2013
•       Submission Date:		22nd March 2013
•       Professor:				Andrew Tyler
•       Purpose:				Controls the variables, and overloaded constructors for 
								the name class.
************************************************************************************/
#include "MartinLander.h"
/********************************************************************
Function name:		Name Assignment
Purpose:			Allows for the allocation of memory for first and last
					name
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
Records::Records(char* tempFirstName, char* tempLastName, float impact){
	
	r_name = new char[strlen(tempFirstName)+1];
	r_time = new char[strlen(tempLastName)+1];

	strcpy(r_name, tempFirstName);
	strcpy(r_time, tempLastName);
	r_impact = impact;
}
/********************************************************************
Function name:		Name Copy Constructor
Purpose:			constructs a new existence of a existing name
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
Records::Records(Records& rs){

	r_name = new char[strlen(rs.GetName())+1];
	r_time = new char[strlen(rs.GetTime())+1];

	memcpy(r_name, rs.r_name, strlen(rs.GetName())+1);
	memcpy(r_time, rs.r_time, strlen(rs.GetTime())+1);
	r_impact = rs.GetImpact();
}
/********************************************************************
Function name:		Name deconstructor
Purpose:			deallocates the memory setout for name
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
Records::~Records(){
	delete[] r_name;
	delete[] r_time;
}
/********************************************************************
Function name:		Name copy constructor
Purpose:			takes the name from one reference and returns it back
					to the calling member.
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
Records& Records::operator=(Records& rs){

	delete[] r_name;
	delete[] r_time;

	r_name = new char[strlen(rs.GetName())+1];
	r_time = new char[strlen(rs.GetTime())+1];

	strcpy(r_name, rs.GetName());
	strcpy(r_time, rs.GetTime());
	r_impact = rs.GetImpact();

	return *this;	
}
/********************************************************************
Function name:		Overloaded > op.
Purpose:			allows for the difference between the two passed students
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
bool Records::operator>(Records& rs){
	if(GetImpact() < rs.GetImpact() && GetTime() < rs.GetTime()) return true;
	else return false;
}
/********************************************************************
Function name:		Overloaded < op.
Purpose:			allows for the difference between the two passed students
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
bool Records::operator<(Records& rs){
	if(GetImpact() < rs.GetImpact() && GetTime() < rs.GetTime()) return true;
	else return false;
}
/********************************************************************
Function name:		Overloaded == op.
Purpose:			allows for the ability to deferintiate between two students
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
bool Records::operator==(Records& rs){
	if(GetImpact() == rs.GetImpact() && GetTime() == rs.GetTime()) return true;
	else return false;
}
/********************************************************************
Function name:		Report()
Purpose:			displays the first and last name specified 
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				James Freill
**********************************************************************/
void Records::Report(){
	cout<<" |Name: "<<GetName()<<" |Impact Speed: "<<GetTime()<<" |Time: "<<GetImpact()<<endl;
}