#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<float> readDataFromFile(string filePath)
{
	ifstream inputFile(filePath);
	vector<float> arrayFromFile;

	if (!inputFile.is_open())
		cout << "Error al abrir el archivo";

	if (inputFile) {
		float value;

		while (inputFile >> value) {
			arrayFromFile.push_back(value);
		}
	}

	inputFile.close();
	return arrayFromFile;
}

void bucketSort(vector<float>& arr)
{
	int n = arr.size();

	vector<float> b[n];
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i]; 
		b[bi].push_back(arr[i]);
	}
	
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main()
{

	auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	vector<float> vectorToSort;
	vectorToSort = readDataFromFile("sample_data/BucketSort_100.txt");

	bucketSort(vectorToSort);

	auto stop = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	cout << endl<< "Duracion de ordenamiento" << endl;
	auto duration = stop - start;
	cout << duration << endl;

	/*for (int i = 0; i < vectorToSort.size(); i++)
		cout << vectorToSort[i] << " ";*/
	return 0;
}
