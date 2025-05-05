//program to implement classes to find the area of different shapes

#include<iostream>
using namespace std;

class Area{
   private:
     int length;
     int breadth;
     int height;
   public:
     //parameterised constructor
     Area(int l,int b,int h){
        length = l;
        breadth = b;
        height = h;
     }
     int area_square();
     int area_rect();
     int area_cube();
     int area_cuboid();
     //destructor function
     ~Area(){
     }
};
int main(){

    int l,b,h;
    cout << "Enter the Length of side:";
    cin >> l;
    cout << "\nEnter the Breadth:";
    cin >> b;
    cout << "\nEnter the Height:";
    cin >> h;
    Area shape(l,b,h);
    int ch;
    
    while(true){
        cout << "\nChoose Shape whose Area is to be calculated\n";
        cout << "1.Square\n";
        cout << "2.Cube\n";
        cout << "3.Rectangle\n";
        cout << "4.Cuboid\n";
        cout << "5.Exit\n";
        cout << "Enter your choice (1-5):";
        cin >> ch;
        
        if(ch == 5){
            cout << "Exiting Program...";
            break;
        }

        switch(ch){
            case 1:
              cout << shape.area_square();
              break;

            case 2:
              cout << shape.area_cube();
              break;

            case 3:
              cout << shape.area_rect();
              break;

            case 4:
              cout << shape.area_cuboid();
              break;

            default:
              cout << "Invalid Choice!!";
              break;
                  
        }
    }

    
}

int Area::area_square(){
    return length*length;
}

int Area::area_cube(){
    return 6*length*length;
}

int Area::area_rect(){
    return length*breadth;
}

int Area::area_cuboid(){
    return 2*((length*breadth) + (breadth*height) + (length*height));
}