/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#include "MyVector-proj5.h"
#include "MyList-proj5.h"
#include "Queue1-proj5.h"
#include "Queue2-proj5.h"
#include "Queue3-proj5.h"

const int SIZE = 100;

int main()
{
    Queue1<int> q1;
    int array[SIZE];

    srand((unsigned) time(0));
    int num;

    for (int i = 0; i < SIZE; i++) {

        array[i] = rand() % 100;

    }

    cout << "Queue1 Enqueuing..." << endl;
    for (int i = 0; i < SIZE; i++) {

        q1.enqueue(array[i]);
    }

    double elapsed_secs = 0;
    clock_t begin1, begin2, begin3;
    begin1 = clock();

    cout << setw(2);
    cout << "Dequeuing..." << endl;
    for (int k = 0; k < 10; k++) {

        for (int i = 0; i < 10; i++) {

            q1.dequeue(num);
            cout << num << " ";
        }

        cout << endl;
    }

    clock_t end1, end2, end3;
    end1 = clock();

    elapsed_secs = double(end1 - begin1) / CLOCKS_PER_SEC;

    cout << "\nTime: " << elapsed_secs;

    Queue2<int> q2;

    elapsed_secs = 0;

    cout << setw(2);
    cout << "\n\nQueue2 Enqueuing..." << endl;
    for (int i = 0; i < SIZE; i++) {

        q2.enqueue(array[i]);
    }

    begin2 = clock();

    cout << "Dequeuing..." << endl;
    for (int k = 0; k < 10; k++) {

        for (int i = 0; i < 10; i++) {

            q2.dequeue(num);
            cout << num << " ";
        }

        cout << endl;
    }

    end2 = clock();

    elapsed_secs = double(end2 - begin2) / CLOCKS_PER_SEC;

    cout << "\nTime: " << elapsed_secs;

    Queue3<int> q3;

    cout << setw(2);
    cout << "\n\nQueue3 Enqueuing..." << endl;
    for (int i = 0; i < SIZE; i++) {

        q3.enqueue(array[i]);
    }

    elapsed_secs = 0;
    begin3 = clock();

    cout << "Dequeuing..." << endl;
    for (int k = 0; k < 10; k++) {

        for (int i = 0; i < 10; i++) {

            q3.dequeue(num);
            cout << num << " ";
        }

        cout << endl;
    }

    end3 = clock();

    elapsed_secs = double(end3 - begin3) / CLOCKS_PER_SEC;

    cout << setprecision(8) << fixed;
    cout << "\nTime: " << elapsed_secs;

    return 0;
}

