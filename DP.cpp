#include "weightLOS.h"

void initialize_DP(DP* dp_table, vector<food_item> * data, health_reg *needs) {
	int num_items = dp_table->size()-1;
	int max_weight = dp_table->at(0).size()-1;
	int food_count;
	int cal_count;
	for (food_count = num_items - 1; food_count >= 0; food_count--) {
		for (cal_count = 0; cal_count < max_weight + 1; cal_count++) {
			(*dp_table)[food_count][cal_count].name = "dp_accumulator_item";
			(*dp_table)[food_count][cal_count].carbohydrates = 0;
			(*dp_table)[food_count][cal_count].cholesterol = 0;
			(*dp_table)[food_count][cal_count].fat = 0;
			(*dp_table)[food_count][cal_count].protein = 0;
			(*dp_table)[food_count][cal_count].saturated_fat = 0;
			(*dp_table)[food_count][cal_count].sum_value = 0;
		}
	}
	for (food_count = num_items - 1; food_count >= 0; food_count--) {
		for (cal_count = 0; cal_count < max_weight+1; cal_count++) {
			//(*dp_table)[food_count][cal_count] = food_count*cal_count;
			if (cal_count >= (int)(data->at(food_count).food_energy) / 5) {
				//(*dp_table)[food_count][cal_count] = 
				double right = give_value(needs, &(*dp_table)[food_count + 1][cal_count], NULL);
				double test =max( right,//max(give_value(needs,(*dp_table)[food_count+1][cal_count],NULL),
				give_value(needs, &data->at(food_count), &(*dp_table)[food_count + 1][cal_count - (int)(data->at(food_count).food_energy) / 5]));
				if (test == right) {
					(*dp_table)[food_count][cal_count] = (*dp_table)[food_count + 1][cal_count];
				}
				else {
					food_item temp = data->at(food_count);
					temp+= (*dp_table)[food_count + 1][cal_count - (int)(data->at(food_count).food_energy) / 5];
					(*dp_table)[food_count][cal_count] = temp;
				}
			}
			else {

				(*dp_table)[food_count][cal_count] = (*dp_table)[food_count + 1][cal_count];
			}
			(*dp_table)[food_count][cal_count].sum_value = give_value(needs, &(*dp_table)[food_count][cal_count], NULL);
		}
	}
	//printDP(dp_table,data);
}


void printDP(DP* dp_table, vector<food_item> * data, bool byName) {
	ofstream myfile;
	if (byName) {
		myfile.open("DP_Names.csv");
	}
	else {
		myfile.open("DP_Numbers.csv");
	}
	
	myfile		<< "\n\n\n";


	for (int j = 0; j < (int)dp_table->at(0).size(); j++) {
		for (int i = 0; i < (int)dp_table->size(); i++) {
			char buffer[50];
			if (byName) {
				sprintf(buffer, "%s,", (*dp_table)[i][j].name);
			} else {
				sprintf(buffer,"%.3f,", (*dp_table)[i][j].sum_value);
			}
			myfile << buffer;
		}
		myfile << "\n";
	}
	myfile.close();
}

void extract_solution(bits* solution, DP* dp_table, vector<food_item> * data) {
	int weight_count = dp_table->at(0).size() - 1;
	for (int i = 0; i < (int)dp_table->size()-1; i++) {
		if ((*dp_table)[i][weight_count].sum_value == (*dp_table)[i + 1][weight_count].sum_value) {
			//(*solution)[i] = 0;
		}
		else {
			(*solution)[i] = 1;
			weight_count -= (int)(data->at(i).food_energy) / 5;
		}
		
	}
}

void print_solution(bits* solution, vector<food_item> * data) {
	for (int i = 0, count = 0; i < (int)solution->size(); i++) {
		if (solution->at(i))
			printf("%d.) \"%s\"\n", ++count, data->at(i).name);
	}
}

