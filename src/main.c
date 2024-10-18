#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>

typedef struct {
    char name[50];
    char email[50];
    char mobile[10];
    char movie_selected[50];
    char row;
    int col;
} Details;

sqlite3 *db;

// Function to open the database
void openDatabase() {
    if (sqlite3_open("cinema_booking.db", &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
}

// Function to create tables
void createTables() {
    const char *sql_users = "CREATE TABLE IF NOT EXISTS Users ("
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "Name TEXT NOT NULL, "
                            "Email TEXT NOT NULL, "
                            "Mobile TEXT NOT NULL);";
    
    const char *sql_bookings = "CREATE TABLE IF NOT EXISTS Bookings ("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                "User ID INTEGER, "
                                "Movie TEXT, "
                                "Row CHAR, "
                                "Column INTEGER, "
                                "FOREIGN KEY(UserID) REFERENCES Users(ID));";
    
    char *errMsg;
    if (sqlite3_exec(db, sql_users, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    if (sqlite3_exec(db, sql_bookings, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

// Function to insert user details into the database
void insertUser (Details *user) {
    char *errMsg;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Users (Name, Email, Mobile) VALUES ('%s', '%s', '%s');",
             user->name, user->email, user->mobile);
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

// Function to book a movie
void bookMovie(Details *user) {
    // Fetch the last inserted user ID
    int userId = sqlite3_last_insert_rowid(db);
    
    char *errMsg;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Bookings (User ID, Movie, Row, Column) VALUES (%d, '%s', '%c', %d);",
             userId, user->movie_selected, user->row, user->col);
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

// Function to display user details
void showDetails() {
    const char *sql = "SELECT * FROM Users;";
    sqlite3_stmt *stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("ID: %d, Name: %s, Email: %s, Mobile: %s\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_text(stmt, 3));
    }
    sqlite3_finalize(stmt);
}

// Function to print the menu
void printMenu() {
    printf("\033[1;36m");
    printf("   ╔════════════════════════════════════════════════════════════╗\n");
    printf("   ║                     🎬 BOOK YOUR SHOW 🎬                  ║\n");
    printf("   ║                                                            ║\n");
    printf("   ║  Please select an option from below:                       ║\n");
    printf("   ║  Please select an option from below:                       ║\n");
    printf("   ║                                                            ║\n");
    printf("   ║    (1) Enter Details                                       ║\n");
    printf("   ║    (2) Show Details                                        ║\n");
    printf("   ║    (3) Book Movies                                         ║\n");
    printf("   ║    (4) Generate Bill                                       ║\n");
    printf("   ║    (5) Exit                                                ║\n");
    printf("   ║                                                            ║\n");
    printf("   ╚════════════════════════════════════════════════════════════╝\n");
    printf("   > ");
    printf("\033[0m");
}

void InputDetails() {
    Details user;
    printf("   >>> Enter your name: ");
    scanf(" %[^\n]", user.name);
    printf("   >>> Enter your email address: ");
    scanf("%s", user.email);
    printf("   >>> Enter mobile number: ");
    scanf("%s", user.mobile);

    // Insert user details into the database
    insertUser (&user);
}

void Book() {
    char search[50];
    printf("   >>> Enter your first or last name: ");
    scanf("%s", search);

    // Here we would typically search for the user in the database
    // For simplicity, we are assuming the user exists and we will book for them
    Details user;
    // Assume user details are filled in for booking
    printf("   Which Movie would you like to watch:\n");
    printf("   \t(1) Dune 2\n");
    printf("   \t(2) Transformers One\n");
    printf("   \t(3) Oppenheimer\n");
    printf("   \t(4) Inception\n");
    printf("   \t(5) Tenet\n");
    printf("   >>> ");
    int movie_choice;
    scanf("%d", &movie_choice);

    // Set the movie name based on choice
    switch (movie_choice) {
        case 1: strcpy(user.movie_selected, "Dune 2"); break;
        case 2: strcpy(user.movie_selected, "Transformers One"); break;
        case 3: strcpy(user.movie_selected, "Oppenheimer"); break;
        case 4: strcpy(user.movie_selected, "Inception"); break;
        case 5: strcpy(user.movie_selected, "Tenet"); break;
        default: printf("Invalid choice!\n"); return;
    }

    // Get seat selection
    printf("   >>> Enter the row you would like (A-J): ");
    scanf(" %c", &user.row);
    printf("   >>> Enter the seat number you would like (1-15): ");
    scanf("%d", &user.col);

    // Book the movie
    bookMovie(&user);
    printf("   Movie booked successfully!\n");
}

void GenerateBill() {
    char search[50];
    printf("   >>> Enter first or last name: ");
    scanf("%s", search);
    
    // Here we would typically fetch user details from the database
    // For simplicity, we're not implementing the fetching logic from the database
    
    // Assuming we have found the user, we would display the bill
    printf("\033[0;31m");
    printf("\n\n\t\t   *************************************\n");
    printf("\t\t     * Name : %s\n", search); // Placeholder for actual name
    printf("\t\t     * Movie Selected: %s\n", "Dune 2"); // Placeholder
    printf("\t\t     * Seat: %c-%d\n", 'A', 1); // Placeholder
    printf("\t\t     * Price: $200\n"); // Placeholder based on seat
    printf("\t\t   *************************************\n\n");
    printf("\033[0m");
}

int main() {
    openDatabase();
    createTables();

    int flag = 0;
    while (flag != 1) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                InputDetails();
                break;
            case 2:
                showDetails();
                break;
            case 3:
                Book();
                break;
            case 4:
                GenerateBill();
                break;
            case 5:
                flag = 1;
                break;
            default:
                printf("Invalid entry!!!\n");
                break;
        }
    }

    sqlite3_close(db); // Close the database connection
    return 0;
}