#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;

    void display() const {
        cout << "Назва: " << title << "\nАвтор: " << author << "\nРік: " << year << "\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        Book b;
        cout << "Введіть назву книги: ";
        getline(cin, b.title);
        cout << "Введіть автора: ";
        getline(cin, b.author);
        cout << "Введіть рік видання: ";
        cin >> b.year;
        cin.ignore();
        books.push_back(b);
        cout << "Книгу додано!\n";
    }

    void showBooks() const {
        if (books.empty()) {
            cout << "Бібліотека порожня.\n";
            return;
        }
        for (const auto& b : books) {
            b.display();
            cout << "---------------------\n";
        }
    }

    void saveToFile(const string& filename) const {
        ofstream out(filename);
        for (const auto& b : books) {
            out << b.title << '\n' << b.author << '\n' << b.year << '\n';
        }
        cout << "Дані збережено у файл " << filename << "\n";
    }

    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) {
            cout << "Не вдалося відкрити файл.\n";
            return;
        }

        books.clear();
        while (!in.eof()) {
            Book b;
            getline(in, b.title);
            if (b.title.empty()) break;
            getline(in, b.author);
            in >> b.year;
            in.ignore();
            books.push_back(b);
        }
        cout << "Дані завантажено з файлу " << filename << "\n";
    }
};

int main() {
    Library lib;
    string filename = "library.txt";
    int choice;

    do {
        cout << "\n1. Додати книгу\n2. Показати всі книги\n3. Зберегти у файл\n4. Завантажити з файлу\n0. Вихід\nВаш вибір: ";
        cin >> choice;
        cin.ignore();  // очищення буфера вводу

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.showBooks(); break;
            case 3: lib.saveToFile(filename); break;
            case 4: lib.loadFromFile(filename); break;
            case 0: cout << "До побачення!\n"; break;
            default: cout << "Невірний вибір!\n"; break;
        }
    } while (choice != 0);

    return 0;
}