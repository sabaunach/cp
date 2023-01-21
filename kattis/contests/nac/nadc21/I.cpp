#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int starts[100000];

void solve() {
	fill(starts, starts+100000, 0);
	int n;
	cin >> n;
	int total = 0;
	int ts = 0;
	while (n--) {
		vector<int> hours, minutes, secs;
		string in;
		cin >> in;
		if (in[0] == '*') {
			hours = vector<int>(24);
			for (int i = 0; i < 24; i++)
				hours[i] = i;
		} else {
			stringstream stream(in);
			while (stream.good()) {
				string substr;
				getline(stream, substr, ',');
				if (substr.find("-") != std::string::npos) {
					stringstream stream2(substr);
					string first, last;
					getline(stream2, first, '-');
					getline(stream2, last, '-');
					for (int i = stoi(first); i <= stoi(last); i++)
						hours.push_back(i);
				} else {
					hours.push_back(stoi(substr));
				}
			}
		}
		
		cin >> in;
		if (in[0] == '*') {
			minutes = vector<int>(60);
			for (int i = 0; i < 60; i++)
				minutes[i] = i;
		} else {
			stringstream stream(in);
			while (stream.good()) {
				string substr;
				getline(stream, substr, ',');
				if (substr.find("-") != std::string::npos) {
					stringstream stream2(substr);
					string first, last;
					getline(stream2, first, '-');
					getline(stream2, last, '-');
					for (int i = stoi(first); i <= stoi(last); i++)
						minutes.push_back(i);
				} else {
					minutes.push_back(stoi(substr));
				}
			}
		}
		
		cin >> in;
		if (in[0] == '*') {
			secs = vector<int>(60);
			for (int i = 0; i < 60; i++)
				secs[i] = i;
		} else {
			stringstream stream(in);
			while (stream.good()) {
				string substr;
				getline(stream, substr, ',');
				if (substr.find("-") != std::string::npos) {
					stringstream stream2(substr);
					string first, last;
					getline(stream2, first, '-');
					getline(stream2, last, '-');
					for (int i = stoi(first); i <= stoi(last); i++)
						secs.push_back(i);
				} else {
					secs.push_back(stoi(substr));
				}
			}
		}
		
		/*for (int h: hours)
			cout << h << " ";
		cout << endl;
		for (int m: minutes)
			cout << m << " ";
		cout << endl;
		for (int s: secs)
			cout << s << " ";
		cout << endl;*/
		
		total += hours.size() * minutes.size() * secs.size();
		for (int h: hours) {
			for (int m: minutes) {
				for (int s: secs) {
					int index = h*60*60 + m*60 + s;
					if (!starts[index]) {
						starts[index] = 1;
						ts++;
					}
				}
			}
		}
	}
	cout << ts << " " << total;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
