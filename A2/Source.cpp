//Assignment 2 ~ Abdelrahman Hashad

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {
	vector<STUDENT_DATA> studentVector;
	ifstream inputFile("C:\\Users\\silve\\AssignmentDocs\\StudentData.txt");
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			size_t commaPos = line.find(',');
			if (commaPos != string::npos) {
				STUDENT_DATA student;
				student.lastName = line.substr(0, commaPos);
				student.firstName = line.substr(commaPos + 1);
				studentVector.push_back(student);
			}
		}
		inputFile.close();
	}
	else {
		cout << "Error couldn't open file." << std::endl;
	}
	#ifdef _DEBUG
	for (const auto& student : studentVector) {
		std::cout << student.lastName << "," << student.firstName << std::endl;
	}
	#endif

	return 0;
}