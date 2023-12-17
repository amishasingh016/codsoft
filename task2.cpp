#include <iostream>
using namespace std;

// Calculator using if and else conditions!

int main()

{
cout << "\033[1;33m******************************************************************\n";
    cout << "\t\t\t\t\t\tWelcome to the SIMPLE CalculatoR! \n";
    cout << "\t\t\t\t\t    Where numbers hold the key to unlocking countless outcomes!\n";
    cout << "**************************************************************************\033[0m";

    while (true)
    {
        double num1, num2, result;
        char op;

        cout<<endl;

        cout<<"Enter your 1st Number: "<<endl;
        cin>>num1;

        cout<<"Choose Operator: +, -, *, /"<<endl;
        cin>>op;
        
        cout<<"Enter your 2nd Number: "<<endl;
        cin>>num2;

        if (op == '+')
        {
            result = num1 + num2;
            cout<<"Your answer is: "<<result<<endl;
        }
        else if (op == '-')
        {
            result = num1 - num2;
            cout<<"Your answer is: "<<result<<endl;
        }
        else if (op == '*')
        {
            result = num1 * num2;
            cout<<"Your answer is: "<<result<<endl;
        }
        else if (op == '/')
        {
            if (num2 == 0)
            {
                cout<<"Division with 0 is not allowed!"<<endl;
            }
            else{
                result = num1 / num2;
                cout<<"Your answer is: "<<result<<endl;
            }
        }
        else{
            cout<<"Result was not possible due to Invalid Operator!"<<endl;
        }
    }
    
}