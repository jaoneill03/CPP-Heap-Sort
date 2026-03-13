// simple C++ program to read in an array of longs, sort
// the array using heapsort, and then write the sorted data
// to a file
//Joshua O'Neill

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// read the file into the vector (starting at index 1)
void readFile(vector<long>& arr, char* fileName);

// write the vector to the file (starting at index 1)
void writeFile(const vector<long>& arr, char* fileName);

// sort the vector using heapsort (data starts at index 1)
void heapsort(vector<long>& arr);


void buildMaxHeap(vector<long>& arr);

void heapify(vector<long>& arr, int size, int index);

int main(int argc, char** argv) {

  if (argc < 3) {
    cout << "Usage: " << argv[0] << " infile outfile\n";
    exit(1);
  }
  char* inFileName = argv[1];
  char* outFileName = argv[2];
  vector<long> theArray;
  
  readFile(theArray, inFileName);

  heapsort(theArray);
  
  writeFile(theArray, outFileName);

  return 0;
}

// method to read a file of longs and adds the longs to an array
void readFile(vector<long>& arr, char* fileName)
{
  // your code here
  ifstream inFile(fileName);
  long num;
  arr.push_back(0);
  while(inFile >> num){
    arr.push_back(num);
  }

  inFile.close();
  
 
}

//writes the sorted longs to a file
void writeFile(const vector<long>& arr, char* fileName)
{
  ofstream outFile(fileName);
  for(int i = 1; i < arr.size(); i++){
    outFile << arr[i] << endl;
  }
  outFile.close();
}

//calls helper methods to build a max heap and iterates through each element to swap first element with 
//last unsorted and heapify to restore heap
void heapsort(vector<long>& arr)
{
  // your code here
   int size = arr.size() -1 ;

  buildMaxHeap(arr);

  for(int i = size; i > 1; i--){
    swap(arr[1], arr[i]);
    heapify(arr, i - 1, 1);
  }
}

  
  //builds max heap and calls heapify for each node
void buildMaxHeap(vector<long>& arr){
  int size = arr.size() -1;
  for(int i  = size/2; i  >= 1; i--){
    heapify(arr, size, i);
  }
}

//heapify method that sorts that finds the largest of three nodes and swaps them in the correct order
void heapify(vector<long>& arr, int size, int index){
  int largest = index;
  int left = 2 * index;
  int right = 2 * index + 1;

  if(left <= size && arr[left]  > arr[largest]){
    largest = left;
  }

  if(right <= size && arr[right] > arr[largest]){
    largest = right;
  }

  if(largest != index){
    swap(arr[index], arr[largest]);
    heapify(arr, size, largest);
  }
}
