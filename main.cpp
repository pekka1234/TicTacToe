#include <iostream>
#include<string>
#include<chrono>
#include<sys/time.h>
#include <list>
#include<algorithm>
using namespace std;

string levels[3] = {"| |  | |  | |", "| |  | |  | |", "| |  | |  | |"};
list<int> usedSpots;

// places for levels places to mark X or O
int nums[3] = {1,6,11};

void mark();


//function for bot's turn
void botMark(){
  // checking milliseconds time and taking last digit of it so it gets a random number
  using namespace std::chrono;
  int ms = system_clock::now().time_since_epoch().count();
  const string MsToStr = to_string(ms); 
  char lastCharFromMsToStr = MsToStr[MsToStr.size()-1];
  int finalIntResult = lastCharFromMsToStr - '0';

  //checking if num is < 9 because tic tac toe has places 0-8 and checking if place is already used. If one those conditions are false, then function runs again
  if(finalIntResult < 9 && (find(usedSpots.begin(), usedSpots.end(), finalIntResult) == usedSpots.end())){
    levels[finalIntResult / 3][nums[finalIntResult % 3]] = 'O';
    system("clear");
    cout << levels[0] << endl << levels[1] << endl << levels[2] << endl << endl;
    usedSpots.push_front(finalIntResult);
    mark();
  }else{
    botMark();
  }
}


//function to gain place input from player and mark it
void mark(){
  int usersInput;
  cin >> usersInput;
  levels[usersInput / 3][nums[usersInput % 3]] = 'X';
  system("clear");
  cout << levels[0] << endl << levels[1] << endl << levels[2] << endl << endl;
  usedSpots.push_front(usersInput);
  botMark();
  mark();
}


int main() {
    mark();
    return 0;
} 


