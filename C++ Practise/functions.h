#pragma once
#include <iostream>
#Darragh Boland

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	
}

bool isAPalindrome(int testNumber) {
	int reversed = 0, original = testNumber;
	while (testNumber != 0) {
		reversed = reversed * 10 + testNumber % 10;
		testNumber /= 10;
	}
	return original == reversed;
}

bool isAPrimeNumber(int numbertoTest) {
	if (numbertoTest <= 1) return false;
	for (int i = 2; i * i <= numbertoTest; i++) {
		if (numbertoTest % i == 0) return false;
	}
	return true;
}

int input5CharsConvertToInt() {
	int result = 0;
	char inputChar;
	for (int i = 0; i < 5; i++) {
		std::cin >> inputChar;
		if (!isdigit(inputChar)) return 0;  // Return 0 if non-digit character is found
		result = result * 10 + (inputChar - '0');
	}
	return result;
}

int convertBinarytoDecimal(int binaryNumber) {
	int decimal = 0, base = 1;
	while (binaryNumber > 0) {
		int last_digit = binaryNumber % 10;
		decimal += last_digit * base;
		binaryNumber /= 10;
		base *= 2;
	}
	return decimal;
}

void drawRightAngledTriangle() {
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "A";
		}
		std::cout << std::endl;
	}
}

void drawIsocelesTriangle() {
	int rows = 4;
	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "A";
		}
		std::cout << std::endl;
	}
	for (int i = rows - 1; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "A";
		}
		std::cout << std::endl;
	}
}


int find(int size, int arr[], int toFind) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == toFind) return i;
	}
	return -1;
}

int find2ndLargest(int size, int arr[]) {
	if (size < 2) return -1;
	int first = INT_MIN, second = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (arr[i] > first) {
			second = first;
			first = arr[i];
		}
		else if (arr[i] > second && arr[i] != first) {
			second = arr[i];
		}
	}
	return (second == INT_MIN) ? -1 : second;
}

void copyArraytoArray(int size, int arr1[], int arr2[]) {
	for (int i = 0; i < size; i++) {
		arr2[i] = arr1[i];
	}
}

bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex) {
	if (count >= size || insertIndex < 0 || insertIndex > count) return false;
	for (int i = count; i > insertIndex; i--) {
		arr[i] = arr[i - 1];
	}
	arr[insertIndex] = elementToInsert;
	count++;
	return true;
}

bool deleteElement(int& size, int& count, int arr[], int deleteIndex) {
	if (deleteIndex < 0 || deleteIndex >= count) return false;
	for (int i = deleteIndex; i < count - 1; i++) {
		arr[i] = arr[i + 1];
	}
	count--;
	return true;
}

int frequencyCount(int size, int arr[], int value) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) count++;
	}
	return count;
}

int countDuplicates(int size, int arr[]) {
	int duplicates = 0;
	bool visited[size] = { false };
	for (int i = 0; i < size; i++) {
		if (visited[i]) continue;
		int count = 1;
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				visited[j] = true;
				count++;
			}
		}
		if (count > 1) duplicates++;
	}
	return duplicates;
}

void reverse(int size, int arr[]) {
	for (int i = 0; i < size / 2; i++) {
		std::swap(arr[i], arr[size - i - 1]);
	}
}

int rotateLeft(int size, int arr[]) {
	if (size == 0) return -1;
	int first = arr[0];
	for (int i = 0; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = first;
	return first;
}

bool twoMovies(int flightLength, int movieLengths[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (movieLengths[i] + movieLengths[j] == flightLength) {
				return true;
			}
		}
	}
	return false;
}

int wordCounter(int size, char characters[]) {
	int wordCount = 0;
	bool inWord = false;
	for (int i = 0; i < size; i++) {
		if ((characters[i] >= 'A' && characters[i] <= 'Z') ||
			(characters[i] >= 'a' && characters[i] <= 'z')) {
			if (!inWord) {
				wordCount++;
				inWord = true;
			}
		}
		else {
			inWord = false;
		}
	}
	return wordCount;
}
