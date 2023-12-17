#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;

// ANSI color escape codes
#define RESET_COLOR "\033[0m"
#define BLUE_COLOR "\033[34m"
#define WHITE_COLOR "\033[37m"
#define CYAN_COLOR "\033[36m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define RED_COLOR "\033[31m"
#define MAGENTA_COLOR "\033[35m"
#define BOLD "\033[1m"

// Function prototype
void saveStudentDataToCSV(const vector<string>& studentNames, const vector<int>& studentGrades);

// Function to display the colorful menu
void displayMenu() {
    cout << MAGENTA_COLOR << BOLD << "------------------------" << endl;
    cout << "\tOPTIONS" << endl;
    cout << "------------------------" << endl;
    cout << BLUE_COLOR << "1. " << RESET_COLOR << "Add Student Grade" << endl;
    cout << WHITE_COLOR << "2. " << RESET_COLOR << "Display Highest, Average, and Lowest Grades" << endl;
    cout << BLUE_COLOR << "3. " << RESET_COLOR << "Edit Student Grades" << endl;
    cout << WHITE_COLOR << "4. " << RESET_COLOR << "Delete Student Grades" << endl;
    cout << BLUE_COLOR << "5. " << RESET_COLOR << "Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to save student data to a CSV file
void saveStudentDataToCSV(const vector<string>& studentNames, const vector<int>& studentGrades) {
    ofstream outputFile("student_data.csv");
    if (!outputFile.is_open()) {
        cout << RED_COLOR << "Failed to open the CSV file for writing." << RESET_COLOR << endl;
        return;
    }

    outputFile << "Name,Grade" << endl; // CSV header

    for (size_t i = 0; i < studentNames.size(); ++i) {
        outputFile << studentNames[i] << "," << studentGrades[i] << endl;
    }

    outputFile.close();
    cout << GREEN_COLOR << "Student data has been saved to student_data.csv." << RESET_COLOR << endl;
}

int main() {
    cout << "\e[1;35m==============================================================================================================================================\n";
cout << "\t\t\t\e[1;35m\t\t\t\tStudent Grading System" << endl;
cout << "\e[1;35m==============================================================================================================================================\n\n" << "\e[0m" << endl;

    vector<string> studentNames;
    vector<int> studentGrades;

    while (true) {
        displayMenu(); // Display the colorful menu at the start of each loop iteration

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: // Add Student Grade
                {
                    int numStudents;
                    cout << YELLOW_COLOR << "Enter the number of students: " << RESET_COLOR;
                    cin >> numStudents;

                    for (int i = 0; i < numStudents; ++i) {
                        string name;
                        int grade;

                        cout << YELLOW_COLOR << "Enter the name of student " << (i + 1) << ": " << RESET_COLOR;
                        cin.ignore();
                        getline(cin, name);

                        cout << YELLOW_COLOR << "Enter grade for " << name << ": " << RESET_COLOR;
                        cin >> grade;

                        studentNames.push_back(name);
                        studentGrades.push_back(grade);
                    }
                    saveStudentDataToCSV(studentNames, studentGrades); // Save data to CSV after adding students
                }
                break;
            case 2: // Display Highest, Average, and Lowest Grades
                {
                    if (studentNames.empty()) {
                        cout << RED_COLOR << "No student data available." << RESET_COLOR << endl;
                    } else {
                        int highestGrade = *max_element(studentGrades.begin(), studentGrades.end());
                        int lowestGrade = *min_element(studentGrades.begin(), studentGrades.end());
                        double averageGrade = static_cast<double>(accumulate(studentGrades.begin(), studentGrades.end(), 0)) / studentNames.size();

                        cout << GREEN_COLOR << "Highest Grade: " << RESET_COLOR << highestGrade << endl;
                        cout << GREEN_COLOR << "Average Grade: " << RESET_COLOR << fixed << setprecision(2) << averageGrade << endl;
                        cout << GREEN_COLOR << "Lowest Grade: " << RESET_COLOR << lowestGrade << endl;
                    }
                }
                break;
            case 3: // Edit Student Grades
                {
                    if (studentNames.empty()) {
                        cout << RED_COLOR << "No student data available." << RESET_COLOR << endl;
                    } else {
                        cout << YELLOW_COLOR << "Enter the name of the student to edit grades: " << RESET_COLOR;
                        string searchName;
                        cin.ignore();
                        getline(cin, searchName);

                        bool found = false;
                        for (size_t i = 0; i < studentNames.size(); ++i) {
                            if (studentNames[i] == searchName) {
                                cout << YELLOW_COLOR << "Enter the new grade for " << searchName << ": " << RESET_COLOR;
                                int newGrade;
                                cin >> newGrade;
                                studentGrades[i] = newGrade;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            cout << RED_COLOR << "Student not found." << RESET_COLOR << endl;
                        }
                        saveStudentDataToCSV(studentNames, studentGrades); // Save data to CSV after editing grades
                    }
                }
                break;
            case 4: // Delete Student Grades
                {
                    if (studentNames.empty()) {
                        cout << RED_COLOR << "No student data available." << RESET_COLOR << endl;
                    } else {
                        cout << YELLOW_COLOR << "Enter the name of the student to delete: " << RESET_COLOR;
                        string deleteName;
                        cin.ignore();
                        getline(cin, deleteName);

                        for (size_t i = 0; i < studentNames.size(); ++i) {
                            if (studentNames[i] == deleteName) {
                                studentNames.erase(studentNames.begin() + i);
                                studentGrades.erase(studentGrades.begin() + i);
                                cout << RED_COLOR << "Student " << deleteName << " has been deleted." << RESET_COLOR << endl;
                                saveStudentDataToCSV(studentNames, studentGrades); // Save data to CSV after deleting a student
                                break;
                            }
                        }
                    }
                }
                break;
            case 5: // Exit
                saveStudentDataToCSV(studentNames, studentGrades); // Save data to CSV before exiting
                cout << MAGENTA_COLOR << "Exiting the program. Goodbye!" << RESET_COLOR << endl;
                return 0;
            default:
                cout << RED_COLOR << "Invalid choice. Please enter a valid option." << RESET_COLOR << endl;
                break;
        }
    }
return 0;
}
