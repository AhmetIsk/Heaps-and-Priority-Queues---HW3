#include <iostream>
#include <string>
#include "maxHeap1.h"
#include <fstream>
#include <sstream>
using namespace std;

class simulator
{
    public:
        simulator() {}

        double findAverageDoctor( int maximumTime) {
            maxHeap1 heap1;

            Doctor* doctorArr;

            int doctorNum = 0;
            int orderPat = 0;
            int order = 0;
            int noOfCured = 0;
            int sumOfWaiting = 0;
            double averageTime = 1000000000;



            do  {
                doctorNum++;
                doctorArr = new Doctor[doctorNum];
                for(int j = 0; j < doctorNum; j++) {
                    doctorArr[j].setId(j);
                }
                noOfCured = 0;
                order = 0;
                averageTime = 0;
                sumOfWaiting = 0;
                for ( int t = -1; t < 2000; t++ ) {
                    for ( int i = orderPat; i < 2000; i++) {
                        if  ( heap1.patientList[i].getArrivalTime() == t ) {

                            heap1.heapInsert(heap1.patientList[i]);
                            order++;

                        }
                        else    {
                            break;
                        }
                    }

                    for (int k = 0; k < doctorNum; k++) {
                        if (doctorArr[k].getStopTime() == t) {
                            doctorArr[k].setTreating(false);
                        }
                    }
                    if (!(heap1.heapIsEmpty())) {

                        for (int c = 0; c < heap1.getSize(); c++) {
                            heap1.items[c].setWaitedTime(t -  heap1.items[c].getArrivalTime());
                        }

                    }
                    for (int k = 0; k < doctorNum; k++) {
                        if (doctorArr[k].getTreating() == false) {
                            if (!(heap1.heapIsEmpty())) {
                                doctorArr[k].setStopTime( t + heap1.items[0].getCureTime());
                                doctorArr[k].setTreating(true);
                                sumOfWaiting += heap1.items[0].getWaitedTime();
                                heap1.heapDelete(heap1.items[0]);
                                noOfCured++;

                            }
                        }
                    }


                    if (noOfCured == heap1.getNumOfPatients() ) {
                        break;
                    }

                orderPat = order;
                }
                delete[] doctorArr;


                averageTime = (double)sumOfWaiting / heap1.getNumOfPatients();


            } while ( maximumTime < averageTime );

            cout << "Minimum number of doctors required: " << doctorNum << '\n' << endl;

            cout << "Simulation with " << doctorNum << " doctors:" << '\n' << endl;

            doctorArr = new Doctor[doctorNum];
                for(int j = 0; j < doctorNum; j++) {
                    doctorArr[j].setId(j);

                }

                noOfCured = 0;
                order = 0;
                averageTime = 0;
                sumOfWaiting = 0;
                for ( int t = -1; t < 2000; t++ ) {

                    for ( int i = orderPat; i < 2000; i++) {

                        if  ( heap1.patientList[i].getArrivalTime() == t ) {

                            heap1.heapInsert(heap1.patientList[i]);

                            order++;

                        }
                        else    {
                            break;
                        }
                    }

                    for (int k = 0; k < doctorNum; k++) {
                        if (doctorArr[k].getStopTime() == t) {
                            doctorArr[k].setTreating(false);
                        }
                    }
                    if (!(heap1.heapIsEmpty())) {

                        for (int c = 0; c < heap1.getSize(); c++) {
                            heap1.items[c].setWaitedTime(t -  heap1.items[c].getArrivalTime());
                        }

                    }
                    for (int k = 0; k < doctorNum; k++) {
                        if (doctorArr[k].getTreating() == false) {
                            if (!(heap1.heapIsEmpty())) {
                                doctorArr[k].setStopTime( t + heap1.items[0].getCureTime());
                                doctorArr[k].setTreating(true);
                                sumOfWaiting += heap1.items[0].getWaitedTime();
                                cout << "Doctor " << doctorArr[k].getId() << " takes patient "
                                    << heap1.items[0].getId() << " at minute " << t << " (wait: "
                                    << heap1.items[0].getWaitedTime() << " mins)" << endl;

                                heap1.heapDelete(heap1.items[0]);
                                noOfCured++;

                            }
                        }
                    }


                    if (noOfCured == heap1.getNumOfPatients()) {
                        break;
                    }

                orderPat = order;
                }
                delete[] doctorArr;

                averageTime = (double)sumOfWaiting / heap1.getNumOfPatients();
            cout << "Average waiting time = " << averageTime <<" minutes" << endl;
            return averageTime;
        }



    protected:

    private:


};

int main() {
    int k = 10;

    simulator sim;
    sim.findAverageDoctor(k);
}
