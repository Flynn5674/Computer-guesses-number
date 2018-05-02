#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/*********************************************
**  Josh Hudgin                             **
**  Spring semester 2018                    **
**  CIS 252                                 **
**  Final Project                           **
**  Number guess game                       **
**  Chapter topics covered are ch9, 10, 14  **
**  pointers, classes, character testing    **
*********************************************/

class Random
{//top of class
private:
    int guess;
    int a=1, b=1001;
    
public:
    void random_number(int a, int b)
    { 
        srand((unsigned)time(0));
        int i;
        i = ( a + b ) / 2 ;//creates random number guess that does not repeat
        
        guess=i;
        cout<<endl<<"Computer guess number : "<<guess;
    }
    
    void Compare(int *d2)
    {
        if(*d2 == guess)
        {
            cout<<endl<<"The Computer got it! "<<endl;
            return;
        }

        if(*d2 > guess)
        {
            cout<<endl<<"The Computer guess is low. "<<endl;
            a=guess;
            random_number(a,b);
            Compare(&*d2);
        }
        if(*d2 < guess)
        {
            cout<<endl<<"The Computer guess is high. "<<endl;
            b=guess;
            random_number(a,b);
            Compare(&*d2);
        }
    }
};//bottom of class

int main(int argc, char** argv)
{//top of main
    int number;
    Random r;
    
    cout<<"See if you can stump the computer. "<<endl;    
    cout<<"Enter number between 1-1,000 : ";
    cin>>number;
    
    //Generate number for guess
    r.random_number(1,1000);
    
    //compare computers guess number
    r.Compare(&number);
    
    return 0;
}//bottom of main