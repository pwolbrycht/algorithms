// Kodowanie Huffmana
// Data: 5.07.2013
// (C)2013 mgr Jerzy Wałaszek
//---------------------------

#include <iostream>
#include <string>

using namespace std;

// Definicja węzła drzewa kodu bezprzystankowego
//----------------------------------------------
struct HTNode
{
    HTNode * next;
    HTNode * left;
    HTNode * right;
    char ch;
    int count;
};

// Tworzy listę wierzchołków
//--------------------------
void MakeList ( HTNode * & root, string s )
{
    unsigned int i, x;
    char cx;
    HTNode * p;
    bool t;

    root = NULL;                    // Tworzymy pustą listę
    for( i = 0; i < s.length( ); i++ ) // Tworzymy węzły i zliczamy znaki
    {
        p = root;                     // Szukamy na liście znaku s [ i ]
        while( p && ( p->ch != s [ i ] ) ) p = p->next;
        if( !p )                        // Jeśli go nie ma, to
        {
            p = new HTNode;             // tworzymy dla niego nowy węzeł
            p->next  = root;            // Węzeł trafi na początek listy
            p->left  = NULL;            // Ustawiamy pola węzła
            p->right = NULL;
            p->ch    = s [ i ];
            p->count = 0;
            root     = p;               // Wstawiamy węzeł na początek listy
        }
        p->count++;                   // Zwiększamy licznik wystąpień znaku
    }
    do                              // Listę sortujemy rosnąco względem count
    {
        t = true;                     // Zakładamy posortowanie listy
        p = root;                     // Sortujemy od pierwszego elementu
        while( p->next )
        {
            if( p->count > p->next->count )
            {
                cx = p->ch;               // Wymieniamy zawartość dwóch kolejnych elementów
                p->ch = p->next->ch;
                p->next->ch = cx;
                x = p->count;
                p->count = p->next->count;
                p->next->count = x;
                t = false;                // Sygnalizujemy nieposortowanie listy
            }
            p = p->next;                // Przechodzimy do następnego elementu
        }
    } while( !t );
}

// Tworzy z listy drzewo Huffmana
//-------------------------------
void MakeTree ( HTNode * & root )
{
    HTNode *p, *r, *v1, *v2;

    while( true )
    {
        v1 = root;                    // Pobieramy z listy dwa pierwsze węzły
        v2 = v1->next;

        if( !v2 ) break;                // Jeśli tylko jeden element, zakończ

        root = v2->next;              // Lista bez v1 i v2

        p = new HTNode;               // Tworzymy nowy węzeł
        p->left = v1;                 // Dołączamy do niego v1 i v2
        p->right = v2;                // i wyliczamy nową częstość
        p->count = v1->count + v2->count;

        // Węzeł wstawiamy z powrotem na listę tak, aby była uporządkowana

        if( !root || ( p->count <= root->count ) )
        {
            p->next = root;
            root = p;
            continue;
        }

        r = root;

        while( r->next && ( p->count > r->next->count ) ) r = r->next;

        p->next = r->next;
        r->next = p;
    }
}

// Drukuje zawartość drzewa Huffmana
//----------------------------------
void PrintTree ( HTNode * p, string b )
{
    if( !p->left ) cout << p->ch << " " << b << endl;
    else
    {
        PrintTree ( p->left, b + "0" );
        PrintTree ( p->right, b + "1" );
    }
}

// Koduje znak
//------------
bool CodeT ( char c, HTNode * p, string b )
{
    if( !p->left )
    {
        if( c != p->ch ) return false;
        else
        {
            cout << b;
            return true;
        }
    }
    else return CodeT ( c, p->left, b+"0" ) || CodeT ( c, p->right, b+"1" );
}

// Koduje tekst kodem Huffmana
//----------------------------
void CodeHuffman ( HTNode * root, string s )
{
    unsigned int i;

    for( i = 0; i < s.length( ); i++ )  // Kodujemy poszczególne znaki
        CodeT ( s [ i ], root, "" );
}

// Procedura DFS:postorder usuwająca drzewo
//-----------------------------------------
void DFSRelease ( HTNode * v )
{
    if( v )
    {
        DFSRelease ( v->left );          // usuwamy lewe poddrzewo
        DFSRelease ( v->right );         // usuwamy prawe poddrzewo
        delete v;                     // usuwamy sam węzeł
    }
}

// **********************
// *** Program główny ***
// **********************

int main( )
{
    HTNode * root;                   // Początek listy / korzeń drzewa
    string s;                        // Przetwarzany łańcuch

    getline ( cin, s );                 // Czytamy łańcuch wejściowy

    MakeList ( root, s );               // Tworzymy listę wierzchołków
    MakeTree ( root );                  // Tworzymy drzewo kodu Huffmana
    PrintTree ( root, "" );             // Wyświetlamy kody znaków
    CodeHuffman ( root, s );            // Kodujemy i wyświetlamy wynik

    DFSRelease ( root );                // Usuwamy drzewo z pamięci

    cout << endl << endl;

    return 0;
}