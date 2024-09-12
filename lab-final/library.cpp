/*
A program for library management
--features--
add, remove and search for books
keep track of borrowers and duet dates
implement a system for calculating fines
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Library {
public:
  string adminUsername;
  string memberUsername;
  string adminPass;
  string memberPass;

  void mainMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t*                                          *\n";
    cout << "\t\t\t\t*       Welcome to the Library System      *\n";
    cout << "\t\t\t\t*                                          *\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t|              1) Admin                    |\n";
    cout << "\t\t\t\t|              2) User                     |\n";
    cout << "\t\t\t\t|              3) Exit                     |\n";
    cout << "\t\t\t\t--------------------------------------------\n";
  };

  void adminMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t*              Admin Menu                  *\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\tEnter your username: ";
    cin >> adminUsername;
    cout << "\t\t\t\tEnter your password: ";
    cin >> adminPass;
  }

  void memberMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t*              Member Menu                 *\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\tEnter your username: ";
    cin >> memberUsername;
    cout << "\t\t\t\tEnter your password: ";
    cin >> memberPass;
  }

  void adminOptions() {
    cout << "\n\n";
    cout << "\t\t\t\t================ Admin Options ================\n";
    cout << "\t\t\t\t|  1. Add a Book                               |\n";
    cout << "\t\t\t\t|  2. Remove a Book                            |\n";
    cout << "\t\t\t\t|  3. Show Available Books                     |\n";
    cout << "\t\t\t\t|  4. Exit Menu                                |\n";
    cout << "\t\t\t\t================================================\n";
  }

  void memberOptions() {
    cout << "\n\n";
    cout << "\t\t\t\t================ Member Options ================\n";
    cout << "\t\t\t\t|  1. Borrow a Book                            |\n";
    cout << "\t\t\t\t|  2. Show Available Books                     |\n";
    cout << "\t\t\t\t|  3. View Borrowed Books                      |\n";
    cout << "\t\t\t\t|  3. Exit Menu                                |\n";
    cout << "\t\t\t\t================================================\n";
  }

  void addBook() {
    string book_name;
    string book_id;
    string status = "uborrowed";
    ofstream book_database("book-database.txt", ios::app);

    cin.ignore();
    cout << "\t\t\t\tEnter the book id: ";
    getline(cin, book_id);
    // cin.ignore();
    cout << "\t\t\t\tEnter the book name: ";
    getline(cin, book_name);

    book_database << book_id << " " << book_name << " " << status << endl;
    book_database.close();
    cout << "\t\t\t\tBook added successfully!\n";
  }


//TO-D0
//add a feature to remobe book using the book ID

void removeBook() {
  string bookIdToRemove;
  ifstream databaseInputStream("book-database.txt");
  ofstream databaseOutputStream("temp.txt");

  cin.ignore();
  cout << "\t\t\t\tEnter the ID of the book you want to remove: ";
  getline(cin, bookIdToRemove);

  string currentLine;
  bool bookFound = false;

  while (getline(databaseInputStream, currentLine)) {
    istringstream iss(currentLine);
    string currentBookId, currentBookName, currentStatus;

    iss >> currentBookId >> currentBookName >> currentStatus;

    if (currentBookId == bookIdToRemove) {
      bookFound = true;
      cout << "\t\t\t\tBook removed successfully!\n";
    } else {
      databaseOutputStream << currentLine << endl;
    }
  }

  if (!bookFound) {
    cout << "\t\t\t\tBook not found!\n";
  }

  databaseInputStream.close();
  databaseOutputStream.close();
  remove("book-database.txt");
  rename("temp.txt", "book-database.txt");
}

void borrowBook() {
  string bookIdToBorrow;
  ifstream databaseInputStream("book-database.txt");
  ofstream databaseOutputStream("temp.txt");

  cin.ignore();
  cout << "\t\t\t\tEnter the ID of the book you want to borrow: ";
  cin >> bookIdToBorrow;
  string currentLine;
  bool bookFound = false;

  while (getline(databaseInputStream, currentLine)) {
    istringstream iss(currentLine);
    string currentBookId, currentBookName, currentStatus;

    iss >> currentBookId >> currentBookName >> currentStatus;

    if (currentBookId == bookIdToBorrow) {
      if (currentStatus == "borrowed") {
        cout << "\t\t\t\tBook is already borrowed!\n";
        databaseOutputStream << currentLine << endl;
      } else {
        bookFound = true;
        databaseOutputStream << currentBookId << " " << currentBookName << " borrowed" << endl;
        cout << "\t\t\t\tBook borrowed successfully!\n";
      }
    } else {
      databaseOutputStream << currentLine << endl;
    }
  }

  if (!bookFound) {
    cout << "\t\t\t\tBook not found!\n";
  }

  databaseInputStream.close();
  databaseOutputStream.close();
  remove("book-database.txt");
  rename("temp.txt", "book-database.txt");
}
void viewBorrowedBooks() {
  ifstream databaseInputStream("book-database.txt");

  cout << "\n\t\t\t\t=============================\n";
  cout << "\t\t\t\t  Borrowed Books\n";
  cout << "\t\t\t\t=============================\n\n";

  string currentBookId, currentBookName, currentStatus;
  int count = 1;
  while (databaseInputStream >> currentBookId >> currentBookName >> currentStatus) {
    if (currentStatus == "borrowed") {
      cout << "\t\t\t\t" << count << ". " << currentBookName << endl;
      count++;
    }
  }

  databaseInputStream.close();
}

  void showAvailableShowBooks() {
    string listName;
    ifstream bookDatabase("book-database.txt");
    cout << "\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t|          Available Books List            |\n";
    cout << "\t\t\t\t--------------------------------------------\n";
    while (!bookDatabase.eof()) {
      getline(bookDatabase, listName);
      cout << "\t\t\t\t* " << listName << "\n";
    }
    cout << "\t\t\t\t--------------------------------------------\n";
    bookDatabase.close();
  }
};

int main() {
  Library library;
  int choice;

  do {
    library.mainMenu();
    cout << "\t\t\t\tEnter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        library.adminMenu();
        if (library.adminUsername == "admin" && library.adminPass == "pass") {
          int adminChoice;
          do {
            library.adminOptions();
            cout << "\t\t\t\tEnter your choice: ";
            cin >> adminChoice;
            switch (adminChoice) {
              case 1:
                library.addBook();
                break;

              case 2:
                library.removeBook();
                break;

              case 3:
                library.showAvailableShowBooks();
                break;

              case 4:
                cout << "\t\t\t\tExiting admin menu!\n";
                break;

              default:
                cout << "\t\t\t\tINVALID OPTION\n";
                break;
            }
          } while (adminChoice != 4);
        } else {
          cout << "\t\t\t\tWrong username or password!!!\n";
        }
        break;
      case 2:
        library.memberMenu();
        if (library.memberUsername == "member" && library.memberPass == "pass") {
          int memberChoice;
          do {
            library.memberOptions();
            cout << "\t\t\t\tEnter your choice: ";
            cin >> memberChoice;

            switch (memberChoice) {
              case 1:
                library.borrowBook();
                break;

              case 2:
                library.showAvailableShowBooks();
                break;
                
              case 3:
                library.viewBorrowedBooks();
                break;
              case 4:
                cout << "\t\t\t\tExiting Menu!!!";
                break;
              case 5:
                cout << "\t\t\t\tInvalid Choice!";
            }
          }  while(memberChoice != 4); 
        } else {
          cout << "\t\t\t\tWrong username or password!!!\n";
        }
        break;
      case 3:
        cout << "\t\t\t\tExiting program!\n";
        break;
      default:
        cout << "\t\t\t\tINVALID OPTION\n";
        break;
    }
  } while (choice != 3);

  return 0;
}
