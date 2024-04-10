#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inputFile("data.csv");
    ofstream outputFile("result.txt");
    string linea;
    double S;
    int n;
    double *w, *r; //definisco i puntatori

    getline(inputFile, linea); //leggo S e n dal file
    S = stod(linea.substr(2));
    getline(inputFile, linea);
    n = stoi(linea.substr(2));

    w = new double[n]; //inizializzo i puntatori
    r = new double[n];

    getline(inputFile, linea); //salto la linea iniziale con w e r

    for (int i = 0; i < n; i++) //leggo i valori di w e r
    {
        getline(inputFile, linea); //leggo la linea
        stringstream ss(linea); //divido la linea
        string pezzo; //memorizzo i pezzi della linea
        getline(ss, pezzo, ';'); //estraggo peso
        w[i] = stod(pezzo); //converto peso in double
        getline(ss, pezzo, ';'); //idem per tasso di rendimento
        r[i] = stod(pezzo);
    }

    inputFile.close();

    double ror = 0;
    for (int i = 0; i < n; i++) //calcolo tasso di rendimento portafoglio
    {
        ror += w[i] * r[i];
    }

    double V = S * (1 + ror); //valore finale portafoglio

    outputFile << "S = " << fixed << setprecision(2) << S << endl << "n = " << n << endl; //2 cifre significative per il valore del portafoglio

    outputFile << "w = [ ";
    for (int i = 0; i < n; i++)
    {
        outputFile << fixed << setprecision(2) << w[i] << " ";
    }
    outputFile << "]" << endl;

    outputFile << "r = [ ";
    for (int i = 0; i < n; i++)
    {
        outputFile << fixed << setprecision(2) << r[i] << " ";
    }
    outputFile << "]" << endl;

    outputFile << "Tasso di rendimento del portafoglio: " << fixed << setprecision(4) << ror << endl; //4 cifre significative per il tasso di rendimento
    outputFile << "Valore finale del portafoglio: " << fixed << setprecision(2) << V << endl;

    delete[] w; //elimino i puntatori
    delete[] r;

    outputFile.close();

    return 0;
}

