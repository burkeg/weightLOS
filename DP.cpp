#include "weightLOS.h"

void initialize_DP(DP* dp_table, vector<food_item> * data) {
	int num_items = dp_table->size()-1;
	int max_weight = dp_table->at(0).size()-1;
	int food_count;
	int cal_count;
	for (food_count = num_items - 1; food_count >= 0; food_count--) {
		for (cal_count = 0; cal_count < max_weight+1; cal_count++) {
			//(*dp_table)[food_count][cal_count] = food_count*cal_count;
			if (cal_count >= (int)(data->at(food_count).food_energy) / 5) {
				(*dp_table)[food_count][cal_count] = max((*dp_table)[food_count+1][cal_count],
					(int)(data->at(food_count).fat + (*dp_table)[food_count + 1][cal_count - (int)(data->at(food_count).food_energy) / 5]));
			}
			else {

				(*dp_table)[food_count][cal_count] = (*dp_table)[food_count + 1][cal_count];
			}
		}
	}
	//printDP(dp_table,data);
}

void printDP(DP* dp_table, vector<food_item> * data) {
	printf("\n\n\n");
	for (int items = 0; items < dp_table->size()-1; items++) {
		printf("%3.1d/%3.1d ", (int)(data->at(items).food_energy) / 5, (int)(data->at(items).protein));
	}
	printf("\n");
	for (int j = 0; j < dp_table->at(0).size(); j++) {
		for (int i = 0; i < dp_table->size(); i++) {
			printf("%7.1d ", (*dp_table)[i][j]);
		}
		printf("\n");
	}
}

void extract_solution(bits* solution, DP* dp_table, vector<food_item> * data) {
	int weight_count = dp_table->at(0).size() - 1;
	for (int i = 0; i < dp_table->size()-1; i++) {
		if ((*dp_table)[i][weight_count] == (*dp_table)[i + 1][weight_count]) {
			//(*solution)[i] = 0;
		}
		else {
			(*solution)[i] = 1;
			weight_count -= (int)(data->at(i).food_energy) / 5;
		}
		
	}
}

void print_solution(bits* solution, vector<food_item> * data) {
	for (int i = 0, count = 0; i < solution->size(); i++) {
		if (solution->at(i))
			printf("%d.) \"%s\"\n", ++count, data->at(i).name);
	}
}

