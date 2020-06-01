#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std; 

class SalesData
{
private:
	ifstream inputfile;
	ofstream outputfile;
	vector<int> salesrecords;
public:
	void loadDataFromFile(string filename);
	void saveBarChartToFile(string filename);
};

void SalesData::loadDataFromFile(string filename)
{
	int salesdata = 0;

	salesrecords.clear(); //clean out any old data

	inputfile.open(filename); // open input file

	if (!inputfile) //does file exist?
	{
		cout << "Error! File " << filename << " does not exist!" << endl;
		return;
	}

	while (inputfile >> salesdata) //whilst data remains
	{
		cout << salesdata << endl;
		salesrecords.push_back(salesdata); //save data to vector
	}

	inputfile.close();

}

void SalesData::saveBarChartToFile(string filename)
{
	if(salesrecords.size()==0) 
	{
		cout << "Error! No sales data available!" << endl;
		return;
	}

	outputfile.open(filename);

	if(!outputfile)  //if file can't be found ....
	{
		cout << "Error! File" << filename << "cannot be opened!" << endl; //...error message appears
		return;
	}

	for (int count = 0; count < salesrecords.size(); count++) //while there is still data in salesrecords
	{
		int noofstars = salesrecords[count] / 100; // divides the number in salesrecords and divides it by 100
		for (int starcount = 0; starcount < noofstars; starcount++) outputfile << "*"; // and prints out the amount of stars
		outputfile << endl;
	}

	outputfile.close();

}
int main(void)
{
	SalesData Call;  //calls the vector
	Call.loadDataFromFile("sales.txt"); //loads data from the sales.txt. file
	Call.saveBarChartToFile("graphs.txt"); //saves the data into the graphs.txt file
	return 0;
}