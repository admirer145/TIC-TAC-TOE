#include<bits/stdc++.h>
using namespace std;

class tictactoe{

 public:
   char arr[3][3];

   tictactoe(){
       for(int i=0;i<3;i++)
      {
          for(int j=0;j<3;j++)
          {
              arr[i][j]='0';
          }
      }
   }
   void insert(int i, int j, char value)
   {
       arr[i][j]=value;
   }

   void display()
   {
       cout<<endl;
      for(int i=0;i<3;i++)
      {
          cout<<"| ";
          for(int j=0;j<3;j++)
          {
              cout<<arr[i][j]<<" | ";
          }
          cout<<endl;
      }
      cout<<endl;
   }

   bool check(int i, int j)
   {
       if(arr[i][j]=='0')
       {
           return true;
       }
       return false;
   }

   bool diagL(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[i][i]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool diagR(char win)
   {
       for(int i=0,j=2;i<3;i++,j--)
       {
           if(arr[i][j]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool hor1(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[0][i]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool hor2(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[1][i]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool hor3(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[2][i]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool vert1(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[i][0]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool vert2(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[i][1]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool vert3(char win)
   {
       for(int i=0;i<3;i++)
       {
           if(arr[i][2]!=win)
           {
               return false;
           }
       }
       return true;
   }

   bool winPlayer(int num, char win)
   {
       switch(num)
       {
       case 0:
           if(hor1(win) || vert1(win) || diagL(win))
           {
               return true;
           }
        break;

       case 1:
           if(hor1(win) || vert2(win))
           {
               return true;
           }
        break;

       case 2:
           if(hor1(win) || vert3(win) || diagR(win))
           {
               return true;
           }
        break;

       case 3:
           if(hor2(win)|| vert1(win))
           {
               return true;
           }
        break;
       case 4:
           if(hor2(win) || vert2(win) || diagL(win) || diagR(win))
           {
               return true;
           }
        break;
       case 5:
           if(hor2(win) || vert3(win))
           {
               return true;
           }
        break;
       case 6:
           if(hor3(win) || vert1(win) || diagR(win))
           {
               return true;
           }
        break;
       case 7:
           if(hor3(win) || vert2(win))
           {
               return true;
           }
        break;
       case 8:
           if(hor3(win) || vert3(win) || diagL(win))
           {
               return true;
           }
        break;
       }
       return false;
   }

};


int main()
{
    tictactoe ttt;

    cout<<"\t\t\t\t\tTIC TAC TOE\n\n";

    while(1)
    {
        int cnt=0,cntr=0;
        string y;

        cout<<"If you want to start the Game press y or Y ....";
        cin>>y;

        if(y.length()==1 && ((y[0] == 'y') || (y[0] == 'Y')))
        {
            int i=1;
            string a,b;
            rename:
            cout<<"\nEnter a Character for player 1:";
            fst:
            cin>>a;
            if(a.length()>1 || a[0]=='0')
            {
                cout<<"Please enter a valid character:";
                goto fst;
            }
            cout<<"\nEnter a Character for player 2:";
            scnd:
            cin>>b;
            if(b.length()>1 || b[0]=='0')
            {
                cout<<"\nPlease enter a valid character:";
                goto scnd;
            }

            char first=a[0];
            char second=b[0];

            if(first==second)
            {
                cout<<"\nPlease select distinct name..."<<endl;
                goto rename;
            }
            cout<<"\nIndex are as follows (1-9):\n"<<endl;
            int k=1;
            for(int i=0;i<3;i++)
            {
                cout<<"| ";
                for(int j=0;j<3;j++)
                {
                    cout<<k<<" | ";
                    k++;
                }
                cout<<endl;
            }

            cout<<"\nGame Starts Now... Select between 1 to 9 as index..."<<endl;

            ttt.display();
            while(1)
            {
                string val;
                reenter:
                cout<<"\nPlayer "<<i<<" : ";
                cin>>val;
                int num=int(val[0])-48;
                num=num-1;
                if(val.length()==1 && val[0]>48 && val[0]<58 && ttt.check(num/3,num%3))
                {
                char win;
                if(i==1)
                {
                    ttt.insert(num/3,num%3,first);
                    win=first;
                }
                else
                {
                     ttt.insert(num/3,num%3,second);
                     win=second;
                }
                i=abs(3-i);
                ttt.display();
                if(ttt.winPlayer(num,win))
                {
                    cout<<"\n **** Yeah Player "<<win<<" won the Match ****\n"<<endl;
                    cntr=1;
                }
                cnt++;

                if(cnt==9||cntr==1)
                {
                    break;
                }
                }
                else
                {
                    cout<<"\nplease re-enter valid Index.."<<endl;
                    goto reenter;
                }
            }
        }
        else
        {
            cout<<"\n@ ...See You Again... @\n"<<endl;
            break;
        }
        if(cnt==9 && cntr==0)
        {
            cout<<"# Match Tie #"<<endl;
            break;
        }
        if(cntr==1)
        {
            break;
        }
    }
    system("pause");
}

