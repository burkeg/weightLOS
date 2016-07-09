#include "weightLOS.h"


void fill_personal_needs(health_reg* needs, double weight_kg, double height_cm, int age, int approx_num_items, double weight_per_day, bool sex) {
	needs->sex = sex;
	if (sex == MALE) {
		needs->food_energy = ((13.75*weight_kg) + 5 * height_cm - 6.76*age + 66)*1.1;
	}
	else {
		needs->food_energy = ((9.56*weight_kg) + 1.85 * height_cm - 4.68*age + 665)*1.1;
	}
	needs->carbs = (0.55*needs->food_energy) / 4;//---------NO CHANGE
	needs->fat = (0.3*needs->food_energy) / 9;//------------NO CHANGE
	needs->protein = 0.8*weight_kg;//-----------------------NO CHANGE    
	needs->saturated_fat = (0.055*needs->food_energy) / 9;//NO CHANGE
	needs->cholesterol = 300;//-----------------------------OK TO CHANGE    
	needs->num_foods = approx_num_items; //-------------------------------OK TO CHANGE 
	needs->weight = weight_per_day; //-------------------------------OK TO CHANGE 
}



double give_value(health_reg *needs, food_item* accu_items, food_item* new_item) {
	double sum = 0;
	food_item *temp = new food_item;
	/*
	temp->name = "temp_item";
	temp->carbohydrates = 0;
	temp->cholesterol = 0;
	temp->food_energy = 0;
	temp->fat = 0;
	temp->protein = 0;
	temp->saturated_fat = 0;
	temp->sum_value = 0;
	temp->weight = 0;
	*/
	*temp = *accu_items;
	if (new_item != NULL) 
		*temp += *new_item;
	sum += 1 * calc_weighting_quad(needs->carbs, temp->carbohydrates);
	sum += 1 * calc_weighting_quad(needs->fat, temp->fat);
	sum += 1 * calc_weighting_quad(needs->protein, temp->protein);
	sum += 1 * calc_weighting_quad(needs->food_energy, temp->food_energy);
	sum += 1 * calc_weighting_linear(needs->saturated_fat, temp->saturated_fat);
	sum += 1 * calc_weighting_linear(needs->cholesterol, temp->cholesterol);
	sum += 1 * calc_weighting_quad(needs->weight, temp->weight);
	sum += 1 * calc_weighting_quad(needs->num_foods, temp->count_yes);

	return sum;
}

double calc_weighting_quad(double thres, double val) {
	return 1 - pow(((val - thres) / thres), 2.0);
}

double calc_weighting_linear(double thres, double val) {
	return 1 - val/(2*thres);
}

void print_results(health_reg* needs, bits* solution, vector<food_item> * data) {
	int count = 0;
	food_item *accumulator = new food_item;
	accumulator->carbohydrates = 0;
	accumulator->cholesterol = 0;
	accumulator->fat = 0;
	accumulator->food_energy = 0;
	accumulator->protein = 0;
	accumulator->saturated_fat = 0;
	accumulator->weight = 0;
	for (int i = 0; i < solution->size(); i++) {
		if (solution->at(i)) {
			count++;
			*accumulator += (*data)[i];
		}
	}
	printf("Results:\n");
	printf("Expected Carbohydrates: %8.3f  |  Actual: %5.3f\n", needs->carbs, accumulator->carbohydrates);
	printf("Expected Cholesterol:   %8.3f  |  Actual: %5.3f  (attemping to minimize)\n", needs->cholesterol, accumulator->cholesterol);
	printf("Expected Fat:           %8.3f  |  Actual: %5.3f\n", needs->fat, accumulator->fat);
	printf("Expected Calories:      %8.3f  |  Actual: %5.3f\n", needs->food_energy, accumulator->food_energy);
	printf("Expected Protein:       %8.3f  |  Actual: %5.3f\n", needs->protein, accumulator->protein);
	printf("Expected Saturated Fat: %8.3f  |  Actual: %5.3f  (attemping to minimize)\n", needs->saturated_fat, accumulator->saturated_fat);
	printf("Total Items: %d | Weight (g) %5.3f\n\n\n", count, accumulator->weight);
}