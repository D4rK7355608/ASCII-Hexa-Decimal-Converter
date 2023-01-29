// Includes standard input/output stream library
#include <iostream>
// Includes FStream library for reading files
#include <fstream>
// Includes string library for manipulation strings
#include <cstring>
// Includes time library for getting time and localtime functions
#include <ctime>
// Includes Windows library for console text attribute manipulation
#include <Windows.h>
using namespace std;

// ASCII conversion function
void asciiConversion() {
    // Declaring variables
    string input;

    // Welcome message
    cout << "Welcome to ASCII Converter!" << endl;
	
	cout << "Enter the string you want to convert: ";
    cin >> input;
    
    // Checking if input have spaces
	if (input.find(' ') != string::npos) {
        cout << "Error: Input cannot contain spaces." << endl;
        return;
    }

	cout << "ASCII Conversion: " << endl;
    for (char c : input) {
        // Shows the output of the input with ASCII numbers
        cout << c << " : " << (int)c << "\n";
    }

	// End function
    cout << "Press any key to continue...";
}

// Hexa conversion function
void hexaConversion() {
	// Declaring variables
	char x;
	//Welcome message
	cout << "Welcome to Hexadecimal Converter!" << endl;
	
	cout << "Enter a character: ";
	cin >> x;
	
	// Hexadecimal conversion
	cout << "Hexadecimal Conversion: " << endl;
    cout << x << " : " << hex << int(x) << endl;
    
    // End function
    cout << "Press any key to continue...";
}

// Lower to upper case conversion function
void letterConversion() {
	// Declaring variables
    char s[256];
    
    // Welcome message
    cout << "Welcome to Lower to Upper Case Converter!" << endl;
    
    // Enter input
    cout << "Enter a string: ";
    cin.getline(s,257);

    // Convert lowercase characters to uppercase
    for (int i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }

    cout << "Result: " << s << endl;
    
    // End function
    cout << "Press any key to continue...";
}

// Decimal conversion function
void decimalConversion() {
    // Declaring variables
    string input;
    
    // Welcome message
    cout << "Welcome to Decimal Converter!" << endl;
    
    cout << "Enter a hexadecimal or decimal number: ";
	cin >> input;
    
    // Check if input is one character long
    if (input.length() != 1) {
        cout << "Error: Input must be one character long." << endl;
        
        // End function
    	cout << "Press any key to continue...";
        return;
    }

    // Check if input is a digit or hexadecimal digit
    if (isdigit(input[0])) {
        int decimal = input[0] - '0';
        cout << "The decimal equivalent is: " << decimal << "." << endl;
        
        // End function
    	cout << "Press any key to continue...";
    } else if (isxdigit(input[0])) {
        int hex = stoi(input, nullptr, 16);
        cout << "The decimal equivalent is: " << hex << "." << endl;
        
        // End function
    	cout << "Press any key to continue...";
    } else {
        cout << "Error: Invalid input." << endl;
        
        // End function
    	cout << "Press any key to continue...";
        return;
    }
}

void fileConversion() {
	// Welcome message
	cout << "Welcome to File Converter!" << endl;
	
	// Opening file
    ifstream file("file.bin", ios::binary);

    // Check if file is open
    if (!file.is_open()) {
        cout << "Error opening file..." << endl;
        return;
    }

    // Read file one byte at a time
    char c;
    while (file.read(&c, sizeof(c))) {
        // Shows the output of the file with ASCII numbers
        cout << c << " : " << int(c) << endl;
    }

    // Close file
    file.close();
    
    // End program
    cout << "Press any key to continue...";
}

// Main function
int main() {
	// Get handle to console window
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Set console text color to blue
    SetConsoleTextAttribute(hConsole, 10);
    
    // Welcome message
    cout << "Hello!!!\nWelcome to my project!\n\nShort description:\nThis C++ code is a suite that let's you convert your text to ASCII, hexa and more!" << endl;
    cout << "Press any key to continue..." << endl;
	getchar();
    
    cout << "--------------------------------\n";
    
    // Options messages
    cout << "1. ASCII conversion" << endl;
    cout << "2. Hexadecimal conversion" << endl;
    cout << "3. Lower to upper case conversion" << endl;
    cout << "4. Decimal conversion" << endl;
    cout << "5. File conversion" << endl;
    
    // Action choosen
    int choice;
    cout << "Please choose an action to perform: ";
    cin >> choice;
    
    getchar();
    cout << "--------------------------------\n";
    
    // Cases with actions
    switch(choice) {
        case 1: asciiConversion(); break;
        case 2: hexaConversion(); break;
        case 3: letterConversion(); break;
        case 4: decimalConversion(); break;
        case 5: fileConversion(); break;
        default: cout << "Invalid choice.";
    }
    
    cout << "\n--------------------------------\n";
    
    // Get current time
    time_t current_time = time(nullptr);
    // Convert current time to local time
    struct tm* local_time = localtime(&current_time);
    int year = local_time->tm_year + 1900;
    
    // End program
    cout << "Thank you for using my program!\n\nCode by: D4rK;\nVersion: 1.0;\nProgramming language: C++;\n\nCopyright " << year << " by D4rK, made with <3 in Romania!";
    return 0;
}