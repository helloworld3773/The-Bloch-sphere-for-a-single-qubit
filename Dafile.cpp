#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void BS(int a);
int main() {
cout << "welcome to the bloch sphere simulation" << "\n" << "to quit the program, type \"Quit\"" << "\n" << "to change the state of the qubit, type \"X Gate\"" << "\n" << "note that this project is a work in progress and is not complete" << "\n";
int a = 1;
BS(a);
while (true) {
string u;
getline(cin,u);
if (u == "Quit") {
return 0;
}
else if (u == "X Gate") {
if (a == 1) {
a = 2;
BS(a);
}
else if (a == 2) {
a = 1;
BS(a);
}
else if ((a == 3) || (a == 4)) {
BS(a);
}
else if (a == 5) {
a = 6;
BS(a);
}
else {
a = 5;
BS(a);
}
}
}
}
void BS(int a) {
int r = 6;
double ar = 2.0; 
for (int y = -r; y <= r; ++y) {
for (int x = static_cast<int>(-r * ar); x <= static_cast<int>(r * ar); ++x) {
double nx = x / ar;
double d = sqrt(pow(nx,2)+ pow(y,2));
if (((y == 0) && ((x == static_cast<int>(-r * ar)) || (x == static_cast<int>(r * ar) - 2))) || (((y == -r) || (y == r)) && (x == -1)) || ((y == -4) && (x == static_cast<int>(ar * 4) - 2)) || ((y == 4) && (-x == static_cast<int>(ar * 4) + 1))) {
cout << "|";
}
else if (((y == 0) && (x == static_cast<int>(-r * ar) + 1)) || ((y == -4) && (x == static_cast<int>(ar * 4) - 1))) {
cout << "-";
}
else if (y == 0 && x == static_cast<int>(r * ar) - 1) {
cout << "+";
}
else if ((y == -4 && x == static_cast<int>(ar * 4)) || (y == 4 && -x == static_cast<int>(ar * 4))) {
cout << "i";
}
else if (y == -r && x == 0) {
cout << "0";
}
else if (y == r && x == 0) {
cout << "1";
}
else if (((y == 0) && ((x == static_cast<int>(-r * ar) + 2) || (x == static_cast<int>(r * ar)))) || ((x == 1) && ((y == -r) || (y == r))) || ((y == -4) && (x == static_cast<int>(ar * 4) + 1)) || ((y == 4) && (-x == static_cast<int>(ar * 4) - 1)) || ((y == 0) && (a == 3) && (x == r + 2))) {
cout << ">";
}
else if (a == 1 && (y == -r + 1 && x == 0)) {
cout << "^";
}
else if (((a == 1) && ((y < 0) && (x == 0) && (y > -r + 1))) || ((a == 2) && ((y > 0) && (x == 0) && (y > -r + 1)))) {
cout << "|";
}
else if (((a == 2) && ((y == r - 1) && (x == 1))) || ((a == 5) && ((0 >= y) && (y >= -3)) && ((y * static_cast<int>(ar * 4)) == (-4 * x))) || ((a == 6) && ((3 >= y) && (y >= 0)) && ((y * static_cast<int>(ar * 4)) == (-4 * x)))) {
cout << "/";
}
else if (a == 2 && (y == r - 1 && x == -1)) {
std::cout << "\\";
}
else if (((a == 3) && ((y == 0) && (x > 0) && (x < r + 2))) || ((a == 4) && (y == 0) && (x < 0) && (x > -r - 2))) {
cout << "-";
}
else if (a == 4 && y == 0 && x == -r - 2) {
cout << "<";
}
else if (d > r - 0.5 && d < r + 0.5) {
cout << "*";
} 
else {
cout << " ";
}
}
cout << "\n";
}
}
