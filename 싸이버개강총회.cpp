#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int getHour(string& s) {
	string hour = "";
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == ':') {
			break;
		} 
		hour += s[i];
	}
	if (hour != "") {
		return stoi(hour);
	}
	else {
		return 0;
	}
}

int getMinute(string& s) {
	string minute = "";
	bool flag = false;
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == ':') {
			flag = true;
		}
		else if (s[i] == ' ') {
			flag = false;
		}
		else if (flag) {
			minute += s[i];
		}
	}
	if (minute != "") {
		return stoi(minute);
	}
	else {
		return 0;
	}
}

string getName(string& s) {
	bool flag = false;
	string name = "";
	for (int i = 0; i < (int)s.length(); ++i) {
		if (flag) {
			name += s[i];
		}
		if (s[i] == ' ') {
			flag = true;
		}
	}
	return name;
}

int main(void) {
	string S;
	string E;
	string Q;
	cin >> S >> E >> Q;
	string cur;
	int shour = getHour(S);
	int sminute = getMinute(S);
	int ehour = getHour(E);
	int eminute = getMinute(E);
	int qhour = getHour(Q);
	int qminute = getMinute(Q);
	cin.ignore();
	unordered_map<string, bool> student;

	while (getline(cin, cur)) {
		if (cur == "\z" || cur == "\n") break;

		int hour = getHour(cur);
		int minute = getMinute(cur);
		if (hour < shour) {
			// 출석
			student[getName(cur)] = false;
		}
		else if (hour == shour) {
			if (minute <= sminute) {
				// 출석
				student[getName(cur)] = false;
			}
			else {
				continue;
			}
		}
		else if (hour > shour&& hour < ehour) {
			continue;
		}
		else if (hour == ehour) {
			if (minute < eminute) {
				continue;
			}
			else {
				if (ehour == qhour) {
					if (minute >= eminute && minute <= qminute) {
						if (student.find(getName(cur)) != student.end()) {
							student[getName(cur)] = true;
						}
					}
				}
				else {
					// 출석 성공
					if (student.find(getName(cur)) != student.end()) {
						student[getName(cur)] = true;
					}
				}
			}
		}
		else if (hour > ehour&& hour < qhour) {
			// 출석 성공
			if (student.find(getName(cur)) != student.end()) {
				student[getName(cur)] = true;
			}
		}
		else if (hour == qhour) {
			if (minute <= qminute) {	// 출석 성공
				if (student.find(getName(cur)) != student.end()) {
					student[getName(cur)] = true;
				}
			}
		}
		else {
			continue;
		}
		cin.clear();
	}

	unordered_map<string, bool>::iterator it = student.begin();
	int cnt = 0;
	for (it = student.begin(); it != student.end(); ++it) {
		if ((*it).second) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}