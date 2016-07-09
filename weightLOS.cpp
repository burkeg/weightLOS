/* Filename: weightLOS.cpp
 * Author: Gabe and Paula
 * Date: 06/16/16
 * Description: contains the function main() written in c/cpp
 */

#include "weightLOS.h"

/* Function: main()
 * Prototype: main( int argc, char * argv[] );
 * Description: 
 * Error Conditions:
 * Return: EXIT_FAILURE on failure, EXIT_SUCCESS on successs
 */
int main(int argc, char * argv[] ) {
	vector<food_item> list;// = new food_item[959];
	readFile("food_call.csv", &list);
	vector<health_reg> profiles;
	profiles.resize(4);
	char * profile_names[50] = {"Gabriel", "Lucia", "Average American Male", "Average American Female"};
	fill_personal_needs(&profiles[0], 86.1826, 183, 20, 7, 2000, MALE); //Gabriel Profile
	fill_personal_needs(&profiles[1], 61, 158, 61, 7, 2000, FEMALE);   //Lucia Profile
	fill_personal_needs(&profiles[2], 88.677308, 177, 37.8, 7, 2000, MALE); //Average American Male Profile
	fill_personal_needs(&profiles[3], 75.387052, 163, 37.8, 7, 2000, FEMALE); //Average American Female Profile

	for (int i = 0; i < profiles.size(); i++) {
		health_reg health_needs = profiles[i];



		DP dp_table(ITEM_COUNT + 1, std::vector<food_item>(FOOD_ENERGY + 1));
		initialize_DP(&dp_table, &list, &health_needs);// , ITEM_COUNT, FOOD_ENERGY);
		bits solution(list.size());
		//*
		extract_solution(&solution, &dp_table, &list);
		printf("%s's Profile:\n", profile_names[i]);
		print_solution(&solution, &list);
		//	printDP(&dp_table, &list, true);
		//	printDP(&dp_table, &list, false);
		print_results(&health_needs, &solution, &list);
		printf("----------------------------------------------------------------------------------\n");
	}
	//give_value(&health_needs, &list.at(0), &list.at(1));
	//*/
	/*
	vector<food_item> mit_list;


	food_item *tmp = new food_item;

	tmp->name = "fountain pen";
	tmp->food_energy = 3 * 5;
	tmp->protein = 70;
	tmp->carbohydrates = 80;
	tmp->fat = 30;
	mit_list.push_back(*tmp);
	
	tmp->name = "golden statue";
	tmp->food_energy = 4 * 5;
	tmp->protein = 15;
	tmp->carbohydrates = 140;
	tmp->fat = 40;	
	mit_list.push_back(*tmp);

	tmp->name = "crystal ball";
	tmp->food_energy = 2 * 5;
	tmp->protein = 41;
	tmp->carbohydrates = 73;
	tmp->fat = 20;
	mit_list.push_back(*tmp);

	tmp->name = "iPhone";
	tmp->food_energy = 4 * 5;
	tmp->protein = 27;
	tmp->carbohydrates = 65;
	tmp->fat = 60;	
	mit_list.push_back(*tmp);

	




	delete tmp;
	int knapsack_cap = 10;
	DP mit_dp_table(mit_list.size() + 1, std::vector<food_item>(knapsack_cap +1));
	initialize_DP(&mit_dp_table, &mit_list,&health_needs);// , 3, knapsack_cap);
   bits mit_solution(mit_list.size());
	extract_solution(&mit_solution, &mit_dp_table, &mit_list);
	printDP(&mit_dp_table, &mit_list, true);
	printDP(&mit_dp_table, &mit_list, false);
	print_solution(&mit_solution, &mit_list);
	*/

	quick_sort(&list, compare_by_Weight, 0, list.size()-1);
	quick_sort(&list, compare_by_Carbohydrates, 0, list.size() - 1);
	quick_sort(&list, compare_by_Amount, 0, list.size() - 1);
	quick_sort(&list, compare_by_Protein, 0, list.size() - 1);
	quick_sort(&list, compare_by_Saturated_Fat, 0, list.size() - 1);

	return 0;
}
