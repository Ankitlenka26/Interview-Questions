#include<iostream>
using namespace std ; 
class Student{
    private : 
    int rollNumber;  // the properties of the class objects are stored here 
    int age; 
    public : 
    // constructor : 
    Student(){
        this->age = 0 ;
        this->rollNumber = 0;
    }
    // function overlaoding in constructors 
    Student(int a){
        this->age = a ; 
        this->rollNumber = 0;
    }
    // Student(int r){
    //     this->age = 0 ; 
    //     this->rollNumber = r; 
    // }
    Student(int a , int r){
        this->age = a; 
        this->rollNumber = r;
    }
    void setAge(int x){
        if(x < 0){
            return ; // we  don't want negative values in age because a person can never be of -2 years 
        }
        this->age = x ; 
    }
    int getAge(){
        return this->age; 
    }
    void setRollNumber(int y){
        if(y<0){
            return ; // we don't want negative values in rollnumbers because it does not make any sense 
        }
        this->rollNumber = y ; 
    }
    int getRollNumber(){
        return this->rollNumber; 
    }
}; 

// by default access modifier of a class is private 

int main(){
    // static allocation of objects
    Student s1;  // simple declaration of object of Type Student(user defined data type) 
    // due to the above statement and the structure of the class just like how we make a 4bytes memory for int this declaration wil 
    // also create a memory allocation of ALMOST 8 bytes . Note : not exactly 8 bytes there are other details associated with class as well
    // dynamic allocation of objects 
    Student *s2 = new Student; // objet is now located in the heap memory 
    
    // // initialising the above objects 
    // s1.age = 19 ; 
    // s1.rollNumber = 2101 ; 
    // s2->age = 21;  // OR we can also write like this *s2.age = 21 ;  
    // s2->rollNumber = 4598 ; 

    // if we want to access any of the private property we have to access it using a public func
    // getters and setters 
    // they help in ensuring some amount of encapsulation from the user and ensures that member values are not getting initialised with absurd values 
    s1.setAge(20); 
    s2->setAge(22); 

    s1.setRollNumber(2101); 
    s2->setRollNumber(2095); 

    cout << s1.getAge() << " " << s1.getRollNumber() << endl ;

    Student s3 ; // constructor 1 called 
    Student s4(19); // constructor 2 called 
    Student s5(19,2101); // constructor 3 called 
    return 0; 
}  