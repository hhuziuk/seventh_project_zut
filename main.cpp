#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
  string Nazwisko;
  string Imie;
  int NrAlbumu;
  string Grupa;
  int Rok;

  friend ostream &operator<<(ostream &output, const Student &data) {
    output << "Nazwisko: " << data.Nazwisko << ", Imie: " << data.Imie
           << ", Nr albumu: " << data.NrAlbumu << ", Grupa: " << data.Grupa
           << ", Rok: " << data.Rok;
    return output;
  }

  friend ofstream &operator<<(ofstream &output, const Student &data) {
    output << data.Nazwisko << endl
           << data.Imie << endl
           << data.NrAlbumu << endl
           << data.Grupa << endl
           << data.Rok << endl;
    return output;
  }

  friend istream &operator>>(istream &input, Student &data) {
    cout << "Podaj nazwisko: ";
    input >> data.Nazwisko;
    cout << "Podaj imie: ";
    input >> data.Imie;
    cout << "Podaj numer albumu: ";
    input >> data.NrAlbumu;
    cout << "Podaj grupe: ";
    input >> data.Grupa;
    cout << "Podaj rok: ";
    input >> data.Rok;
    return input;
  }

  friend ifstream &operator>>(ifstream &input, Student &data) {
    input >> data.Nazwisko >> data.Imie >> data.NrAlbumu >> data.Grupa >>
        data.Rok;
    return input;
  }
};

int main() {
  vector<Student> students;
  Student student;

  ifstream file("students.txt");
  while (file >> student) {
    students.push_back(student);
  }
  file.close();

  ofstream outputFile("output.txt");
  for (const auto &s : students) {
    outputFile << s << endl;
  }
  outputFile.close();

  for_each(students.begin(), students.end(),
           [](const Student &s) { cout << s << endl; });

  int count = count_if(students.begin(), students.end(),
                       [](const Student &s) { return s.Rok == 3; });
  cout << "Liczba studentow 3 roku: " << count << endl;

  return 0;
}
