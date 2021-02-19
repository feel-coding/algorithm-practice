#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int defaultHp;
	int defaultMp;
	int defaultAttack;
	int defaultDefend;
	int hp;
	int mp;
	int attack;
	int defend;
	for (int i = 0; i < n; i++) {
		cin >> defaultHp >> defaultMp >> defaultAttack >> defaultDefend >> hp >> mp >> attack >> defend;
		hp = defaultHp + hp;
		mp = defaultMp + mp;
		attack = defaultAttack + attack;
		defend = defaultDefend + defend;
		if (hp < 1) hp = 1;
		if (mp < 1) mp = 1;
		if (attack < 0) attack = 0;
		cout << hp + 5 * mp + 2 * attack + 2 * defend << '\n';
	}
	return 0;
}