#include <iostream>
#include <fstream>

using namespace std;
  
void FindMax (ifstream& inputFile, string fileName, int& maxRow, int& maxColumn);
void PrintMessage (char messageArray[100][100], int maxRowIndex, int maxColumnIndex);
void BuildOutput (ifstream& inputFile, string fileName, int maxRowIndex, int maxColumnIndex);

int main() {
    ifstream inputFile;//input file
    string fileName; //name of input file
    int maxRow = 0; //maximum row index
    int maxColumn = 0; //maximum column index

    //prepare input file for use
    cout << "Enter the name of the file to read " << endl;
    cin >> fileName;
    
    //calls function to find number of rows and columns
    FindMax(inputFile, fileName, maxRow, maxColumn);

    //calls function to create the array "map" and output results
    BuildOutput(inputFile, fileName, maxRow, maxColumn);

    return 0;
}

//finds the max row value and the max column value. As main()reads values from the input file,
//the column/row value and current max column/row value are passed to the function, which returns
//the new current max value.  
void FindMax (ifstream& inputFile, string fileName, int& maxRow, int& maxColumn){
    int rCoordinate; //row indicator for array
    int cCoordinate; //column indicator for array
    char inputCharacter; //output character

    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    
    //find maximum row and column index
    while (!inputFile.eof()) {
        inputFile >> cCoordinate;
        inputFile >> inputCharacter;
        inputFile >> rCoordinate;
        if (!inputFile.fail()) {
            if(rCoordinate > maxRow) {
                maxRow = rCoordinate;
            }
            if(cCoordinate > maxColumn) {
                maxColumn = cCoordinate;
            }
        }
    }
    inputFile.close();

}

//loops through each column within each row of the array, and outputs the character value at every index
//BuildOutput function passes array and max row and column values to PrintMessage function
void PrintMessage (char messageArray[100][100], int maxRowIndex, int maxColumnIndex) {
    int row;
    int column;

    for (row = 0; row <= maxRowIndex; ++row) {
        for (column = 0; column <= maxColumnIndex; ++column) {
            cout << messageArray[row][column];
        }

        cout << endl;
    }
}

//this function fills a 2D array with characters from an input file
//input file, highest row index value, and highest column index value are passed from main()
//this function calls a PrintMessage function to output characters that reveal a message
void BuildOutput (ifstream& inputFile, string fileName, int maxRowIndex, int maxColumnIndex) {
    char messageArray [100][100]; //array allocation values may need to be updated to accomodate an input file with more character assignments
    int row;
    int column;
    char inputCharacter;

    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    //loops through each index in a 2D array to initialize all values to ' '
    for (row = 0; row <= maxRowIndex; ++row) {
        for (column = 0; column <= maxColumnIndex; ++column) {
            messageArray[row][column] = ' ';
        }
    }

    //loops through input file to assign character values to their proper place in a 2D array
    while (!inputFile.eof()) {
        inputFile >> column;
        inputFile >> inputCharacter;
        inputFile >> row;

        if (!inputFile.fail()) {
            messageArray[row][column] = inputCharacter;
        }

    }

    inputFile.close();

    //calls a function to output characters in an array, revealing a block annotated message
    PrintMessage (messageArray, maxRowIndex, maxColumnIndex);

}