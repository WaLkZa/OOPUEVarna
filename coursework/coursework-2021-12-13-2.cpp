#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

const int SMALL_CHILD_MAX_AGE = 7;
const int YOUNG_CHILD_MAX_AGE = 12;
const int OLDER_CHILD_MAX_AGE = 18;

// Цена на стандартен билет в левове.
const double DEFAULT_TICKET_PRICE = 20;

// Намаления за индивидуални хора.
const double YOUNG_CHILD_DISCOUNT = 0.30; // Намаление за деца между 7 и 12 години.
const double OLDER_CHILD_DISCOUNT = 0.25; // Намаление за деца между 13 и 18 години.
const double STUDENT_DISCOUNT = 0.20;	  // Намаление за студенти.
const double ELDERLY_DISCOUNT = 0.25;	  // Намаление за възрастни.

// Намаления за групи от хора.
const double FAMILY_DISCOUNT = 0.13;	   // Намаление за семейства.
const double SCHOOL_GROUP_DISCOUNT = 0.20; // Намаление за групи, идващи от училища (учител + деца).

using namespace std;

class ISerializable
{
public:
	virtual string serialize() = 0;
};

// Купувач на билет.
//
// Това е общ клас, който описва всички купувачи на билети.
// За всеки купувач на билет се следи неговото име (name) и се изчислява
// поотделно каква е цената на билета му (calculateTicketPrice()).
//
// Класът също поддържа изписване на информация за купувача (printInfo()).
class TicketBuyer : public ISerializable
{
public:
	// Изпиши информация за купувача на командния ред.
	virtual void printInfo() = 0;

	// Изчисли цената на билета за даден купувач.
	virtual double calculateTicketPrice() = 0;

	// Функция, връщаща името на клиента.
	string getName()
	{
		return this->name;
	}

	// Функция, задаваща името на клиента. Прави няколко проверки за валидност
	// и хвърля invalid_argument exception при грешка.
	void setName(string name)
	{
		if (name.empty())
		{
			throw invalid_argument("Name cannot be empty!");
		}

		if (name.length() < 3)
		{
			throw invalid_argument("Name must be at least 3 symbols.");
		}

		this->name = name;
	}

protected:
	string name;

	TicketBuyer(string name)
	{
		setName(name);
	}
};

// Малолетен посетител на музея.
//
// Според възрастта на малолетния:
//	- под 7 години - билета е безплатен
//	- между 7 и 12 години - билета е намален с 30%
//	- между 13 и 18 години - билета е намален с 25%
class Child : public TicketBuyer
{
public:
	Child(string name, int age) : TicketBuyer(name)
	{
		setAge(age);
	}

	string serialize() override
	{
		stringstream ss;
		ss << "Child\t" << name << '\t' << age;
		return ss.str();
	}

	virtual void printInfo()
	{
		cout << "Child name: " << name << ", age: " << age << ", ticket price: " << calculateTicketPrice() << endl;
	}

	virtual double calculateTicketPrice()
	{
		if (age < SMALL_CHILD_MAX_AGE)
		{
			// Билетите са безплатни за деца под 7 години.
			return 0;
		}
		else if (age <= YOUNG_CHILD_MAX_AGE)
		{
			// Цената на билета за дете м/у 7 и 12 години е намалена с 30%.
			return DEFAULT_TICKET_PRICE * (1 - YOUNG_CHILD_DISCOUNT);
		}
		else
		{
			// Цената на билета за дете м/у 13 и 18 години е намалена с 25%.
			return DEFAULT_TICKET_PRICE * (1 - OLDER_CHILD_DISCOUNT);
		}
	}

	// Функция, която връща възрастта на детето.
	int getAge()
	{
		return this->age;
	}

	// Функция, която задава възрастта на дете. Прави проверка за валидност и
	// хвърля invalid_argument при провал.
	void setAge(int age)
	{
		if (age < 0 || age >= OLDER_CHILD_MAX_AGE)
		{
			throw invalid_argument("Child's age must be between 0 and 18 years.");
		}

		this->age = age;
	}

private:
	int age;
};

// Клас за студент.
class Student : public TicketBuyer
{
public:
	Student(string name) : TicketBuyer(name) {}

	string serialize() override
	{
		stringstream ss;
		ss << "Student\t" << name;
		return ss.str();
	}

	virtual void printInfo()
	{
		cout << "Student name: " << getName() << ", Ticket Price: " << calculateTicketPrice() << endl;
	}

	virtual double calculateTicketPrice()
	{
		return DEFAULT_TICKET_PRICE * (1 - STUDENT_DISCOUNT);
	}
};

// Клас за пълнолетни посетители на музея.
class Adult : public TicketBuyer
{
public:
	Adult(string name) : TicketBuyer(name) {}

	string serialize() override
	{
		stringstream ss;
		ss << "Adult\t" << name;
		return ss.str();
	}

	virtual void printInfo()
	{
		cout << "Adult name: " << getName() << ", Ticket Price: " << calculateTicketPrice() << endl;
	}

	virtual double calculateTicketPrice()
	{
		return DEFAULT_TICKET_PRICE;
	}
};

// Клас за пенсионери.
class Elderly : public TicketBuyer
{
public:
	Elderly(string name) : TicketBuyer(name) {}

	string serialize() override
	{
		stringstream ss;
		ss << "Elderly\t" << name;
		return ss.str();
	}

	virtual void printInfo()
	{
		cout << "Pensioner name: " << getName() << ", Ticket Price: " << calculateTicketPrice() << endl;
	}

	virtual double calculateTicketPrice()
	{
		return DEFAULT_TICKET_PRICE * (1 - ELDERLY_DISCOUNT);
	}
};

class Family : public TicketBuyer
{
public:
	Family(string familyName) : TicketBuyer(familyName) {}

	string serialize() override
	{
		stringstream ss;
		ss << "Family\t" << name << "\t";

		ss << "Parents";
		for (int i = 0; i < parents.size(); i++)
		{
			ss << "\t" << parents[i]->getName();
		}

		ss << "\tChildren";
		for (int i = 0; i < children.size(); i++)
		{
			ss << "\t" << children[i]->getName() << "\t" << children[i]->getAge();
		}

		return ss.str();
	}

	virtual void printInfo()
	{
		// Изписва "Семейство [еди-кои-си] с [брой деца + брой родители] членове".
		cout << "Family '" << name << "' of " << parents.size() + children.size() << ":\n";

		// След което изписва информация за родителите и децата с два интервала индентация.
		for (int i = 0; i < parents.size(); i++)
		{
			cout << "  ";
			parents[i]->printInfo();
		}

		for (int i = 0; i < children.size(); i++)
		{
			cout << "  ";
			children[i]->printInfo();
		}
	}

	virtual double calculateTicketPrice()
	{
		if (children.empty() || parents.empty())
		{
			throw logic_error("There must be at least one parent and one child.");
		}

		if (parents.size() > 2)
		{
			throw logic_error("There can't be more than two parents.");
		}

		double parentsSum = 0;
		double childrenSum = 0;

		for (int i = 0; i < parents.size(); i++)
		{
			parentsSum += parents[i]->calculateTicketPrice();
		}

		for (int i = 0; i < children.size(); i++)
		{
			childrenSum += children[i]->calculateTicketPrice();
		}

		// Прилагаме 5% допълнителна отстъпка от цената на билетите за децата
		// за всяко дете след второто.
		childrenSum *= 1 - 0.05 * (children.size() - 1);

		return (parentsSum + childrenSum) * (1 - FAMILY_DISCOUNT);
	}

	void addParent(string firstName)
	{
		parents.push_back(new Adult(firstName));
	}

	void addChild(string firstName, int age)
	{
		if (children.size() > 6)
		{
			throw logic_error("There can't be more than six childrens.");
		}

		children.push_back(new Child(firstName, age));
	}

private:
	vector<Adult *> parents;
	vector<Child *> children;
};

class SchoolGroup : public TicketBuyer
{
public:
	SchoolGroup(string schoolName, string teacherName) : TicketBuyer(schoolName)
	{
		teacher = new Adult(teacherName);
	}

	string serialize() override
	{
		stringstream ss;
		ss << "SchoolGroup\t" << name << '\t' << teacher->getName() << '\t';

		ss << "Children";
		for (int i = 0; i < children.size(); i++)
		{
			ss << "\t" << children[i]->getName() << '\t' << children[i]->getAge();
		}

		return ss.str();
	}

	virtual void printInfo()
	{
		cout << name << " - a group of " << children.size() << " children and a teacher:\n";

		cout << "  Teacher: ";
		teacher->printInfo();

		for (int i = 0; i < children.size(); i++)
		{
			cout << "  ";
			children[i]->printInfo();
		}
	}

	void addChild(string name, int age)
	{
		children.push_back(new Child(name, age));
	}

	virtual double calculateTicketPrice()
	{
		if (children.size() < 5)
		{
			throw logic_error("School Group must have at least 5 children.");
		}

		double teacherPrice = teacher->calculateTicketPrice();
		double childrenSum = 0;

		for (int i = 0; i < children.size(); i++)
		{
			childrenSum += children[i]->calculateTicketPrice();
		}

		childrenSum *= 1 - (0.025 * children.size());

		return (teacherPrice + childrenSum) * (1 - SCHOOL_GROUP_DISCOUNT);
	}

private:
	Adult *teacher;
	vector<Child *> children;
};

class VisitorManager
{
public:
	void add(TicketBuyer *ptr)
	{
		visitors.push_back(ptr);
	}

	void list()
	{
		if (visitors.empty())
		{
			cout << "No people in queue\n";
			return;
		}

		cout << "People in queue:\n"
			 << "------------------\n";

		for (int i = 0; i < visitors.size(); i++)
		{
			visitors[i]->printInfo();
		}
	}

	void deleteFirst()
	{
		if (visitors.empty())
		{
			cout << "No people in queue\n";
			return;
		}

		cout << "Processing:\n";
		visitors[0]->printInfo();

		visitors.erase(visitors.begin());
	}

	vector<TicketBuyer *> getVisitors()
	{
		return visitors;
	}

	double getTotalProfit()
	{
		double sum = 0;

		for (int id = 0; id < visitors.size(); id++)
		{
			try
			{
				sum += visitors[id]->calculateTicketPrice();
			}
			catch (const exception &e)
			{
				cerr << "ERROR: Adding to sum failed - " << e.what() << endl;
			}
		}

		return sum;
	};

	double getAverageProfit()
	{
		return getTotalProfit() / visitors.size();
	};

	double getVAT()
	{
		return getTotalProfit() * 1.2;
	};

private:
	vector<TicketBuyer *> visitors;
};

void SaveToDisk(VisitorManager &visMan)
{
	ofstream visitorsFile("museum-data-visitors.txt");

	for (auto &v : visMan.getVisitors())
		visitorsFile << v->serialize() << '\n';

	visitorsFile.close();
}

vector<string> split(string &str, char delim)
{
	vector<string> res;
	enum State
	{
		Delim,
		Char
	};

	State currState = (str[0] == delim ? Delim : Char);

	auto it = str.begin();
	it++;
	auto wordStart = (currState == Char ? str.begin() : it);

	while (it != str.end())
	{
		State newState = (*it == delim ? Delim : Char);

		if (newState == currState)
		{
			it++;
		}
		else if (newState == Delim)
		{
			res.push_back(
				str.substr(
					distance(str.begin(), wordStart),
					distance(wordStart, it)));
			it++;
		}
		else if (newState == Char)
		{
			wordStart = it;
			it++;
		}

		currState = newState;
	}

	if (currState == Char)
		res.push_back(
			str.substr(
				distance(str.begin(), wordStart),
				distance(wordStart, it)));

	return res;
}

string trim(string s)
{
	if (s.empty())
		return "";

	const char *whitespaceChars = "\n\t \r";

	size_t str_start = s.find_first_not_of(whitespaceChars);
	size_t str_end = s.find_last_not_of(whitespaceChars);

	if (str_start == string::npos)
		return "";

	return s.substr(str_start, str_end + 1 - str_start);
}

void LoadFromDisk(VisitorManager &visMan)
{
	ifstream visitorsData("museum-data-visitors.txt");

	if (!visitorsData.is_open())
	{
		return;
	}

	string line;
	while (getline(visitorsData, line))
	{
		vector<string> data = split(line, '\t');

		string typeInput = data[0],
			   name = data[1];

		if (typeInput == "Child")
		{
			visMan.add(new Child(name, stoi(data[2])));
		}
		else if (typeInput == "Student")
		{
			visMan.add(new Student(name));
		}
		else if (typeInput == "Adult")
		{
			visMan.add(new Adult(name));
		}
		else if (typeInput == "Elderly")
		{
			visMan.add(new Elderly(name));
		}
		else if (typeInput == "Family")
		{
			Family *f = new Family(name);

			int i = 3;
			for (; i < data.size() && data[i] != "Children"; i++)
			{
				f->addParent(data[i]);
			}

			for (i += 1; i < data.size(); i += 2)
			{
				f->addChild(data[i], stoi(data[i + 1]));
			}

			visMan.add(f);
		}
		else if (typeInput == "SchoolGroup")
		{
			SchoolGroup *sg = new SchoolGroup(name, data[2]);

			for (int i = 4; i < data.size(); i += 2)
			{
				sg->addChild(data[i], stoi(data[i + 1]));
			}

			visMan.add(sg);
		}
		else
		{
			cerr << "ERROR: Unrecognized visitor type \"" << typeInput << "\"" << endl;
		}
	}

	visitorsData.close();
}

int main()
{
	VisitorManager visManager;
	int choice;

	LoadFromDisk(visManager);

	do
	{
		cout << "\n\n"
			 << "MENU\n"
			 << "==================================\n"
			 << "1. Add a student\n"
			 << "2. Add an adult\n"
			 << "3. Add a pensioner\n"
			 << "4. Add a family.\n"
			 << "5. Add a school group\n"
			 << "6. List all\n"
			 << "7. Delete first entry\n"
			 << "8. Total profit\n"
			 << "0. Exit\n"
			 << "CHOOSE AN OPTION: ";

		cin >> choice;
		cin.ignore(100, '\n');

		string name;

		if (choice > 0 && choice < 6)
		{
			cout << "Name: ";
			getline(cin, name);
		}

		switch (choice)
		{
		case 1:
			try
			{
				visManager.add(new Student(name));
			}
			catch (const exception &e)
			{
				cerr << e.what() << endl;
			}
			break;
		case 2:
			try
			{
				visManager.add(new Adult(name));
			}
			catch (const exception &e)
			{
				cerr << e.what() << endl;
			}
			break;
		case 3:
			try
			{
				visManager.add(new Elderly(name));
			}
			catch (const exception &e)
			{
				cerr << e.what() << endl;
			}
			break;

		case 4:
		{
			Family *f;

			try
			{
				f = new Family(name);
			}
			catch (const exception &e)
			{
				cerr << "ERROR: Couldn't create family - " << e.what() << endl;
				break;
			}

			do
			{
				cout << "0. Finish\n"
					 << "1. Add parent\n"
					 << "2. Add child\n"
					 << "3. Preview\n"
					 << ">> ";

				int input;
				cin >> input;
				cin.ignore(100, '\n');

				if (input == 0)
				{
					break;
				}

				if (input < 1 || input > 3)
				{
					cout << "Please enter a number between 1 and 3.\n";
					continue;
				}

				if (input == 1)
				{
					cout << "  Parent's first name: ";

					string parentName;
					getline(cin, parentName);

					try
					{
						f->addParent(parentName);
					}
					catch (const exception &e)
					{
						cerr << "ERROR: Couldn't add parent - " << e.what() << endl;
					}
				}
				else if (input == 2)
				{
					cout << "  Child's first name: ";

					string childName;
					getline(cin, childName);

					cout << "  Child's age: ";

					int childAge;
					cin >> childAge;
					cin.ignore(100, '\n');

					try
					{
						f->addChild(childName, childAge);
					}
					catch (const exception &e)
					{
						cerr << "ERROR: Couldn't add child - " << e.what() << endl;
					}
				}
				else
				{
					cout << "-------------\n";
					f->printInfo();
					cout << "-------------\n\n";
				}
			} while (true);

			visManager.add(f);
		}
		break;

		case 5:
		{
			SchoolGroup *sg;

			try
			{
				cout << "Teacher's name: ";

				string teacherName;
				getline(cin, teacherName);

				sg = new SchoolGroup(name, teacherName);
			}
			catch (const exception &e)
			{
				cerr << "ERROR: Couldn't create school group - " << e.what() << endl;
				break;
			}

			do
			{
				cout << "0. Finish\n"
					 << "1. Add child\n"
					 << "2. Preview\n"
					 << ">> ";

				int input;
				cin >> input;
				cin.ignore(100, '\n');

				if (input == 0)
				{
					break;
				}

				if (input < 0 || input > 2)
				{
					cout << "Please enter either 1 or 2.\n";
					continue;
				}

				if (input == 1)
				{
					cout << "  Child's first name: ";

					string childName;
					getline(cin, childName);

					cout << "  Child's age: ";

					int childAge;
					cin >> childAge;
					cin.ignore(100, '\n');

					try
					{
						sg->addChild(childName, childAge);
					}
					catch (const exception &e)
					{
						cerr << "ERROR: Couldn't add child - " << e.what() << endl;
					}
				}
				else
				{
					cout << "-------------------\n";
					sg->printInfo();
					cout << "-------------------\n\n";
				}
			} while (true);

			visManager.add(sg);
		}
		break;

		case 6:
			visManager.list();
			break;
		case 7:
			visManager.deleteFirst();
			break;
		case 8:
			cout << "Total profit: " << visManager.getTotalProfit() << endl;
			break;
		case 9:
			cout << "Avg profit: " << visManager.getAverageProfit() << endl;
			break;
		}
	} while (choice != 0);

	SaveToDisk(visManager);

	return 0;
}
