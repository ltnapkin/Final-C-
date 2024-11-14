/*
Travieon Fields
Final

RPG final Version for Submiting 

*/


//Liberies
#include <iostream>
#include <string>
#include<Windows.h>
#include<time.h>
using namespace std;

// for changing the class of the player
int classChoice(char playersChoiceforClass);
//Allows The player To Advance ther class
// Allows the player to see the state of all the stats you worry about in game
int statChecker();
//Allows the player to sleep and gain caravan hp back
int Rest();
// The state that shows if the player gets through the game
int WinState();
// Basically only shows up if tyhe player dies 
int LoseState();
//The bread and butter of the game and give you random things that might happen to you
int RandomEvent();
//picks different enemies to attack you
int EnemyEncounter();
//Gives you choices that you can make based on your stats
void StoryChoices();
//inc the players stats 
int StatBuff();

// a majority of thes stats have to do with win lose state of the game
int caravanHealth = 15;
int dayToTown = 10;
int dayOnRoad = 0;
int playerChoiceIntForm;
char playersChoiceforADVClass;
//The players stats Set to 3 so i know that they change during game play
int Str = 3;
int Wis = 3;
int Spd = 3;
// a randomn int that is use by all enemies
int enemyDmg;

//Mainly for flavor text to enhance the game give more character to events
string playerName;
string playerClass;
string randomEnemyName;



//Allows the player to choose certain events 
char playersChoiceGPLoop;

//Mainly use to check if the player has chosen an answer so the game can keep running
bool choice = false;
bool classChoosen = false;
bool didYouRest = false;
bool classAdvacement = false;

// makes it so i can change the text color
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);



class CharcacterClass {

public:

	void Warrior() {
		playerClass = "Warrior";
		Str = 8;
		Wis = 2;
		Spd = 4;

	}

	void Mage() {
		playerClass = "Mage";
		Str = 2;
		Wis = 9;
		Spd = 3;
	}


	void Ranger() {
		playerClass = "Ranger";
		Str = 4;
		Wis = 4;
		Spd = 7;
	}

	void ClassAdvancemet() {
		cout << "This class is advacing" << playerClass << endl;
	}


};

class Warriors : public CharcacterClass {
public:


	void ClassAdvancemet() {
		bool ADVclassChoosen = false;
		cout << "Please choose an Advance class For: " << playerClass << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "0)Destroyer 1)Ravenger 2)Beserker" << endl;
		cin >> playersChoiceforADVClass;
		while (!ADVclassChoosen)
		{
			if (playersChoiceforADVClass == '0') {
				playerClass = "Destroyer";
				Str = Str +6;
				Wis = Wis +2;
				Spd = Spd+2;
				

				ADVclassChoosen = true;
			}
			else if (playersChoiceforADVClass == '1') {
				playerClass = "Ravenger";
				Str = Str+2;
				Wis = Wis + 6;
				Spd = Spd+2;
				
				ADVclassChoosen = true;
			}
			else if (playersChoiceforADVClass == '2') {
				playerClass = "Beserker";
				Str = Str+2;
				Wis = Wis+2;
				Spd = Spd + 6;

				ADVclassChoosen = true;
			}
			else {
				cout << "please choose a class from list" << endl;
				cin >> playersChoiceforADVClass;
			}
		}
	}





};

class Mages :public CharcacterClass {
public:


	void ClassAdvancemet() {
		bool ADVclassChoosen = false;
		cout << "Please choose an Advance class For: " << playerClass << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "0)Warlock 1)Wizard 2)Trickster" << endl;
		cin >> playersChoiceforADVClass;
		while (!ADVclassChoosen)
		{
			if (playersChoiceforADVClass == '0') {
				playerClass = "Warlock";
				Str = Str + 6;
				Wis = Wis + 2;
				Spd = Spd + 2;


				ADVclassChoosen = true;
			}
			else if (playersChoiceforADVClass == '1') {
				playerClass = "Wizard";
				Str = Str + 2;
				Wis = Wis + 6;
				Spd = Spd + 2;

				ADVclassChoosen = true;
			}
			else if (playersChoiceforADVClass == '2') {
				playerClass = "Trickster";
				Str = Str + 2;
				Wis = Wis + 2;
				Spd = Spd + 6;

				ADVclassChoosen = true;
			}
			else {
				cout << "please choose a class from list" << endl;
				cin >> playersChoiceforADVClass;
			}
		}
	}


};


class Rangers : public CharcacterClass {
public:


	void ClassAdvancemet() {
		bool ADVclassChoosen = false;
		cout << "Please choose an Advance class For: " << playerClass << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "0)Mercenary 1)SpellSword 2)Assassin" << endl;
		cin >> playersChoiceforADVClass;
		while (!ADVclassChoosen)
		{
			if (playersChoiceforADVClass == '0') {
				playerClass = "Mercenary";
				Str = Str + 6;
				Wis = Wis;
				Spd = Spd;


				ADVclassChoosen = true;
			}
			else if (playersChoiceforADVClass == '1') {
				playerClass = "SpellSword";
				Str = Str;
				Wis = Wis + 6;
				Spd = Spd;

				ADVclassChoosen = true;
			}
			else if (playersChoiceforADVClass == '2') {
				playerClass = "Assassin";
				Str = Str;
				Wis = Wis;
				Spd = Spd + 6;

				ADVclassChoosen = true;
			}
			else {
				cout << "please choose a class from list" << endl;
				cin >> playersChoiceforADVClass;
			}
		}
	}



};




//Main interctions
int main()
{


	//A local var that allows the player to chose there class
	char playersClassChoice;

	//Ask and gets the players name.
	cout << "Please enter your adventure's name" << endl;
	cin >> playerName;

	//A loop that makes the player choose a class 
	cout << "Please choose a class" << endl;
	cout << "0)Warrior 1)Mage 2)Ranger" << endl;
	cin >> playersClassChoice;
	// the function that makes the player choose a class.
	classChoice(playersClassChoice);




	// The setup text of the game
	cout << playerName + " The " << playerClass << " has decide to Take a trip to town, you heard a lot of Dangers lurk on the road to the Town" << endl;
	cout << "It will take you " << dayToTown << " Days To make it to town! good luck!" << endl;
	cout << "" << endl;


	// The Gameplay look that bascially checks if the player caravan health is above 0 as well as if the days passed
	while (dayOnRoad < dayToTown && caravanHealth > 0)
	{
		SetConsoleTextAttribute(h, 7);
		cout << "You have " << dayToTown - dayOnRoad << " Left to go What will you do?" << endl;

		SetConsoleTextAttribute(h, 2);
		cout << "0) Advance" << endl;
		cout << "1) Set up Camp" << endl;
		cout << "2) Status Check" << endl;
		//Gets the players answer
		cin >> playersChoiceGPLoop;

		//An if statement that only sets the choice true if the player puts the correct item in and advances the game
		try {
			if (playersChoiceGPLoop == '0') {
				playerChoiceIntForm = 0;
				choice = true;
			}
			else if (playersChoiceGPLoop == '1') {
				playerChoiceIntForm = 1;
				choice = true;
			}
			else if (playersChoiceGPLoop == '2') {
				playerChoiceIntForm = 2;
				choice = true;
			}
			else {
				throw invalid_argument("Please pick a valid answer");
			}
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
		}

		// Converts the chocies into a int that can be use in a switch to check and see how to proceed in the game
		if (choice)
		{
			switch (playerChoiceIntForm)
			{
			case 0:
				//Calls a random event as well as adding  1 to the days on the road
				RandomEvent();
				//Fail safe so that you cant spam resting and gain more health than intended
				didYouRest = false;
				dayOnRoad++;
				break;

			case 1:
				// Check to seee if you have rested if you did it doesn't allow you to rest
				if (!didYouRest)
				{
					Rest();

					if (dayOnRoad >= 4 && classAdvacement == false) {
						SetConsoleTextAttribute(h, 1);
						cout << playerName << " Can now Advance their Class!" << endl;
						if(playerClass == "Warrior") {
							Warriors classAdv;
							classAdv.ClassAdvancemet();
							
							classAdvacement = true;
						}
						else if (playerClass == "Mage")
						{
							Mages classAdv;
							classAdv.ClassAdvancemet();
							
							classAdvacement = true;

						}
						else if (playerClass == "Ranger")
						{
							Rangers classAdv;
							classAdv.ClassAdvancemet();

							classAdvacement = true;
						}
						SetConsoleTextAttribute(h, 1);
						cout << playerName << " Has Advanced To a: " << playerClass << endl;
					}
					
				}
				else {
					cout << "You are already Rested!" << endl;
				}
				break;

			case 2:
				//Basically prints out all stats of the player
				statChecker();
				break;


			}
		}
	}
	//Checks to see if you have died or won
	if (dayToTown <= dayOnRoad && caravanHealth > 0)
	{
		WinState();
	}
	else {
		LoseState();
	}



	return 0;
}
// Sets stats for class chosen.
int classChoice(char playersChoiceforClass) {

	CharcacterClass characterClassChoice;

	//says if class isn't true stay in this loop
	while (!classChoosen)
	{
		if (playersChoiceforClass == '0') {
			

			characterClassChoice.Warrior();

			classChoosen = true;
		}
		else if (playersChoiceforClass == '1') {
			

			characterClassChoice.Mage();
			classChoosen = true;
		}
		else if (playersChoiceforClass == '2') {

			characterClassChoice.Ranger();
			classChoosen = true;
		}
		else {
			cout << "please choose a class from list" << endl;
			cin >> playersChoiceforClass;
		}
	}




	return 0;
}



//Check the status of your player.
int statChecker()
{
	//Prints out all the stats of the player
	cout << "Name:" << playerName << endl;
	cout << "Class:" << playerClass << endl;
	cout << "Stats:";
	cout << " Str:" << Str;
	cout << " Wis:" << Wis;
	cout << " Spd:" << Spd << endl;
	cout << "Caravan Hp:" << caravanHealth << endl;
	// shows the player the days until they reach the town and win
	cout << "Days till reaching town " << dayToTown - dayOnRoad << endl;


	return 0;
}

//alow the player to rest and inc Stats of players caravan Hp
int Rest()
{
	srand(time(0));
	cout << "you have Taken time to rest " << playerName << endl;
	// gives you a random amout of health back for resting
	caravanHealth += rand() % 6 + 1;

	//Sets resting to true so you cannot spam it
	didYouRest = true;
	return 0;
}


// allow you to win the game
int WinState() {

	SetConsoleTextAttribute(h, 3);
	cout << "You did It! you have face all the trials and made it to town! " << "Congrats " << playerName << endl;


	return 0;
}




// basically makes you lose the game
int LoseState() {


	cout << "Your caravan was Never seen again. . . . " << "GameOver " << playerName << endl;
	return 0;
}


//allowss random events to happen
int RandomEvent() {
	srand(time(0));
	//creates a local var that is in charge of all the random events
	int randomEvent = 0;
	//allow the random number to be 0,1, or 2.	
	randomEvent = rand() % 3;


	switch (randomEvent)
	{
	case 0:
		SetConsoleTextAttribute(h, 2);
		cout << "*StoryChoice*" << endl;
		StoryChoices();
		break;


	case 1:
		//Calls the function enemy encounter to set the enemy name and dmg
		SetConsoleTextAttribute(h, 4);
		cout << "*EnemyEncounter*" << endl;
		EnemyEncounter();
		//Fail safe that if the enemies dmg is less than 0 that the player doesnt get health for there caravan
		if (enemyDmg <= 0)
		{
			SetConsoleTextAttribute(h, 3);
			cout << "you were attack by " << randomEnemyName << " However you were able to come out Unharmed " << endl;
		}
		else {
			//if the number is greater than 0 It will dmg the player caravan
			caravanHealth -= enemyDmg;
			SetConsoleTextAttribute(h, 4);
			cout << "you were attack by " << randomEnemyName << " You Caravan took " << enemyDmg << " Of damage" << endl;
		}
		break;

	case 2:
		// randomly applies a buff to the stats of the player
		StatBuff();
		break;
	}


	return 0;
}

void StoryChoices()
{
	srand(time(0));
	//creates a local var that is in charge of all the random events
	int randomEvent = 0;
	//allow the random number to be 0 up to 4.	
	randomEvent = rand() % 5;
	bool choiceWasChoosen = false;

	char choiceCheck;

	int randomstatCheck;

	randomstatCheck = rand() % 30 / dayToTown;

	while (!choiceWasChoosen)
	{
		//All of these are different story events that can happen and change your stats.
		switch (randomEvent)
		{
		case 0:
			//Calls the function enemyencounter to make the enemy random that you may meet
			EnemyEncounter();
			SetConsoleTextAttribute(h, 7);
			cout << "While walking the plan you see a group of " << randomEnemyName << endl;
			cout << "They seem to be asleep in the plains, You decide" << endl;


			SetConsoleTextAttribute(h, 2);
			cout << "A)The only good " << randomEnemyName << " is a dead!(Attack the " << randomEnemyName << ") * STR CHECK * " << endl;
			cout << "B)It's safer To find another way around.(Change route)*Adds +1 to days yo make it to town*" << endl;


			cin >> choiceCheck;
			choiceCheck = toupper(choiceCheck);
			//Checks to see if you put in A or B
			if (choiceCheck == 'A')
			{
				if (Str + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "You defeated all the " << randomEnemyName << " with ease ! your Str stat has gone up!" << endl;
					Str += rand() % 4 + 1;
				}
				else if (Str + dayOnRoad <= randomstatCheck) {
					SetConsoleTextAttribute(h, 4);
					cout << "you were overwelmed by the enemies and your cart took some dmg " << endl;
					if (enemyDmg > 0)
					{
						caravanHealth -= enemyDmg;
					}
					else {
						caravanHealth--;
					}
				}



				choiceWasChoosen = true;
			}
			else if (choiceCheck == 'B')
			{
				SetConsoleTextAttribute(h, 3);
				cout << "You go to find another route,It may take longer but its safer" << endl;
				dayToTown++;



				choiceWasChoosen = true;
			}
			else {
				cout << "Please Choose A or B" << endl;
			}







			break;

		case 1:
			SetConsoleTextAttribute(h, 7);
			cout << "Your wagons Wheel seems to have begun to wear." << endl;
			cout << "You your very far from any outpost. so you decide. . " << endl;


			SetConsoleTextAttribute(h, 2);
			cout << "A)Ease the weight of the wagon by carrying some supplies *STR CHECK*" << endl;
			cout << "B)Fix the wagon wheel yourself *WIS CHECK*" << endl;


			cin >> choiceCheck;
			choiceCheck = toupper(choiceCheck);

			if (choiceCheck == 'A')
			{
				if (Str + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "While Carrying the stuff may have Slowed your pace, You Have grown stronger because of it! STR++ Days to Town++" << endl;
					Str++;
					dayToTown++;
				}
				else if (Str + dayOnRoad <= randomstatCheck) {
					SetConsoleTextAttribute(h, 4);
					cout << "May have bitten off more than you could chew, and it took you much longer to make it to an outpost." << endl;
					dayToTown + 3;
				}



				choiceWasChoosen = true;
			}
			else if (choiceCheck == 'B')
			{
				if (Wis + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "You made short work of the wagon wheel and looks like it moves even faster! WIS++ Days to town--" << endl;
					Wis++;
					dayToTown--;
				}
				else if (Wis + dayOnRoad <= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 4);
					cout << "At first it seem to be a easy task but it took you far to long and somebody found you day later and helped. Days to town++" << endl;
					dayToTown + 4;
				}



				choiceWasChoosen = true;
			}
			else {
				cout << "Please Choose A or B" << endl;
			}


			break;

		case 2:

			SetConsoleTextAttribute(h, 7);
			cout << "Made it to a Bridge, Well the bridge is flooded by water." << endl;
			cout << "you have a few options to cross. " << endl;


			SetConsoleTextAttribute(h, 2);
			cout << "A)Swim across *SPD CHECK*" << endl;
			cout << "B)Find Another way Around *WIS CHECK*" << endl;


			cin >> choiceCheck;
			choiceCheck = toupper(choiceCheck);

			if (choiceCheck == 'A')
			{
				if (Spd + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "With ease you make it across, Some things got wet but Nothing to important. Spd++" << endl;
					Spd++;
				}
				else if (Spd + dayOnRoad <= randomstatCheck) {
					SetConsoleTextAttribute(h, 4);
					cout << "the current was Far too strong, you barely make it across every part of your body is sore SPD--" << endl;
					Spd--;
				}



				choiceWasChoosen = true;
			}
			else if (choiceCheck == 'B')
			{
				if (Wis + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "You find a better looking bridge across the way And make short work of the river WIS++" << endl;
					Wis++;

				}
				else if (Wis + dayOnRoad <= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 4);
					cout << "You look for what seems like hours to find a way across until you finally finds one. Days to town++" << endl;
					dayToTown + 2;
				}



				choiceWasChoosen = true;
			}
			else {
				cout << "Please Choose A or B" << endl;
			}
			break;

		case 3:
			SetConsoleTextAttribute(h, 7);
			cout << " While walking deep into the forrest you find a Big tree at the top of the tree are a bunch of apples." << endl;
			cout << "You havent eaten in a while and you deciding on the which apples to eat. " << endl;


			SetConsoleTextAttribute(h, 2);
			cout << "A)Climb the tree *Str CHECK*" << endl;
			cout << "B)Search the ground *WIS CHECK*" << endl;


			cin >> choiceCheck;
			choiceCheck = toupper(choiceCheck);

			if (choiceCheck == 'A')
			{
				if (Str + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "Made Short work of climbing the tree and picking some of the best apples you could eat! STR++" << endl;
					Str++;
				}
				else if (Str + dayOnRoad <= randomstatCheck) {
					SetConsoleTextAttribute(h, 4);
					cout << "Makes many attempts to climb the tree but you keep losing your footing, you can't count how many times you fall off the tree till you give up all together and quest on STR--" << endl;
					Str--;
				}



				choiceWasChoosen = true;
			}
			else if (choiceCheck == 'B')
			{
				if (Wis + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "Eyeing the newly fallen apples you found the best ones that were untouched by creature, they were very tasty WIS++" << endl;
					Wis++;

				}
				else if (Wis + dayOnRoad <= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 4);
					cout << "has eaten worst, but that doesn't mean this was any better you feel sick to your core after eating a couple of the apples, no wonder they were on the ground!" << endl;
					Wis--;
				}



				choiceWasChoosen = true;
			}
			else {
				cout << "Please Choose A or B" << endl;
			}


			break;

		case 4:
			SetConsoleTextAttribute(h, 7);
			cout << " Some knights stop you on your travels And inform you that they need to check your cart for any stolen goods" << endl;
			cout << "While you know you don't have any stolen goods you decide " << endl;


			SetConsoleTextAttribute(h, 2);
			cout << "A)Press The knights knightlyhood *Str CHECK*" << endl;
			cout << "B)Question the knights  *WIS CHECK*" << endl;


			cin >> choiceCheck;
			choiceCheck = toupper(choiceCheck);

			if (choiceCheck == 'A')
			{
				if (Str + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "The knights backdown from your questioning and leave hastly STR++" << endl;
					Str++;
				}
				else if (Str + dayOnRoad <= randomstatCheck) {
					SetConsoleTextAttribute(h, 4);
					cout << "You and the knights get into a Spat and your caravan gets dmg in the process" << endl;
					caravanHealth--;
				}



				choiceWasChoosen = true;
			}
			else if (choiceCheck == 'B')
			{
				if (Wis + dayOnRoad >= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 3);
					cout << "After talking with the knights they allow you to go unscaved!" << endl;
					Wis++;

				}
				else if (Wis + dayOnRoad <= randomstatCheck)
				{
					SetConsoleTextAttribute(h, 4);
					cout << "On and on you go back and forth with the knights and it takes forever for you guys to reach a agreement" << endl;
					dayToTown + 2;
				}



				choiceWasChoosen = true;
			}
			else {
				cout << "Please Choose A or B" << endl;
			}
			break;


		}
	}




}

// Different Types Of Enemies 
int EnemyEncounter()
{
	//Make sure Number Are random based on time
	srand(time(0));
	//Basically the same as the random ecounter but sets Enemies up
	int randomEnemy;
	//Makes only weak enemies appear based on the days on the road.
	if (dayOnRoad <= 3)
	{
		randomEnemy = rand() % 4;
	}
	else if (dayOnRoad <= 6)
	{
		randomEnemy = rand() % 6;
	}
	else if (dayOnRoad > 6)
	{
		randomEnemy = rand() % 10;
	}
	//Gives the enemies a name and dmg  
	switch (randomEnemy)
	{
	case 0:
		randomEnemyName = "Goblins";
		//Lowers the enemies dmg by a stat
		enemyDmg = rand() % 10 - Str;
		break;

	case 1:
		randomEnemyName = "Bandits";
		enemyDmg = rand() % 12 - Wis;
		break;

	case 2:
		randomEnemyName = "Undead";
		enemyDmg = rand() % 15 - Spd;
		break;


	case 3:
		randomEnemyName = "HobGoblins";
		enemyDmg = rand() % 20 - Str;
		//for stronger enemies lowers them by one full stat and half of another
		enemyDmg -= Wis / 2;
		break;

	case 4:
		randomEnemyName = "Cultists";
		enemyDmg = rand() % 26 - Wis;
		enemyDmg -= Spd / 2;
		break;

	case 5:
		randomEnemyName = "Lich";
		enemyDmg = rand() % 30 - Spd;
		enemyDmg -= Str / 2;
		break;

	case 6:
		randomEnemyName = "Dark Knights";
		enemyDmg = rand() % 45 - Str;
		enemyDmg -= Str / 2;
		break;

	case 7:
		randomEnemyName = "Dark Assassins";
		enemyDmg = rand() % 45 - Spd;
		enemyDmg -= Str / 2;
		break;

	case 8:
		randomEnemyName = "Dark Wizards";
		enemyDmg = rand() % 45 - Wis;
		enemyDmg -= Str / 2;
		break;

	case 9:
		randomEnemyName = "Dark Lords";
		enemyDmg = rand() % 60 - Spd;
		enemyDmg -= Str / 2;
		break;
	}



	return 0;
}




//Inc the stats of the player randomly
int StatBuff()
{
	srand(time(0));

	SetConsoleTextAttribute(h, 1);
	cout << "*FREE TIME*" << endl;
	// uses two randoms to inc the stats of the player,  added a 1 so that it always does it by at least 1
	int freeTimeChoice;
	bool didYouMakeAChoice = false;
	int buffstats = 0;
	int randomDiaologue = 0;

	//Default white color
	SetConsoleTextAttribute(h, 7);
	cout << "What will you do with your free time?" << endl;
	//changes Text to Green
	SetConsoleTextAttribute(h, 2);
	cout << "0)Plot your area" << endl;
	cout << "1)Hone Your skills" << endl;
	cout << "2)Adventure out from your caravan" << endl;
	cin >> freeTimeChoice;
	//Makes the diologue random based on the a number
	randomDiaologue = rand() % 3;
	buffstats = rand() % 4 + 1;
	while (!didYouMakeAChoice)
	{
		SetConsoleTextAttribute(h, 3);
		switch (freeTimeChoice)
		{

		case 0:

			if (randomDiaologue == 0)
			{
				cout << "You took the time to get familar with the area" << endl;
			}
			else if (randomDiaologue == 1)
			{
				cout << "You traded maps with the locals" << endl;
			}
			else if (randomDiaologue == 2)
			{
				cout << "You took time to explore the plains" << endl;
			}

			cout << "your Wis Stat Went up by " << buffstats << endl;
			Wis += buffstats;
			didYouMakeAChoice = true;

			break;

		case 1:
			if (randomDiaologue == 0)
			{
				cout << "You took time to sharpen the blade." << endl;
			}
			else if (randomDiaologue == 1)
			{
				cout << "10000 pushups later Made you feel powerful" << endl;
			}
			else if (randomDiaologue == 2)
			{
				cout << "You change the wagons wheels" << endl;
			}
			cout << "your Str Stat Went up by " << buffstats << endl;
			Str += buffstats;
			didYouMakeAChoice = true;
			break;

		case 2:
			if (randomDiaologue == 0)
			{
				cout << "You ran with the local Wildlife" << endl;
			}
			else if (randomDiaologue == 1)
			{
				cout << "You got rid of unwanted items" << endl;
			}
			else if (randomDiaologue == 2)
			{
				cout << "You played catch with locals" << endl;
			}
			cout << "your Speed Stat Went up by " << buffstats << endl;
			Spd += buffstats;
			didYouMakeAChoice = true;
			break;





		default:

			cout << "Please make a choice" << endl;
			cin >> freeTimeChoice;
			break;

		}
	}

	return 0;
}