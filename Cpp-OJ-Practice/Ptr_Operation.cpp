#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
vector<string> num;
string Str(string str);
int Int(string str);
string add();
int find() {
	string S, sN;
	cin >> S;
	S = Str(S);
	cin >> sN;
	int N = 0;
	N = Int(sN);
	int result = 0;
	result = num[N - 1].find(S);
	return result;}
int rfind() {
	string S, sN;
	cin >> S;
	S = Str(S);
	cin >> sN;
	int N = 0;
	N = Int(sN);
	int result = 0;
	result = num[N - 1].rfind(S);
	return result;}
int Int(string str) {
	int N=0;
	if (str == "find")	return find();
	else if (str == "rfind")	return rfind();
	else {
		const char *p = str.c_str();
		return *p - '0';}}
string copy() {
	string sN, sX, sL;
	int N = 0, X = 0, L = 0;
	cin >> sN;
	N = Int(sN);
	cin >> sX;
	X = Int(sX);
	cin >> sL;
	L = Int(sL);
	string result;
	result=num[N-1].substr(X, L);
	return result;
}
string Str(string str) {
	if (str == "copy")	return copy();
	if (str == "add")	return add();
	return str;}
string add() {
	string S1,S2,Sum;
	cin >> S1;
	S1 = Str(S1);
	cin >> S2;
	S2 = Str(S2);
	int judge = 1;
	if (S1.size() > 5 || S2.size() > 5)	judge = 2;
	else {
		for (int i = 0; i < S1.size(); i++) {
			if (!(S1[i] >= '0'&& S1[i] <= '9'))	judge = 2;}
		for (int i = 0; i < S2.size(); i++) {
			if (!(S2[i] >= '0'&& S2[i] <= '9'))	judge = 2;}}
	if (judge == 1) {
		int nS1 = atoi(S1.c_str());
		int nS2 = atoi(S2.c_str());
		int nSum = nS1 + nS2;
		Sum = to_string(nSum);}
	if (judge == 2) {	Sum = S1 + S2;}
	return Sum;}
int main() {
	int n=0;
     string s;
	cin >> n;
	while (n--) {
		cin >> s;
		num.push_back(s);}

	while (1) {
		cin >> s;
		if (s == "over")break;
		if (s == "print")
            {
			 string temp_s;
			 cin >> temp_s;
			 int N = 0;
			 N= Int(temp_s);
			 cout << num[N-1] << endl;
			}
		if (s == "add") add();
		if (s == "copy")	copy();
		if (s == "find")	find();
		if (s == "rfind")	rfind();
		if (s == "printall") {
			vector<string>::const_iterator p;
			for (p = num.begin(); p <= num.end(); p++) {
				cout << *p << endl;}}
		if (s == "insert") {
			string S
			cin >> S;
			S= Str(S);
			int N = 0, X = 0;
			string sN,sX;
			cin >> sN;
			N = Int(sN);
			cin >> sX;
			X = Int(sX);
			num[N - 1].insert(X,S);}
		if (str == "reset") {
			string S;
			cin >> S;
			S =Str(S);
			int N=0;
			string sN;
			cin >> sN;
			N = Int(sN);
			num[N - 1].assign(S);}}
	return 0;}
