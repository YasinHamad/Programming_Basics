#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "clsOutput.h"



using namespace std;

class clsFiles
{
public:
	static void PrintFileContent(string file_path) {
		fstream my_file;
		my_file.open(file_path, ios::in);

		if (my_file.is_open()) {
			string line = "";
			cout << clsOutput::FormatString(20, file_path, clsOutput::enPosition::center, "-") << endl;

			while (getline(my_file, line)) {
				cout << line << endl;
			}

			my_file.close();
			cout << clsOutput::GetChar(20, "-") << endl;
		}
	}

	static void LoadDataFromFileToVector(string file_path, vector<string>& _vector) {
		fstream my_file;
		my_file.open(file_path, ios::in);

		if (my_file.is_open()) {
			string line = "";

			while (getline(my_file, line)) {
				_vector.push_back(line);
			}

			my_file.close();
		}
	}

	static void SaveVectorToFile(const string file_path, vector<string>& _vector) {
		fstream my_file;
		my_file.open(file_path, ios::out);

		if (my_file.is_open()) {

			for (string& line : _vector) {
				if (!line.empty()) {
					my_file << line << endl;
				}
			}

			my_file.close();
		}
	}

	static void DeleteRecordFromFile(const string file_path, string record) {
		vector<string> _vector;

		LoadDataFromFileToVector(file_path, _vector);

		for (string& line : _vector) {
			if (line == record) {
				line = "";
				break;
			}
		}

		SaveVectorToFile(file_path, _vector);
	}

	static void UpdateRecordInFile(const string file_path, string record, string new_record) {
		vector<string> _vector;

		LoadDataFromFileToVector(file_path, _vector);

		for (string& line : _vector) {
			if (line == record) {
				line = new_record;
				break;
			}
		}

		SaveVectorToFile(file_path, _vector);
	}

	static void AddLineToFile(string line, string file_path) {
		fstream my_file;
		my_file.open(file_path, ios::out | ios::app);

		if (my_file.is_open()) {
			my_file << line << endl;
			my_file.close();
		}
	}
private:

};

