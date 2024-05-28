#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include <sstream>

using namespace std;

class Book {
public:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

    Book() : author(""), title(""), publisher(""), year(0), pages(0) {}

    Book(string author, string title, string publisher, int year, int pages)
        : author(author), title(title), publisher(publisher), year(year), pages(pages) {}

    friend ostream& operator<<(ostream& out, const Book& book) {
        out << "Author: " << book.author << ", Title: " << book.title << ", Publisher: " << book.publisher
            << ", Year: " << book.year << ", Pages: " << book.pages << endl;
        return out;
    }
};

bool compareBooks(const Book& b1, const Book& b2) {
    return b1.title < b2.title;
}

int main() {
    vector<Book> books;
    ifstream input("input.txt");
    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        string author, title, publisher;
        int year, pages;
        getline(ss, author, ',');
        getline(ss, title, ',');
        getline(ss, publisher, ',');
        ss >> year >> pages;
        books.emplace_back(author, title, publisher, year, pages);
    }
    input.close();

    ofstream output("output.txt");
    output << "Original container:" << endl;
    for (const auto& book : books) {
        output << book;
    }

    deque<Book> copiedBooks;
    copiedBooks.resize(books.size());
    copy(books.begin(), books.end(), copiedBooks.begin());
    sort(books.begin(), books.end(), compareBooks);

    output << "Sorted container:" << endl;
    for (const auto& book : books) {
        output << book;
    }

    output << "Copied container:" << endl;
    for (const auto& book : copiedBooks) {
        output << book;
    }

    output.close();

    return 0;
}