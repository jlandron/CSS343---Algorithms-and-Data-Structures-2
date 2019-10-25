#include "MovieStore.h"

using namespace std;
/**--------------------------------MovieStore::MovieStore---------------------------
 * default no arg constructor
 */
MovieStore::MovieStore() {
    m_MovieLists = new map<char, vector<Movie*>>;
    m_Customers = new HashTable();
    vector<Movie*> comedies;
    vector<Movie*> dramas;
    vector<Movie*> classics;
    m_MovieLists->insert(pair<char, vector<Movie*>>('F', comedies));
    m_MovieLists->insert(pair<char, vector<Movie*>>('D', dramas));
    m_MovieLists->insert(pair<char, vector<Movie*>>('C', classics));
}
/**--------------------------------MovieStore::~MovieStore--------------------------
 *  complete destructor that deleats all objects expected in the heap.
 */
MovieStore::~MovieStore() {
    delete m_Customers;
    // delete movie objects in each vector
    map<char, vector<Movie*>>::iterator it;
    for (it = m_MovieLists->begin(); it != m_MovieLists->end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            delete (it->second.at(i));
        }
    }
    delete m_MovieLists;
}
/**-------------------------------------buildTrees--------------------------------
 * takes a filestream and reads it line by line while creating and adding Movie
 * objects to their correct vector in m_MovieLists.
 * @param  {ifstream} in : filestream of Movie information
 */
void MovieStore::buildTrees(ifstream& in) {
    // create a movie factory to build all movies
    MovieFactory myFactory;
    string line;
    while (getline(in, line)) {
        Movie* tmp = myFactory.buildMovie(line);
        if (tmp) {
            m_MovieLists->at(tmp->m_Genre).push_back(tmp);
        }
    }
    // sort vectors
    map<char, vector<Movie*>>::iterator it;
    for (it = m_MovieLists->begin(); it != m_MovieLists->end(); it++) {
        // std::sort with a passed lambda expression to sort Movie pointers
        sort(it->second.begin(), it->second.end(),
             [](Movie* a, Movie* b) { return *a < *b; });
    }
}
/**-----------------------------------buildCustomers-------------------------------
 * takes a filestream and reads it line by line while creating and adding
 * customers to the HashList of customer objects.
 * @param  {ifstream} in : filestream of customer information.
 */
void MovieStore::buildCustomers(ifstream& in) {
    string line;
    while (getline(in, line)) {
        Customer* currentCustomer = new Customer(line);
        m_Customers->insertNode(currentCustomer->getID(), currentCustomer);
    }
}
/**-----------------------------------doTransactions-------------------------------
 * doTransactions
 * takes a filestream and reads it line by line while conducting the
 * transactions
 * @param  {ifstream} in : filestream of transactions to be completed.
 */
void MovieStore::doTransactions(ifstream& in) {
    TransactionFactory myFactory;
    string line;
    while (getline(in, line)) {
        Transaction* currentTransaction = myFactory.makeTransaction(line);
        if (currentTransaction != NULL) {
            currentTransaction->doTransaction(m_MovieLists, m_Customers, line);
            delete currentTransaction;
        }
    }
}
/**-----------------------------------printMovie-------------------------------
 * prints all movies in a single
 * @param  {char} genreCode : The single letter Genre code that is desired.
 */
void MovieStore::printMovies(char genreCode) const {
    if (!m_MovieLists->at(genreCode).empty()) {
        cout << "Printing all Movies in Genre: "
             << m_MovieLists->at(genreCode).at(0)->m_Genre << endl;
        for (int i = 0; i < m_MovieLists->at(genreCode).size(); i++) {
            m_MovieLists->at(genreCode).at(i)->display();
        }
    }
}
/**-----------------------------------printMovies-------------------------------
 * method that calls the printMovie method in the desired order for all genres
 */
void MovieStore::printMovies() {
    cout << "----------------------------------------------------------"
         << endl;
    cout << "Printing all Movies in Genre: Comedy" << endl;
    printMovies('F');
    cout << "Printing all Movies in Genre: Drama" << endl;
    printMovies('D');
    cout << "Printing all Movies in Genre: Classic" << endl;
    printMovies('C');
    cout << "----------------------------------------------------------"
         << endl;
}
/**-----------------------------------printCustomers-------------------------------
 * Prints all customers currently in the MovieStore.
 */
void MovieStore::printCustomers() const { m_Customers->display(); }
