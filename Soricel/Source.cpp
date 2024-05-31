#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

typedef std::pair<int, int> pozitie;

class Soarece
{
private:
	pozitie soarece, branza;
	std::queue<pozitie> drum;
	int** matrice;
	int n, m;
public:
	void citireMatrice()
	{
		std::ifstream f("date.txt");
		f >> n >> m;
		matrice = new int* [n];
		for (int i = 0; i < n; i++)
		{
			matrice[i] = new int[m];
			for (int j = 0; j < m; j++)
				f >> matrice[i][j];
		}
		f >> soarece.first >> soarece.second;
		f >> branza.first >> branza.second;
		drum.push(soarece);
		f.close();
	}
	void dealocareMatrice()
	{
		for (int i = 0; i < n; i++)
			delete[] matrice[i];
		delete[] matrice;
	}
	void drumul()
	{
		matrice[soarece.first][soarece.second] = 0;
		while (drum.front() != branza || drum.empty())
		{
			pozitie curenta = drum.front();
			drum.pop();
			if (curenta.second >= 1 && matrice[curenta.first][curenta.second - 1] == 0)
			{
				matrice[curenta.first][curenta.second - 1] = matrice[curenta.first][curenta.second] + 1;
				drum.push({ curenta.first,curenta.second - 1 });
			}
			if (curenta.second < m - 1 && matrice[curenta.first][curenta.second + 1] == 0)
			{
				matrice[curenta.first][curenta.second + 1] = matrice[curenta.first][curenta.second] + 1;
				drum.push({ curenta.first,curenta.second + 1 });
			}
			if (curenta.first >= 1 && matrice[curenta.first - 1][curenta.second] == 0)
			{
				matrice[curenta.first - 1][curenta.second] = matrice[curenta.first][curenta.second] + 1;
				drum.push({ curenta.first - 1,curenta.second });
			}
			if (curenta.first < n - 1 && matrice[curenta.first + 1][curenta.second] == 0)
			{
				matrice[curenta.first + 1][curenta.second] = matrice[curenta.first][curenta.second] + 1;
				drum.push({ curenta.first + 1,curenta.second });
			}
		}
		matrice[soarece.first][soarece.second] = 0;
		if (drum.front() == branza)
		{
			std::cout << "Drumul este\n";
			int i = branza.first, j = branza.second;
			std::cout << i << ' ' << j << '\n';
			do
			{
				if (j >= 1 && matrice[i][j - 1] == (matrice[i][j] - 1))
				{
					std::cout << i << ' ' << j - 1 << std::endl;
					j--;
					if (i == soarece.first && j == soarece.second)
						break;
				}
				if (j < m - 1 && matrice[i][j + 1] == (matrice[i][j] - 1))
				{
					std::cout << i << ' ' << j + 1 << std::endl;
					j++;
					if (i == soarece.first && j == soarece.second)
						break;
				}
				if (i >= 1 && matrice[i - 1][j] == (matrice[i][j] - 1))
				{
					std::cout << i - 1 << ' ' << j << std::endl;
					i--;
					if (i == soarece.first && j == soarece.second)
						break;
				}
				if (i < n - 1 && matrice[i + 1][j] == (matrice[i][j] - 1))
				{
					std::cout << i + 1 << ' ' << j << std::endl;
					i++;
					if (i == soarece.first && j == soarece.second)
						break;
				}
			} while (i != soarece.first || j != soarece.second);
		}
		else
			std::cout << "Nu se poate ajunge la branza";
	}
};

int main()
{
	Soarece soarece;
	soarece.citireMatrice();
	soarece.drumul();
	soarece.dealocareMatrice();
	return 0;
}