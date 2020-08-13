#ifndef MAXHEAP1_H
#define MAXHEAP1_H
//#include "maxHeap1.h"

const int MAX_HEAP = 2000;
using namespace std;


//#include "KeyedItem.h"// definition of KeyedItem
//typedef KeyedItem HeapItemType;
class Patient {

    public:
        Patient();
        Patient( Patient &fToCopy);
        ~Patient();
        void operator=( Patient &right);


        int getId();
        int getPriority();
        int getArrivalTime();
        int getCureTime();
        int getWaitedTime();
        void setId( int n = -1 );
        void setPriority( int n = -1);
        void setArrivalTime( int n = -1);
        void setCureTime( int n = -1);
        void setWaitedTime( int n = -1);

    private:
        int id;
        int priority;
        int arrivalTime;
        int cureTime;
        int waitedTime;
};

class Doctor
{
    public:
        Doctor(int id = 1);
        virtual ~Doctor();
        int getId();
        void setId( int no );
        int getStopTime();
        bool getTreating();
        void setStopTime( int k );
        void setTreating( bool yesNo );

    protected:

    private:
        int id;
        int stopTime;
        bool treating;
};

class maxHeap1 {
public:


    Patient items[MAX_HEAP];
    Patient* patientList;
    Doctor* doctorList;
	maxHeap1();
	~maxHeap1();				// default constructor
	// copy constructor and destructor are supplied by the compiler

    int getNumOfPatients();
	bool heapIsEmpty() const;
	void heapInsert( Patient &newItem);
	void heapDelete(Patient& rootItem);

	//swap method override
    void swap(Patient &x, Patient &y);
        // partition method override
    void partition(Patient theArray[], int first, int last, int &pivotIndex);
    // helper method for quick sort algorithm takes first as 0
    // and takes last as size - 1
    void helperQuicksort(Patient theArray[], int first, int last, int size);
    void quickSort(Patient *arr, int size);
    int getSize();


protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:




		// array of heap items
	int          size;
    int numOfPatients;



	      	// number of heap items;;
};


#endif // MAXHEAP1_H
