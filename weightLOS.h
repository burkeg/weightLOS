#ifndef WEIGHTLOS_H_
#define WEIGHTLOS_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#pragma warning( disable : 4996 )

using namespace std;
//structs

typedef vector<vector<char> > dag;
typedef vector<vector<struct food_item> > DP;
typedef vector<bool> bits;

struct health_reg
{
	bool sex;
	double fat;
	double food_energy;
	double carbs;
	double protein;
	double cholesterol;
	double saturated_fat;
};
struct food_item
{
	double sum_value;
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

	food_item& operator +(const food_item& a)
	{
		food_item ret;
		ret.carbohydrates = this->carbohydrates + a.carbohydrates;
		ret.cholesterol = this->cholesterol + a.cholesterol;
		ret.fat = this->fat + a.fat;
		ret.food_energy = this->food_energy + a.food_energy;
		ret.protein = this->protein + a.protein;
		ret.saturated_fat = this->saturated_fat + a.saturated_fat;
		return ret;
	}

	food_item& operator +=(const food_item& a)
	{
		this->carbohydrates += a.carbohydrates;
		this->cholesterol += a.cholesterol;
		this->fat += a.fat;
		this->food_energy += a.food_energy;
		this->protein += a.protein;
		this->saturated_fat += a.saturated_fat;
		return *this;
	}
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
#define FLAT_FLAG 0x01
#define DOWN_FLAG 0x02
#define SET_FLAG  0x04
#define ITEM_COUNT 959
#define FOOD_ENERGY 460
#define MALE true
#define FEMALE false

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

void initialize_DAG(dag* DAG_REF, vector<food_item> * data);
void initialize_DP(DP* dp_table, vector<food_item> * data, health_reg *needs);
void printDP(DP* dp_table, vector<food_item> * data, bool byName);
void extract_solution(bits* solution, DP* dp_table, vector<food_item> * data);
void print_solution(bits* solution, vector<food_item> * data);
void fill_personal_needs(health_reg* needs, double weight_kg, double height_cm, int age, bool sex);
double give_value(health_reg* needs, food_item* accu_items, food_item* new_item);

#endif

