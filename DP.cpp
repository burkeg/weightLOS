#include "weightLOS.h"

void initialize_DP(DP* dp_table, vector<food_item> * data) {
	int food_count;
	int cal_count;
	for (cal_count = 0; cal_count < FOOD_ENERGY; cal_count++) {
		(*dp_table)[ITEM_COUNT][cal_count] = 1;
	}
}