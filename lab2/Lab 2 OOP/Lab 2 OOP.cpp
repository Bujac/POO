#include <iostream>
#include <list>
#include <stdbool.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "Faculty.h"
#include "FileManager.h"
#include "Logger.h"
#include "Functions.h"
#include "GlobalVariables.h"

using namespace std;

int main()
{
    int optiune = 0;
    int optiune1 = 0;
    int optiune2 = 0;
    int dateSalvate = 0;
    while (true)
    {
        cout << endl;
        cout << "1. Operatiuni generale." << endl;
        cout << "2. Operatiuni cu facultati." << endl;
        cout << "3. Salveaza sesiunea." << endl;
        cout << "4. Incarca sesiunea anterioara." << endl;
        cout << "0. Iesire." << endl;
        cout << "Alege o optiune: ";
        cin >> optiune;
        if (optiune < 0 || optiune > 5)
        {
            logger.log(WARNING, "Optiune invalida");
        }
        switch (optiune)
        {
        case 1:
        {
            optiune1 = 0;
            while (optiune1 != 6)
            {
                cout << endl;
                cout << "Ce doresti sa faci?" << endl;
                cout << "1. Creeaza o noua facultate." << endl;
                cout << "2. Cauta facultatea unui student dupa un identificator unic (email)." << endl;
                cout << "3. Afiseaza facultatile Universitatii." << endl;
                cout << "4. Afiseaza toate facultatile dintr-un domeniu." << endl;
                cout << "5. Afiseaza informatii despre un student." << endl;
                cout << "6. Inapoi." << endl;
                cout << "Alege o optiune: ";
                cin >> optiune1;
                switch (optiune1)
                {
                case 1:
                {
                    newFaculty();
                    break;
                }
                case 2:
                {
                    belongsbyemail();
                    break;
                }
                case 3:
                {
                    displayFaculties();
                    break;
                }
                case 4:
                {
                    byField();
                    break;
                }
                case 5:
                    studentinfo();
                    break;
                }
            }
            break;
        }
        case 2:
        {
            optiune2 = 0;
            while (optiune2 != 8)
            {
                cout << endl;
                cout << "Ce doresti sa faci?" << endl;
                cout << "1. Creeaza si aloca un student la o facultate." << endl;
                cout << "2. Absolva un student de la o facultate." << endl;
                cout << "3. Afiseaza studentii inscrisi in prezent." << endl;
                cout << "4. Afiseaza absolventii." << endl;
                cout << "5. Spune daca un student apartine sau nu unei facultati." << endl;
                cout << "6. Inscriere in lot." << endl;
                cout << "7. Absolvire in lot." << endl;
                cout << "8. Inapoi." << endl;
                cout << "Alege o optiune: ";
                cin >> optiune2;
                switch (optiune2)
                {
                case 1:
                {
                    if (!faculties.empty()) {
                        createandassign();
                    }
                    else logger.log(ERROR, "Trebuie sa creezi mai intai o facultate!");
                    break;
                }
                case 2:
                {
                    graduate();
                    break;
                }

                case 3:
                {
                    displayenrolled();
                    break;
                }
                case 4:
                {
                    displaygraduated();
                    break;
                }
                case 5:
                {
                    tellbelongsornot();
                    break;
                }
                case 6:
                {
                    batchenrollment();
                    break;
                }
                case 7:
                {
                    if (dateSalvate == 1) {
                        batchgraduation();
                    }
                    else logger.log(ERROR, "Trebuie sa salvezi mai intai sesiunea!");
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            FileManager::saveData(faculties);
            dateSalvate = 1;
            break;
        }
        case 4:
        {
            FileManager::loadData(faculties);
            break;
        }
        case 0:
        {
            return 0;
        }
        }
    }
    return 0;
}
