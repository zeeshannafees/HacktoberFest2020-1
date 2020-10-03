#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
//prog written specifically for use by travel agent, not customer


//user defined function
void extraline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

static int p=0; //static, global integer variable
//p is used as an index to refer to the buses

class busreserve{

private:
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10];
  char seat[10][4][15]; /*10 rows, 4 seats in each row and 15 spaces for storing reservation status - 3d array*/

public:

void addnewbus(); //add-details-of-new-bus

void reservation(); // check-bus-seat-and-reserve

void set_empty(); //bus-seat-check-for-empty

void show();//show-all-buses-seats-booked-empty-details

void status(int l);//to show list of seats reserved and unreserved

void avail(); //show-all-the-available-buses

void cancel(); //cancels reserved seats

}bus[15];/*array of objects-sets number of buses as 15*/


// definition of member functions

void busreserve::addnewbus()
{
 //add-details-of-new-bus
 cout<<"Enter bus no:";
 cin>>bus[p].busn;

 cout<<"Enter bus driver name:";
 cin>>bus[p].driver;

 cout<<"Enter the departure time:";
 cin>>bus[p].arrival;

 cout<<"Enter the arrival time:";
 cin>>bus[p].depart;

 cout<<"FROM:";
 cin>>bus[p].from;

 cout<<"TO :";
 cin>>bus[p].to;

 p++; //p is incremented after every new bus is added
}

void busreserve::reservation()
{
  // check-bus-seat-and-reserve
  int seat;
  char number[5];
  start:
  cout<<"Bus no: ";
  cin>>number;

  int n;
  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break; //to check if entered bus no corresponds to existing bus

  }

  //now n value is equal to that of the reqd bus

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>40)

    { cout<<"\nThere are only 40 seats available in this bus.";  }

    else

    {

      if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
/*this is to compare the str seat with empty to find if it's empty*/
      {
        cout<<"Enter passenger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];
/*the passenger's name is stored in the place of empty*/
       break;

      }

      else/*this case is executed when the string isn't equal to 'Empty'*/

      {cout<<"The seat no. is already reserved.\n"; goto start;}

    }

   }

if(n>p) /*exceptional case if wrong bus no is given*/

    {cout<<"Enter correct bus no.\n"; goto start;}


}





void busreserve::set_empty(){//bus-seat-sets-for-empty

 for(int i=0;i<10;i++)
    {
      for(int j=0;j<4;j++)
         {
                strcpy(bus[p].seat[i][j], "Empty"); //'Empty' is copied into the seats

         }
    }

}


void busreserve::show()
{
 //show-all-buses-seats-booked-or-empty-details
  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  extraline('*');

  cout<<endl;

  cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart<<"\nFrom :"<<bus[n].from<<"To: \t"<<bus[n].to<<"\n\n";

  extraline('*');

  cout<<endl;

  bus[0].status(n); //using 0th object to access status function


   break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}

void busreserve::status(int l){
//displays seats

  int m=0,k=0;

  for (int i =0; i<10;i++)

  {

    for (int j = 0;j<4; j++)

    {

      m++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' '); /*funtions to regulate output on display screen*/

          cout<<m<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          k++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<m<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<k<<" seats empty in Bus No: "<<bus[l].busn<<endl;


}

void busreserve::avail()
{ //show-all-the-available-buses

  for(int n=0;n<=p;n++)

  {

    extraline('*'); cout<<endl;

    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    extraline('*');

    cout<<endl;

    extraline('~');
    extraline('~');

    cout<<endl;



}




}


 void busreserve::cancel()
 {
 	char number[5];
    int seat;
    top:
    cout<<"Enter the bus no: ";
    cin>>number;
    cout<<endl;
   	int n;
   	for (n=0;n<=p;n++)
   		{ if (strcmp(bus[n].busn,number)==0)
          break;
        }
while(n<=p){
    cout<<"Enter the seat number to be cancelled: ";
    cin>>seat;

    if(seat>40)
    	{cout<<"This bus has only 40 seats.";}

    else
        { if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
          {cout<<"This seat is already empty.Enter the correct seat number. ";}
          else
          {strcpy(bus[n].seat[seat/4][(seat%4)-1],"Empty");
            cout<<"The seat number "<<seat<<"has been successfully cancelled"<<endl;}
        break ;}
    }

    if(n>p) {cout<<"The bus number is wrong"<<endl; goto top;}

 }



int main()

{
int w;
 cout<<"\t\t\t\t**Bus Reservation********"<<endl<<endl;
while(1) /*while loop runs until option 6 is chosen*/

{



  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Add new Bus Details:\n\t\t\t"

  <<"2.Reserve your seats:\n\t\t\t"

  <<"3.Buses Available Now:\n\t\t\t"

  <<"4.Show the bus seats Available: \n\t\t\t"<<"5.Cancel a ticket: \n\t\t\t"

  <<"6.exit \n\t\t\t";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;
  bus[0].set_empty();
  switch(w)

  {

    case 1:
             bus[p].addnewbus();

      break;

    case 2:  bus[p].reservation();

      break;

    case 3:  bus[0].avail();

      break;

    case 4:  bus[0].show();

      break;
    case 5: bus[p].cancel();

     break;

    case 6:  exit(0);

      break;


  }

}

return 0;

}
