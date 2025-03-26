#include "matrix.hpp" // include the helper file
#include <iostream> // normal import
#include <fstream> // text file reading
#include <iomanip> // formatting import
#include <vector> // vector for dynamic arrays
#include <string> // string handling
#include <limits> // limits of data types

// Helper function to print a matrix with aligned columns
void printMatrixAligned(const Matrix &mat) { // printing matrix function
    int N = mat.get_size(); // get size of the array
    for (int i = 0; i < N; ++i) {// for each row
        for (int j = 0; j < N; ++j) {// for each column
            std::cout << std::setw(4) << mat.get_value(i, j);// print num with an alignment
        }
        std::cout << std::endl;// add new line after every row
    }
}


void waitForEnter(const std::string &message = "Press ENTER to continue...") {// Helper to pause and wait for the user to press ENTER
    std::cout << message;// print given message
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // input handling
}

int main(int argc, char *argv[]) {// define the main class
    
    std::ifstream inFile("testfile.txt");// Open the input file
    if (!inFile) {//if no file found
        std::cerr << "Error: Could not open testfile.txt" << std::endl;// print no file found
        return 1;//end program
    }

    // Reads the matrix size and data from file
    int N;
    inFile >> N;

    // Reads the first matrix
    std::vector<std::vector<int>> data1(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            inFile >> data1[i][j];// for every number add it to the correct position

    // Reads the second matrix
    std::vector<std::vector<int>> data2(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            inFile >> data2[i][j];// for every number add it to the correct position

    inFile.close();// close the file

    // Construct Matrix objects as defined in matrix.cpp
    Matrix m1(data1);
    Matrix m2(data2);

    // Display the two matrices using our aligned printing method
    std::cout << "Matrix 1:" << std::endl;
    printMatrixAligned(m1);
    std::cout << "\nMatrix 2:" << std::endl;
    printMatrixAligned(m2);

    waitForEnter("\nPress ENTER to perform matrix addition and multiplication...");// calls the wait for input message

    // adds the two matricies and shows result
    std::cout << "\n--- Matrix Addition (m1 + m2) ---" << std::endl;
    Matrix sumMat = m1 + m2;
    printMatrixAligned(sumMat);

    // Multiply the two matrices and display the result
    std::cout << "\n--- Matrix Multiplication (m1 * m2) ---" << std::endl;
    Matrix prodMat = m1 * m2;
    printMatrixAligned(prodMat);

    waitForEnter("\nPress ENTER to compute diagonal sums for a chosen matrix..."); // wait

    // 4. Get the sum of matrix diagonal elements after choosing which matrix to sum
    int choice;
    std::cout << "\nCompute diagonals for which matrix? (Enter 1 for Matrix 1, 2 for Matrix 2): ";
    std::cin >> choice;
    Matrix *diagMatrix = (choice == 1) ? &m1 : &m2;
    std::cout << "Major (main) diagonal sum: " << diagMatrix->sum_diagonal_major() << std::endl;
    std::cout << "Minor (secondary) diagonal sum: " << diagMatrix->sum_diagonal_minor() << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  

    waitForEnter("\nPress ENTER to swap rows in a chosen matrix...");//wait

    // Swap matrix rows 
    std::cout << "\nSwap rows in which matrix? (Enter 1 for Matrix 1, 2 for Matrix 2): ";
    std::cin >> choice; // sets which matrix
    Matrix *swapRowMatrix = (choice == 1) ? &m1 : &m2; // makes a matrix with parent matrix info
    int r1, r2; // initialize rows
    std::cout << "Enter first row index (0-indexed): ";
    std::cin >> r1; // define the row
    std::cout << "Enter second row index (0-indexed): ";
    std::cin >> r2; // define the row 2
    swapRowMatrix->swap_rows(r1, r2); //call swap rows
    std::cout << "Matrix after swapping rows:" << std::endl;
    printMatrixAligned(*swapRowMatrix);// print new matrix
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    waitForEnter("\nPress ENTER to swap columns in a chosen matrix..."); // wait

    // Swap matrix columns (same as rows almost)
    std::cout << "\nSwap columns in which matrix? (Enter 1 for Matrix 1, 2 for Matrix 2): ";
    std::cin >> choice;
    Matrix *swapColMatrix = (choice == 1) ? &m1 : &m2;
    int c1, c2;
    std::cout << "Enter first column index (0-indexed): ";
    std::cin >> c1;
    std::cout << "Enter second column index (0-indexed): ";
    std::cin >> c2;
    swapColMatrix->swap_cols(c1, c2);
    std::cout << "Matrix after swapping columns:" << std::endl;
    printMatrixAligned(*swapColMatrix);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    waitForEnter("\nPress ENTER to update an element in a chosen matrix..."); // wait

    // Update a matrix element 
    std::cout << "\nUpdate element in which matrix? (Enter 1 for Matrix 1, 2 for Matrix 2): ";
    std::cin >> choice; // choosen matrix
    Matrix *updateMatrix = (choice == 1) ? &m1 : &m2; // copy
    int row, col, newValue; // initialize
    std::cout << "Enter row index (0-indexed): ";
    std::cin >> row; // define
    std::cout << "Enter column index (0-indexed): ";
    std::cin >> col; // define
    std::cout << "Enter new value: ";
    std::cin >> newValue; // define
    updateMatrix->set_value(row, col, newValue); // update matrix value
    std::cout << "Matrix after update:" << std::endl;
    printMatrixAligned(*updateMatrix); // print matrix
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nAll operations completed." << std::endl; // display all things completed
    return 0;// end main
}