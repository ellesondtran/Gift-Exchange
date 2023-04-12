//Elleson Tran
//Roberts
//Gift Exchange Program
//A program that randomly generates of who gives gifts to who
//FINAL

#include <iostream>
#include <ctime>
#include <vector>
 
using namespace std;

//makes the list of participants
void buildListNames(vector<string>&names){
  int num = 1;
  for(int x = 0; x < names.size(); x++){
    string name;
    cout<<"Person "<<num<<":";
    cin>>name;
    names[x] = name;

    num = num + 1;
  }
}

//makes the list of numbers to assign to the participants
void buildListIndexes(vector<int>&nums){
  for(int x = 0; x < nums.size(); x++){
    nums[x] = x;
  }  
}

//generates a random number that is not the assigned number
int getRandomNotYourself(vector<int>nums, int number){
  int randomNum = rand()%nums.size();
  while(randomNum == number){
    randomNum = rand()%nums.size();
  }
  if (randomNum != number){
    return randomNum;
  }
}

//swaps the two values in a vector
void Swap(vector<int>&nums, int firstNum, int secondNum){
  swap(nums[firstNum], nums[secondNum]);
}

//jumbles the vector, and makes sure that no one in the vector gets themselves
void jumble(vector<int>&nums){
  for (int x = 0; x < nums.size(); x++){
    Swap(nums, x, getRandomNotYourself(nums, x));
    if(nums[x] == x){
      Swap(nums, x, getRandomNotYourself(nums, x));
    }
  }
}

//prints out who buys a gift for who
void displayAssignments(vector<string>&names, vector<int>&nums){
  cout<<endl;
  for(int x = 0; x < nums.size(); x++){
    cout<<names[x]<<" buys a gift for "<<names[nums[x]]<<endl;
  }
}


int main(){
  srand(time(0));
  
  //number of participants
  int numPeople;
  cout<<"How many people? ";
  cin>>numPeople;
  
  //makes the list of participants
  vector<string>people(numPeople);
  buildListNames(people);

  //makes the list of numbers to assign to the participants
  vector<int>assignments(numPeople);
  buildListIndexes(assignments);


  jumble(assignments);
  displayAssignments(people, assignments);

  return 0;
}
