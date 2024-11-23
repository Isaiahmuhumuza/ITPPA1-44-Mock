#include <iostream>
#include <string>
#include <iterator>
#include <vector> 
#include <fstream>
using namespace std;

class Movie {
public:
	string title;
	string director;
	string genre;
	string availability;

	// A method to input movie details from the user
	void addMovie() {
		cout << "Enter movie title: " << endl;
		getline(cin, title);
		cout << "Enter director: " << endl;
		getline(cin, director);
		cout << "Enter genre: " << endl;
		getline(cin, genre);
		cout << "Is the movie available? (yes/no): " << endl;
		cin >> availability;
		cin.ignore(); // Clear the newline character from input buffer

		cout << "Movie added successfully" << endl;
	}
	void displayDetails() const {
		cout << "\nMovie Name: " << title;
		cout << "\nMovie Name: " << director;
		cout << "\nGenre: " << genre;
		cout << "\nAvailability: " << availability << "\n";
	}
};

void searchMovie(const vector<Movie>& movies) {
	string titleSearch;
	cout << "Enter movie title to search: " << endl;
	getline(cin, titleSearch);

	auto search = find_if(movies.begin(), movies.end(), [&titleSearch](const Movie& movie) {
		return movie.title == titleSearch;
		});

	if (search != movies.end()) { // If a match is found
		cout << "\nMovie Found: " << endl;;
		search->displayDetails(); // Display the movie's details
	}
	else {
		cout << "\nMovie not found." << endl;
	}

}

void showAllMovies(const vector<Movie>& movies) {
	if (movies.empty()) {
		cout << "\nNo movies to display.\n";
		return;
	}

	cout << "\nList of All Movies:\n";
	for (size_t i = 0; i < movies.size(); ++i) {
		cout << "\nMovie: " << (i + 1) << endl;
		movies[i].displayDetails();
	}
}

int main() {
	vector<Movie> movies;
	bool active = true;
	do {
		int i = 0;
		int choice;
		cout << "\nMovie Rental Management Menu: " << endl;
		cout << "1. Add movie" << endl;
		cout << "2. Search movie" << endl;
		cout << "3. View all movies" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1: {
			Movie movie;
			movie.addMovie();
			movies.push_back(movie);
			break;
		}
		case 2: {
			searchMovie(movies);
			break;
		}
		case 3: {
			showAllMovies(movies);
			break;
		}
		case 4: {
			active = false;
			cout << "Thank you for using the program. Goodbye!" << endl;
			break;
		}
		}
	} while (active);

}