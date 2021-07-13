#include<bits/stdc++.h>

using namespace std;


//Function Prototypes:
const int ARRAY_SIZE = 100;
void addAlbum();
void displayAlbums();
void searchAlbum ();
bool deleteAlbum(string deletedAlbum, bool success);



int main()
{
    //Declare variables
    ifstream fin;
    ofstream fout;
    bool success;
    string deletedAlbum;
    string albumTitle;
    int choice = 0;

    //Main Menu of Program:
    cout << "Welcome to the music storage program."<< endl;
    cout << "Here you can keep track of your favorite albums, artists and release years." << endl;
    cout << "What would you like to do?" << endl;

    do
    {
        cout << "1: Display Favorite Albums" << endl;
        cout << "2: Add an Album" << endl;
        cout << "3: Remove an Album" << endl;
        cout << "4: Search for Album" << endl;
        cout << "5: Exit" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore (100,'\n');
        if(choice == 1)
            displayAlbums();
            //Displays albums on screen, to the user.
        if(choice == 2)
            addAlbum();
            //Adds an album that the user may enter into the program.
        if(choice == 3)
            //Asks user to enter the title of the album they wish to delete.

        {
            cout << "Enter an album to remove: " << endl;
            getline (cin,deletedAlbum);
            success = deleteAlbum(deletedAlbum, success);
            if(success == true)
                cout << "Album deleted." << endl;
            else
            {
                cout << endl;
                cout << "Could not delete. I guess you can't get that one song out of your head..." << endl;
            }
        }
        if (choice == 4)
            searchAlbum ();
            //Searches file text for album

    } while(choice != 5);
    return 0;
}



//Name: displayAlbums
//Description: Displays on screen the contents of "myFavoriteAlbums.txt".
//Precondition: Text file must have been created ("myFavoriteAlbums.txt"), complete with variables such as year of release, album artist and title.

void displayAlbums()
{
    string title;
    string artist;
    string yearReleased;
    ifstream fin;
    fin.open("myFavoriteAlbums.txt");
    if(fin.is_open())
    {
        while(isalnum(fin.peek()))
        //Display of albums to user
        {
            getline(fin, title);
            getline(fin, artist);
            fin >> yearReleased;
            fin.ignore(5, '\n');
            cout << title << " by " << artist << " released in " << yearReleased << "." << endl;
        }
        fin.close();
    }
    else //if the file open is unsuccessful
    {
        cout << "File cannot be opened." << endl;
    }
}



//Name: addAlbum
//Description: Adds user-inputted album to "myFavoriteAlbums.txt".
//Precondition: Needs "myFavoriteAlbums.txt" to be opened for append.
//Precondition: New entry should have been added to "myFavoriteAlbums.txt".

void addAlbum ()
{
    ofstream fout;
    ifstream fin;
    string albumTitle;
    string albumArtist;
    int yearOfRelease;
    fout.open("myFavoriteAlbums.txt", ios::app);
    if(fout.is_open())
    {
        cout << "Enter the title of the album: ";
        getline(cin, albumTitle);
        fout << albumTitle << endl;
        cout << "Enter the artist who crafted the gem of an album: ";
        getline(cin, albumArtist);
        fout << albumArtist << endl;
        cout << "Enter the year the album was released: ";
        cin >> yearOfRelease;
        cin.ignore(100, '\n');
        fout << yearOfRelease << endl;
        fout.close();
        cout << endl;
    }
    else
        {
            cout << "We can't input that album. You either entered in Justin Bieber, or there is an error." << endl;
        }
    (fin.close());
return;
}



//Name: deleteAlbum
//Description: Deletes album data from program.
//Input:  string deletedAlbum
//        bool success - determines if deleted successfully
//Output: bool success - determines if deleted successfully
//Precondition: The user selected option 3 and chose to delete an album
//Postcondition: One of the records in "myFavoriteAlbums.txt" will have been deleted.

bool deleteAlbum (string deletedAlbum, bool success)
{
    ifstream fin;
    ofstream fout;
    success = false;
    const int ARRAY_SIZE = 100;
    string albumTitle [ARRAY_SIZE] = {" "};
    string albumArtist [ARRAY_SIZE] = {" "};
    string yearOfRelease [ARRAY_SIZE] = {" "};
    int counter = 0;
    string title, artist;
    string yearReleased;
    fin.open("myFavoriteAlbums.txt");

    //Open file and extract contents
    if(fin.is_open())
    {
        while(getline (fin, title) && counter < ARRAY_SIZE)
        {
            getline(fin, artist);
            getline (fin, yearReleased);
            if(title != deletedAlbum)
            {
                albumTitle [counter] = title;
                albumArtist[counter] = artist;
                yearOfRelease[counter] = yearReleased;
                counter++;
            }
            else
            {
                success = true;
            }
        }
        fin.close();
    }
    else
        cout << "File cannot be read." << endl;
    fout.open("myFavoriteAlbums.txt"); //Overwrites data in file and program.
    if(fout.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            fout << albumTitle[i] << endl;
            fout << albumArtist[i] << endl;
            fout << yearOfRelease[i] << endl;
        }
        fout.close();
    }
    else
        cout << "Cannot read file!" << endl;
    return success;
}


void searchAlbum (){

    string search = " ";
    int count = 0;
    string line;
	ifstream fin;

    fin.open ("myFavoriteAlbums.txt");
    cout << "Type the name of the album you want to search for: " << endl;
    cin>>line;

    if (fin.is_open())
    {
        while (isalnum(fin.peek()))
        {
            getline(fin, line);
            if (count == line.find(search, 0)!= string:: npos)
            {
                cout << "Found " << search << endl;
            }
        }
        fin.close();
    }
    else
    {
        cout << "Could not open file." << endl;
    }
    return;
}
