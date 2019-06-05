#include <iostream>
using namespace std;
#define ALPHABET_LEN 27

int main() {
	char alphabet[ALPHABET_LEN];
	for (int i = 1; i < ALPHABET_LEN; i++) {
		alphabet[i] = 'a' + (i - 1);
	}
	char n;
	while (cin >> n) {
		for (int i = 1; i < ALPHABET_LEN; i++) {
			if (n == alphabet[i]) {
				cout << i << endl;
			}
		}
	}
}
