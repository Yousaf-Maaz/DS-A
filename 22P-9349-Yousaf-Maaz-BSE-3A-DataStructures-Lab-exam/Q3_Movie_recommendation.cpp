#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int movieID;
	string title;
	string genre;
	int ratings;
	Node *left;
	Node *right;

	// define the constructor
	Node()
	{

		left = nullptr;
		right = nullptr;
	}
};

class MovieRecommendationSystem
{
private:
	Node *root;

public:
	// define the constructor
	MovieRecommendationSystem()
	{
		root = nullptr;
	}

	// Insert a movie into the BST
	Node *insertMovie(Node *root, int movieID, string title, string genre, int ratings)
	{
		if (root == nullptr)
		{
			
			return new Node(movieID, title, genre, ratings, root->left, root->right);
		}
		else if (movieID < root->movieID)
		{
			insertMovie(root->left, movieID, title, genre, ratings);
		}
		else
		{
			insertMovie(root->right, movieID, title, genre, ratings);
		}

		return Node;
	}

	// Recommend movies of a given genre
	void recommendMoviesByGenre(string genre)
	{
		if (genre == root->genre)
		{
			cout << root->genre;
		}
		else
		{
			cout << "sorry recommendation is not Availible" << endl;
		}
	}

	// Delete a movie by ID

	Node *deleteMovieByID(Node *root, int movieID)
	{
		if (root == nullptr)
		{
			return root;
		}

		if (movieID < root->movieID)
		{
			root->left = deleteMovieByID(root->left, movieID);
		}
		else if (movieID > root->movieID)
		{
			root->right = deleteMovieByID(root->right, movieID);
		}
		else
		{

			if (root->left == nullptr)
			{
				Node *temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Node *temp = root->left;
				delete root;
				return temp;
			}

			Node *temp;

			root->movieID = temp->movieID;

			root->right = deleteMovieByID(root->right, temp->movieID);
		}

		return root;
	}

	// swap need for sort
	void swap(MovieRecommendationSystem *a, MovieRecommendationSystem *b)
	{
		MovieRecommendationSystem temp = *a;
		*a = *b;
		*b = temp;
	}

	void Sort_Algo(int size = 5, int arr[rating])
	{

		for (int i = 0; i < 4; i++)
		{
			int check_m = i;
			for (int j = i + 1; j < rating; j++)
			{

				if (arr[j] < arr[check_m])
					check_m = j;
			}
			//will do swap here for sort the array.

			// i try on this selection sort but ig i  do wrong
		}
	}

	void displayMovies(Node root)
	{
		cout << root;
		displayMovies(root->left);
		displayMovies(root->right);
	}
};

int main()
{
	MovieRecommendationSystem engine;
	int choice;
	while (true)
	{
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Ratings\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int movieID;
			string title, genre;
			double ratings;
			cout << "Enter Movie ID: ";
			cin >> movieID;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Movie Title: ";
			getline(cin, title);
			cout << "Enter Movie Genre: ";
			getline(cin, genre);
			cout << "Enter Ratings: ";
			cin >> ratings;

			engine.insertMovie(root, movieID, title, genre, ratings);
			cout << "Movie added successfully!" << endl;
			break;
		}
		case 2:
		{
			int deleteID;
			cout << "Enter Movie ID to delete: ";
			cin >> deleteID;
			root = deleteMovieByID(root, deleteID);
			cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
			break;
		}
		case 3:
		{
			string genre;
			cout << "Enter your favorite genre: ";
			cin.ignore(); // Clear newline character from the buffer
			getline(cin, genre);
			recommendMoviesByGenre(genre);
			break;
		}
		case 4:
			displayMovies();
			break;
		case 5:
			cout << "Exiting the program." << endl;
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
	return 0;
}
