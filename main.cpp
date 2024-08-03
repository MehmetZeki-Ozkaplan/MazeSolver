#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <thread>
#include <chrono>

// Constants: Map dimensions
#define YUKSEKLIK 20
#define GENISLIK 50

using namespace std;
using namespace std::chrono;

// Enum representing movement directions
enum Yon {
    ASAGI, SOL, YUKARI, SAG
};

// Map array; each row is allocated WIDTH + 1 characters
char harita[YUKSEKLIK][GENISLIK + 1];

// Function to read the map file and determine the entry and exit points
void haritaOku(const string& dosyaAdi, int &baslangicX, int &baslangicY, int &cikisX, int &cikisY) {
    ifstream fp(dosyaAdi); // Open the file
    if (!fp) { // Error message if the file cannot be opened
        cerr << "Dosya acilamadi" << endl;
        exit(EXIT_FAILURE);
    }

    // Read the map from the file
    for (int i = 0; i < YUKSEKLIK; i++) {
        fp.getline(harita[i], GENISLIK + 1); // Read rows and assign them to the map array
    }
    fp.close(); // Close the file
    cout << "Harita basariyla okundu." << endl;

    // Flag to track if the entry point is found
    bool girisBulundu = false;
    // Search for empty spaces (entry) in the first and last rows
    for (int j = 0; j < GENISLIK; j++) {
        if (harita[0][j] == ' ') { // Empty space in the first row
            baslangicX = 0;
            baslangicY = j;
            girisBulundu = true;
            break;
        }
        if (harita[YUKSEKLIK - 1][j] == ' ') { // Empty space in the last row
            baslangicX = YUKSEKLIK - 1;
            baslangicY = j;
            girisBulundu = true;
            break;
        }
    }
    if (!girisBulundu) { // If no entry point is found in the first and last rows
        // Search for empty spaces (entry) in the first and last columns
        for (int i = 0; i < YUKSEKLIK; i++) {
            if (harita[i][0] == ' ') { // Empty space in the first column
                baslangicX = i;
                baslangicY = 0;
                girisBulundu = true;
                break;
            }
            if (harita[i][GENISLIK - 1] == ' ') { // Empty space in the last column
                baslangicX = i;
                baslangicY = GENISLIK - 1;
                girisBulundu = true;
                break;
            }
        }
    }

    // Flag to track if the exit point is found
    bool cikisBulundu = false;
    // Search for empty spaces (exit) in the first and last rows
    for (int j = 0; j < GENISLIK; j++) {
        if (harita[0][j] == ' ' && (0 != baslangicX || j != baslangicY)) { // Empty space in the first row and not the same as entry point
            cikisX = 0;
            cikisY = j;
            cikisBulundu = true;
            break;
        }
        if (harita[YUKSEKLIK - 1][j] == ' ' && (YUKSEKLIK - 1 != baslangicX || j != baslangicY)) { // Empty space in the last row and not the same as entry point
            cikisX = YUKSEKLIK - 1;
            cikisY = j;
            cikisBulundu = true;
            break;
        }
    }
    if (!cikisBulundu) { // If no exit point is found in the first and last rows
        // Search for empty spaces (exit) in the first and last columns
        for (int i = 0; i < YUKSEKLIK; i++) {
            if (harita[i][0] == ' ' && (i != baslangicX || 0 != baslangicY)) { // Empty space in the first column and not the same as entry point
                cikisX = i;
                cikisY = 0;
                cikisBulundu = true;
                break;
            }
            if (harita[i][GENISLIK - 1] == ' ' && (i != baslangicX || GENISLIK - 1 != baslangicY)) { // Empty space in the last column and not the same as entry point
                cikisX = i;
                cikisY = GENISLIK - 1;
                cikisBulundu = true;
                break;
            }
        }
    }

    // Print the entry and exit points to the screen
    cout << "Baslangic noktasi: (" << baslangicX << ", " << baslangicY << ")" << endl;
    cout << "Cikis noktasi: (" << cikisX << ", " << cikisY << ")" << endl;
}

// Node structure: x, y coordinates, and movement direction
struct Dugum {
    int x, y;
    Yon yon;
};

// Function to check if the given (x, y) coordinates are passable
bool gezilebilirMi(int x, int y) {
    return x >= 0 && x < YUKSEKLIK && y >= 0 && y < GENISLIK && harita[x][y] == ' ';
}

// Function to change the (x, y) coordinates according to the given direction
bool yonDegistir(int &x, int &y, Yon yon) {
    switch (yon) {
        case ASAGI: x++; break; // Move down
        case SOL: y--; break; // Move left
        case YUKARI: x--; break; // Move up
        case SAG: y++; break; // Move right
        default: return false; // Invalid direction
    }
    return true;
}

// Function to clear the screen (for Windows and Unix-based systems)
void temizle() {
    #ifdef _WIN32
        system("cls"); // Clear the screen on Windows
    #else
        system("clear"); // Clear the screen on Unix-based systems
    #endif
}

// Function to print the map to the screen and add a short delay between steps
void haritayiYazdir() {
    temizle(); // Clear the screen
    for (int i = 0; i < YUKSEKLIK; i++) { // Print each row
        for (int j = 0; j < GENISLIK; j++) {
            cout << harita[i][j]; // Print each cell
        }
        cout << endl; // End of row
    }
    cout << "----------------------------------------------" << endl;
    this_thread::sleep_for(milliseconds(200)); // Wait 200 ms between steps
}

// Solution finding: Using depth-first search (DFS) algorithm
bool cozumBul(int baslangicX, int baslangicY, int cikisX, int cikisY) {
    stack<Dugum> yigin; // Create a stack of nodes
    Dugum baslangic = {baslangicX, baslangicY, ASAGI}; // Create the start node
    yigin.push(baslangic); // Push the start node onto the stack

    while (!yigin.empty()) { // Continue until the stack is empty
        Dugum suAnki = yigin.top(); // Get the top node from the stack
        yigin.pop(); // Remove the node from the stack

        // Print the current position to the screen
        cout << "Su anki konum: (" << suAnki.x << ", " << suAnki.y << ")" << endl;

        // Check if the exit point is reached
        if (suAnki.x == cikisX && suAnki.y == cikisY) {
            harita[suAnki.x][suAnki.y] = ' ? '; // Mark the exit point
            haritayiYazdir(); // Print the final state to the screen
            return true; // Solution found
        }

        // Check neighboring nodes
        for (int i = 0; i < 4; i++) { // Check 4 directions (down, left, up, right)
            int yeniX = suAnki.x, yeniY = suAnki.y;
            yonDegistir(yeniX, yeniY, static_cast<Yon>(i)); // Calculate new coordinates

            if (gezilebilirMi(yeniX, yeniY)) { // Are the new coordinates passable?
                harita[yeniX][yeniY] = '^'; // Mark the visited place
                haritayiYazdir(); // Print the step to the screen
                Dugum yeniDugum = {yeniX, yeniY, static_cast<Yon>(i)}; // Create a new node
                yigin.push(yeniDugum); // Push the new node onto the stack
            } else {
                cout << "Gezilemeyen nokta: (" << yeniX << ", " << yeniY << ")" << endl;
            }
        }
    }
    return false; // Solution not found
}

// Main function
int main() {
    int baslangicX, baslangicY, cikisX, cikisY;
    haritaOku("Map.txt", baslangicX, baslangicY, cikisX, cikisY); // Read the map and determine the entry and exit points

    // Find the solution and print the result to the screen
    if (cozumBul(baslangicX, baslangicY, cikisX, cikisY)) {
        cout << "Cozum bulundu!" << endl; // Message if solution is found
    } else {
        cout << "Cozum bulunamadi." << endl; // Message if solution is not found
    }

    return 0; // Exit the program successfully
}
