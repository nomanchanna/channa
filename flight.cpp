#include <iostream>
using namespace std;

    int pnr;
    char f_d[10],toja[7],tojd[7]; //protected members
    long int doj;
    int choice,src,dest;

   
    int j_detail() // function declaration and definition for domestic journey
    {
        cout << "\nEnter DateOfJourney(DDMMYY)." << "Please enter a valid date." <<  endl;
        cin >> doj;
        cout << "\1.Brisbane(1) \t\2.Sydney(2) \t\3.Melbourne(3) \t\4.Canberra(4)" << endl << endl;
        cout << "\tEnter Source" << endl;
        cin >> src;
        cout << "\tEnter destination" << endl;
        cin >> dest;
        if((src==1 && dest==2) || (src==2 && dest==1))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
        }

        else if((src==1 && dest==3) || (src==3 && dest==1))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
        }

        else if((src==1 && dest==4) || (src==4 && dest==1))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.4000\t\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\tRs.4250\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6100\t\tRefundable\n";
        }

        else if((src==2 && dest==3) || (src==3 && dest==2))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5400\t\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\tRs.2500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.2890\t\tRefundable\n";
        }

        else if((src==2 && dest==4) || (src==4 && dest==2))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\tRs.4500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
        }
        else if((src==3 && dest==4) || (src==4 && dest==3))//condition
         {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5800\t\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\tRs.5508\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6050\t\tRefundable\n";
        }
        else if(src==dest)//condition
        {
            cout << "\nSource and destination can't be same.\nTry again\n\n\n" << endl;
            return j_detail();
        }
        else
        {
            cout <<"\nWrong input entered\nTry again\n\n\n" << endl;
            return j_detail();
        }

    }

    int  select_flight() //function declaration and definition for selecting flight
    {   cout << "\nEnter your choice" << endl;
        cin >> choice;
        switch(choice) // switch case
        {
          case 1://condition
                cout << "\nFlight selected:"<<endl;
                cout << "Qantas"<<endl;
                strcpy(f_d,"Qantas");//copy to string
                cout << "Departure Time : 08:00"<<endl;
                cout<<"Arrival Time: 11:05"<<endl;
                strcpy(tojd,"8:00"); //copy to string
                strcpy(toja,"11:05");// copy to string
                break;
          case 2://condition
                cout << "\nFlight selected:"<<endl;
                cout << "Fly Dubai"<<endl;
                strcpy(f_d,"Fly Dubai");//copy to string
                cout << "Departure Time : 14:00"<<endl;
                cout<<"Arrival Time: 17:05"<<endl;
                strcpy(tojd,"14:00");//copy to string
                strcpy(toja,"17:05");//copy to string
                break;
          case 3://condition
                cout << "\nFlight selected:" << endl;
                cout << "Go Air" << endl;
                strcpy(f_d,"Go Air");//copy to string
                cout << "Departure Time : 19:00" << endl;
                cout<<"Arrival Time: 22:05" << endl;
                strcpy(tojd,"19:00");//copy to string
                strcpy(toja,"22:05");//copy to string
                break;
          default://condition
                cout << "Wrong input entered.\nTry again" << endl;
                return select_flight();
        }
    }
}



    int pnri;
    char f_i[10],tojai[7],tojdi[7];
    long int doji;
    int srci,desti,choicei;

    //brought to you by code-projects.org
    int j_detaili()// function declaration and definition for journey details
    {
        cout << "Enter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;;
        cin >> doji;
        cout << "\1.London(1) \2.Dubai(2) \3.Abu Dhabi(3) \4.Singapore(4) \5.NewYork(5) " << endl << endl;
        cout << "\tEnter Source" << endl;
        cin >> srci;
        cout << "\nEnter destination" ;
        cin >> desti;
        cout << "\t \t \tFlights Found" << endl << endl;

        if((srci==1 && desti==3) || (srci==3 && desti==1))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25000\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\tRs.21500\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24000\tRefundable\n";
        }

        else if((srci==1 && desti==4) || (srci==4 && desti==1))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25500\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\tRs.21300\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24650\t\tRefundable\n";
        }

        else if((srci==1 && desti==5) || (srci==5 || desti==1))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.52500\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\tRs.59420\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.64892\tRefundable\n";
        }

        else if((srci==2 && desti==3) || (srci==3 && desti==2))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.17800\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\tRs.14900\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.18700\tRefundable\n";
        }

        else if((srci==2 && desti==4) || (srci==4 && desti==2))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.32000\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\tRs.38500\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs41259\tRefundable\n";        }

        else if(srci==2 && desti==5 || (srci==5 && desti==2))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.82500\tRefundable\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\tRs.87550\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs81478\tRefundable\n";

        }
        else if(srci==desti)//condition
        {
            cout << "wrong input entered.\nTry again\n\n\n"<< endl;
            return j_detaili();
        }
        else//condition
            {
            cout << "Wrong input entered.\nTry again\n\n\n";
            return j_detaili();
        }

    }

    int select_flighti()//function declaration and definition for selecting flight
    {
        cout << "\nEnter your choice" << endl;
        cin >> choicei;
        switch(choicei)//switch case
        {
        case 1://condition
            cout << "\nFlight selected:" <<endl;
            cout << "Vistara" << endl;
            strcpy(f_i,"Vistara");//copy to string
            cout << "Departure Time: 10:00" << endl;
            cout << "Arrival Time: 14:05" << endl;
            strcpy(tojdi,"10:00");//copy to string
            strcpy(tojai,"14:05");//copy to string
            break;
        case 2://condition
               cout << "\nFlight selected:" << endl;
               cout << "Fly Dubai" << endl;
               strcpy(f_i,"Fly Dubai");//copy to string
               cout << "Departure Time: 14:00" << endl;
               cout << "Arrival Time: 18:05" << endl;
               strcpy(tojdi,"14:00");//copy to string
                strcpy(tojai,"18:05");//copy to string
                break;
        case 3://condition
            cout << "\nFlight selected:" << endl;
            cout << "Emirates" << endl;
            strcpy(f_i,"Emirates");//copy to string
            cout << "Departure Time : 18:00" << endl;
            cout << "Arrival Time: 22:05" << endl;
            strcpy(tojdi,"18:00");//copy to string
            strcpy(tojai,"22:05");//copy to string
            break;
        default://condition
            cout << "Wrong input entered" << endl;
            return select_flighti();
        }
    }
}





    char f_name[20],l_name[20],email[50];
    int age,gender;
    long int c_no;
public://public member functions
    void p_detail(int x)//function declaration and definition
    {   if(x==1)//if else for domestic and international booking selection
        { j_detail();//function call
          select_flight();//function call
        }
          else
          {  j_detaili();//function call1353
             select_flighti();//function call
          }
        cout << "\n\n\nEnter passenger details";
        cout << "\nFirst Name:";
        cin >> f_name;
        cout << "Last Name:";
        cin >> l_name;
    }
    int gender_check()//to check gender input as valid
    {
        cout << "\nGender:\nMale-press:1::\nFemale-press:2::";
        cin >> gender;
        if(gender>2)//condition
        {
            cout << "\n\nWrong input entered.\nTry again\n\n" << endl;
            return gender_check();//function call
        }
    }
       void more_details()//to take more details of the passenger
       {
        cout << "Age:";
        cin >> age;
        cout << "Email Id:";
        cin >> email;
        cout << "Contact no.(6 digits):";
        cin >> c_no;
        cout << "\n\nDetails Entered:\n";
        cout << "Name:" << f_name << " " << l_name << endl;
        cout << "Gender:" << gender << endl;      //displaying details
        cout << "Age:" << age << endl;
        cout << "Email id:" << email << endl;
        cout << "Contact No.:" << c_no << endl;
    }


     int getpnr()//function to get pnr for domestic booking
        {
            return pnr;
        }

     int getpnri()//function to get pnr for international booking
     {
         return pnri;
     }

     void disp()//function to display details for domestic booking
     {
         cout<<"PNR:" << pnr << endl;
         cout<<"Flight:" << f_d << endl;
         cout<<"Name:" << f_name << " " << l_name << endl;
         cout<<"DOJ:" << doj << endl;
         cout<<"Departure Time:" << tojd << endl;
         cout<<"Arrival Time:" << toja;
     }

      void dispi()//function to display details for international booking
     {
         cout<<"PNR:" << pnri << endl;
         cout<<"Flight:" << f_i << endl;
         cout<<"Name:" << f_name << " " << l_name << endl;
         cout<<"DOJ:" << doji << endl;
         cout<<"Departure Time:" << tojdi << endl;
         cout<<"Arrival Time:" << tojai;
     }
};


int main(){
	cout << "\n\n\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
              cout << "\nPlease enter your option" << endl;
              int choice2;
              cin>>choice2;
              switch(choice)
             p1.d_pnr();
                        p1.p_detail(1);//function calls
                        p1.gender_check();
                        p1.more_details();
                        p2.pay_detail();
                        p1.disp();
                        createfile(p1);//call to create file
                        break;
                   case 2: //for booking international ticket
                           p1.p_detail(2);//function calls
                           p1.i_pnr();
                           p1.gender_check();
                           p1.more_details();
                           p2.pay_detail();
                           p1.dispi();
                           createfilei(p1);//call to create file
                           break;
                   default://wrong input
                    cout << "Wrong input entered\nTry again\n\n\n" << endl;
                    cin.clear();
                    return main();
              }
			  
              
}
