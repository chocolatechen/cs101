#include<iostream>
#include<string>

using namespace std;

class Clock {
	public:
		int hr, min, sec;
		string mer;
		Clock(int a, int b, int c, string d) {
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (hr < 1 || hr > 12) {
				cout << "hour is out of range" << endl;
			} else  if (min < 0 || min > 59) {
				cout << "minute is out of range" << endl;
			} else if (sec < 0 || sec > 59) {
				cout << "second is out of range" << endl;
			} else if (mer != "AM" || mer != "PM") {
				cout << "meridian is wrong" << endl;
			} else {
				cout << hr << ":" << min << ":" << sec << " " << mer << endl;
			}
		}
};

class StandardClock : Clock {
	public:
		StandardClock(int a, int b, int c, string d) : Clock(a, b, c, d){
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (hr < 1 || hr > 12) {
				cout << "hour is out of range" << endl;
			} else  if (min < 0 || min > 59) {
				cout << "minute is out of range" << endl;
			} else if (sec < 0 || sec > 59) {
				cout << "second is out of range" << endl;
			} else if (mer != "AM" || mer != "PM") {
				cout << "meridian is wrong" << endl;
			} else {
				if (mer == "AM") {
					cout << "上午 " << hr << ":" << min << ":" << sec << endl;
				} else if (mer == "PM") {
					cout << "下午 " << hr << ":" << min << ":" << sec << endl;
				}
			}
		}
};

class MilitaryClock : Clock {
	public:
		MilitaryClock(int a, int b, int c, string d) : Clock(a, b, c, d){
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (hr < 1 || hr > 12) {
				cout << "hour is out of range" << endl;
			} else  if (min < 0 || min > 59) {
				cout << "minute is out of range" << endl;
			} else if (sec < 0 || sec > 59) {
				cout << "second is out of range" << endl;
			} else if (mer != "AM" || mer != "PM") {
				cout << "meridian is wrong" << endl;
			} else {
					if (mer == "AM") {
						cout << hr << ":" << min << ":" << sec << endl;
					} else if (mer == "PM") {
						cout << hr+12 << ":" << min << ":" << sec << endl;
					}
			}
		}
};

int main() {
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 25, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();
	return 0;
}
