#ifndef WEIGHTLOS_H_
#define WEIGHTLOS_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#pragma warning( disable : 4996 )

using namespace std;
//structs

struct health_reg
{
	double min_fat;
	double max_fat;
	double food_energy;
	double carbs_min;
	double carbs_perc_min;
	double carbs_perc_max;
};
struct food_item
{
	char *name;
	double amount;
	char *units;
	double fat;
	double food_energy;
	double carbohydrates;
	double protein;
	double cholesterol;
	double weight;
	double saturated_fat;

};

struct mealPlan {
	int num_Meals;
	vector<struct food_item> * meals;
};

struct dayPlan {
	double num_timeslot;
	vector<struct schedule> * timeslots;
	
};

struct schedule {
	char * activity;
	double calories_burned;
	double calories_gained;
};
//global varaibles
#define DAY 24
#define SEGS 96

//function prototypes
int readFile(const char * filename, vector<food_item> * file_contents);
void quick_sort(vector<food_item> * data, double compare(vector<food_item> * data, const void *, const void *, bool getA), int left, int right);

double compare_by_Name(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Amount(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Units(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Food_Energy(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Carbohydrates(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Protein(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Cholesterol(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Weight(vector<food_item> * data, const void * a, const void * b, bool getA);
double compare_by_Saturated_Fat(vector<food_item> * data, const void * a, const void * b, bool getA);




#endif

