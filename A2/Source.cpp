//Assignment 2 ~ Abdelrahman Hashad

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//#define PRE_RELEASE

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
	
#ifdef PRE_RELEASE
	string email;
#endif
};

void parseStudentData(vector<STUDENT_DATA>& studentVector, const string& filename) {
	ifstream inputFile(filename);
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			size_t commaPos = line.find(',');
			if (commaPos != string::npos) {
				STUDENT_DATA student;
				student.lastName = line.substr(0, commaPos);
				student.firstName = line.substr(commaPos + 1);
#ifdef PRE_RELEASE
				string line2 = student.firstName;
				size_t commaPos2 = line2.find(',');
				student.firstName = line.substr(commaPos + 1, commaPos2);
				student.email = line.substr(commaPos2 + commaPos + 2);
#endif
				studentVector.push_back(student);
			}
		}
		inputFile.close();
	}
	else {
		cout << "Error couldn't open file." << endl;
	}
}

int main() {
	vector<STUDENT_DATA> studentVector;
	string filename = "C:\\Users\\silve\\AssignmentDocs\\StudentData.txt";
#ifdef PRE_RELEASE
	cout << "Running Pre-Release Code" << endl;
	parseStudentData(studentVector, "C:\\Users\\silve\\AssignmentDocs\\StudentData_Emails.txt");
#else
	cout << "Running Standard Code" << endl;
	parseStudentData(studentVector, filename);
#endif

#if defined(_DEBUG) && defined(PRE_RELEASE)
	for (const auto& student : studentVector) {
		std::cout << student.lastName << "," << student.firstName << " ," << student.email << std::endl;
	}
#elif _DEBUG
	for (const auto& student : studentVector) {
		std::cout << student.lastName << "," << student.firstName << std::endl;
	}
#endif
	return 0;
}