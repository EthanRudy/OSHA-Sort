#ifndef OSHA_SORT_HPP
#define OSHA_SORT_HPP

#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <thread>
#include <time.h>

/*
	OSHA Sort:
		This sort strives to create a safe, labor law inclusive workspace for your beloved computer
		The base sorting method is a good old insertion sort, but in compliance with modern labor laws
		For every index that data is moved, the computer will take a 1 second break.
		Ex. Index 5 -> Index 3, the computer will take a 2 second break

		In addition to the quick breaks that the computer autimatically takes, there is also a small chance
		that when the computer clocks into its shift, will will start a 30 minute break as is allowed in
		labor laws

	This file contains OSHA Sorts for vectors, standard arrays, and arrays of all comparable types
*/

const float BREAKCHANCE = RAND_MAX - 1;

template <typename T>
void OSHA_sort(std::vector<T>& vec) {
	std::cout << "OSHA Sorting...\n";

	std::cout << "\tComputer clocking in...\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\tClocked in, getting to work!\n\n";

	// Setting random seed
	srand(time(NULL));

	// Test for 30 minute break
	int longBreak = rand();
	if (longBreak == BREAKCHANCE) {
		std::cout << "\tUnlucky! The computer just clocked out for its 30 minute break!";
		std::this_thread::sleep_for(std::chrono::minutes(30));
	}

	// Auxilary variables for insertion sort
	int i, j, size = vec.size();
	T key;

	// Loop through entire vector
	for (i = 1; i < size; ++i) {
		key = vec[i];	// Set key
		j = i - 1;	// Set starting backtrack position
		while (j >= 0 && vec[j] > key) {	// Backtrack till sorted
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
		int wait = i - j;	// Calculate break duration

		std::cout << "\tTaking a " << wait << " second break...\n";
		std::this_thread::sleep_for(std::chrono::seconds(wait));	// Take a break
		std::cout << "\tBack to work!\n\n";
	}

	std::cout << "Done!\n";
}

template <typename T, std::size_t SIZE>
void OSHA_sort(std::array<T, SIZE>& arr) {
	std::cout << "OSHA Sorting...\n";

	std::cout << "\tComputer clocking in...\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\tClocked in, getting to work!\n\n";

	// Setting random seed
	srand(time(NULL));

	// Test for 30 minute break
	int longBreak = rand();
	if (longBreak == BREAKCHANCE) {
		std::cout << "\tUnlucky! The computer just clocked out for its 30 minute break!";
		std::this_thread::sleep_for(std::chrono::minutes(30));
	}

	// Auxilary variables for insertion sort
	int i, j, size = arr.size();
	T key;

	// Loop through entire array
	for (i = 1; i < size; ++i) {
		key = arr[i];	// Set key
		j = i - 1;	// Set starting backtrack position
		while (j >= 0 && arr[j] > key) {	// Backtrack till sorted
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
		int wait = i - j;	// Calculate break duration

		std::cout << "\tTaking a " << wait << " second break...\n";
		std::this_thread::sleep_for(std::chrono::seconds(wait));	// Take a break
		std::cout << "\tBack to work!\n\n";
	}

	std::cout << "Done!\n";
}

template <typename T>
void OSHA_sort(T arr[], int size) {
	std::cout << "OSHA Sorting...\n";

	std::cout << "\tComputer clocking in...\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\tClocked in, getting to work!\n\n";

	// Setting random seed
	srand(time(NULL));

	// Test for 30 minute break
	int longBreak = rand();
	if (longBreak == BREAKCHANCE) {
		std::cout << "\tUnlucky! The computer just clocked out for its 30 minute break!";
		std::this_thread::sleep_for(std::chrono::minutes(30));
	}

	// Auxilary variables for insertion sort
	int i, j;
	T key;

	// Loop through entire vector
	for (i = 1; i < size; ++i) {
		key = arr[i];	// Set key
		j = i - 1;	// Set starting backtrack position
		while (j >= 0 && arr[j] > key) {	// Backtrack till sorted
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
		int wait = i - j;	// Calculate break duration

		std::cout << "\tTaking a " << wait << " second break...\n";
		std::this_thread::sleep_for(std::chrono::seconds(wait));	// Take a break
		std::cout << "\tBack to work!\n\n";
	}

	std::cout << "Done!\n";
}

#endif OSHA_SORT_HPP
