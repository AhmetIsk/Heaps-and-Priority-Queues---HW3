#include "maxHeap1.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
maxHeap1::maxHeap1() : size(0) {

    int a = 0;
    int x;
    size = 0;


    ifstream inFile;

    inFile.open("test_data.txt");
    if (!inFile) {
        cout << "Unable to open file";// terminate with error
    }
    int k = 0;
    if (inFile >> x)
        numOfPatients = x;

    int temp[numOfPatients*4];

    while (inFile >> x) {
        temp[k] = x;
        k++;
    }

    inFile.close();

    patientList = new Patient[numOfPatients];

    for(int i = 0; i < numOfPatients; i++) {

        patientList[i].setId(temp[a]);
        patientList[i].setPriority(temp[a+1]);
        patientList[i].setArrivalTime(temp[a+2]);
        patientList[i].setCureTime(temp[a+3]);

        a = a + 4;
    }


    quickSort(patientList, numOfPatients);

}

maxHeap1::~maxHeap1() {
    delete []doctorList;
    delete []patientList;

}

int maxHeap1::getNumOfPatients() {
    return numOfPatients;
}

bool maxHeap1::heapIsEmpty() const {
	return (size == 0);
}

void maxHeap1::heapInsert( Patient &newItem) {

	if (size >= MAX_HEAP) {
		cout << "HeapException: Heap full"<< endl;
		return;
	}
	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority()) ) {

		    Patient temp;
            temp = items[parent];


            items[parent] = items[place];

            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
	}
 	++size;
}

void maxHeap1::heapDelete(Patient& rootItem) {
	if (heapIsEmpty()){
		cout << "HeapException: Heap is empty"<< endl;
		return;
	}
		rootItem = items[0];


		items[0] = items[--size];

		heapRebuild(0);
		//cout << rootItem.getId()

}

//BURAYI DÜZENLEMEN GEREKİYOR AYNI INSERTTE OLDUĞU GİBİ
void maxHeap1::heapRebuild(int root) {
	int child = (2 * root) + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild].getPriority() >= items[child].getPriority() )) {
		         if (items[rightChild].getPriority() == items[child].getPriority() ) {
                    if ((items[rightChild].getWaitedTime() > items[child].getWaitedTime() ))
                        child = rightChild;
		         }else {
                    child = rightChild;
		         }
		     }
				// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root].getPriority() <= items[child].getPriority() ) {
                if(items[root].getPriority() == items[child].getPriority()) {
                    if (items[root].getWaitedTime() < items[child].getWaitedTime()) {
                        Patient temp;
                        temp = items[root];

                        items[root] = items[child];

                        items[child] = temp;

                        // transform the new subtree into a heap
                        heapRebuild(child);
                    }
                }
                else {
                    Patient temp;
                temp = items[root];

                items[root] = items[child];

                items[child] = temp;

                // transform the new subtree into a heap
                heapRebuild(child);
                }
		}
	}
}

int maxHeap1::getSize() {
    return size;
}

void maxHeap1::swap(Patient &x, Patient &y) {
   Patient temp;
   temp = x;
   x = y;
   y = temp;
}

void maxHeap1::partition(Patient theArray[], int first, int last,
			int &pivotIndex) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

	// place pivot in theArray[first]
   //choosePivot(theArray, first, last);

   int pivot = theArray[first].getArrivalTime(); // copy pivot

   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown].getArrivalTime() < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);

      }	// else belongs to S2

   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;

}

void maxHeap1::helperQuicksort(Patient theArray[], int first, int last, int size) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

   if (first<last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      helperQuicksort(theArray, first, pivotIndex-1, size);
      helperQuicksort(theArray, pivotIndex+1, last, size);
   }
}

void maxHeap1::quickSort(Patient *arr, int size) {
    int low = 0;
    int high = size - 1;
    helperQuicksort(arr, low, high, size);
}


Doctor::Doctor(int newId )
{
    id = newId;
    treating = false;
    stopTime = 0;
}

Doctor::~Doctor()
{
    //dtor
}

int Doctor::getId() {
    return id;
}

void Doctor::setId( int no ) {
    id = no;
}

int Doctor::getStopTime() {
    return stopTime;
}

bool Doctor::getTreating() {
    return treating;
}

void Doctor::setStopTime( int k ) {
    stopTime = k;
}

void Doctor::setTreating( bool yesNo ) {
    treating = yesNo;
}


Patient::Patient( Patient &pToCopy) {
    //Patient newPatient;
    this->id = pToCopy.getId();
    this->waitedTime = pToCopy.getWaitedTime();
    this->priority = pToCopy.getPriority();
    this->cureTime = pToCopy.getCureTime();
    this->arrivalTime = pToCopy.getArrivalTime();
}
Patient::Patient() {

}
Patient::~Patient() {

}
void Patient::operator=( Patient &right) {
    if (&right != this)
    {
        //Patient newPatient;
        this->id = right.getId();
        this->arrivalTime = right.getArrivalTime();
        this->cureTime = right.getCureTime();
        this->waitedTime = right.getWaitedTime();
        this->priority = right.getPriority();
    }
}


int Patient::getId() {
    return id;
}
int Patient::getPriority() {
    return priority;
}
int Patient::getArrivalTime() {
    return this->arrivalTime;
}
int Patient::getCureTime() {
    return cureTime;
}
int Patient::getWaitedTime() {
    return waitedTime;
}
void Patient::setId( int n ) {
    this->id = n;
}
void Patient::setPriority( int n ) {
    this->priority = n;
}
void Patient::setArrivalTime( int n ) {
    this->arrivalTime = n;
}
void Patient::setCureTime( int n ) {
    this->cureTime = n;
}
void Patient::setWaitedTime( int n ) {
    this->waitedTime = n;
}



