#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>  //Für Zufall
#include <stdlib.h> //Für Zufall
#include <time.h>   //Für Zufall

using namespace std;

//Funktionsprototypen
void meldung (char sprache_mel, int meldungszahl_mel);
void galton (int &zeilenanzahl_gal, int &spaltenanzahl_gal, char sprache_gal, char galtonbrett_gal[30][61], int &brettzahl_gal);
void unterprogramm (char &wahlunterprogramm_unt, char &sprache_unt, int &zeilenanzahl_unt, int &spaltenanzahl_unt, char galtonbrett_unt [30][61], int &brettzahl_unt, int &wurfzaehler_unt);
void sprache_prog (char &sprache_spra);
void ausgabe (char sprache_aus, char galtonbrett_aus [30][61], int zeilenanzahl_aus, int spaltenanzahl_aus, int brettzahl_aus);
void nagelbrett (int zeilenanzahl_nag, int spaltenanzahl_nag, char galtonbrett_nag [30][61], char sprache_nag, int brettzahl_nag);
void loeschen (int zeilenanzahl_loe, int spaltenanzahl_loe, char galtonbrett_loe [30][61], char sprache_loe, int brettzahl_loe, int &wurfzaehler_loe);
void wurf(char sprache_wurf, char galtonbrett_wurf [30][61], int zeilenanzahl_wurf, int spaltenanzahl_wurf, int &wurfzaehler_wurf, int brettzahl_wurf);
void zusatz(int zeilenanzahl_zu, int spaltenanzahl_zu, char sprache_zu, int brettzahl_zu, char &z_zu);

//Hauptprogramm
int main (){
	//Vereinbarungen
	char sprache;
	int meldungszahl, zeilenanzahl, spaltenanzahl;
	char wahlunterprogramm;
	int brettzahl = 0;
	char galtonbrett[30][61];
	int wurfzaehler = 1;
	char z = 'y';
	int durchgang = 0;

	//Sprache auswählen -> Aufruf des Unterprogramms
	sprache_prog (sprache);

	//Aufrufen der Unterporgramme
	unterprogramm (wahlunterprogramm, sprache, zeilenanzahl, spaltenanzahl, galtonbrett, brettzahl, wurfzaehler);

	//Test Galton-Brett
	//cout << "Zeilenanzahl: " << zeilenanzahl << endl;
	//cout << "Spaltenanzahl: " << spaltenanzahl << endl;

    //Zusatzaufgabe
    while(z == 'y'){
        do{
            if(durchgang < 1){
                meldungszahl = 5;
                meldung(sprache, meldungszahl);
                cin >> z;
                durchgang++;
            }
            else{
                cout << endl;
                meldungszahl = 6;
                meldung(sprache, meldungszahl);
                cin >> z;
            }
            cout << endl << endl;
        } while(z != 'y' && z != 'n');

        if(z == 'y'){
            zusatz(zeilenanzahl, spaltenanzahl, sprache, brettzahl, z);
        }
    }

	//Ausgabe
	meldungszahl = 999;
	cout << endl << endl;
	meldung (sprache, meldungszahl);
	cout << endl << endl;
	getch();
}

//Funktionen-Unterprogramme

//Meldung
void meldung(char sprache_mel, int meldungszahl_mel){
	switch(sprache_mel){
	//Deutsch
	case 'd':
		//Eingabe Meldungszahl
		switch(meldungszahl_mel){
			case 0: cout << endl << "Sie haben Deutsch als Sprache gewaehlt!" << endl << endl;
					break;
			case 1: cout  << endl  << endl << "Bitte waehlen Sie ein Unterprogramm" << endl << endl;
					cout << "[0] Wahl der Sprache" << endl;
					cout << "[1] Erstellung Galton-Brett" << endl;
                    cout << "[2] Werfen einer Kugel" << endl;
                    cout << "[3] Loeschen aller Wuerfe" << endl;
					cout << "[4] Grafische Ausgabe des Galton-Brettes" << endl;
					cout << "[5] Programm schliessen" << endl << endl;
					break;
			case 2: cout << "Bitte geben Sie die Zeilenanzahl an (min: 3 ; max: 30): ";
					break;
            case 3: cout << "Sie haben 4 mal geworfen";
                    break;
			case 4: cout << "Sie haben alle Wuerfe erfolgreich geloescht" << endl << endl;
                    break;
            case 5: cout << "Wollen Sie die Zusatzaufgabe ausfuehren? ( y = Ja , n = Nein ) ---> ";
                    break;
            case 6: cout << "Wollen Sie die Zusatzaufgabe erneut ausfuehren? ( y = Ja , n = Nein ) ---> ";
                    break;
            case 989:   cout << "Es wurde zuvor kein Galton-Brett generiert!";
                        break;
			case 990:   cout << "Bitte geben Sie eine Wurfzahl an ( min: 1 ; max: 99999 ): ";
                        break;
			case 991:   cout << "Wollen Sie noch einen Wurf taetigen? ( y = Ja , n = Nein ) ---> ";
                        break;
            case 992:   cout << " Wuerf(e) uebrig" << endl;
                        break;
            case 993:   cout << ". Wurf" << endl;
                        break;
			case 994:   cout << "Sie haben noch keinen Wurf getaetigt" << endl;
                        break;
			case 995:   cout << "Bitte erstellen Sie zuerst ein Galton-Brett [1]" << endl << endl;
                        break;
			case 996:   cout << "Sie haben erfolgreich ein Galtonbrett erstellt" << endl << endl;
                        break;
			case 997:   cout << "Sie haben bereits ein Galton-Brett definiert" << endl << endl;
                        break;
			case 998:   cout << "Galton-Brett" << endl;
                        cout << "------------" << endl << endl << endl;
                        break;
			case 999: 	cout << "Sie haben das Programm geschlossen!";
						break;
		break;
		}
	break;

	//English
	case 'e':
		//Eingabe Meldungszahl
		switch(meldungszahl_mel){
			case 0: cout << endl << "You have chosen english as your default language!" << endl << endl;
					break;
			case 1: cout << endl << endl << "Please make a choice" << endl << endl;
					cout << "[0] Select your language" << endl;
					cout << "[1] Create a bean machine" << endl;
                    cout << "[2] run" << endl;
                    cout << "[3] Clear all runs" << endl;
					cout << "[4] Graphical output" << endl;
					cout << "[5] Close the program" << endl;
					break;
			case 2: cout << "Please enter the number of lines ( min: 3 ; max: 30): ";
					break;
            case 3: cout << "You have already run 4 times";
                    break;
			case 4: cout << "You have successfully deleted all runs" << endl << endl;
                    break;
            case 5: cout << "Do you want to run the additional task? ( y = yes , n = no ) ---> ";
                    break;
            case 6: cout << "Do you want to run the additional task again? ( y = yes , n = non ) ---> ";
                    break;
            case 989:   cout << "It has been previously generated no bean machine!";
                        break;
			case 990:   cout << "Please enter a number of runs ( min: 1 ; max: 99999 ): ";
                        break;
			case 991:   cout << "Do you want to run it again? ( y = yes , n = no ) ---> ";
                        break;
            case 992:   cout << " run(s) left" << endl;
                        break;
            case 993:   cout << ". run" << endl;
                        break;
			case 994:   cout << "You have started no run" << endl;
                        break;
			case 995:   cout << "Please create a bean machine [1]" << endl << endl;
                        break;
			case 996:   cout << "You have successfully created a bean machine" << endl << endl;
                        break;
			case 997:   cout << "You have already created successfully a beach machine" << endl << endl;
                        break;
			case 998:   cout << "Bean-Machine" << endl;
                        cout << "------------" << endl << endl << endl;
                        break;
			case 999: 	cout << "You have closed the program!";
						break;

		break;
		}
	break;
	}
}

//Unterprogramme-Auswahl
void unterprogramm(char &wahlunterprogramm_unt, char &sprache_unt, int &zeilenanzahl_unt, int &spaltenanzahl_unt, char galtonbrett_unt [30][61], int &brettzahl_unt, int &wurfzaehler_unt){
	//Vereinbarungen
	int meldungszahl_unt;
	do{
        meldungszahl_unt = 1;
		meldung(sprache_unt, meldungszahl_unt);
		cout << endl << "-----> ";
		cin >> wahlunterprogramm_unt;
		cout << endl << endl;
		switch(wahlunterprogramm_unt){
			case '0': // Sprache wählen
				sprache_prog(sprache_unt);
				break;
			case '1': //Galton-Brett
                galton(zeilenanzahl_unt, spaltenanzahl_unt, sprache_unt, galtonbrett_unt, brettzahl_unt);
				break;
            case '2': //Würfe max. 4
                wurf(sprache_unt, galtonbrett_unt, zeilenanzahl_unt, spaltenanzahl_unt, wurfzaehler_unt, brettzahl_unt);
                break;
            case '3': //Nagelbrett löschen
                loeschen(zeilenanzahl_unt, spaltenanzahl_unt, galtonbrett_unt, sprache_unt, brettzahl_unt, wurfzaehler_unt);
                break;
			case '4': //Ausgabe Galton-Brett
				ausgabe(sprache_unt, galtonbrett_unt, zeilenanzahl_unt, spaltenanzahl_unt, brettzahl_unt);
				break;
            case '5': //Return
                return;
                break;
            default: unterprogramm (wahlunterprogramm_unt, sprache_unt, zeilenanzahl_unt, spaltenanzahl_unt, galtonbrett_unt, brettzahl_unt, wurfzaehler_unt);
		}
	} while (wahlunterprogramm_unt != '5');
}

//Galton-Brett [1]
void galton (int &zeilenanzahl_gal, int &spaltenanzahl_gal, char sprache_gal, char galtonbrett_gal [30][61], int &brettzahl_gal){
	//Vereinbarungen
	int mitte_gal, zeil_gal, spal_gal; //Anzahl Bretter einbringen
	int meldungszahl_gal;

	//Eingabe der Zeilen
	if(brettzahl_gal == 0){
        do{
        meldungszahl_gal = 2;
        meldung(sprache_gal, meldungszahl_gal); // "Bitte geben Sie die Zeilenanzahl an (min: 3 ; max: 30): "

        cin >> zeilenanzahl_gal;
        cout << endl << endl;
        } while(zeilenanzahl_gal < 3 || zeilenanzahl_gal > 30);
        spaltenanzahl_gal = zeilenanzahl_gal * 2 + 1;   // Berechnung der benötigten Spaltenanzahl

        //Nagelbrett erstellen
        brettzahl_gal = 1;
        nagelbrett(zeilenanzahl_gal, spaltenanzahl_gal, galtonbrett_gal, sprache_gal, brettzahl_gal);

        meldungszahl_gal = 996;
        meldung(sprache_gal, meldungszahl_gal); // "Sie haben erfolgreich ein Galtonbrett erstellt"
    }
    else{
        meldungszahl_gal = 997;
        meldung(sprache_gal, meldungszahl_gal); // "Sie haben bereits ein Galton-Brett definiert"
    }
}

//Sprache
void sprache_prog(char &sprache_spra){
    //Vereinbarungen
    int meldungszahl_spra = 0;
	do{
	cout << endl << "Choose your default language ( e = English, d = Deutsch ): ";
	cin >> sprache_spra;
	cout << endl;
	} while(sprache_spra != 'e' && sprache_spra != 'd');  // <-- hier logisches UND ganz wichtig, wenn nicht e UND nicht d, dann laufe Schleife erneut

	//Test der Sprachfunktion
	meldung (sprache_spra, meldungszahl_spra = 0);
}

//Ausgabe-Galton-Brett-[4]
void ausgabe(char sprache_aus, char galtonbrett_aus[30][61], int zeilenanzahl_aus, int spaltenanzahl_aus, int brettzahl_aus){
    //Vereinbarungen
    int zeil_aus, spal_aus, meldungszahl_aus;
    if(brettzahl_aus < 1){

        meldungszahl_aus = 995;
        meldung(sprache_aus, meldungszahl_aus); // "Bitte erstellen Sie zuerst ein Galton-Brett [1]"
        cout << endl;
    }
    else{
        meldungszahl_aus = 998;
        meldung(sprache_aus, meldungszahl_aus); // "Galton-Brett"

        for(zeil_aus = 0; zeil_aus < zeilenanzahl_aus; zeil_aus++){
            for(spal_aus = 0; spal_aus < spaltenanzahl_aus; spal_aus++){
                cout.width(2);
                cout << galtonbrett_aus[zeil_aus][spal_aus];
            }
            cout << endl;
        }
    }
	cout << endl << endl;
}

//nagelbrett [3] und Funktion von [1]
void nagelbrett (int zeilenanzahl_nag, int spaltenanzahl_nag, char galtonbrett_nag[30][61], char sprache_nag, int brettzahl_nag){
    // Vereinbarungen
    int zeil_nag, spal_nag, mitte_nag, meldungszahl_nag;
    if (brettzahl_nag < 1){

        meldungszahl_nag = 995;
        meldung (sprache_nag, meldungszahl_nag);    // "Bitte erstellen Sie zuerst ein Galton-Brett [1]"
    }
    else{
        //Übernehmen der Variablen
        //zeil_nag = zeilenanzahl_nag - 1;
        spal_nag = spaltenanzahl_nag - 1;
        mitte_nag = spal_nag / 2;

        //Leeren des Galton-Brettes
        for (zeil_nag = 0; zeil_nag < zeilenanzahl_nag; zeil_nag++){
            for (spal_nag = 0; spal_nag < spaltenanzahl_nag; spal_nag++){
                galtonbrett_nag [zeil_nag][spal_nag] = ' ';
            }
        }

        if (zeilenanzahl_nag%2 != 0){ //Für ungerade Zeilenzahlen
            for (zeil_nag = 0; zeil_nag < zeilenanzahl_nag; zeil_nag++){
                for (spal_nag =  mitte_nag - (zeil_nag + 1); spal_nag < mitte_nag + (zeil_nag + 2); spal_nag++){
                    if (zeil_nag%2 == 0){
                        if (spal_nag%2 == 0){
                            galtonbrett_nag[zeil_nag][spal_nag] = '|';
                        }
                        else{
                            galtonbrett_nag[zeil_nag][spal_nag] = ' ';
                        }
                    }
                    else{
                        if (spal_nag%2 == 0){
                        galtonbrett_nag[zeil_nag][spal_nag] = ' ';
                        }
                        else{
                            galtonbrett_nag[zeil_nag][spal_nag] = '|';
                        }
                    }
                }
            }
        }
        else { //für gerade Zeilenzahlen
            for (zeil_nag = 0; zeil_nag < zeilenanzahl_nag; zeil_nag++){
                for (spal_nag =  mitte_nag - (zeil_nag + 1); spal_nag < mitte_nag + (zeil_nag + 2); spal_nag++){
                    if (zeil_nag%2 == 0){
                        if (spal_nag%2 == 0){
                            galtonbrett_nag[zeil_nag][spal_nag] = ' ';
                        }
                        else{
                            galtonbrett_nag[zeil_nag][spal_nag] = '|';
                        }
                    }
                    else{
                        if (spal_nag%2 == 0){
                        galtonbrett_nag[zeil_nag][spal_nag] = '|';
                        }
                        else{
                            galtonbrett_nag[zeil_nag][spal_nag] = ' ';
                        }
                    }
                }
            }
        }
    }
}

//Löschen  [3]
void loeschen (int zeilenanzahl_loe, int spaltenanzahl_loe, char galtonbrett_loe[30][61], char sprache_loe, int brettzahl_loe, int &wurfzaehler_loe){
    //Vereinbarungen
    int meldungszahl_loe;
    nagelbrett(zeilenanzahl_loe, spaltenanzahl_loe, galtonbrett_loe, sprache_loe, brettzahl_loe);
    if (brettzahl_loe > 0){
        meldung(sprache_loe, meldungszahl_loe = 4); // "Sie haben alle Wuerfe erfolgreich geloescht"
    }
    wurfzaehler_loe = 1;
}

//Wurf
void wurf(char sprache_wurf, char galtonbrett_wurf[30][61], int zeilenanzahl_wurf, int spaltenanzahl_wurf, int &wurfzaehler_wurf, int brettzahl_wurf){

    //Vereinbarungen
    int meldungszahl_wurf, zeil_wurf, spal_wurf, pos_wurf;
    char abfrage_wurf = 'y';
    char symbol_wurf;
    int rand();
    int zufall_wurf;
    int ausgabe_wurf;

    time_t t;

    //Zufall generieren
    time(&t);
    srand((unsigned int)t);              /* Zufallsgenerator initialisieren */

    //Zähler
    if (brettzahl_wurf < 1){

        meldungszahl_wurf = 995;
        meldung(sprache_wurf, meldungszahl_wurf);   // "Bitte erstellen Sie zuerst ein Galton-Brett [1]"
    }
    else{
        if (wurfzaehler_wurf < 5){
            while (wurfzaehler_wurf < 5 && abfrage_wurf == 'y'){
                //Mitte wählen für Start
                pos_wurf = (spaltenanzahl_wurf - 1) / 2;
                switch (wurfzaehler_wurf){
                    case 1: symbol_wurf = '*';
                            break;
                    case 2: symbol_wurf = '+';
                            break;
                    case 3: symbol_wurf = ':';
                            break;
                    case 4: symbol_wurf = '#';
                            break;
                break;
                }

                for (zeil_wurf = 0 ; zeil_wurf < zeilenanzahl_wurf ; zeil_wurf++){
                  if (zeil_wurf == 0){
                    galtonbrett_wurf[zeil_wurf][pos_wurf] = symbol_wurf;
                  }
                  else{
                    zufall_wurf = rand() %2;
                    pos_wurf = pos_wurf + 1 + (-2)*zufall_wurf;
                    galtonbrett_wurf[zeil_wurf][pos_wurf] = symbol_wurf;
                  }
                }
                wurfzaehler_wurf ++;
                if (wurfzaehler_wurf < 5){
                    ausgabe_wurf = wurfzaehler_wurf - 1;
                    cout << ausgabe_wurf;

                    meldungszahl_wurf = 993;
                    meldung(sprache_wurf, meldungszahl_wurf);   // ". Wurf"
                    cout << endl << endl;
                    cout << 5-wurfzaehler_wurf;

                    meldungszahl_wurf = 992;
                    meldung(sprache_wurf, meldungszahl_wurf);   // " Wuerf(e) uebrig"

                    do{
                        meldungszahl_wurf = 991;
                        meldung(sprache_wurf, meldungszahl_wurf);   // "Wollen Sie noch einen Wurf taetigen? ( y = Ja , n = Nein ) ---> "

                        cin >> abfrage_wurf;
                        cout << endl << endl;
                    }
                    while (abfrage_wurf != 'y' && abfrage_wurf != 'n');
                }
                else{
                meldungszahl_wurf = 3;
                meldung(sprache_wurf, meldungszahl_wurf);   // "Sie haben 4 mal geworfen"
                }
            }

        }
        else{
        meldungszahl_wurf = 3;
        meldung(sprache_wurf, meldungszahl_wurf);   // "Sie haben 4 mal geworfen"
        }
    }
}

//Zusatzaufgabe
void zusatz(int zeilenanzahl_zu, int spaltenanzahl_zu, char sprache_zu, int brettzahl_zu, char &z_zu){

    //Vereinbarungen
    int meldungszahl_zu, zeil_zu, spal_zu, pos_zu;
    int galtonbrett_zu[30][61];
    int rand();
    int zufall_zu;
    int eingabe_zu, wurf_zu;

    //Zeit
    time_t t;

    //Zufall generieren
    time(&t);
    srand((unsigned int)t);

    //Prüfen ob Brettzahl > 0
    if (brettzahl_zu > 0){
        //Eingabe der Wurfanzahl
        do{
            meldungszahl_zu = 990;
            meldung(sprache_zu, meldungszahl_zu);
            cin >> eingabe_zu;
            cout << endl << endl;
        }
        while(eingabe_zu < 1 || eingabe_zu > 99999);

        //zeil_zu = zeilenanzahl_zu - 1;
        spal_zu = spaltenanzahl_zu - 1;

        //Leeren des Galton-Brettes
        for (zeil_zu = 0; zeil_zu < zeilenanzahl_zu; zeil_zu++){
            for (spal_zu = 0; spal_zu < spaltenanzahl_zu; spal_zu++){
                galtonbrett_zu [zeil_zu][spal_zu] = 0;
            }
        }

        //Durchläufe
        for (wurf_zu = 0; wurf_zu < eingabe_zu; wurf_zu++){

            //Mitte für Start
            pos_zu = (spaltenanzahl_zu - 1) / 2;
            //einzelner Durchlauf
            for(zeil_zu = 0; zeil_zu < zeilenanzahl_zu; zeil_zu++){
                galtonbrett_zu[zeil_zu][pos_zu] = galtonbrett_zu[zeil_zu][pos_zu] + 1;
                zufall_zu = rand() % 2;
                pos_zu = pos_zu + 1 + (-2)*zufall_zu;
            }
        }

        //Ausgabe
        zeil_zu = zeilenanzahl_zu - 1;
        for (spal_zu = 0; spal_zu < spaltenanzahl_zu; spal_zu++){
            if (spal_zu % 2 == 0){
                cout.width (2);
                cout << "|";
            }
            else{
                cout.width (8);
                cout << galtonbrett_zu[zeil_zu][spal_zu];
            }
        }
        cout << endl << endl;
    }
    else{
    cout << endl;
    meldungszahl_zu = 989;
    meldung(sprache_zu, meldungszahl_zu);
    cout << endl << endl;
    z_zu = 'n';
    }
}
