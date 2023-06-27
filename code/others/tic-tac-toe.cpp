# include <iostream>
using namespace std;

char ticks[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void print(){
    cout<<"     |     |     \n";
    cout<<"  " << ticks[0][0] << "  |  " << ticks[0][1] << "  |  " << ticks[0][2]<< "  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  " << ticks[1][0] << "  |  " << ticks[1][1] << "  |  " << ticks[1][2]<< "  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  " << ticks[2][0] << "  |  " << ticks[2][1] << "  |  " << ticks[2][2]<< "  \n";
    cout<<"     |     |     \n";   
}

int main(){
        print();

        for(int k=0 ; k<4 ; k ++){
            cout << "X chance, pick a number: \n";
            char selectednum ;
            cin >> selectednum;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(selectednum==ticks[i][j]){
                        ticks[i][j] = 'x';}
                    }
                }
            print();

            cout << " Now its the other persons turn, select a number: ";
            cin >> selectednum;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(selectednum==ticks[i][j]){
                        ticks[i][j] = 'o';}
                    }
                }
            print();
        }



    return 0;

}


/*
int main() 
{
    cout << "hwllo world";
    return 0;
}
*/
