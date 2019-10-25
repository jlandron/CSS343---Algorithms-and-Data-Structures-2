/**
 *#############################################################################
 *#---------------------------- Driver ---------------------------------------
 *# Driver file that makes a complete movie store sends informations to complete
 *# transactions.
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  22May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Transaction.
 *Assumptions:
 * If the relative file paths for input are changed, the filepaths below should
 *be edited to reflect that change.
 * The program can be run using the build.sh command in terminal which compiles
 *all files and runs the program with valgrind
 * This program must be compiled with C++11 or later
 *
 * once build.sh is completed once, the program can be executed with ./a.out as
 *usual or the program can be run directly from linux executable ./runMovieStore
 **/
#include <fstream>
#include "MovieStore.h"

using namespace std;

int main(int argc, char const* argv[]) {
    // initialize a movie store
    MovieStore myStore;
    // initialize file streams
    ifstream movieFile;
    ifstream customerFile;
    ifstream transactionFile;

    // open files in relative directory references
    try {
        movieFile.open("../references/data4movies.txt");
        customerFile.open("../references/data4customers.txt");
        transactionFile.open("../references/data4commands.txt");
    } catch (const exception& e) {
        cerr << e.what() << '\n';
    }

    // call the three main methods of myStore
    myStore.buildTrees(movieFile);
    myStore.buildCustomers(customerFile);
    myStore.doTransactions(transactionFile);

    // close all file streams
    transactionFile.close();
    customerFile.close();
    movieFile.close();
    return 0;
}
