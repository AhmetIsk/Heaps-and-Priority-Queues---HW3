# Heaps-and-Priority-Queues---HW3
# Question:
In this programming assignment, you will find a software solution to the problem of the director of
Covid-19 Clinic. She is trying to figure out how many doctors should work in this clinic. For each doctor
in this clinic, the expense increases; however, according to the standards, the average waiting time for
all patients should not exceed a given amount of time. So, she needs to optimize this number and asks
for your help in this task. The clinic has the data of past patients. Your program should use these data
to calculate average waiting times and find out the minimum number of doctors needed to meet the
average waiting time requirement.

The data are stored in a plain test_data.txt. The first line of the file contains the number of patients. The
subsequent lines contain four integers, each separated by one or more whitespace characters (space
or tab). These denote, respectively, the patient id, the patient priority (from 1 to 10, higher is more
urgent), arrival time (in minutes from a given point—e.g., 12:00 am) and service time (in minutes).
For example, from the file content given below, we understand that there are 3 patients. The first
patient with id 1 has priority of 9, arrives at the clinic at minute 1, and his examination lasts for 5
minutes. The second patient with id 14 has priority of 3, arrives at the clinic at minute 70, and his
examination lasts for 10 minutes. The third patient with id 5 has priority of 3, arrives at the clinic at
minute 82, and his examination lasts for 70 minutes.

Sample input file:
********************

3

1 9 1 5

14 3 70 10

5 3 82 70

********************

In this assignment, you are asked to write a simulation program that reads patient data from an input
file and calculates the minimum number of doctors required for a given maximum average waiting
time.

In your implementation, you may make the following assumptions:

- The data file will always be valid. All data are composed of integers.

- In the data file, the patients are sorted according to their arrival times.

- There may be at most 2000 patients in the data file.


Your implementation must obey the following requirements:

- The patient with the highest priority should be examined first.

- In case of having two patients with the same highest priority, the patient who has waited
longer should be selected first.

- If more than one doctor is available at a given time, the patient is assigned to the doctor with
a lower id.

- Once a patient is assigned to a doctor, the doctor immediately starts examining that patient
and is not available during the examination period given for that patient. After the examination
of that patient ends, the doctor becomes available immediately.

- The waiting time of a patient is the duration (difference) between the arrival time of the
patient and the time he is assigned to a doctor.


Put the class definition and implementation of the heap data structure in maxHeap1.h and
maxHeap1.cpp, respectively. Put the function that drives your simulation as well as your main function
in a file called simulator.cpp function.
