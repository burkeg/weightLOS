#include "weightLOS.h"

void initialize_DAG(dag* DAG_REF, vector<food_item> * data) {
	int food_count;
	int cal_count;
	(*DAG_REF)[0][0] |= SET_FLAG;
	for (food_count = 0; food_count < 959; food_count++) {
		for (cal_count = 0; cal_count < 460; cal_count++) {
			if ((*DAG_REF)[food_count][cal_count] && SET_FLAG) {
				(*DAG_REF)[food_count][cal_count] |= FLAT_FLAG;
				(*DAG_REF)[food_count + 1][cal_count] |= SET_FLAG;
				if (cal_count + (int)(data->at(food_count).food_energy) / 5 < 460) {
					(*DAG_REF)[food_count+1][cal_count + (int)(data->at(food_count).food_energy) / 5] |= SET_FLAG;
					(*DAG_REF)[food_count][cal_count] |= DOWN_FLAG;
				}
			}
		}
	}
}