#include <iostream>
#include <fstream>
#include <string>
#include<regex>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

int main () {

  string line;
  int i=0,j=0,k=0,len,last=0;
  string num = "";
  double arr[7000][10];
  ifstream infile ("car.csv");

  if(infile.is_open())
  {
    while ( getline(infile,line) )
    {

      // Takes complete row
      // cout << line<< '\n';

       k=0,last=0,j=0;
       len=line.length();

        while(k!=len){
                if(line[k]==','||k==len-1){

                    //for converting string into number
                    arr[i][j]=atof(num.append(line,last,k).c_str());
                    //cout<<"new entry -> "<<arr[i][j]<<" endl \n";

                    //Emtying string for getting next data
                    num="";

                    //increasing column number after saving data
                    j++;

                    if(k!=len-1)
                    last=k+1;
                }
                k++;
        }
        //increase row number for array
        i++;
    }
    //close the file
    infile.close();
  }
  else cout << "Unable to open file";

  cout<<"Matrix of CSV file below \n";

  int col=0;

  //For finding the number of columns
    for(int x=0;x<len;x++){
       if(line[x]==',')
       col++;
       }
    // i= number of rows
    // col = number of columns
   for(int l=0;l<i;l++){
        for(int m=0;m<=col;m++){
        cout<<arr[l][m]<<"\t";
        }
   cout<<"\n";
}
  return 0;
}
