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
	dag DAG(ITEM_COUNT, std::vector<char>(FOOD_ENERGY));
//	initialize_DAG(&DAG, &list);
	DP dp_table(ITEM_COUNT+1, std::vector<int>(FOOD_ENERGY+1));
//	initialize_DP(&dp_table, &list);// , ITEM_COUNT, FOOD_ENERGY);


	vector<food_item> mit_list;


	food_item *tmp = new food_item;

	tmp->name = "fountain pen";
	tmp->food_energy = 3 * 5;
	tmp->protein = 7;
	mit_list.push_back(*tmp); 
	
	tmp->name = "golden statue";
	tmp->food_energy = 4 * 5;
	tmp->protein = 10;
	mit_list.push_back(*tmp);

	tmp->name = "iPhone";
	tmp->food_energy = 4 * 5;
	tmp->protein = 8;
	mit_list.push_back(*tmp);

	tmp->name = "crystal ball";
	tmp->food_energy = 2 * 5;
	tmp->protein = 4;
	mit_list.push_back(*tmp);





	delete tmp;
	int knapsack_cap = 10;
	DP mit_dp_table(mit_list.size() + 1, std::vector<int>(knapsack_cap +1));
	initialize_DP(&mit_dp_table, &mit_list);// , 3, knapsack_cap);
	bits solution(mit_list.size());
	extract_solution(&solution, &mit_dp_table, &mit_list);


	quick_sort(&list, compare_by_Weight, 0, list.size()-1);
	quick_sort(&list, compare_by_Carbohydrates, 0, list.size() - 1);
	quick_sort(&list, compare_by_Amount, 0, list.size() - 1);
	quick_sort(&list, compare_by_Protein, 0, list.size() - 1);
	quick_sort(&list, compare_by_Saturated_Fat, 0, list.size() - 1);

	return 0;
}
