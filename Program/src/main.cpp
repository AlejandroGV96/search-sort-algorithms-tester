#include<iostream>
#include "chrono.cpp"

enum MatrixInfo
{
	bubble = 0,
	selection,
	insertion,
	quick,
	mergeTopDown,
	mergeBottomUp,
	linearSearch,
	BinarySearch,

	ordered = 0,
	reversed,
	random,

	n1 = 0,
	n2,
	n3,
	n4,
	n5,
	n6,
};

typedef std::unique_ptr<int[]> sixSizesArrays; // n1 - n6 data sizes
typedef std::unique_ptr<sixSizesArrays[]> typeOfData; // ordered, reverse and 'random'
typedef std::unique_ptr<typeOfData[]> algorithms; // algorithms that will sort stored data
typedef std::unique_ptr<algorithms[]> fullDataStructure; // Data Matrix containing all data

/// <summary>
///		Function that will fill the data arrays with values depending on its type ( ordered, reversed or 'random')
/// </summary>
/// <param name="Matrix"> Data Structure</param>
/// <param name="alg"> Branch of the data structure (insertion, bubble, merge...) </param>
/// <param name="type"> Branch of type of data</param>
/// <param name="nArr"> Brach of data size</param>
/// <param name="size"> Size available for storage</param>
void matrixValFiller(fullDataStructure& Matrix, int& alg, int& type, int &nArr, unsigned int& size) {
	for (int k = 0; k < size; k++) {
		switch (type) {
		case ordered:
			Matrix[alg][type][nArr][k] = k + 1;
			break;
		case reversed:
			Matrix[alg][type][nArr][k] = size - k;
			break;
		case random:
			Matrix[alg][type][nArr][k] = rand() % size;
			break;
		}
	}
}

int main() {


	// possibility to define custom data sizes
	unsigned int size[6]{100, 1000, 10000, 100000, 1000000, 10000000};
	//for (auto i = 0; i < 6; i++) {
	//	std::cin >> size[i];
	//}
	{
		std::cin.get();

		fullDataStructure DataMatrix = std::make_unique<algorithms[]>(8);

		for (auto i = 0; i < 8; ++i) {
			std::cout << "Initializing " << i + 1 << "# set of arrays" << std::endl;
			Timer timer; // setting benchmarking timer
			DataMatrix[i] = std::make_unique<typeOfData[]>(3);

			std::srand(1); // reseting randomizer

			for (auto j = 0; j < 3; ++j) {
				DataMatrix[i][j] = std::make_unique<sixSizesArrays[]>(6);

				for (auto n = 0; n < 6; ++n) {
					DataMatrix[i][j][n] = std::make_unique<int[]>(size[n]);
						matrixValFiller(DataMatrix, i, j, n, size[n]);
				}
			}
		}

		std::cout << DataMatrix[insertion][ordered][n6][9000000] << std::endl;



		std::cin.get();

	}
	std::cin.get();


}


/*
	REFERENCES:

		-Inspiration for using typedef, to create a smart pointers data structure
		 that allows automatic deallocation of memory used
		https://stackoverflow.com/questions/15488470/syntax-for-dynamically-allocating-a-2d-array-of-smart-pointers

		-Benchmarking with chrono
		https://www.youtube.com/watch?v=YG4jexlSAjc

*/