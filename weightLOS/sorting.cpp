#include "weightLOS.h"


double compare_by_Name(vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? *(int*)a : string(data->at(*(int*)a).name) >= string(data->at(*(int*)b).name);			//DO NOT USE YET, COMPARES APLHABETICALLY
}

double compare_by_Amount (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).amount : data->at(*(int*)a).amount >= data->at(*(int*)b).amount;
}

double compare_by_Units(vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? *(int*)a : string(data->at(*(int*)a).units) >= string(data->at(*(int*)b).units);  //DO NOT USE YET, COMPARES APLHABETICALLY
}

double compare_by_Food_Energy (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).food_energy : data->at(*(int*)a).food_energy >= data->at(*(int*)b).food_energy;
}

double compare_by_Carbohydrates (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).carbohydrates : data->at(*(int*)a).carbohydrates >= data->at(*(int*)b).carbohydrates;
}

double compare_by_Protein (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).protein : data->at(*(int*)a).protein >= data->at(*(int*)b).protein;
}

double compare_by_Cholesterol (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).cholesterol : data->at(*(int*)a).cholesterol >= data->at(*(int*)b).cholesterol;
}

double compare_by_Weight (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).weight : data->at(*(int*)a).weight >= data->at(*(int*)b).weight;
}

double compare_by_Saturated_Fat (vector<food_item> * data, const void * a, const void * b, bool getA)
{
	return getA ? data->at(*(int*)a).saturated_fat : data->at(*(int*)a).saturated_fat >= data->at(*(int*)b).saturated_fat;
}

void quick_sort(vector<food_item> * data, double compare(vector<food_item> * data,const void *, const void *, bool getA), int left, int right) {
	
	int i = left, j = right;
	food_item tmp;
	int pivot = (left + right) / 2;
	double pivot_val = compare(data, &pivot, NULL, true);

	while (i <= j) {
		while (compare(data, &i, NULL, true) < pivot_val)
			i++;
		while (compare(data, &j, NULL, true) > pivot_val)
			j--;
		if (i <= j) {
			tmp = data->at(i);
			data->at(i) = data->at(j);
			data->at(j) = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		quick_sort(data, compare, left, j);
	if (i < right)
		quick_sort(data, compare, i, right);
}
