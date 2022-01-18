#include <bits/stdc++.h>
using namespace std;

int counter = 0; //count the number of songs
string s, artist, g, line; //declaring  the strings
struct MusicPlayer //declaring the structure
{
    string song;
    string artist_name;
    string genre;
    struct MusicPlayer *next;
    struct MusicPlayer *prev;
    MusicPlayer() //constructor
    {
        song = "";
        artist_name = "";
        genre = "";
        next = prev = NULL;
    }
};
typedef struct MusicPlayer *node;
node Insert(node head, node newnode) //function to add new node to the linked list
{
    node a;
    if (head == NULL)
    {
        head = a = newnode;
    }
    else
    {
        a = head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        a->next = newnode;
        newnode->prev = a;
        newnode->next = NULL;
    }
    return head;
}
int check_presence(node a)
{
    char found = 'n';
    ifstream fin("Fav.txt",ios::in);
    if(!fin){
        cout<<"Can't open"<<endl;
        }
    while(fin.eof()==0)
    {
        getline(fin, line);
        stringstream ss(line);
        getline(ss, s, '|');
        getline(ss, artist, '|');
        getline(ss, g);
        if(a->song==s){found='y';}
    }
    fin.close();
    if(found=='y'){return 1;}
    return 0;
}
node load_data(node head, string songtype) //function to load the particular genre songs into a linked list
{
    ifstream fin("list.txt", ios::in);

    if (!fin)
    {
        cout << "file not found" << endl;
    }
    while (fin.eof() == 0)
    {
        node one = new MusicPlayer();
        getline(fin, line);
        stringstream ss(line);
        getline(ss, s, '|');
        getline(ss, artist, '|');
        getline(ss, g);
        if (g == songtype)
        {
            one->song = s;
            one->artist_name = artist;
            one->genre = g;
            head = Insert(head, one);
            counter++;
        }
    }
    fin.close();
    return head;
}
node load_fav(node head) //function to load the favourite songs into a linked list
{
    ifstream fin("Fav.txt", ios::in);

    if (!fin)
    {
        cout << "file not found" << endl;
        return head;
    }
    while (fin.eof() == 0)
    {
        node one = new MusicPlayer();
        getline(fin, line);
        stringstream ss(line);
        getline(ss, s,'|');
        getline(ss, artist,'|');
        getline(ss, g);
        one->song = s;
        one->artist_name = artist;
        one->genre = g;
        head = Insert(head, one);
        counter++;
    }
    fin.close();
    return head;
}

void print_data(node head) //function to print all the data of linked list
{
    node a;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    a = head;
    while (a!= NULL)
    {
        cout << "Song name - " << a->song << endl;
        cout << "Singer name - " << a->artist_name << endl;
        cout << "Genre - " << a->genre << endl;
        cout << endl;
        a = a->next;
    }
}
void print_the_one(node one) //function to print a node in particular format
{
    cout<<"----------------------------------------------------"<<endl;
    cout << " \tSong name - " << one->song << endl;
    cout << " \tSinger name - " << one->artist_name << endl;
    cout << " \tGenre - " << one->genre << endl;
    cout<<"----------------------------------------------------"<<endl;
    cout << endl;
}

node search(node head,string name) //function to search a song and play it
{
    cout<<"Passed value of string: "<<name<<endl;
    node a;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    a = head;
    while (a->song!=name)
    {
        if(a->next==NULL){
            cout<<"Song not found :( "<<endl;
            return head;
            }
        a = a->next;
    }
    cout<<"Song found"<<endl;
    cout<<"Currently Playing...."<<endl;
    print_the_one(a);
    //if(found==0){cout<<"Song not found :( "<<endl;}
    return head;
}

void fav(node one) //function to add song to favourites
{
    ofstream fout("Fav.txt",ios::app);
    fout<<one->song<<"|"<<one->artist_name<<"|"<<one->genre<<endl;
    fout.close();
}

void remove_song(string song_match) //function to remove song from favourites
{
    //cout<<"present"<<endl;
    fstream fio("Fav.txt",ios::in);
    ofstream fout("temp.txt",ios::out);
    while(!fio.eof())
    {
        getline(fio, line);
        stringstream ss(line);
        getline(ss, s,'|');
        getline(ss, artist,'|');
        getline(ss, g);
        if(song_match.compare(s)==0)
        {
            ;
        }
        else{
            fout<<s<<"|"<<artist<<"|"<<g<<endl;
        }
    }
    fio.close();
    fout.close();
    remove("Fav.txt");
    rename("temp.txt","Fav.txt");
}

void delay(int milliseconds) //delay function to create effect
{
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milliseconds)
        ;
}

void play(node current) //recursive play function to play songs of a particular genre
{
    int choice,flag;
    node one = current;

    if (one->prev == NULL) //check for the first node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"This is the first song in the list"<<endl;
        cout<<"\nEnter 9 to add song in favorites";
        cout << "\nEnter 1 For Next ";
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else if (one->next == NULL) //check for the last node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"You have reached end of list"<<endl;
         cout<<"\nEnter 9 to add song in favorites";
        cout << "\nEnter 2 For Previous Songs ";
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else //for the nodes in between
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"\nEnter 9 to add song in favorites";
        cout << "\nEnter 1 For Next";
        cout << "\nEnter 2 For Previous Song";
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        one = one->next;
        play(one); //recursive calling
    }
    if (choice == 2)
    {
        one = one->prev;
        play(one); //recursive calling
    }
    if(choice == 9)
    {
        flag = check_presence(one);
        if(flag==0){
            fav(one);
            cout<<"\nSong added successfully...!!\n"<<endl;
        }
        else{
            cout<<"This song is already exists in favourites"<<endl;
        }
        //fav(one);
        //cout<<"Added successfully"<<endl;
        play(one);
    }
    if(choice!=1||choice!=2||choice!=9){
        return;
    }
}

void play1(node current) //recursive play function to play favourite songs
{
    int choice,flag;
    node one = current;
    node a;
    if (one->prev == NULL) //check for the first node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"This is the first song in the list"<<endl;
        cout << "\nEnter 1 For Next ";
        cout<<"\nEnter 7 to remove song from favorites"<<endl;
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else if (one->next == NULL) //check for the last node
    {
        cout << "Currently playing...." << endl;

        print_the_one(one);
        cout<<"You have reached end of list"<<endl;
        cout << "\nEnter 2 For Previous Songs ";
        cout<<"\nEnter 7 to remove song from favorites"<<endl;
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else //for the nodes in between
    {
        cout << "Currently playing...." << endl;

        print_the_one(one);
        cout << "\nEnter 1 For Next";
        cout << "\nEnter 2 For Previous Song";
        cout<<"\nEnter 7 to remove song from favorites"<<endl;
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        one = one->next;
        play1(one); //recursive calling
    }
    if (choice == 2)
    {
        one = one->prev;
        play1(one); //recursive calling
    }
    if(choice==7)
    {
       
        remove_song(one->song);
        cout<<"Removal currently under progress"<<endl;
        play1(one->next);
    }
    if(choice!=1||choice!=2||choice!=7){
        return;
    }
}

void free_data(node head) //funncton to free the memory occupied by linked list
{
    node current = head;
    while(current!=NULL)
    {
        node next = current->next;
        free(current);
        current = next;
    }
}
int main()
{
    int choose,ch;
    node head1 = NULL; //for main songs
    node head2 = NULL; //for playlist
    //add to playlist using files
    string song_type;
    string name;
    cout << "\n*****MUSIC PLAYER****" << endl;
    cout << "Enter the genre:" << endl;
    cout << " (1) Romantic\n (2) Sad\n (3) Dance Party\n (4) Rap and Bollywood\n (5) Favorite songs\n (0) Exit the program\n Your choice: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        counter = 0;
        song_type = "Romantic";
        head1 = load_data(head1, song_type); //forming the linked list of Romantic songs
        cout << "\nSearching Romantic songs..........\n"
             << endl;
        delay(3000); //delay to create effect
        cout << "\nTotal Number of Romantic songs are: " << counter << endl;
        do{
        cout<<"\n[1] See all songs\n[2] Play\n[3] Search a song\n[0] to exit\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data(head1); //show all Romantic songs
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1); //call to recursive function play song
                break;
            case 3:
                cout << "Enter the name of song:"<<endl;
                cin.ignore(); //resetting the buffer
                getline(cin,name);
                cout<<"\n"<<name<<endl;
                head1 = search(head1,name); //search function 
                break;
            case 0:
                cout<<"Thank you for using the program"<<endl;
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        }while(ch!=0);
        free_data(head1);
        break;
    case 2:
        counter = 0;
        song_type = "Sad";
        head1 = load_data(head1, song_type); //forming the linked list of Sad songs
        cout << "\nSearching Sad songs..........\n"
             << endl;
        delay(3000);
        cout << "\nTotal Number of Romantic songs are: " << counter << endl;
        do{
        cout<<"\n[1] See all songs\n[2] Play\n[3] Search a song\n[0] to exit\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data(head1); //show all Sad songs
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1); //call to recursive function play song
                break;
            case 3:
                cout << "Enter the name of song:"<<endl;
                cin.ignore(); //resetting the buffer
                getline(cin,name);
                //cin.getline(name,50);
                cout<<"\n"<<name<<endl;
                head1 = search(head1,name); //search function
                break;
            case 0:
                cout<<"Thank you for using the program"<<endl;
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        }while(ch!=0);
        free_data(head1);
        break;
    case 3:
        counter = 0;
        song_type = "Dance Party";
        head1 = load_data(head1, song_type); //forming the linked list of Dance Party songs
        cout << "\nSearching Dance Party songs..........\n"

             << endl;
        //delay
        delay(3000);
        cout << "\nTotal Number of Dance Party songs are: " << counter << endl;
        do{
        cout<<"\n[1] See all songs\n[2] Play\n[3] Search a song\n[0] to exit\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data(head1); //show all Dance Party songs
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1); //call to recursive function play song
                break;
            case 3:
                cout << "Enter the name of song:"<<endl;
                cin.ignore(); //resetting the buffer
                getline(cin,name);
                //cin.getline(name,50);
                cout<<"\n"<<name<<endl;
                head1 = search(head1,name); //search function
                break;
            case 0:
                cout << "Thank you for using the program" << endl;
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        }while(ch!=0);
        free_data(head1);
        break;
    case 4:
        counter = 0;
        song_type = "Rap and Bollywood";
        head1 = load_data(head1, song_type); //forming the linked list of Rap and Bollywood songs
        cout << "\nSearching Rap and Bollywood songs..........\n"
             << endl;
        delay(3000);
        cout << "\nTotal Number of Rap and Bollywood songs are: " << counter << endl;
        do{
        cout<<"\n[1] See all songs\n[2] Play\n[3] Search a song\n[0] to exit\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data(head1); //show all Rap and Bollywood songs
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1); //call to recursive function play song
                break;
            case 3:
                cout << "Enter the name of song:"<<endl;
                cin.ignore(); //resetting the buffer
                getline(cin,name);
                //cin.getline(name,50);
                cout<<"\n"<<name<<endl;
                head1 = search(head1,name); //search function
                break;
            case 0:
                cout << "Thank you for using the program" << endl;
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        }while(ch!=0);
        free_data(head1);
        break;
    case 5:
        counter = 0;
        head2 = load_fav(head2); //forming the linked list of favourite songs
        if(counter==0){break;}
        cout << "\nSearching Your favorite songs..........\n"
             << endl;
        delay(3000);
        cout << "\nTotal Number of Favorite songs are: "<< counter-1 << endl;
        do{
        cout<<"\n[1] See all songs\n[2] Play\n[3] Search a song\n[0] to exit\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all favorite Songs"<<endl;
                print_data(head2); //show all favourite songs
                break;
            case 2:
                cout<<"First favorite song coming right up"<<endl;
                delay(2000);
                play1(head2); //call to recursive function play1 song
                break;
            case 3:
                cout << "Enter the name of song:"<<endl;
                cin.ignore(); //resetting the buffer
                getline(cin,name);
                //cin.getline(name,50);
                cout<<"\n"<<name<<endl;
                head1 = search(head2,name); //search function
                break;
            case 0:
                cout<<"Thank you for using"<<endl;
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        }while(ch!=0);
        free_data(head2);
        break;
    case 0:
        cout << "Thank you for using the program" << endl;
        exit(1);
        break;
    default:
        cout << "Wrong option selected, refer menu and try again" << endl;
        exit(1);
    }
    return 0;
}
