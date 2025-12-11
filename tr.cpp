#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <thread>
#include <algorithm>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void delay(void){
    Sleep(120);
}

void delay2(void){
    Sleep(90);
}

void delayy(void){
    int delayy;
    delayy = 1;
    while(delayy < 90000000){
        delayy++;
    }
}

void setConsoleColor(int background, int text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, background * 16 + text);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printLoadingBar() {
    setConsoleColor(6, 0);
    system("cls");

    gotoxy(30, 5);
    cout << "Nungguin yaaa...";
    gotoxy(30, 7);
    for (int i = 0; i < 60; ++i) {

        cout << char(219);
    }
    gotoxy(78, 9);
    cout << "Sabar sayang!";

    system("pause > nul");
    system("cls");
}

void headerMenuUtama() {
    gotoxy(30, 3);
    cout << "+========================================================+"; delay();
    gotoxy(30, 4);
    cout << "||                  MENU UTAMA BIOSKOP                  ||"; delay();
    gotoxy(30, 5);
    cout << "||                   KELOMPOK BIOSKOP                   ||"; delay();
    gotoxy(30, 6);
    cout << "+========================================================+"; delay();
}

void headeropsisalahMenuUtama() {
    gotoxy(30, 3);
    cout << "+========================================================+";
    gotoxy(30, 4);
    cout << "||                  MENU UTAMA BIOSKOP                  ||";
    gotoxy(30, 5);
    cout << "||                   KELOMPOK BIOSKOP                   ||";
    gotoxy(30, 6);
    cout << "+========================================================+";
}

void opsisalah() {
    gotoxy(35, 9);
        cout << "Menu Utama:";
        gotoxy(35, 10);
        cout << "1. Pesan Tiket";
        gotoxy(35, 11);
        cout << "2. Menu Admin";
        gotoxy(35, 12);
        cout << "3. Keluar";
        gotoxy(35, 13);
        cout << "Opsi Salah!";
}

void opsiadminsalah(){
    for (int i = 30; i <= 80; i++) {
            gotoxy(i, 3);
            cout << "*";
        }

        for (int i = 80; i >= 30; i--) {
            gotoxy(i, 7);
            cout << "*";
        }
        gotoxy(40, 4);
        cout << "CREATE, READ, UPDATE, DELETE";

        gotoxy(47, 6);
        cout << "TIKET BIOSKOP";

        gotoxy(38, 9);
        cout << "Menu 1. Tambah Tiket Bioskop";
        gotoxy(38, 10);
        cout << "Menu 2. Edit Tiket Bioskop";
        gotoxy(38, 11);
        cout << "Menu 3. Hapus Tiket Bioskop";
        gotoxy(38, 12);
        cout << "Menu 4. Lihat Tiket Bioskop";
        gotoxy(38, 13);
        cout << "Menu 5. Search Tiket Bioskop";
        gotoxy(38, 14);
        cout << "Menu 6. Keluar";
        gotoxy(38, 16);
        cout << "Opsi salah! ";
}

void opsisortirsalah(){
    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
    }

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 4);
        cout << "*";
    }

    gotoxy(33, 3);
    cout << "SORTING TIKET BIOSKOP";

    gotoxy(33, 6);
    cout << "Pilih metode sorting: ";
    gotoxy(33, 7);
    cout << "1. Ascending ";
    gotoxy(33, 8);
    cout << "2. Descending ";
    gotoxy(33, 9);
    cout << "Opsi salah! ";
}

void printTopLoadingBar() {
    for (int i = 30; i <= 80; i++) {
        gotoxy(i, 3);
        cout << "=";
        delayy();
    }
    gotoxy(30, 3);
    cout << "[";
    gotoxy(80, 3);
    cout << "]";
}

void printBottomLoadingBar() {
    for (int i = 80; i >= 30; i--) {
        gotoxy(i, 13);
        cout << "=";
        delayy();
    }
    gotoxy(30, 13);
    cout << "[";
    gotoxy(80, 13);
    cout << "]";
}

void printLeftLoadingBar() {
    for (int i = 4; i <= 12; i++) {
        gotoxy(30, i);
        cout << "|";
        delayy();
    }
}

void printRightLoadingBar() {
    for (int i = 12; i >= 4; i--) {
        gotoxy(80, i);
        cout << "|";
        delayy();
    }
}

void printLoadingUserAdmin() {


}

struct Tiket {
    int kode;
    string nama;
    string kategori;
    double diskon;
    double harga;
};

void tabel(const vector<Tiket>& tiket) {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    cout << endl << endl;

    cout << "╔════════╦═══════════════════════════════════╦═══════════════╦═══════════╦════════════════╗" << endl;
    cout << "║ KODE   ║ NAMA MENU                         ║ HARGA         ║ DISKON(%) ║ KATEGORI       ║" << endl;
    cout << "╠════════╬═══════════════════════════════════╬═══════════════╬═══════════╬════════════════╣" << endl;

    for (size_t i = 0; i < tiket.size(); ++i) {
        const auto& Tiket = tiket[i];
        cout << "║ " << setw(6) << Tiket.kode << " ║ "
             << setw(33) << left << Tiket.nama << " ║ "
             << "Rp." << setw(10) << right << Tiket.harga << " ║ "
             << setw(9) << right << Tiket.diskon << " ║ "
             << setw(14) << left << Tiket.kategori << " ║" << endl;

        if (i < tiket.size() - 1) {
            cout << "╠════════╬═══════════════════════════════════╬═══════════════╬═══════════╬════════════════╣" << endl;
        } else {
            cout << "╚════════╩═══════════════════════════════════╩═══════════════╩═══════════╩════════════════╝" << endl;
        }
    }

    cout << endl;
}

void printTableHeader() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    cout << endl << endl;

    setConsoleColor(0, 9);
    cout << "╔════════╦═══════════════════════════════════╦═══════════════╦═══════════╦════════════════╗" << endl;
    cout << "║ KODE   ║ NAMA MENU                         ║ HARGA         ║ DISKON(%) ║ KATEGORI       ║" << endl;
    cout << "╠════════╬═══════════════════════════════════╬═══════════════╬═══════════╬════════════════╣" << endl;

}

void printTableRow(const Tiket& t) {
    cout << "║ " << setw(3) << t.kode << "  ║ "
         << setw(33) << left << t.nama << " ║ "
         << "Rp." << setw(10) << right << t.harga << " ║ "
         << setw(9) << right << t.diskon << " ║ "
         << setw(14) << left << t.kategori << " ║ " << endl;
}

void tabel1(const Tiket& t) {
    system("cls");

    setConsoleColor(0, 9);
    printTableHeader();

    printTableRow(t);

    cout << "╚════════╩═══════════════════════════════════╩═══════════════╩═══════════╩════════════════╝" << endl;

    cout << endl;
}

void displayHeader(const string& header) {
    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
    }
    delay();

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 4);
        cout << "*";
    }
    delay();

    gotoxy(33, 3);
    cout << header;
    delay();
}

void tabelPesananTiketHeader() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 for proper character display on Windows
#endif

    cout << endl << endl;
    cout << "╔════════╦═══════════════════════════════════╦═══════════════╦═══════════╦════════════════╗" << endl;
    cout << "║ KODE   ║ NAMA MENU                         ║ HARGA         ║ DISKON(%) ║ KATEGORI       ║" << endl;
    cout << "╠════════╬═══════════════════════════════════╬═══════════════╬═══════════╬════════════════╣" << endl;
}

void tabelPesananTiketRow(const Tiket& t) {
    cout << "║ " << setw(3) << t.kode << "  ║ "
         << setw(33) << left << t.nama << " ║ "
         << "Rp." << setw(10) << right << t.harga << " ║ "
         << setw(9) << right << t.diskon << " ║ "
         << setw(14) << left << t.kategori << " ║ " << endl;

    cout << "╚════════╩═══════════════════════════════════╩═══════════════╩═══════════╩════════════════╝" << endl;
}

void tabelPesananTiket(const Tiket& t) {
    system("cls");

    tabelPesananTiketHeader();

    tabelPesananTiketRow(t);

    cout << endl;
}

void tabelPesananTiketHeaderrr() {
    cout << endl << endl;
    cout << "=======================================================================================================================" << endl;
    cout << "| KODE   | NAMA TIKET                        | HARGA         | DISKON(%) | KATEGORI      | JUMLAH    | HARGA TOTAL    |" << endl;
    cout << "=======================================================================================================================" << endl;
}

void tabelPesananTiketRowww(const Tiket& t) {
    cout << "| " << setw(3) << t.kode << "  | "
         << setw(33) << left << t.nama << " | "
         << "Rp." << setw(10) << right << t.harga << " | "
         << setw(9) << right << t.diskon << " | "
         << setw(14) << left << t.kategori << " | " ;

    cout << "=======================================================================================================================" << endl;
}

string getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S %p", ltm);
    return string(buffer);
}

vector<Tiket> tiket;
int kodeTiketBerikutnya = 1;

void tampilkanMenuUtama();
void tampilkanMenuAdmin();
void tambahTiket();
void editTiket();
void hapusTiket();
void lihatTiket();
void cariTiket();
void pesanTiket();
void simpanDataTiket();
void muatDataTiket();

bool loginAdmin() {
    setConsoleColor(9, 0);
    system("cls");
    printLoadingUserAdmin();

    string username, password;

    gotoxy(50, 1);
    cout << "Login";
    gotoxy(40, 5);
    cout << "Username: ";
    cin >> username;
    gotoxy(40, 7);
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "121") {
        tampilkanMenuAdmin();
        return true;
    } else {
        gotoxy(47, 10);
        cout << "Login gagal.\n";
        system("pause > nul");
        return loginAdmin();
    }

    system("cls");
}

void tampilkanMenuUtama() {
    int pilihan;

    printLoadingBar();

    do {
        setConsoleColor(0, 6);
        system("cls");
        headerMenuUtama();
        gotoxy(35, 9);
        cout << "Menu Utama:";
        gotoxy(35, 10);
        cout << "1. Pesan Tiket";
        gotoxy(35, 11);
        cout << "2. Menu Admin";
        gotoxy(35, 12);
        cout << "3. Keluar";
        gotoxy(35, 13);
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (cin.fail() || pilihan < 1 || pilihan > 3) {
            system("cls");
            setConsoleColor(0, 4);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            headeropsisalahMenuUtama();
            opsisalah();
            system("pause > nul");
            setConsoleColor(0, 6);
        } else {
            switch (pilihan) {
                case 1:
                    pesanTiket();
                    break;
                case 2:
                    loginAdmin();
                    break;
                case 3:
                    system("cls");
                    system("pause > nul");
                    exit(0);
                default:
                    cout << "Pilihan tidak valid. Coba lagi.\n";
            }
        }
    } while (pilihan != 3);
}


void tampilkanMenuAdmin() {
    setConsoleColor(0, 9);
    system("cls");
    int pilihan;

    do {
        for (int i = 30; i <= 80; i++) {
            gotoxy(i, 3);
            cout << "*";
        } delay();

        for (int i = 80; i >= 30; i--) {
            gotoxy(i, 7);
            cout << "*";
        } delay();

        gotoxy(40, 4);
        cout << "CREATE, READ, UPDATE, DELETE"; delay();

        gotoxy(47, 6);
        cout << "TIKET BIOSKOP"; delay();

        gotoxy(38, 9);
        cout << "Menu 1. Tambah Tiket Bioskop";
        gotoxy(38, 10);
        cout << "Menu 2. Edit Tiket Bioskop";
        gotoxy(38, 11);
        cout << "Menu 3. Hapus Tiket Bioskop";
        gotoxy(38, 12);
        cout << "Menu 4. Lihat Tiket Bioskop";
        gotoxy(38, 13);
        cout << "Menu 5. Search Tiket Bioskop";
        gotoxy(38, 14);
        cout << "Menu 6. Keluar";
        gotoxy(38, 16);
        cout << "Pilihan: ";
        cin >> pilihan;
        if (cin.fail() || pilihan < 1 || pilihan > 6) {
            system("cls");
            setConsoleColor(0, 4);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opsiadminsalah();
            system("pause > nul");
            system("cls");
            setConsoleColor(0, 9);
        } else {
            switch (pilihan) {
                case 1:
                    tambahTiket();
                    break;
                case 2:
                    editTiket();
                    break;
                case 3:
                    hapusTiket();
                    break;
                case 4:
                    lihatTiket();
                    break;
                case 5:
                    cariTiket();
                    break;
                case 6:
                    cout << "Sampai Jumpa Lagi :)";
                    break;
                default:
                    cout << "Pilihan tidak valid. Coba lagi.";
            }
        }
    } while (pilihan != 6);
}

string getKategori(int kategori) {
    switch (kategori) {
        case 1:
            return "Action";
        case 2:
            return "Adventure";
        case 3:
            return "Romantic";
        case 4:
            return "War";
        case 5:
            return "Race";
        default:
            return "Unknown";
    }
}

void tambahTiket() {
    system("cls");

    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 3);
        cout << "*";
    } delay();

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 5);
        cout << "*";
    } delay();

    gotoxy(33, 4);
    cout << "CREATE TIKET BIOSKOP"; delay();

    Tiket tiketBaru;

    gotoxy(30, 7);
    cout << "Masukkan nama film: ";
    cin.ignore();
    getline(cin, tiketBaru.nama);

    int kategori = 0;
    gotoxy(30, 9);
    cout << "Kategori film:";
    gotoxy(30, 10);
    cout << "1. Action";
    gotoxy(30, 11);
    cout << "2. Adventure";
    gotoxy(30, 12);
    cout << "3. Romantic";
    gotoxy(30, 13);
    cout << "4. War";
    gotoxy(30, 14);
    cout << "5. Race";
    gotoxy(30, 15);
    cout << "Pilih kategori: ";
    cin >> kategori;
    tiketBaru.kategori = getKategori(kategori);

    gotoxy(30, 17);
    cout << "Masukkan diskon 0-100: ";
    cin >> tiketBaru.diskon;
    gotoxy(30, 18);
    cout << "Masukkan harga: ";
    cin >> tiketBaru.harga;

    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    int numDigits = to_string(static_cast<int>(tiketBaru.harga)).length();
    do {
        tiketBaru.kode = rand() % static_cast<int>(pow(10, numDigits)) + static_cast<int>(pow(10, numDigits - 1));
    } while (find_if(tiket.begin(), tiket.end(), [&tiketBaru](const Tiket &t) { return t.kode == tiketBaru.kode; }) != tiket.end());

    tiket.push_back(tiketBaru);

    simpanDataTiket();

    system("cls");
    setConsoleColor(0, 2);

    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 3);
        cout << "*";
    }

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 5);
        cout << "*";
    }

    gotoxy(33, 4);
    cout << "CREATE TIKET BIOSKOP";

    gotoxy(30, 7);
    cout << "Masukkan nama film: " << tiketBaru.nama;
    gotoxy(30, 9);
    cout << "Kategori film:\n";
    gotoxy(30, 10);
    cout << "1. Action\n";
    gotoxy(30, 11);
    cout << "2. Adventure\n";
    gotoxy(30, 12);
    cout << "3. Romantic\n";
    gotoxy(30, 13);
    cout << "4. War\n";
    gotoxy(30, 14);
    cout << "5. Race";
    gotoxy(30, 15);
    cout << "Pilih kategori: " << tiketBaru.kategori;
    gotoxy(30, 17);
    cout << "Masukkan diskon 0-100 " << tiketBaru.diskon;
    gotoxy(30, 18);
    cout << "Masukkan harga: " << tiketBaru.harga;
    gotoxy(30, 20);
    cout << "Tiket berhasil ditambahkan!";

    system("pause > nul");

    setConsoleColor(0, 9);

    system("cls");
}

void editTiket() {
    system("cls");

    if (tiket.empty()) {
        setConsoleColor(0, 4);
        for (int i = 20; i <= 70; i++) {
            gotoxy(i, 2);
            cout << "*";
        }
        delay();

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }
        delay();

        gotoxy(33, 3);
        cout << "UPDATE TIKET BIOSKOP";
        delay();

        gotoxy(34, 6);
        cout << "Data masih kosong.";

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);
        return;
    }

    setConsoleColor(0, 9);
    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
    }
    delay();

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 4);
        cout << "*";
    }
    delay();

    gotoxy(33, 3);
    cout << "UPDATE TIKET BIOSKOP";
    delay();
    tabel(tiket);

    int kode;
    cout << "Masukkan kode tiket untuk diedit: ";
    cin >> kode;
    cout << endl;

    bool found = false;
    for (auto &t : tiket) {
        if (t.kode == kode) {
            found = true;

            system("cls");

            for (int i = 20; i <= 70; i++) {
                gotoxy(i, 2);
                cout << "*";
            }

            for (int i = 70; i >= 20; i--) {
                gotoxy(i, 4);
                cout << "*";
            }

            gotoxy(33, 3);
            cout << "UPDATE TIKET BIOSKOP";
            tabel(tiket);

            cout << "Masukkan kode tiket untuk diedit: " << kode << endl;
            cout << "Mengedit tiket " << kode << ":" << endl;
            cout << "Masukkan nama film baru: ";
            cin.ignore();
            getline(cin, t.nama);
            int kategori;
            cout << "Pilih kategori film baru:" << endl;
            cout << "1. Action"<< endl;
            cout << "2. Adventure" << endl;
            cout << "3. Romantic" << endl;
            cout << "4. War" << endl;
            cout << "5. Race" << endl;
            cout << "Pilih kategori: ";
            cin >> kategori;
            cout << endl;
            t.kategori = getKategori(kategori);
            cout << "Masukkan diskon baru 0-100: ";
            cin >> t.diskon;
            cout << endl;
            cout << "Masukkan harga baru: ";
            cin >> t.harga;
            cout << endl;

            system("cls");

            setConsoleColor(0, 2);
            for (int i = 20; i <= 70; i++) {
                gotoxy(i, 2);
                cout << "*";
            }

            for (int i = 70; i >= 20; i--) {
                gotoxy(i, 4);
                cout << "*";
            }
            gotoxy(33, 3);
            cout << "UPDATE TIKET BIOSKOP";
            delay();
            tabel(tiket);

            cout << "Masukkan kode tiket untuk diedit: " << kode << endl;
            cout << "Mengedit tiket " << kode << ":"<< endl;
            cout << "Masukkan nama film baru: " << t.nama << endl;
            cout << "Pilih kategori film baru:" << endl;
            cout << "1. Action" << endl;
            cout << "2. Adventure" << endl;
            cout << "3. Romantic" << endl;
            cout << "4. War" << endl;
            cout << "5. Race" << endl;
            cout << "Pilih kategori: " << t.kategori << endl;
            cout << "Masukkan diskon baru 0-100: " << t.diskon << endl;
            cout << "Masukkan harga baru: " << t.harga << endl;
            cout << "Tiket berhasil diedit." << endl;

            system("pause > nul");
            system("cls");
            setConsoleColor(0, 9);

            simpanDataTiket();
            break;
        }
    }

    if (!found) {
        system("cls");
        setConsoleColor(0, 4);

        for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
        }

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }

        gotoxy(33, 3);
        cout << "UPDATE TIKET BIOSKOP";
        tabel(tiket);

        cout << "Masukkan kode tiket untuk diedit: " << kode << endl << endl;
        cout << "Tiket tidak ditemukan." << endl;

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);
    }

    system("cls");
}



void hapusTiket() {
    system("cls");

    if (tiket.empty()) {
        setConsoleColor(0, 4);
        for (int i = 20; i <= 70; i++) {
            gotoxy(i, 2);
            cout << "*";
        }
        delay();

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }
        delay();

        gotoxy(33, 3);
        cout << "DELETE TIKET BIOSKOP";
        delay();

        gotoxy(34, 6);
        cout << "Data masih kosong.";

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);
        return;
    }

    setConsoleColor(0, 9);
    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
    }
    delay();

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 4);
        cout << "*";
    }
    delay();

    gotoxy(33, 3);
    cout << "DELETE TIKET BIOSKOP";
    delay();
    tabel(tiket);

    int kode;
    cout << "Masukkan kode tiket untuk dihapus: ";
    cin >> kode;
    cout << endl;

    auto it = find_if(tiket.begin(), tiket.end(), [&kode](const Tiket &t) { return t.kode == kode; });
    if (it != tiket.end()) {
        tiket.erase(it);

        system("cls");

        setConsoleColor(0, 2);
        for (int i = 20; i <= 70; i++) {
            gotoxy(i, 2);
            cout << "*";
        }

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }

        gotoxy(33, 3);
        cout << "DELETE TIKET BIOSKOP";
        tabel(tiket);

        cout << "Masukkan kode tiket untuk dihapus: " << kode << endl << endl;
        cout << "Tiket berhasil dihapus.";

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);

        simpanDataTiket();
    } else {
        system("cls");

        setConsoleColor(0, 4);
        for (int i = 20; i <= 70; i++) {
            gotoxy(i, 2);
            cout << "*";
        }

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }

        gotoxy(33, 3);
        cout << "DELETE TIKET BIOSKOP";
        tabel(tiket);

        cout << "Masukkan kode tiket untuk dihapus: " << kode << endl << endl;
        cout << "Tiket tidak ditemukan.";

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);
    }

    system("cls");
}

bool compareByCodeAscending(const Tiket& a, const Tiket& b) {
    return a.kode < b.kode;
}

bool compareByCodeDescending(const Tiket& a, const Tiket& b) {
    return a.kode > b.kode;
}

bool compareByNameAscending(const Tiket& a, const Tiket& b) {
    return a.nama < b.nama;
}

bool compareByNameDescending(const Tiket& a, const Tiket& b) {
    return a.nama > b.nama;
}

bool compareByCategoryAscending(const Tiket& a, const Tiket& b) {
    return a.kategori < b.kategori;
}

bool compareByCategoryDescending(const Tiket& a, const Tiket& b) {
    return a.kategori > b.kategori;
}

bool compareByPriceAscending(const Tiket& a, const Tiket& b) {
    return a.harga < b.harga;
}

bool compareByPriceDescending(const Tiket& a, const Tiket& b) {
    return a.harga > b.harga;
}

bool compareByDiscountAscending(const Tiket& a, const Tiket& b) {
    return a.diskon < b.diskon;
}

bool compareByDiscountDescending(const Tiket& a, const Tiket& b) {
    return a.diskon > b.diskon;
}

void clearScreenAndWait() {
    system("pause > nul");
    system("cls");
}

void lihatTiket() {
    system("cls");

    int pilihmetodesorting;
    int pilihsortingby;

    if (tiket.empty()) {
        setConsoleColor(0, 4);
        return;
    }

    setConsoleColor(0, 9);

    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
    }
    delay();

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 4);
        cout << "*";
    }
    delay();

    gotoxy(33, 3);
    cout << "VIEW TIKET BIOSKOP";
    delay();

    gotoxy(33, 6);
    cout << "Pilih metode sorting: ";
    gotoxy(33, 7);
    cout << "1. Ascending ";
    gotoxy(33, 8);
    cout << "2. Descending ";
    gotoxy(33, 9);
    cout << "Pilih Opsi Sorting: ";
    cin >> pilihmetodesorting;
    if (cin.fail() || pilihmetodesorting < 1 || pilihmetodesorting > 2) {
            system("cls");
            setConsoleColor(0, 4);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opsisortirsalah();
            system("pause > nul");
            system("cls");
            setConsoleColor(0, 6);
            tampilkanMenuAdmin();
    }

    gotoxy(33, 11);
    cout << "Pilih cara urut: ";
    gotoxy(33, 12);
    cout << "1. Kode";
    gotoxy(33, 13);
    cout << "2. Nama";
    gotoxy(33, 14);
    cout << "3. Kategori";
    gotoxy(33, 15);
    cout << "4. Harga";
    gotoxy(33, 16);
    cout << "5. Diskon ";
    gotoxy(33, 17);
    cout << "Pilihan: ";
    cin >> pilihsortingby;
    if (cin.fail() || pilihsortingby < 1 || pilihsortingby > 5) {
            system("cls");
            setConsoleColor(0, 4);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            for (int i = 20; i <= 70; i++) {
                gotoxy(i, 2);
                cout << "*";
            }

            for (int i = 70; i >= 20; i--) {
                gotoxy(i, 4);
                cout << "*";
            }

            gotoxy(33, 3);
            cout << "VIEW TIKET BIOSKOP";

            gotoxy(33, 6);
            cout << "Pilih metode sorting: ";
            gotoxy(33, 7);
            cout << "1. Ascending ";
            gotoxy(33, 8);
            cout << "2. Descending ";
            gotoxy(33, 9);
            cout << "Pilih Opsi Sorting: " << pilihmetodesorting;
            gotoxy(33, 11);
            cout << "Pilih cara urut: ";
            gotoxy(33, 12);
            cout << "1. Kode";
            gotoxy(33, 13);
            cout << "2. Nama";
            gotoxy(33, 14);
            cout << "3. Kategori";
            gotoxy(33, 15);
            cout << "4. Harga";
            gotoxy(33, 16);
            cout << "5. Diskon ";
            gotoxy(33, 17);
            cout << "Opsi salah! ";
            system("pause > nul");
            system("cls");
            setConsoleColor(0, 6);
            tampilkanMenuAdmin();
    }

    system("cls");

    switch (pilihsortingby) {
        case 1:
            if (pilihmetodesorting == 1) {
                sort(tiket.begin(), tiket.end(), compareByCodeAscending);
            } else if (pilihmetodesorting == 2) {
                sort(tiket.begin(), tiket.end(), compareByCodeDescending);
            }
            break;
        case 2:
            if (pilihmetodesorting == 1) {
                sort(tiket.begin(), tiket.end(), compareByNameAscending);
            } else if (pilihmetodesorting == 2) {
                sort(tiket.begin(), tiket.end(), compareByNameDescending);
            }
            break;
        case 3:
            if (pilihmetodesorting == 1) {
                sort(tiket.begin(), tiket.end(), compareByCategoryAscending);
            } else if (pilihmetodesorting == 2) {
                sort(tiket.begin(), tiket.end(), compareByCategoryDescending);
            }
            break;
        case 4:
            if (pilihmetodesorting == 1) {
                sort(tiket.begin(), tiket.end(), compareByPriceAscending);
            } else if (pilihmetodesorting == 2) {
                sort(tiket.begin(), tiket.end(), compareByPriceDescending);
            }
            break;
        case 5:
            if (pilihmetodesorting == 1) {
                sort(tiket.begin(), tiket.end(), compareByDiscountAscending);
            } else if (pilihmetodesorting == 2) {
                sort(tiket.begin(), tiket.end(), compareByDiscountDescending);
            }
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }

    tabel(tiket);

    clearScreenAndWait();
}

void cariTiket() {
    system("cls");

    if (tiket.empty()) {
        setConsoleColor(0, 4);
        for (int i = 20; i <= 70; i++) {
            gotoxy(i, 2);
            cout << "*";
        }
        delay();

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }
        delay();

        gotoxy(33, 3);
        cout << "SEARCH TIKET BIOSKOP";
        delay();

        gotoxy(34, 6);
        cout << "Data masih kosong.";

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);
        return;
    }

    setConsoleColor(0, 9);
    for (int i = 20; i <= 70; i++) {
        gotoxy(i, 2);
        cout << "*";
    }
    delay();

    for (int i = 70; i >= 20; i--) {
        gotoxy(i, 4);
        cout << "*";
    }
    delay();

    gotoxy(33, 3);
    cout << "SEARCH TIKET BIOSKOP";
    delay();

    string cari;
    gotoxy(33, 6);
    cout << "Masukkan (Nama/Kategori): ";
    cin.ignore();
    getline(cin, cari);
    cout << endl;

    bool found = false;
    for (const auto& t : tiket) {
        if (t.nama == cari || t.kategori == cari) {
            found = true;

            system("cls");

            setConsoleColor(0, 2);
            printTableHeader();

            printTableRow(t);

            cout << "╚════════╩═══════════════════════════════════╩═══════════════╩═══════════╩════════════════╝" << endl;

            system("pause > nul");
            system("cls");

            break;
        }
    }

    if (!found) {
        system("cls");
        setConsoleColor(0, 4);

        for (int i = 20; i <= 70; i++) {
            gotoxy(i, 2);
            cout << "*";
        }

        for (int i = 70; i >= 20; i--) {
            gotoxy(i, 4);
            cout << "*";
        }

        gotoxy(33, 3);
        cout << "SEARCH TIKET BIOSKOP";
        delay();

        gotoxy(34, 6);
        cout << "Tiket tidak ditemukan.";

        system("pause > nul");
        system("cls");
        setConsoleColor(0, 9);
    }
}

void pesanTiket() {
    system("cls");
    char a[100]= "TERIMAKASIH, SELAMAT MENONTON...!!!";

    if (tiket.empty()) {
        system("color F4");
        displayHeader("PESAN TIKET BIOSKOP");
        cout << "Data masih kosong." << endl;
        system("pause > nul");
        return;
    }

    system("color F9");
    displayHeader("PESAN TIKET BIOSKOP");

    tabel(tiket);

    int kode, jumlah;
    cout << endl << "Masukkan kode tiket untuk dipesan: ";
    cin >> kode;
    auto it = find_if(tiket.begin(), tiket.end(), [&kode](const Tiket &t) { return t.kode == kode; });

    if (it != tiket.end()) {
        system("cls");
        displayHeader("PESAN TIKET BIOSKOP");
        tabelPesananTiketHeader();
        tabelPesananTiketRow(*it);

        cout << endl << "Menu yang dipesan = " << it->nama << endl;
        cout << "Masukkan jumlah   = ";
        cin >> jumlah;
        cout << endl;

        if (jumlah <= 0) {
            cout << "Jumlah tidak valid." << endl;
            system("pause");
            return;
        }

        double totalHarga = jumlah * it->harga * (1 - it->diskon / 100.0);
        cout << "===============================================" << endl;
        cout << "Pesanan berhasil ditambahkan!" << endl;
        cout << "Total harga: " << totalHarga << endl;

        char pesanLagi;
        cout << endl << "Apakah Anda ingin memesan tiket lagi? (Y/N): ";
        cin >> pesanLagi;

        if (pesanLagi == 'Y' || pesanLagi == 'y') {
            pesanTiket();
            return;
        }

        system("cls");

        int pilihanPembayaran;

        displayHeader("PESAN TIKET BIOSKOP");
        tabelPesananTiketHeaderrr();
        tabelPesananTiketRowww(*it);

        cout << endl << "1. Bayar Tiket" << endl;
        cout << "2. Keluar (Batalkan pembelian)" << endl;
        cout << "Pilihan: ";
        cin >> pilihanPembayaran;

        if (pilihanPembayaran == 1) {
            double jumlahPembayaran;
            system("cls");
            displayHeader("PESAN TIKET BIOSKOP");
            tabelPesananTiketHeaderrr();
            tabelPesananTiketRowww(*it);

            cout << endl << "Total yang harus dibayar: " << totalHarga;
            cout << endl << "Masukkan jumlah pembayaran: ";
            cin >> jumlahPembayaran;

            while (jumlahPembayaran < totalHarga) {
                cout << "Jumlah pembayaran tidak cukup. Anda masih kurang " << (totalHarga - jumlahPembayaran) << endl;
                cout << "Masukkan jumlah tambahan: ";
                double jumlahTambahan;
                cin >> jumlahTambahan;
                jumlahPembayaran += jumlahTambahan;
            }

            double kembalian = jumlahPembayaran - totalHarga;

            cout << "Pembayaran berhasil. Mencetak struk..." << endl;

            ofstream struk("struk.txt");
            if (struk.is_open()) {
                struk << "!!..STRUK PEMBAYARAN..!!" << endl;
                struk << "=======================================================================================================================" << endl;
                struk << "|                          Gold restaurant                                                                            |" << endl;
                struk << "|                          Jawa Tengah                                                                                |" << endl;
                struk << "|                          Telp : (0283)521099 / 085432985260                                                         |" << endl;
                struk << "=======================================================================================================================" << endl;
                struk << "| KODE   | NAMA TIKET                        | HARGA         | DISKON(%) | KATEGORI      | JUMLAH    | HARGA TOTAL    |" << endl;
                struk << "=======================================================================================================================" << endl;
                struk << "| " << setw(3) << it->kode << "  | "
                     << setw(33) << left << it->nama << " | "
                     << "Rp." << setw(10) << right << it->harga << " | "
                     << setw(9) << right << it->diskon << " | "
                     << setw(13) << left << it->kategori << " | " << jumlah << setw(12) << right << " | "
                     << "Rp." << setw(10) << right << totalHarga << " |" << endl;
                struk << "=======================================================================================================================" << endl << endl;
                struk << "=================================================================" << endl;
                struk << "| Total Keseluruhan                        = " << totalHarga << "              |" << endl;
                struk << "| Uang bayar                              = " << jumlahPembayaran << "               |" << endl;
                struk << "| Kembalian                                = " << kembalian << "               |" << endl;
                struk << "|                                                               |" << endl;
                struk << "|                                                               |" << endl;
                struk << "| " << getCurrentTime() << endl;
                struk << "| Perhatian : Barang yang dibeli tidak bisa dikembalikan!       |" << endl;
                struk << "|                                                               |" << endl;
                struk << "=================================================================" << endl;

                struk.close();
                system("notepad struk.txt");

                system("cls");
                system("color F0");
                gotoxy(39, 7);
                for (int i = 0; i <= strlen(a); i++) {
                    delay2();
                    printf("%c", a[i]);
                }
                system("cls");
                system("pause > nul");
                exit(0);
            } else {
                cout << "Gagal menyimpan struk." << endl;
            }
        } else if (pilihanPembayaran == 2) {
            cout << "Pesan tiket dibatalkan." << endl;
        } else {
            system("cls");
            system("color F4");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayHeader("PESAN TIKET BIOSKOP");
            tabelPesananTiketHeaderrr();
            tabelPesananTiketRowww(*it);

            cout << endl << "Total yang harus dibayar: " << totalHarga;
            cout << endl << "Masukkan jumlah pembayaran: " << pilihanPembayaran;
            cout << endl << "Opsi salah!";

            system("pause > nul");
            system("cls");
            setConsoleColor(0, 6);
            tampilkanMenuAdmin();
        }
    } else {
        system("cls");
        system("color F4");
        displayHeader("PESAN TIKET BIOSKOP");
        tabel(tiket);
        cout << "Kode tiket tidak valid. Silahkan coba lagi!" << endl;

        char pesanulang;
        cout << "Apakah Anda ingin memesan tiket ulang? (Y/N): ";
        cin >> pesanulang;

        if (pesanulang == 'Y' || pesanulang == 'y') {
            pesanTiket();
            return;
        }
    }

    simpanDataTiket();
}

void simpanDataTiket() {
    ofstream file("data_tiket.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file untuk menyimpan data tiket." << endl;
        return;
    }

    for (const auto& t : tiket) {
        file << t.kode << ','
             << t.nama << ','
             << t.kategori << ','
             << t.diskon << ','
             << t.harga << endl;
    }

    file.close();
}

void muatDataTiket() {
    ifstream file("data_tiket.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file untuk memuat data tiket." << endl;
        return;
    }

    tiket.clear();

    Tiket t;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        t.kode = stoi(token);

        getline(ss, token, ',');
        t.nama = token;

        getline(ss, token, ',');
        t.kategori = token;

        getline(ss, token, ',');
        t.diskon = stod(token);

        getline(ss, token, ',');
        t.harga = stod(token);

        tiket.push_back(t);
    }

    file.close();
}

int main() {
    muatDataTiket();
    tampilkanMenuUtama();
    return 0;
}