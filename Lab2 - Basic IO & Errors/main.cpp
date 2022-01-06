#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;

int main()
{
	string title_name;
	string col_1;
	string col_2;
	string data_input;
	vector<string> authors(0);
	vector<int> num_of_books(0);

	/* Overall flow of the program:
	Get some input for the title
	Get some input for column header #1
	Get some input for column header #2
	Print out data in table format
	Print out data in chart format
	*/

	// Title input:
	cout << "Enter a title for the data:" << endl;
	getline(cin, title_name);
	cout << "You entered: " << title_name << endl << endl;

	// Column header input:
	cout << "Enter the column 1 header:" << endl;
	getline(cin, col_1);
	cout << "You entered: " << col_1 << endl << endl;

	cout << "Enter the column 2 header:" << endl;
	getline(cin, col_2);
	cout << "You entered: " << col_2 << endl << endl;

	// Get data input:
	while (1) 
	{
		try 
		{
			cout << "Enter a data point (-1 to stop input):" << endl;
			getline(cin, data_input);
			
			//exit condition
			if (data_input == "-1")  
			{
				break;
			}

			//find or search for the first comma
			size_t comma_location = data_input.find(","); 

			//first comma doesn't exist in data_input, throw error
			if (comma_location == string::npos) 
			{
				throw runtime_error("Error: No comma in string.");
			}

			//first comma does exist, move foreward
			else if (comma_location != string::npos) 
			{
				string author_name = data_input.substr(0, comma_location); 		//get authors name based on comma location
				string remaining_data = data_input.substr(comma_location + 1); 	//the remaing string after the first comma
				
				try 
				{
					//if there is a comma in the remaining string, then theres more than 1 total comma, throw error
					if (remaining_data.find(",") != string::npos) 
					{
						throw runtime_error("Error: Too many commas in input.");
					}
					//only 1 total comma, so move foreward
					else  
					{
						int data_int = stoi(remaining_data); //will throw invalid_argument error if improper type
						authors.push_back(author_name);
						num_of_books.push_back(data_int);
						cout << "Data string: " << author_name << endl << "Data integer: " << data_int << endl;
					}
				}
				catch (invalid_argument&)
				{
					cout << "Error: Comma not followed by an integer." << endl;
				}
			}
		}

		catch (runtime_error& excpt) 
		{
			cout << excpt.what() << endl;
		}
		cout << endl;
	}

	//print table heading
	cout << endl << setw(33) << right << title_name << endl << setw(20) << left << col_1 << "|" << setw(23) << right << col_2 << endl;
	cout << string(44, '-') << endl;


	//use a loop to display data
	for (size_t i = 0; i < authors.size(); i++) 
	{
		cout << setw(20) << left << authors[i] << "|" << setw(23) << right << num_of_books[i] << endl;
	}
	cout << endl;

	//print histogram
	for (unsigned i = 0; i < authors.size(); i++)
	{
		cout << setw(20) << right << authors[i] << " " << string(num_of_books[i], '*') << endl;
	}
	return 0;
}