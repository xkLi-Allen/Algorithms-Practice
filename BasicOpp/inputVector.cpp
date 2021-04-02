# include<iostream>
# include<vector>
using namespace std;

vector<int> createVector() {
	cout << "input Vector" << endl;
	char c;
	int temp;
	cin >> temp;
	vector<int> input;
	input.push_back(temp);
	while ((c = getchar()) != '\n') {
		cin >> temp;
		input.push_back(temp);
	}
	return input;
}