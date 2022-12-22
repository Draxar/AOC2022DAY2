#include <fstream>
#include <iostream>
#include <string>
/*
A for Rock
B for Paper
C for Scissors
PA:
X for Rock
Y for Paper
Z for Scissors
PB:
X-lose
Y-draw
Z-win
*/
std::string translateA(std::string line)
{
  //X-A
  //Y-B
  //Z-C  
  switch (line[2]) {
  case 'X':
    line[2] = 'A';
    break;
    
  case 'Y':
    line[2] = 'B';
    break;

  case 'Z':
    line[2] = 'C';
    break;

  default:
    break;
  }
  return line;
}
std::string translateB(std::string line)
{
  //X-lose
  //Y-draw
  //Z-win
    switch (line[2]) {
  case 'X':
    if(line[0] == 'A')
      line[2] = 'C';
    else if(line[0] == 'B')
      line[2] = 'A';
    else 
      line[2] = 'B';
    break;
    
  case 'Y':
    line[2] = line[0];
    break;

  case 'Z':
    if(line[0] == 'A')
      line[2] = 'B';
    else if(line[0] == 'B')
      line[2] = 'C';
    else 
      line[2] = 'A';
    break;

  default:
    break;
  }
  return line;
}
int getScore(std::string line) {
  int ret = 0;

  //Our move value
  switch (line[2]) {
  case 'A':
    ret += 1;
    break;

  case 'B':
    ret += 2;
    break;

  case 'C':
    ret += 3;
    break;

  default:
    break;
  }

  //Win value
  if (line == "A B" || line == "B C" || line == "C A")
    ret += 6;
  //Draw value 
  else if (line == "A A" || line == "B B" || line == "C C")
    ret += 3;
  
  return ret;
}

int main() {

  std::ifstream myfile;
  std::string line;
  int ans1 = 0;
  int ans2 = 0;
  std::getline(myfile, line);
  myfile.open("input.txt");
  while (myfile) {
    ans1 += getScore(translateA(line));
    ans2 += getScore(translateB(line));
    std::getline(myfile, line);

  }
  std::cout << "Answer1: "<< ans1 << std::endl;
  std::cout << "Answer2: "<< ans2 << std::endl;
  
  return 0;
}