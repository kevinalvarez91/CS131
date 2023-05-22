#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Define the dimensions of the grid
const int ROWS = 5;
const int COLS = 5;

// Define the possible movement directions
const int NUM_DIRECTIONS = 4;
const int dx[NUM_DIRECTIONS] = {-1, 0, 1, 0}; // Left, Up, Right, Down
const int dy[NUM_DIRECTIONS] = {0, -1, 0, 1};

// Node class representing a cell in the grid
class Node {
	public:
		int row;
		int col;
		int g; // g-score
		int h; // h-score (heuristic)
		int f; // f-score = g + h
		Node* parent;

		Node(int row, int col, int g, int h, Node* parent = nullptr)
			: row(row), col(col), g(g), h(h), f(g + h), parent(parent) {}

		// Comparison operator for priority queue
		bool operator<(const Node& other) const {
			return f > other.f; // Lower f-score has higher priority
		}
};

// A* search function
void aStarSearch(vector<vector<int>>& grid, Node start, Node goal) {
	priority_queue<Node> openList;
	openList.push(start);

	vector<vector<int>> gScore(ROWS, vector<int>(COLS, INT_MAX)); // g-scores for all cells, initialized to infinity 
	gScore[start.row][start.col] = 0;

	vector<vector<Node*>> cameFrom(ROWS, vector<Node*>(COLS, nullptr)); // Parent pointers for all cells

	while (!openList.empty()) {
		Node current = openList.top();
		openList.pop();

		if (current.row == goal.row && current.col == goal.col) {
			// Goal reached
			cout << "Path found!" << endl;
			return;
		}

		// Explore neighbors
		for (int i = 0; i < NUM_DIRECTIONS; ++i) {
			int newRow = current.row + dx[i];
			int newCol = current.col + dy[i];

			if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && grid[newRow][newCol] != 1) {
				int tentativeGScore = gScore[current.row][current.col] + 1;

				if (tentativeGScore < gScore[newRow][newCol]) {
					// Update g-score and f-score
					gScore[newRow][newCol] = tentativeGScore;
					int h = abs(newRow - goal.row) + abs(newCol - goal.col); // Manhattan distance heuristic
					Node neighbor(newRow, newCol, tentativeGScore, h, &current);
					openList.push(neighbor);
					cameFrom[newRow][newCol] = &current;
				}
			}
		}
	}

	// No path found
	cout << "No path found!" << endl;
}

int main() {
	// Example usage

	// Define the grid
	vector<vector<int>> grid = {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 0}
	};

	// Define the start and goal nodes
	Node start(0, 0, 0, 0);
	Node goal(4, 4, 0, 0);

	// Run A* search
	aStarSearch(grid, start, goal);

	return 0;

}
