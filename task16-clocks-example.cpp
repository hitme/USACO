#include <iostream>
#include <fstream>
#include <string>
#include <queue>
 
using namespace std;
 
class Clock {
public:
	int mask;
	char moves[50];
	int prev;
	int index;
 
	Clock(int states[9]) {
		mask = 0;
		for (int i = 0; i < 9; i++) {
			mask = put(mask, states[i], i);
		}
		index = 0;
		moves[index] = '0';
		index++;
		moves[index] = '\0';
	}
 
	Clock(int mask) {
		this->mask = mask;
		index = 0;
		moves[index] = '0';
		index++;
		moves[index] = '\0';
	}
 
	void move(int moveNum) {
		switch (moveNum) {
		case 1: {
			mask = put(mask, (get(mask, 'A' - 'A') + 1) % 4, 'A' - 'A');
			mask = put(mask, (get(mask, 'B' - 'A') + 1) % 4, 'B' - 'A');
			mask = put(mask, (get(mask, 'D' - 'A') + 1) % 4, 'D' - 'A');
			mask = put(mask, (get(mask, 'E' - 'A') + 1) % 4, 'E' - 'A');
			moves[index] = '1';
			index++;
			moves[index] = '\0';
			break;
		}
		case 2: {
			mask = put(mask, (get(mask, 'A' - 'A') + 1) % 4, 'A' - 'A');
			mask = put(mask, (get(mask, 'B' - 'A') + 1) % 4, 'B' - 'A');
			mask = put(mask, (get(mask, 'C' - 'A') + 1) % 4, 'C' - 'A');
			moves[index] = '2';
			index++;
			moves[index] = '\0';
			break;
		}
		case 3: {
			mask = put(mask, (get(mask, 'B' - 'A') + 1) % 4, 'B' - 'A');
			mask = put(mask, (get(mask, 'C' - 'A') + 1) % 4, 'C' - 'A');
			mask = put(mask, (get(mask, 'E' - 'A') + 1) % 4, 'E' - 'A');
			mask = put(mask, (get(mask, 'F' - 'A') + 1) % 4, 'F' - 'A');
			moves[index] = '3';
			index++;
			moves[index] = '\0';
			break;
		}
		case 4: {
			mask = put(mask, (get(mask, 'A' - 'A') + 1) % 4, 'A' - 'A');
			mask = put(mask, (get(mask, 'D' - 'A') + 1) % 4, 'D' - 'A');
			mask = put(mask, (get(mask, 'G' - 'A') + 1) % 4, 'G' - 'A');
			moves[index] = '4';
			index++;
			moves[index] = '\0';
			break;
		}
		case 5: {
			mask = put(mask, (get(mask, 'B' - 'A') + 1) % 4, 'B' - 'A');
			mask = put(mask, (get(mask, 'D' - 'A') + 1) % 4, 'D' - 'A');
			mask = put(mask, (get(mask, 'E' - 'A') + 1) % 4, 'E' - 'A');
			mask = put(mask, (get(mask, 'F' - 'A') + 1) % 4, 'F' - 'A');
			mask = put(mask, (get(mask, 'H' - 'A') + 1) % 4, 'H' - 'A');
			moves[index] = '5';
			index++;
			moves[index] = '\0';
			break;
		}
		case 6: {
			mask = put(mask, (get(mask, 'C' - 'A') + 1) % 4, 'C' - 'A');
			mask = put(mask, (get(mask, 'F' - 'A') + 1) % 4, 'F' - 'A');
			mask = put(mask, (get(mask, 'I' - 'A') + 1) % 4, 'I' - 'A');
			moves[index] = '6';
			index++;
			moves[index] = '\0';
			break;
		}
		case 7: {
			mask = put(mask, (get(mask, 'D' - 'A') + 1) % 4, 'D' - 'A');
			mask = put(mask, (get(mask, 'E' - 'A') + 1) % 4, 'E' - 'A');
			mask = put(mask, (get(mask, 'G' - 'A') + 1) % 4, 'G' - 'A');
			mask = put(mask, (get(mask, 'H' - 'A') + 1) % 4, 'H' - 'A');
			moves[index] = '7';
			index++;
			moves[index] = '\0';
			break;
		}
		case 8: {
			mask = put(mask, (get(mask, 'G' - 'A') + 1) % 4, 'G' - 'A');
			mask = put(mask, (get(mask, 'H' - 'A') + 1) % 4, 'H' - 'A');
			mask = put(mask, (get(mask, 'I' - 'A') + 1) % 4, 'I' - 'A');
			moves[index] = '8';
			index++;
			moves[index] = '\0';
			break;
		}
		case 9: {
			mask = put(mask, (get(mask, 'E' - 'A') + 1) % 4, 'E' - 'A');
			mask = put(mask, (get(mask, 'F' - 'A') + 1) % 4, 'F' - 'A');
			mask = put(mask, (get(mask, 'H' - 'A') + 1) % 4, 'H' - 'A');
			mask = put(mask, (get(mask, 'I' - 'A') + 1) % 4, 'I' - 'A');
			moves[index] = '9';
			index++;
			moves[index] = '\0';
			break;
		}
		default:
			break;
		}
	}
 
	int get(int mask, int from) {
		from *= 2;
		int to = from + 1;
		int num = ((1 << from) & mask) >> from;
		num |= ((1 << to) & mask) >> from;
		return num;
	}
 
	int put(int mask, int state, int from) {
		int anding = (~0) ^ (3 << (2 * from));
		mask &= anding;
		mask |= state << 2 * from;
		return mask;
	}
};
 
bool operator < (Clock a, Clock c)
{
	if (c.index < a.index) return true;
	if (c.index > a.index) return false;
	int cmp = strcmp(c.moves, a.moves);
	if (cmp < 0) return true;
	return false;
}
 
int main () {
	ifstream fin("clocks.in");
	ofstream fout ("clocks.out");
	int states[9];
	int fstates[] = { 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	for (int i = 0; i < 9; i++) {
		fin >> states[i];
		states[i] /= 3;
		states[i]--;
	}
	Clock start(states);
	Clock end(fstates);
	priority_queue<Clock> graph;
	bool visited[1000000];
	memset(visited, false, sizeof(visited));
	graph.push(start);
	while (!graph.empty()) {
		Clock current = graph.top();
		graph.pop();
		if (current.mask == end.mask) {
			for (int i = 1; i < current.index; i++)
			{
				if (i != 1) fout << " ";
				fout << current.moves[i];
			}
			fout << endl;
			return 0;
		}
		if (visited[current.mask]) {
			continue;
		}
		visited[current.mask] = true;
		for (int i = current.moves[current.index - 1] - '0'; i <= 9; i++) {
			Clock temp(current.mask);
			strcpy(temp.moves, current.moves);
			temp.index = current.index;
			temp.move(i);
			graph.push(temp);
		}
	}
	return 0;
}
