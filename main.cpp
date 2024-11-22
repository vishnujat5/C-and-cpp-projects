#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string to_string(int num) {
    	string result = "";
    	bool isNegative = false;

    	if (num < 0) {
        	isNegative = true;
        	num = -num; 
    	}
    	do {
        	char digit = (num % 10) + '0'; 
        	result = digit + result;      
        	num /= 10;
    	} while (num > 0);

    if (isNegative) {
        result = '-' + result;
    }
    return result;
}
	int to_int(string str){
		int num = 0,startIndex=0;
		bool isNegative = false;
		if(str[0]=='-'){
			isNegative = true;
			startIndex = 1;
		}
		for(int i=startIndex;i<str.length();i++){
			if(str[i]>='0' && str[i]<='9'){
				num = num*10 + (str[i] - '0');
			}else{
				cout<<"Invalid input: non-numeric character found."<<endl;
			}
		}
		if(isNegative)
			num = -num;
		return num;
	}
class addEmployee{
	public:
	string name;
	string dob;
	string mob;
	string total_record_count;
	char group;
	int getRecord(){
		fstream totalRecordsFile;
		totalRecordsFile.open("totalRecords.txt",ios::in);
		if(!totalRecordsFile){
			cerr<<"can't open file.\n";
			return 1;
		}
	getline(totalRecordsFile,total_record_count);
	totalRecordsFile.close();
	}
	void printData(){
		cout<<total_record_count;
	}
	
	string updateRecordsCount(string data,int count_added){
		int num = to_int(data);
		num += count_added;
		return to_string(num);
	}
	
};

//int remove(){
//    const string filename = "data.txt";
//    string substring_to_remove = "ankit mehra		013		section F";
//
//    ifstream inputFile("data.txt");// Open the file for reading
//    if (!inputFile.is_open()) {
//        cerr << "Failed to open the file for reading." << endl;
//        return 1;
//    }
//
//    ofstream temp_file("temp.txt"); // Temporary file for modified data
//    if (!temp_file.is_open()) {
//        cerr << "Failed to open the temporary file for writing." << endl;
//        return 1;
//    }
//
//    string line;
//    while (getline(inputFile, line)) {
//        // Remove the specific substring from the line
//        size_t pos;
//        while ((pos = line.find(substring_to_remove)) != string::npos) {
//            line.erase(pos, substring_to_remove.length());
//        }
//        temp_file << line << endl;
//    }
//
//    inputFile.close();
//    temp_file.close();
//
//    // Replace the original file
//    remove(filename.c_str());
//    rename("temp.txt", filename.c_str());
//
//    cout << "Substring removed successfully!" << endl;
//
//}
int append(string updated_records){
    fstream file("totalRecords.txt", ios::out);
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }
    // Data to append
    cout<< updated_records;
   	file << updated_records << endl;
    file.close();
    cout << "Data appended to the file successfully!" << endl;
}
//void searchAndPrintLine(const string& fileName, const string& searchText) {
//    ifstream file(fileName); // Open the file for reading
//    if (!file.is_open()) {
//        cerr << "Error: Unable to open file " << fileName << endl;
//        return;
//    }
//
//    string line;
//    int lineNumber = 0; // To track the line number
//    bool found = false;
//
//    while (getline(file, line)) {
//        lineNumber++;
//        if (line.find(searchText) != string::npos) { // Check if the line contains the search text
//            cout << "Line " << lineNumber << ": " << line << endl;
//            found = true;
//        }
//    }
//
//    if (!found) {
//        cout << "Text \"" << searchText << "\" not found in the file." << endl;
//    }
//
//    file.close(); // Close the file
//}

int main() {
    //append();
    int a = 10;
    addEmployee obj;
	obj.getRecord();
	obj.printData();
	cout<<"\nafter adding 10: \n"<<endl;
	append(obj.updateRecordsCount(obj.total_record_count,a));
	//obj.getRecord();
    return 0;
}
