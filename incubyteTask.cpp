#include<string>
#include<iostream>

using namespace std;

class space{

    int x,y,z;
    string dir;
    string prevdir;
    public:
    space(){
        x=0;
        y=0;
        z=0;
        dir="N";
    }
    void turn(string direction){
        if(direction=="l")
        {
            if(dir=="N")
               dir="W";
            else if(dir=="W")
               dir="S"; 
            else if(dir=="S")
               dir="E"; 
            else if(dir=="E")
               dir="N"; 
        }
        else if(direction=="r"){
        {
            if(dir=="N")
               dir="E";
            else if(dir=="E")
                dir="S"; 
            else if(dir=="S")
               dir="W"; 
            else if(dir=="W")
                dir="N"; 
        }
        }
        else if(direction=="u")
        {
            this->prevdir = this->dir;
            if(this->dir=="N")
               this->dir="U";
            else if(this->dir=="W")
               this->dir="U"; 
            else if(this->dir=="S")
               this->dir="U"; 
            else if(this->dir=="E")
               this->dir="U"; 
        }
        else if(direction=="d")
        {
            this->prevdir = this->dir;
            if(this->dir=="N")
               this->dir="D";
            else if(this->dir=="W")
               this->dir="D"; 
            else if(this->dir=="S")
               this->dir="D"; 
            else if(this->dir=="E")
               this->dir="D"; 
        }

    }
    void move(string direction){
        if(dir=="U"||dir=="D"){
            if(direction=="f"){
                z++;
            }
            else if(direction=="b"){
                z--;
            }
        }
        else if(dir=="N"||dir=="S"){
            if(direction=="f"){
                y++;
            }
            else if(direction=="b"){
                y--;
            }
        }
        else if(dir=="E"||dir==""){
            if(direction=="f"){
                x++;
            }
            else if(direction=="b"){
                x--;
            }
        }
        else if(this->dir=="U")
        {if(this->prevdir=="N")
                this->dir="W";
               if(this->prevdir=="S")
                this->dir="E";
               if(this->prevdir=="E")
                this->dir="N";
               if(this->prevdir=="W")
                this->dir="S";}
            else if(this->dir=="D"){
               if(this->prevdir=="N")
                this->dir="W";
               if(this->prevdir=="S")
                this->dir="E";
               if(this->prevdir=="E")
                this->dir="N";
               if(this->prevdir=="W")
                this->dir="S";
            }
            else if(this->dir=="U")
               if(this->prevdir=="N")
                this->dir="E";
               if(this->prevdir=="S")
                this->dir="W";
               if(this->prevdir=="E")
                this->dir="S";
               if(this->prevdir=="W")
                this->dir="N";
            else if(this->dir=="D"){
                 if(this->prevdir=="N")
                this->dir="E";
               if(this->prevdir=="S")
                this->dir="W";
               if(this->prevdir=="E")
                this->dir="S";
               if(this->prevdir=="W")
                this->dir="N";
            }
              
    }
    void action (string c)
    {
        if(c=="l" || c=="r")
        {
            turn(c);
        }
        else if(c=="f" || c=="b")
        {
            move(c);
        }
    }
    void display(){

        cout<<"position x "<<x<<endl;
        cout<<"position y "<<y<<endl;
        cout<<"position z "<<z<<endl;
        cout<<"Cordinates "<<"("<<x<<","<<y<<","<<z<<")"<<endl;
        cout<<"Direction "<<dir<<endl;
    }

};
int main(){
    space chandrayan;
    string commands[] ={"f","b","b","r","l"};
    for (string c : commands)
    {
        chandrayan.action(c);
    }
    chandrayan.display();

    return 0;
}