#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

typedef std::pair<int, int> position;

class Mouse
{
private:
	position m_mouse, m_cheese;
	std::queue<position> m_path;
	int** m_matrix=nullptr;
	int m_rows=0, m_column=0;
public:
	void ReadMatrix()
	{
		std::ifstream f("date.txt");
		f >> m_rows >> m_column;
		m_matrix = new int* [m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_matrix[i] = new int[m_column];
			for (int j = 0; j < m_column; j++)
				f >> m_matrix[i][j];
		}
		f >> m_mouse.first >> m_mouse.second;
		f >> m_cheese.first >> m_cheese.second;
		m_path.push(m_mouse);
		f.close();
	}
	void DeallocateMatrix()
	{
		for (int i = 0; i < m_rows; i++)
			delete[] m_matrix[i];
		delete[] m_matrix;
	}
	void Path()
	{
		m_matrix[m_mouse.first][m_mouse.second] = 0;
		while (m_path.front() != m_cheese || m_path.empty())
		{
			position current = m_path.front();
			m_path.pop();
			if (current.second >= 1 && m_matrix[current.first][current.second - 1] == 0)
			{
				m_matrix[current.first][current.second - 1] = m_matrix[current.first][current.second] + 1;
				m_path.push({ current.first,current.second - 1 });
			}
			if (current.second < m_column - 1 && m_matrix[current.first][current.second + 1] == 0)
			{
				m_matrix[current.first][current.second + 1] = m_matrix[current.first][current.second] + 1;
				m_path.push({ current.first,current.second + 1 });
			}
			if (current.first >= 1 && m_matrix[current.first - 1][current.second] == 0)
			{
				m_matrix[current.first - 1][current.second] = m_matrix[current.first][current.second] + 1;
				m_path.push({ current.first - 1,current.second });
			}
			if (current.first < m_rows - 1 && m_matrix[current.first + 1][current.second] == 0)
			{
				m_matrix[current.first + 1][current.second] = m_matrix[current.first][current.second] + 1;
				m_path.push({ current.first + 1,current.second });
			}
		}
		m_matrix[m_mouse.first][m_mouse.second] = 0;
		if (m_path.front() == m_cheese)
		{
			std::cout << "The path is:\n";
			int i = m_cheese.first, j = m_cheese.second;
			std::cout << i << ' ' << j << '\n';
			do
			{
				if (j >= 1 && m_matrix[i][j - 1] == (m_matrix[i][j] - 1))
				{
					std::cout << i << ' ' << j - 1 << std::endl;
					j--;
					if (i == m_mouse.first && j == m_mouse.second)
						break;
				}
				if (j < m_column - 1 && m_matrix[i][j + 1] == (m_matrix[i][j] - 1))
				{
					std::cout << i << ' ' << j + 1 << std::endl;
					j++;
					if (i == m_mouse.first && j == m_mouse.second)
						break;
				}
				if (i >= 1 && m_matrix[i - 1][j] == (m_matrix[i][j] - 1))
				{
					std::cout << i - 1 << ' ' << j << std::endl;
					i--;
					if (i == m_mouse.first && j == m_mouse.second)
						break;
				}
				if (i < m_rows - 1 && m_matrix[i + 1][j] == (m_matrix[i][j] - 1))
				{
					std::cout << i + 1 << ' ' << j << std::endl;
					i++;
					if (i == m_mouse.first && j == m_mouse.second)
						break;
				}
			} while (i != m_mouse.first || j != m_mouse.second);
		}
		else
			std::cout << "The cheese cannot be reached.";
	}
};

int main()
{
	Mouse mouse;
	mouse.ReadMatrix();
	mouse.Path();
	mouse.DeallocateMatrix();
	return 0;
}