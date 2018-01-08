/// ALEXANDRU CRINGUREANU
/// POO - LAB 11 - Stack - templates
/********************
Stack implemented with a vector template from STL
v.back(), v.empty(), v.push_back, v.pop_back
OBS:
- in meniu, la TOP si POP, exista blocul:
if(st.isEmpty())
{
    cout << "*EROARE* STIVA este goala!\n";
    break;
}
care este comentat. Deci programul, atunci cand POP si TOP vor fi apelate cand stiva este goala,
va da eroare (exceptions -> throw).
Puteti sa decomentati acest bloc in cele doua optiuni pentru ca programul sa nu se mai opreasca datorita exceptiei.
*********************/
#include <iostream>
#include <vector> /// Am folosit din Standard Template Library un vector
#include <stdlib.h>
using namespace std;

/// clasa Stack<T>
template<typename T>
class Stack
{
public:

    bool isEmpty() const; /// bool Stack::empty() – returneaza daca stiva este goala
    void push(const T& item); /// void Stack::push(const T &item) – adauga item la stiva
    const T& top() const /// T &Stack::top() – returneaza referinta catre cel mai recent adaugat item
    {
        if (isEmpty())
        {
            throw "Stiva este goala!\n";
        }
        return v.back();
    }
    /// OBS: nu pot pune doar prototipul functiei top() si apoi sa o declar extern
    void pop(); /// void Stack::pop() – scoate din stiva itemul cel mai recent adaugat
    vector <T> v;
};

/// MODIFICARE # GITHUB
/// declarare metode publice al clasei Stack
template<typename T>
bool Stack<T>::isEmpty() const
{
    return v.empty();
}

template<typename T>
void Stack<T>::push(const T& item)
{
    v.push_back(item);
}

template<typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        throw "Stiva este goala!\n";
    }
    v.pop_back();
}

/// main
int main()
{

    Stack <int> st;
    int option;
    int n;

    while(true)
    {
        cout << endl;
        cout << "[o]----<3----<>> MENIU <<>----POO----[o]" << endl;
        cout << "[1] - Push                             -" << endl;
        cout << "[2] - Pop                              -" << endl;
        cout << "[3] - Top                              -" << endl;
        cout << "[4] - isEmpty?                         -" << endl;
        cout << "[5] - Afisare stiva                    -" << endl;
        cout << "[6] - Incheiere program                -" << endl;
        cout << "[][][] Ce optiune doriti? :D [][][] --> ";
        cin >> option;
        cout << endl;
        system("cls");

        switch(option)
        {
        case 1:
            cout << "\n<> 1. PUSH <>\n";
            cout << "Introduceti numarul pe care vreti sa-l introduceti in stiva: ";
            cin >> n;
            st.push(n);
            cout << "\n\n";
            break;
        case 2:
            cout << "\n<> 2. POP <>\n";
            cout << "*POP*\n";
            /*if(st.isEmpty())
            {
                cout << "*EROARE* STIVA este goala!\n";
                break;
            }*/
            st.pop();
            cout << "\n\n";
            break;
        case 3:
            cout << "\n<> 3. TOP <>\n";
            /*if(st.isEmpty())
            {
                cout << "*EROARE* STIVA este goala!\n";
                break;
            }*/
            cout << "Elementul din TOP este: ";
            cout << st.top();
            cout << "\n\n";
            break;
        case 4:
            cout << "\n<> 4. isEmpty <>\n";
            if(st.isEmpty())
            {
                cout << "isEmpty: DA, stiva este goala!\n";
            }
            else
            {
                cout << "isEmpty: NU, stiva nu este goala!\n";
            }
            cout << "\n\n";
            break;
        case 5:
            cout << "\n<> 5. Afisare stiva <>\n";
            if(st.isEmpty())
            {
                cout << "*Eroare de afisare* STIVA este goala!\n";
                break;
            }
            for(int i=st.v.size()-1; i>=0; i--)
            {
                cout << st.v[i] << endl;
            }
            cout << "\n\n";
            break;
        case 6:
            cout << "<> Incheiere program... :( <>\n";
            return 0;
        default:
            cout << "\n<> OOPS!\n!! Optiune inexistenta. Reintroduceti optiunea dorita. !!<>\n\n" << endl;
        }
    }

    return 0;
}
