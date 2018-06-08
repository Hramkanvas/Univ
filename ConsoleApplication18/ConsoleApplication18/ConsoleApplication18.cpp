#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdexcept>
#include <tchar.h>
#include <strsafe.h>
#include <ctime>
#define MAX_SEM_COUNT 10
int number_of_threads = 0;
int dimension = 0;
CRITICAL_SECTION cs1;
HANDLE *startMarkerEvent = nullptr;
HANDLE *stopMarkerEvent = nullptr;
HANDLE *whatNextMarkerEvent = nullptr;
int *lab_array = nullptr;

int *get_array()
{
	std::cout << "print dimension:\n";
	std::cin >> dimension;
	if (dimension < 0) throw "dimension < 1";
	auto *result = new int[dimension];
	for (int i = 0; i < dimension; i++)
	{
		result[i] = 0;
	}
	return result;
}

DWORD WINAPI marker(LPVOID dw_id)
{
	HANDLE set_of_events[2];
	DWORD dwEvent;
	int id = reinterpret_cast<int>(dw_id);
	int idd = id + 1;
	set_of_events[0] = startMarkerEvent[id];
	set_of_events[1] = stopMarkerEvent[id];
	WaitForSingleObject(set_of_events[0], INFINITE);
	srand(static_cast<unsigned int>(id));
	int temp = 0;
	int num_of_marked_elements = 0;
	int *array_of_indexes = new int[dimension];
	bool flag = true;
	while (flag)
	{
		temp = rand() % dimension;
		EnterCriticalSection(&cs1);
		if (lab_array[temp] == 0)
		{
			Sleep(5);
			lab_array[temp] = idd;
			Sleep(5);
			array_of_indexes[num_of_marked_elements] = temp;
			num_of_marked_elements++;
			LeaveCriticalSection(&cs1);
		}
		else
		{
			std::cout << "num of thread" << idd << std::endl;
			std::cout << "quantity of marked elements" << num_of_marked_elements << std::endl;
			std::cout << "rand element" << temp << std::endl;
			LeaveCriticalSection(&cs1);
			SetEvent(whatNextMarkerEvent[id]);
			dwEvent = WaitForMultipleObjects(2, set_of_events, FALSE, INFINITE);
			ResetEvent(whatNextMarkerEvent[id]);
			//+EnterCriticalSection(&cs1);
			//std::cout << "******" << temp << std::endl;
			//LeaveCriticalSection(&cs1);
			switch (dwEvent)
			{
			case WAIT_OBJECT_0 + 0:
				break;
			case WAIT_OBJECT_0 + 1:
				EnterCriticalSection(&cs1);
				for (int i = 0; i < num_of_marked_elements; i++)
				{
					lab_array[array_of_indexes[i]] = 0;
				}
				LeaveCriticalSection(&cs1);
				flag = false;
				break;
			case WAIT_TIMEOUT:
				printf("Wait timed out.\n");
				break;
			}
		}
	}
	SetEvent(whatNextMarkerEvent[id]);
	return 0;
}

int main()
{
	lab_array = get_array();
	std::cout << "\nprint the number of threads:\n";
	std::cin >> number_of_threads;
	if (number_of_threads < 1) throw "number of threads < 1 !!";
	HANDLE *aThread = new HANDLE[number_of_threads];
	DWORD *ThreadID = new DWORD[number_of_threads];
	int i;
	startMarkerEvent = new HANDLE[number_of_threads];
	stopMarkerEvent = new HANDLE[number_of_threads];
	whatNextMarkerEvent = new HANDLE[number_of_threads];
	InitializeCriticalSection(&cs1);
	for (i = 0; i < number_of_threads; i++)
	{
		startMarkerEvent[i] = CreateEvent(
			nullptr,
			FALSE,
			FALSE,
			nullptr);
		stopMarkerEvent[i] = CreateEvent(
			nullptr,
			FALSE,
			FALSE,
			nullptr);
		whatNextMarkerEvent[i] = CreateEvent(
			nullptr,
			TRUE,
			FALSE,
			nullptr);
		if (aThread[i] == nullptr) throw "aThread == nullptr";
		aThread[i] = CreateThread(
			nullptr,
			0,
			marker,
			reinterpret_cast<LPVOID>(i),
			0,
			&ThreadID[i]
		);

	}
	for (i = 0; i < number_of_threads; i++)
	{
		SetEvent(startMarkerEvent[i]);
	}
	int ordered_number = 0;
	int lock = 0;
	while (lock < number_of_threads)
	{
		lock++;
		WaitForMultipleObjects(static_cast<DWORD>(number_of_threads), whatNextMarkerEvent, TRUE, INFINITE);
		EnterCriticalSection(&cs1);
		std::cout << "\narray\n";
		for (i = 0; i < dimension; i++)
		{
			std::cout << lab_array[i] << " ";
		}
		std::cout << std::endl << "ordered number of thread= ";
		std::cin >> ordered_number;
		LeaveCriticalSection(&cs1);
		SetEvent(stopMarkerEvent[ordered_number]);
		WaitForSingleObject(aThread[ordered_number], INFINITE);
		std::cout << "\narray\n";
		for (i = 0; i < dimension; i++)
		{
			std::cout << lab_array[i] << " ";
		}
		for (i = 0; i < number_of_threads; i++)
		{
			SetEvent(startMarkerEvent[i]);
		}
	}
	for (i = 0; i < number_of_threads; i++)
	{
		CloseHandle(aThread[i]);
		CloseHandle(startMarkerEvent[i]);
		CloseHandle(stopMarkerEvent[i]);
		CloseHandle(whatNextMarkerEvent[i]);
	}
	DeleteCriticalSection(&cs1);
	std::system("pause");
	return 0;
}