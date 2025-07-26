#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

vector<char> alphabets;
vector<char> sequence;
int L, C;

void backTracking(int depth, int start) {
	
	if (depth == L) {
		int vowel_count = 0;
		int consonant_count = 0;

		for (auto& s : sequence) {
			if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
				vowel_count++;
			}
			else {
				consonant_count++;
			}
		}

		if (vowel_count >= 1 && consonant_count >= 2) {
			for (auto& s : sequence) {
				cout << s;
			}
			cout << "\n";
		}

		return;
	}

	for (int i = start; i < C; i++) {
		sequence.push_back(alphabets[i]);
		backTracking(depth + 1, i+1);
		sequence.pop_back();
	}
}



int main() {
	cin >> L >> C;
	alphabets.resize(C);
	for (int i = 0; i < alphabets.size(); i++) {
		cin >> alphabets[i];
	}
	sort(alphabets.begin(), alphabets.end());
	
	
	backTracking(0, 0);

	return 0;
}