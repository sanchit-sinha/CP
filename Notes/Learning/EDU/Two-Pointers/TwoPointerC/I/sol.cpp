#include "bits/stdc++.h"
using namespace std;

struct service1{
    string type;
    int num_addition_details;
    vector<string> additional_details;
    vector<vector<string>> options;
    string service_description;
    string info_regarding_disease;
    vector<float> charges; 

    service1(){
        type = "Medical Check Up";
        num_addition_details = 1;

        additional_details.push_back("Any chronical disease");

        vector<string> individual_option;
        individual_option.push_back("Yes");
        individual_option.push_back("No");
        options.push_back(individual_option);
    
        service_description = "Medical checkup will be conducted by medical officer. Patient needs to be fasting for 10 hours prior to test";

        charges.push_back(150);
    }
};

struct service2{
    string type;
    int num_addition_details;
    vector<string> additional_details;
    vector<vector<string>> options;
    string service_description;
    string info_regarding_disease;
    vector<float> charges; 

    service2(){
        type = "Blood test";
        num_addition_details = 2;

        additional_details.push_back("Purpose of blood test");
        additional_details.push_back("Type of blood test");

        vector<string> individual_option;
        
        individual_option.push_back("Regular Check Up");
        individual_option.push_back("Job Requirement");
        individual_option.push_back("Education Requirement");
        options.push_back(individual_option);

        individual_option.clear();
       
        individual_option.push_back("Basic");
        individual_option.push_back("Advance");
        individual_option.push_back("Special");
        options.push_back(individual_option);

        service_description = "Patient need to be at the blood test counter at Level 2A 15 minutes. Result of blood test can be collected only one the next day.";

        charges.push_back(80);
        charges.push_back(100);
        charges.push_back(80);
    }
};

struct service3{
    string type;
    int num_addition_details;
    vector<string> additional_details;
    vector<vector<string>> options;
    string service_description;
    string info_regarding_disease;
    vector<float> charges; 

    service3(){
        type = "Covid 19 Swab Test";
        num_addition_details = 2;

        additional_details.push_back("Under Quarantine");
        additional_details.push_back("Suspected to be infected");

        vector<string> individual_option;
        
        individual_option.push_back("Yes");
        individual_option.push_back("No");
        options.push_back(individual_option);

        individual_option.clear();
        individual_option.push_back("Yes");
        individual_option.push_back("No");
        options.push_back(individual_option);

        service_description = "After the test, patient need to be quarantine at home until the result is out.";
        
        charges.push_back(80);
        charges.push_back(100);
        charges.push_back(80);
    }
};

struct service4{
    string type;
    int num_addition_details;
    vector<string> additional_details;
    vector<vector<string>> options;
    string service_description;
    string info_regarding_disease;
    vector<float> charges; 

    service4(){
        type = "Vaccination";
        num_addition_details = 1;

        additional_details.push_back("Type of Vaccination");

        vector<string> individual_option;
        
        individual_option.push_back("Coronavirus");
        individual_option.push_back("Influenzas");
        individual_option.push_back("Pneumonococcal");
        options.push_back(individual_option);

        service_description = "Patient need to undergo pre-screening before the  vaccination.";

        charges.push_back(180);
        charges.push_back(120);
        charges.push_back(110);
    }
};

string ask(string s){
    cout << s;

    string ans;
    cin >> ans;

    return ans;
}
int main(){
    service1 a;
    service2 b;
    service3 c;
    service4 d;

    string Name , contact_number;
    float Age;
    bool is_senior_citizen = false;

    Name = ask("Please Enter your Name : ");

    cout << "Please Enter your Age : ";
    cin >> Age;

    if(Age > 65.0) is_senior_citizen = true;

    contact_number = ask("Please Enter your Contact Number : ");

    cout << "Choose your sevice type : \n";
    cout << "Input 1 for " << a.type << "\n";
    cout << "Input 2 for " << b.type << "\n";
    cout << "Input 3 for " << c.type << "\n";
    cout << "Input 4 for " << d.type << "\n";

    cout << "Enter your service Type : ";
    int service_chosen;
    cin >> service_chosen;

    vector<string> questions;
    vector<string> user_additional_details;
    string users_service_detals;
    string users_service;
    float total_price;

    if(service_chosen == 1){
        users_service = a.type;
        users_service_detals = a.service_description;

        int num = a.additional_details.size();
            
        cout << "\nProvide some of the additional details required\n\n";
        for(int i = 0 ; i < num ; i++){
            cout << (i + 1) << " : " <<  a.additional_details[i] << " - \n";
            questions.push_back(a.additional_details[i]);

            int len = a.options[i].size();
            for(int j = 0 ; j < len ; j++){
                cout << "Option " << j + 1 << ") " << a.options[i][j] << "\n";
            }

            cout << "Enter your option Number : ";
            int option;
            cin >> option;

            user_additional_details.push_back(a.options[i][option - 1]);
            cout << "\n\n";
        }

        total_price = a.charges[0];
    }
    else if(service_chosen == 2){
        users_service = b.type;
        users_service_detals = b.service_description;

        int num = b.additional_details.size();
            
        cout << "\nProvide some of the additional details required\n\n";
        for(int i = 0 ; i < num ; i++){
            cout << (i + 1) << " : " <<  b.additional_details[i] << " - \n";
            questions.push_back(b.additional_details[i]);

            int len = b.options[i].size();
            for(int j = 0 ; j < len ; j++){
                cout << "Option " << j + 1 << ") " << b.options[i][j] << "\n";
            }

            cout << "Enter your option Number : ";
            int option;
            cin >> option;

            user_additional_details.push_back(b.options[i][option - 1]);
            cout << "\n\n";
        }

        string input = user_additional_details[1];
        int len = (b.options[1]).size();
        for(int i = 0 ; i < len ; i++){
            if(b.options[1][i] == input) total_price = b.charges[i]; 
        }
    }
    else if(service_chosen == 3){
        users_service = c.type;
        users_service_detals = c.service_description;

        int num = c.additional_details.size();
            
        cout << "\nProvide some of the additional details required\n\n";
        for(int i = 0 ; i < num ; i++){
            cout << (i + 1) << " : " <<  c.additional_details[i] << " - \n";
            questions.push_back(c.additional_details[i]);

            int len = c.options[i].size();
            for(int j = 0 ; j < len ; j++){
                cout << "Option " << j + 1 << ") " << c.options[i][j] << "\n";
            }

            cout << "Enter your option Number : ";
            int option;
            cin >> option;

            user_additional_details.push_back(c.options[i][option - 1]);
            cout << "\n\n";
        }
        total_price = a.charges[0];
    }
    else{
        users_service = d.type;
        users_service_detals = d.service_description;

        int num = d.additional_details.size();
            
        cout << "\nProvide some of the additional details required\n\n";
        for(int i = 0 ; i < num ; i++){
            cout << (i + 1) << " : " <<  d.additional_details[i] << " - \n";
            questions.push_back(d.additional_details[i]);

            int len = d.options[i].size();
            for(int j = 0 ; j < len ; j++){
                cout << "Option " << j + 1 << ") " << d.options[i][j] << "\n";
            }

            cout << "Enter your option Number : ";
            int option;
            cin >> option;

            user_additional_details.push_back(d.options[i][option - 1]);
            cout << "\n\n";
        }

        string input = user_additional_details[0];
        int len = (d.options[0]).size();
        for(int i = 0 ; i < len ; i++){
            if(d.options[0][i] == input) total_price = d.charges[i]; 
        }
    }


    if(is_senior_citizen) total_price = total_price*(0.65);


    cout << "************INPUT DETAILS**************\n";
    cout << "Name : " << Name << "\n";
    cout << "Age : " << Age << "\n";
    cout << "Contact Details : " << Name << "\n\n";

    cout << "Service Chosen : " << users_service << "\n\n";
    cout << "Service Details : \n";
    cout << users_service_detals << "\n\n";

    cout << "Additional details Provided by users\n";
    int len = questions.size();
    for(int i = 0 ; i < len ; i++){
        cout << i + 1 << ") " << questions[i] << "\n" << "-> " << user_additional_details[i] << "\n\n"; 
    }


    cout << "Total Charges incurred : " << total_price << "\n";
    if(is_senior_citizen) cout << "You have been provided a discount of 15%\n";
}