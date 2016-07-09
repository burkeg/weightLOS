#include "weightLOS.h"



int readFile(const char * filename, vector<food_item> * file_contents) {
	string line;
	ifstream myfile(filename);
	//allocate_table(file_contents);
	int row = 0;
	int column = 0;

	if (myfile.is_open())
	{
		getline(myfile, line); //skip first 2 lines
		getline(myfile, line);
		while (getline(myfile, line)) //while not at end of the file
		{
			char * cstr = new char[line.length() + 1];
			std::strcpy(cstr, line.c_str());

			food_item *tmp = new food_item;

			char * pch;

			pch = strtok(cstr, ",");
			tmp->name = pch;
			
			pch = strtok(NULL, ",");
			tmp->amount = strtod(pch, NULL);

			pch = strtok(NULL, ",");
			tmp->units = pch;

			pch = strtok(NULL, ",");
			tmp->fat= strtod(pch,NULL);

			pch = strtok(NULL, ",");
			tmp->food_energy = strtod(pch,NULL);

			pch = strtok(NULL, ",");
			tmp->carbohydrates= strtod(pch,NULL);

			pch = strtok(NULL, ",");
			tmp->protein = strtod(pch,NULL);

			pch = strtok(NULL, ",");
			tmp->cholesterol = strtod(pch,NULL);

			pch = strtok(NULL, ",");
			tmp->weight = strtod(pch,NULL);

			pch = strtok(NULL, ",");
			tmp->saturated_fat = strtod(pch,NULL);
			
			tmp->sum_value = 0;
			tmp->count_yes = 0;
			file_contents->push_back(*tmp);
			delete tmp;
			//cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	return 0;
}