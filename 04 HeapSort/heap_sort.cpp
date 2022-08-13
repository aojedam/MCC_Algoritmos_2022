#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> readDataFromFile(string filePath)
{
	ifstream inputFile(filePath);
	vector<int> arrayFromFile;

	if (!inputFile.is_open())
		cout << "Error al abrir el archivo";

	if (inputFile) {
		int value;

		while (inputFile >> value) {
			arrayFromFile.push_back(value);
		}
	}

	inputFile.close();
	return arrayFromFile;
}

//void printVector(vector<int>& vectorToPrint)
//{
//	for (auto index = vectorToPrint.begin(); index != vectorToPrint.end(); ++index)
//		cout << *index << " ";
//}

void heapify(vector<int>& vectorToSort, int vectorSize, int index)
{
	int largest = index; // Padre
	int leftChild = 2 * index + 1; // Hijo izquierdo = 2 * i + 1
	int rightChild = 2 * index + 2; // Hijo derecho = 2 * i + 2

	if (leftChild < vectorSize && vectorToSort[leftChild] > vectorToSort[largest])
		largest = leftChild;

	if (rightChild < vectorSize && vectorToSort[rightChild] > vectorToSort[largest])
		largest = rightChild;

	if (largest != index) {
		swap(vectorToSort[index], vectorToSort[largest]);

		heapify(vectorToSort, vectorSize, largest);
	}
}

void heapSort(vector<int>& heapVector)
{
	int vectorSize = heapVector.size();

	for (int index = vectorSize / 2 - 1; index >= 0; index--)
		heapify(heapVector, vectorSize, index);

	for (int index = vectorSize - 1; index >= 0; index--) {
		swap(heapVector[0], heapVector[index]);

		heapify(heapVector, index, 0);
	}
}

int main()
{
	//auto start = high_resolution_clock::now();
	auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	vector<int> vectorToSort;
	vectorToSort = readDataFromFile("C:\\Projects\\Maestria\\AyED\\Data_100000.txt");
	heapSort(vectorToSort);
	//printVector(vectorToSort);

	//auto stop = high_resolution_clock::now();
	auto stop = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	cout << endl<< "Duracion de ordenamiento" << endl;
	auto duration = stop - start;
	cout << duration << endl;

	return 0;
}

