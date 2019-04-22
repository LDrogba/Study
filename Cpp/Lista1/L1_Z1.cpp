#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

bool Prime( uint64_t x )
{
    for (uint64_t i=2; i<=sqrt(x); i++)
        if(x%i == 0)
            return false;
    return true;
}

vector<string> Arg_to_string(int argc, char* argv[] )
{
    vector<string> argList;
    for (int i = 1; i < argc; i++)
        argList.push_back(argv[i]);

    return argList;
}

int64_t String_to_int( string str)
{
    string::iterator ptr = str.begin();
    int64_t val = 0;
    int sign = 1;

    if( *ptr == '-'){
        sign = -1;
        ptr++;
    }

    while ( ptr != str.end()){
        val*=10;
        if(*ptr - '0' > 9 || *ptr - '0' < 0){
            throw invalid_argument("Blad znaku!");
            return 0;
        }
        val += *ptr - '0';
        ptr++;
    }

    return val*sign;
}

vector <int64_t> Rozklad(int64_t x)
{
    vector <int64_t> Liczby;
    uint64_t k;

    if(x == 1)
        return {1};

    if(Prime(x))
        return {x};

    else if(x == 0)
        return {0};

    else if(x < 0){
        Liczby.push_back(-1);
        if (x == numeric_limits<int64_t>::min())
            k = -numeric_limits<int64_t>::min();
        else
        k = -x;
    }
    else
        k=x;

    for(uint64_t i=2; i<=sqrt(k); i++){
        while(k%i == 0){
            Liczby.push_back(i);
            k /= i;
        }
    }

    if(k > 1)
        Liczby.push_back(k);
    return Liczby;
}

void Show(const vector<int64_t>& argList)
{
    for( int64_t num : argList )
    {
        vector <int64_t> act_num = Rozklad(num);
        int s = act_num.size();

        cout << num << " = ";

        for (int i=0; i<s; i++ ){
            cout << act_num[i];
            if( i != s-1)
                cout << " * ";
        }
    cout << endl << "--------------------------" << endl;
    }
}

vector <int64_t> Vector_string_to_int(vector <string> lista_str)
{
    int s = lista_str.size();
    vector <int64_t> lista_int;
    for(int i=0; i<s; i++){
        lista_int.push_back(String_to_int(lista_str[i]));
    }

    return lista_int;
}

void Blad()
{
    cerr << "Aby poprawnie uruchomic program, nalezy podac mu argumenty" << endl
             << "wywolania skladajace sie z cyfr od 0 do 9 z ewentualnym znakiem '-' na poczatku" << endl
             << "oznaczjacym liczbe ujemna. Program z blednymi danymi zwroci blad.";
}

int main( int argc, char* argv[])
{
    if(argc < 2)
        Blad();

    vector <string> argList = Arg_to_string(argc, argv);
    vector <int64_t> argList_int = Vector_string_to_int( argList );
    Show(argList_int);

    return 0;
}
