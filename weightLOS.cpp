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
	quick_sort(&list, compare_by_Weight, 0, list.size()-1);
	quick_sort(&list, compare_by_Carbohydrates, 0, list.size() - 1);
	quick_sort(&list, compare_by_Amount, 0, list.size() - 1);
	quick_sort(&list, compare_by_Protein, 0, list.size() - 1);
	quick_sort(&list, compare_by_Saturated_Fat, 0, list.size() - 1);

	return 0;
}
