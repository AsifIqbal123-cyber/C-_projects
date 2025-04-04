#include <iostream>
using namespace std;

int main(){
    
    double num1,num2;
    char operation;
    
    
    cout<< "Enter the first number: ";
    cin>> num1;

    cout<< "Enter the second number: ";
    cin>> num2;

    cout<< "Enter an operator (*,/,+,-): ";
    cin>> operation;

    switch (operation)
    {
    case  '+':
        cout<< "Result "<< num1+num2;
        /* code */
        break;
    case '-':
        cout<< "Result "<< num1-num2;
        break;
    case '/':
        if(num2!=0){
            cout<< "Result "<< num1/num2;
        } else {
            cout<< "Error in division";
        }
        break;
    case '*':
        cout<< "Result "<< num1*num2;
        break;
    default:
        break;
    }

    cout<<"\n";



}