#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Node
{
public:
	char data;
	Node* prev;
	Node* next;
	Node()
	{
		data = '\0';
		prev = nullptr;
		next = nullptr;
	}
	Node(char const data)
	{
		this->data = data;
		prev = nullptr;
		next = nullptr;
	}
	~Node()
	{
		prev = nullptr;
		next = nullptr;
		delete prev, next;
	}
};
class DoublyLinkedList
{
	Node* head;
public:
	DoublyLinkedList()
	{
		head = nullptr;
	}
	void insertAtStart(char const data)
	{
		Node* temp = new Node(data);
		if (head == nullptr)
			head = temp;
		else
		{
			Node* temp2 = new Node(data);
			temp = head;
			temp2->next = temp;
			temp->prev = temp2;
			head = temp2;
			temp2 = nullptr;
			delete temp2;
		}
		temp = nullptr;
		delete temp;
	}
	void insertAtEnd(char const data)
	{
		Node* temp = new Node(data);
		if (head == nullptr)
			head = temp;
		else
		{
			temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
			Node* temp2 = new Node(data);
			temp2->prev = temp;
			temp->next = temp2;
			temp2 = nullptr;
			delete temp2;
		}
		temp = nullptr;
		delete temp;
	}
	void setData(int index, char const data)
	{
		if (checkLength(index) == true)
		{
			Node* temp = head;
			for (int i = 0; i <= index; i++)
			{
				if (i == index)
					temp->data = data;
				else
					temp = temp->next;
			}
			temp = nullptr;
			delete temp;
		}
		else
			cout << "Invalid Index\n";
	}
	char getData(int const index)
	{
		if (checkLength(index) == true)
		{
			if (head == nullptr)
				cout << "DoublyLinkedList is empty\n";
			else
			{
				Node* temp = head;
				for (int i = 0; i <= index; i++)
				{
					if (i == index)
						return temp->data;
					else
						temp = temp->next;
				}
			}
		}
		else
		{
			cout << "Invalid Index\n";
			return '-1';
		}
	}
	int getIndex(char const data)
	{
		if (head == nullptr)
			cout << "DoublyLinkedList is empty\n";
		else
		{
			Node* temp = head;
			for (int i = 0; temp != nullptr; i++)
			{
				if (temp->data == data)
					return i;
				else temp = temp->next;
			}
			temp = nullptr;
			delete temp;
		}
		return -1;
	}
	bool checkLength(int index)
	{
		if (head == nullptr)
			cout << "DoublyLinkedList is empty\n";
		else
		{
			Node* temp = head;
			int size = 0;
			for (int i = 0; temp != nullptr; i++, size++)
				temp = temp->next;
			temp = nullptr;
			delete temp;
			if (index <= size)
				return true;
			else
				return false;
		}
	}
	void print()
	{
		Node* temp = head;
		if (head == nullptr)
			cout << "DoublyLinkedList is empty\n";
		else
		{
			while (temp != nullptr)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
			temp = nullptr;
			delete temp;
		}
	}
	void print(int index)
	{
		if (head == nullptr)
			cout << "DoublyLinkedList is empty\n";
		else
		{
			cout << "okay\n";
			Node* temp = head;
			if (checkLength(index) == true)
			{
				for (int i = 0; i < index; i++)
				{
					cout << temp->data << " ";
					temp = temp->next;
				}
			}
			else
				cout << "Index is not valid\n";
			temp = nullptr;
			delete temp;
		}
	}
	void print(int stIndex, int endIndex)
	{
		if (head == nullptr)
			cout << "DoublyLinkedList is empty\n";
		else
		{
			if (checkLength(stIndex) == true && checkLength(endIndex) == true)
			{
				Node* temp = head;
				int i = 0;
				for (i; i < stIndex; i++)
					temp = temp->next;
				for (i; i < endIndex; i++)
				{
					cout << temp->data << "  ";
					temp = temp->next;
				}
			}

		}
	}
	~DoublyLinkedList()
	{
		head = nullptr;
		delete head;
	}
};
class PacManBoard
{
	DoublyLinkedList board;
	int score;
	bool apple; //checks whether pacMan has eaten apple or not
	int advantage; //if pacMan eats apple then advantage gives 10 chances to increase score after hitting ghosts
	int lives;
public:
	PacManBoard()
	{
		score = 0;
		apple = false;
		advantage = 0;
		lives = 3;
	}
	void setBoard()
	{
		for (int i = 0; i < 220; i++) //for all indexes
			board.insertAtEnd('.');
		for (int i = 0; i < 220; i++)
		{
			if (i < 20 || i > 199) //for first and last row
				board.setData(i, '_');
			if (i == 0 || i == 219) //for first and last index
				board.setData(i, '|');
			if (i % 20 == 0) //for first and last column
			{
				board.setData(i, '|');
				board.setData(i - 1, '|');
			}
			if (i == 42)
			{
				board.setData(i, '_');
				board.setData(i + 1, '_');
				board.setData(i + 20, '|');
				board.setData(i + 40, '|');
				board.setData(57, '_');
				board.setData(57 - 1, '_');
				board.setData(57 + 20, '|');
				board.setData(57 + 40, '|');
				board.setData(122, '|');
				board.setData(122 + 20, '|');
				board.setData(122 + 40, '_');
				board.setData(122 + 40 + 1, '_');
				board.setData(137, '|');
				board.setData(137 + 20, '|');
				board.setData(137 + 40, '_');
				board.setData(137 + 40 - 1, '_');
			}
			if (i == 25)
			{
				board.setData(i, '|');
				board.setData(i + 20, '|');
				board.setData(14 + 20, '|');
				board.setData(14 + 40, '|');
				board.setData(205 - 20, '|');
				board.setData(205 - 40, '|');
				board.setData(214 - 20, '|');
				board.setData(214 - 40, '|');
			}
			if (i == 84)
			{
				board.setData(i, '_');
				board.setData(i + 1, '_');
				board.setData(94, '_');
				board.setData(94 + 1, '_');
				board.setData(i + 40, '_');
				board.setData(i + 40 + 1, '_');
				board.setData(94 + 40, '_');
				board.setData(94 + 40 + 1, '_');
			}
			if (i == 47)
			{
				board.setData(i, '_');
				board.setData(i + 1, '_');
				board.setData(i + 2, '_');
				board.setData(i + 3, '_');
				board.setData(i + 4, '_');
				board.setData(i + 5, '_');
				board.setData(i + 120, '_');
				board.setData(i + 120 + 1, '_');
				board.setData(i + 120 + 2, '_');
				board.setData(i + 120 + 3, '_');
				board.setData(i + 120 + 4, '_');
				board.setData(i + 120 + 5, '_');
			}
			if (i == 87)
			{
				board.setData(i, '_');
				board.setData(i + 1, '_');
				board.setData(i + 4, '_');
				board.setData(i + 5, '_');
				board.setData(i + 20, '|');
				board.setData(i + 5 + 20, '|');
				board.setData(i + 40, '_');
				board.setData(i + 40 + 1, '_');
				board.setData(i + 40 + 2, '_');
				board.setData(i + 40 + 3, '_');
				board.setData(i + 40 + 4, '_');
				board.setData(i + 40 + 5, '_');
			}
			if (i == 151)
			{
				board.setData(i, 'P'); //for pacman
				//board.setData(i - 1, 'E'); //for ghost
				//board.setData(i - 2, 'e'); //for ghost
			}
			if (i == 21)
				board.setData(i, '1'); //for ghost1
			if (i == 150)
				board.setData(i, '2'); //for ghost2
			if (i == 198)
				board.setData(i, '3'); //for ghost3
		}
		placeapples(); //places apples
	}
	void placeapples() //places apples
	{
		for (int i = 0; i < 4; i++)
		{
		setapples:
			srand(time(0));
			int ran = rand() % 220;
			if (board.getData(ran) == '.')
				board.setData(ran, 'O');
			else
				goto setapples;
		}
		printBoard();
	}
	bool checkGhosts(int const index) //check whether ghost is at the index on board or not
	{
		if (board.getData(index) != '1' && board.getData(index) != '2' && board.getData(index) != '3')
			return false;
		else
			return true;
	}
	bool ghosteatPacMan(int index, int index2) //check whether pacMan hits ghost or not
	{
		//for ghost 1
		if ((board.getData(index) == '1' && board.getData(index2) == 'P') || (board.getData(index) == 'P' && board.getData(index2) == '1'))
		{
			if (apple == false) //if pacMan hits ghost and apple is false then lives--
			{
				board.setData(index, ' ');
				board.setData(index2, '1');
				if (lives > 0);
				board.setData(108, 'P'); //if pacMan gets hit by ghost then moves pacMan to index 98 if lives > 0
				cout << "\n\n\n***PacMan is being eaten by ghost***\n\n";
				lives--;
				printBoard();

				return true;
			}
			else //if pacMan hits ghost and apple is true then score=score+5
			{
				score = score + 5;
				board.setData(index2, 'P');
				board.setData(index, ' ');
				placeGhostRandomly('1');
				printBoard();
				return false;
			}
		}
		//for ghost 2
		else if ((board.getData(index) == '2' && board.getData(index2) == 'P') || (board.getData(index) == 'P' && board.getData(index2) == '2'))
		{
			if (apple == false)
			{
				board.setData(index, ' ');
				board.setData(index2, '2');
				if (lives > 0);
				board.setData(108, 'P'); //if pacMan gets hit by ghost then moves pacMan to index 98 if lives > 0
				cout << "\n\n\n***PacMan is being eaten by ghost***\n\n";
				lives--;
				printBoard();
				return true;
			}
			else
			{
				score = score + 5;
				board.setData(index2, 'P');
				board.setData(index, ' ');
				placeGhostRandomly('2');
				printBoard();
				return false;
			}
		}
		//for ghost 3
		else if ((board.getData(index) == '3' && board.getData(index2) == 'P') || (board.getData(index) == 'P' && board.getData(index2) == '3'))
		{
			if (apple == false)
			{
				board.setData(index, ' ');
				board.setData(index2, '3');
				if (lives > 0);
				board.setData(108, 'P'); //if pacMan gets hit by ghost then moves pacMan to index 98 if lives > 0
				cout << "\n\n\n***PacMan is being eaten by ghost***\n\n";
				lives--;
				printBoard();
				return true;
			}
			else
			{
				score = score + 5;
				board.setData(index2, 'P');
				board.setData(index, ' ');
				placeGhostRandomly('3');
				printBoard();
				return false;
			}
		}
		return false;
	}
	bool moveUp(char const data) //moves the data up on board
	{
		if (board.checkLength(board.getIndex(data) - 20) == true) //checks whether index is valid or not
		{
			int index = board.getIndex(data);
			if (board.getData(index - 20) != '|' && board.getData(index - 20) != '_' && checkGhosts(index - 20) == false) //if there is no wall
			{
				if (board.getData(index - 20) == 'O' && data == 'P') //if pacMan eats apple then Apple is true
				{
					apple = true;
					advantage = advantage + 10;
				}
				board.setData(index - 20, data);
				board.setData(index, ' ');
				return true;
			}
			else if (checkGhosts(index - 20) == true && data == 'P') //checks whether pacMan hits with ghost or not
			{
				ghosteatPacMan(index, index - 20);
				return true;
			}
		}
		return false;
	}
	bool moveDown(char const data) //moves the data down on board
	{
		if (board.checkLength(board.getIndex(data) + 20) == true)
		{
			int index = board.getIndex(data);
			if (board.getData(index + 20) != '|' && board.getData(index + 20) != '_' && checkGhosts(index + 20) == false)
			{
				if (board.getData(index + 20) == 'O' && data == 'P')
				{
					apple = true;
					advantage = advantage + 10;
				}
				board.setData(index + 20, data);
				board.setData(index, ' ');
				return true;
			}
			else if (checkGhosts(index + 20) == true && data == 'P')
			{
				ghosteatPacMan(index, index + 20);
				return true;
			}
		}
		return false;
	}
	bool moveLeft(char const data) //moves the data left on board
	{
		if (board.checkLength(board.getIndex(data) - 1) == true)
		{
			int index = board.getIndex(data);
			if (board.getData(index - 1) != '|' && board.getData(index - 1) != '_' && checkGhosts(index - 1) == false)
			{
				if (board.getData(index - 1) == 'O' && data == 'P')
				{
					apple = true;
					advantage = advantage + 10;
				}
				board.setData(index - 1, data);
				board.setData(index, ' ');
				return true;
			}
			else if (checkGhosts(index - 1) == true && data == 'P')
			{
				ghosteatPacMan(index, index - 1);
				return true;
			}
		}
		return false;
	}
	bool moveRight(char const data) //moves the data right on board
	{
		if (board.checkLength(board.getIndex(data) + 1) == true)
		{
			int index = board.getIndex(data);
			if (board.getData(index + 1) != '|' && board.getData(index + 1) != '_' && checkGhosts(index + 1) == false)
			{
				if (board.getData(index + 1) == 'O' && data == 'P')
				{
					apple = true;
					advantage = advantage + 10;
				}
				board.setData(index + 1, data);
				board.setData(index, ' ');
				return true;
			}
			else if (checkGhosts(index + 1) == true && data == 'P')
			{
				ghosteatPacMan(index, index + 1);
				return true;
			}
		}
		return false;
	}
	void placeGhostRandomly(const char data) //places Ghosts on random position if pacMan eats ghost
	{
	placeghostRandomly:
		srand(time(0));
		int ran = rand() % 220;
		//checks whether at random index there is wall or not
		if (board.getData(ran) != '|' && board.getData(ran) != '_' && board.getData(ran) != 'P' && board.getData(ran) != 'O' && board.getData(ran) != '1' && board.getData(ran) != '2' && board.getData(ran) != '3')
		{
			board.setData(ran, data);
		}
		else
			goto placeghostRandomly;
	}
	void moveGhosts(const char data) //move ghosts on board
	{
	moveGhost:
		srand(time(0));
		int ran = rand() % 4;
		if (ran == 0) //moves ghost up on board
		{
			if (moveUp(data) == false)
				goto moveGhost;
		}
		else if (ran == 1) //moves ghost down on board
		{
			if (moveDown(data) == false)
				goto moveGhost;
		}
		else if (ran == 2) //moves ghost left on board
		{
			if (moveLeft(data) == false)
				goto moveGhost;
		}
		else //moves ghost right on board
		{
			if (moveRight(data) == false)
				goto moveGhost;
		}
	}
	void movePacMan() //moves pacMan on board
	{
	inputkey:
		cout << "Enter key: ";
		char key = '\0';
		cin >> key;
		if (key == 'W' || key == 'A' || key == 'D' || key == 'S' || key == 'w' || key == 'a' || key == 'd' || key == 's')
		{
			if (key == 'W' || key == 'w')
			{
				if (moveUp('P') == false) //moves up
					goto inputkey;
			}
			else if (key == 'S' || key == 's')
			{
				if (moveDown('P') == false) //moves down
					goto inputkey;
			}
			else if (key == 'A' || key == 'a')
			{
				if (moveLeft('P') == false) //moves left
					goto inputkey;
			}
			else if (key == 'D' || key == 'd')
			{
				if (moveRight('P') == false) //moves right
					goto inputkey;
			}
			score++; //after every movement of Pacman score++
		}
		else
			goto inputkey;
		printBoard();
	}
	void game()
	{
		printBoard();
		for (int i = 0; lives > 0; i++)
		{
			if (advantage > 0) //if advantage > 0 then sets apple true
			{
				apple = true;
			}
			movePacMan();
			moveGhosts('1');
			moveGhosts('2');
			moveGhosts('3');
			printBoard();
			apple = false;
			if (advantage == 1) //if advantage is 1 then set advantage 0
				advantage = 0;
			else
				advantage--; //decreases advantage by 1
		}
	}
	void printBoard()
	{
		cout << "SCORE IS: " << score << endl;
		cout << "LIVES ARE: " << lives << endl;
		cout << "APPLE IS: " << apple << endl;
		for (int i = 0; i < 11; i++)
		{
			board.print(i * 20, (i + 1) * 20); //prints entries on new line after every 20th data
			cout << endl;
			cout << endl;
		}
	}
	~PacManBoard()
	{

	}
};
int main()
{
	PacManBoard p;
	p.setBoard();
	//p.printBoard();
	p.game();
	system("pause");
	return 0;
}