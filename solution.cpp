
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	names[size] = name; 
	gpas[size] = gpa;
	size++;
	
}

void updateGPA(double* gpaPtr, double newGpa){
	*gpaPtr = newGpa; 
}

void printStudent(const char* name, const double& gpa){
	std::cout << name << ": " << gpa << std::endl; 
}

double averageGPA(const double gpas[], int size){
	double sum = 0.0;
	for(int i = 0; i < size; i++){
		sum += gpas[i]; 
	}
	double retSize = static_cast<double>(size); 
	return (sum / retSize);	
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
			    	std::string input1;  
			    	double gpa;
			    	std::cout << "Enter name: " << std::endl; 
			    	std::cin >> input1;
			    	char* name = new char[input1.length() + 1];
			    	for(int i = 0; i < input1.length(); i++){
					    name[i] = input1[i]; 
			    	}
			    	name[input1.length()] = '\0';
			    	std::cout << "Enter gpa: " << std::endl; 
			    	std::cin >> gpa;
					if (size == capacity){
						std::cout << "List full" << std::endl;
				    	delete(name); 
						break;
					}
					else{
			    		addStudent(name, gpa, names, gpas, size, capacity);
			    		break;
					}
            }
            case 2: {

			    int index; 
			    double gpa; 
			    std::cout << "Enter index: " << std::endl; 
			    std::cin >> index;  
			    std::cout << "Enter new GPA: " << std::endl;
			    std::cin >> gpa;
			    if(index >= 0 && index < size){
				    double* gpaPtr = &gpas[index];
				    updateGPA(gpaPtr, gpa);
			    }
			    break; 
            }
            case 3: {
			    for(int i = 0; i < size; i++){
				    printStudent(names[i], gpas[i]);
			    }
			    break;
            }
            case 4: {
			    if(size == 0){
				    std::cout << "No students" << std::endl;
				    break;
			    }
			    else{
			    	int average = static_cast<int>(averageGPA(gpas, size));
			    	std::cout << "Average GPA: " << average << std::endl; 
			    	break;
			    }	
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    delete[] names; 
    return 0;
}
