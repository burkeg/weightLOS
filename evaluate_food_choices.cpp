#include "weightLOS.h"

double calc_weighting(double thres, double val);

void fill_personal_needs(health_reg* needs, double weight_kg, double height_cm, int age, bool sex) {
	needs->sex = sex;
	if (sex == MALE) {
		needs->food_energy = ((13.75*weight_kg) + 5 * height_cm - 6.76*age + 66)*1.1;
	}
	else {
		needs->food_energy = ((9.56*weight_kg) + 1.85 * height_cm - 4.68*age + 665)*1.1;
	}
	needs->carbs = (0.55*needs->food_energy) / 4;
	needs->cholesterol = 300;
	needs->fat = (0.3*needs->food_energy) / 9;
	needs->protein = 0.8*weight_kg;
	needs->saturated_fat = (0.055*needs->food_energy) / 9;
}



double give_value(health_reg *needs, food_item* accu_items, food_item* new_item) {
	double sum = 0;
	food_item *temp = new food_item;
	temp->name = "temp_item";
	temp->carbohydrates = 0;
	temp->cholesterol = 0;
	temp->fat = 0;
	temp->protein = 0;
	temp->saturated_fat = 0;
	temp->sum_value = 0;

	*temp += *accu_items;
	if (new_item != NULL) 
		*temp += *new_item;
	sum += 0.5*calc_weighting(needs->carbs, temp->carbohydrates);
	sum += 2*calc_weighting(needs->fat, temp->fat);
	sum += 3*calc_weighting(needs->protein, temp->protein);
	
	//sum += calc_weighting(needs->cholesterol, accu_items->cholesterol);
	//sum += calc_weighting(needs->saturated_fat, accu_items->saturated_fat);

	return sum;
}

double calc_weighting(double thres, double val) {
	return 1 - pow(((val - thres) / thres), 2.0);
}
