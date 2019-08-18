#include "SlotMachine.h"

/**
*Method for starting the creation process of three objects pf shapes
*/
void SlotMachine::make_shapes() {
	int i{ 0 };
	while (i < 3) {
		make_shape(i);
		i++;
	}
}
/**
*Mehod where actual shapes object is made
*/
void SlotMachine::make_shape(int k) {
	std::random_device randomNumber;  
	std::mt19937 gen(randomNumber()); 
	std::uniform_int_distribution<> distribution(0, 3);
	int resultN{distribution(gen)};
	distribution.reset();
	std::uniform_int_distribution<> distribution2(1,25);
	int width{distribution2(gen)};
	distribution2.reset();
	if (resultN == 0) {
		reel[k].reset(new Rhombus(width));
	}
	else if (resultN == 1) {
		reel[k].reset(new AcuteTriangle(width));
	}
	else if (resultN == 2) {
		reel[k].reset(new RightTriangle(width));
	}
	else {
		std::uniform_int_distribution<> distribution3(1, 25);
		int height{ distribution3(gen) };
		reel[k].reset(new Rectangle(width,height));
		distribution3.reset();
	}
}

/**
*Method to draw the three objects
*/
void SlotMachine::display() {
	Grid box_0 = reel[0]->draw();
	Grid box_1 = reel[1]->draw();
	Grid box_2 = reel[2]->draw();
	int height{};
	for (int i{ 0 }; i < 3; ++i) {
		if (height < reel[i]->getBoundingHeight()) {
			height = reel[i]->getBoundingHeight();
		}
	}
	for (int k{ 0 }; k < 3; ++k) {
		if (reel[k]->getBoundingHeight() < height) {
			int tempWidth{ reel[k]->getBoundingWidth() };
			int tempHeight{ reel[k]->getBoundingHeight() };
			for (int i{ tempHeight }; i < height; ++i) {
				vector<char> temp;
				for (int j{ 0 }; j < tempWidth; ++j) {
					temp.push_back(' ');
				}
				if (k == 0) {
					box_0.push_back(temp);
				}
				else if(k == 1) {
					box_1.push_back(temp);
				}
				else {
					box_2.push_back(temp);
				}
				
			}
		}
	}
	for (int x{ 0 }; x < height + 2; ++x) {
		if (x == 0 || x == height +1) {
			cout << "+";
			for (int i{ 0 }; i <( reel[0]->getBoundingWidth()+ 2); ++i) {
				cout << "-";
			}
			cout << "+";
			for (int i{ 0 }; i <( reel[1]->getBoundingWidth() + 2); ++i) {
				cout << "-";
			}
			cout << "+";
			for (int i{ 0 }; i < (reel[2]->getBoundingWidth() + 2); ++i) {
				cout << "-";
			}
			cout << "+";
			cout << std::endl;
		}
		else {
			cout << "|";
			cout << " ";
			
			for (int i{ 0 }; i < (box_0[x - 1].size()); ++i) {
				cout << (box_0[x - 1])[i];
			}
			cout << " ";
			cout << "|";
			cout << " ";
			for (int i{ 0 }; i < (box_1[x - 1].size()); ++i) {
				cout << (box_1[x - 1])[i];
			}
			cout << " ";
			cout << "|";
			cout << " ";
			for (int i{ 0 }; i < (box_2[x - 1].size()); ++i) {
				cout << (box_2[x - 1])[i];
			}
			cout << " ";
			cout << "|";
			cout << std::endl;
		}
	}
	cout << "(" + reel[0]->getName() + "," + to_string(reel[0]->getBoundingHeight()) + "," + to_string(reel[0]->getBoundingWidth()) + ") "
		+ "(" + reel[1]->getName() + "," + to_string(reel[1]->getBoundingHeight()) + "," + to_string(reel[1]->getBoundingWidth()) + ") "
		+ "(" + reel[2]->getName() + "," + to_string(reel[2]->getBoundingHeight()) + "," + to_string(reel[2]->getBoundingWidth()) + ")\n";
	
}

/**
*Method containing running procedure of slot machine
*/
void SlotMachine::run() {
	cout << "Welcome to 3-Reel Lucky Slot Machine Game! \nEach reel will randomly display one of four shapes, each in 25 sizes. \n";
	cout << "To win 3x bet Get 2 similar shapes AND 2 shapes with equal Scr Areas \nTo win 2x bet Get 3 similar shapes\n";
	cout << "To win 1x bet Get (Middle) Scr Area > (Left+Right) Scr Areas\nTo win or loose nothing Get same Left and Right shapes\n";
	cout << "Otherwise,you will lose your bet.\nYou start with 10 free slot tokens!"; 
	int input{10};
	int balance{10};
	int bet{};
	while (input) {
		if (balance == 0||input==0) {
			break;
		}
		cout<<"\n\nHow much would you like to bet(enter 0 to quit)";
		std::cin >> input;
		if (input < 0) {
			if (input == 0 || balance == 0) {
				break;
			}
			cout << "No negative bets,try again!\n";
		}
		else if (input > balance) {
			if (input == 0 || balance == 0) {
				break;
			}
			cout << "You can't bet more than "+to_string(balance)+" ,try again\n";
		}
		else {
			if (input == 0||balance==0) {
				break;
			}
			bet = input;
			make_shapes();
			display();
			if (typeid(*reel[0]) == typeid(*reel[1]) || typeid(*reel[0]) == typeid(*reel[2])) {
				if (reel[0]->screenArea() == reel[1]->screenArea() || reel[0]->screenArea() == reel[2]->screenArea()) {
					int temp{bet*3};
					cout << "Jackpot!2 Similar Shapes AND 2 Equal Screen Areas\nCongratulations!You won 3 time your bet:" + to_string(temp) ;
					balance = balance + temp;
					cout << "\nYou now have " + to_string(balance) + " tokens\n";
					
				}
				else if (typeid(*reel[0]) == typeid(*reel[1]) && typeid(*reel[1]) == typeid(*reel[2])) {
					cout << "Three similar shapes\n";
					int temp{ bet * 2 };
					cout<< "Congratulations!You won 2 time your bet : " + to_string(temp);
					balance = balance + temp;
					cout << "\nYou now have " + to_string(balance) + " tokens\n";
				}
				else if (reel[1]->screenArea()>(reel[0]->screenArea()+reel[2]->screenArea())) {
					cout << "Middle > Left + Right,in Screen Areas\nCongratulations! you win your bet:" + to_string(bet);
					balance = balance + bet;
					cout << "\nYou now have " + to_string(balance) + " tokens\n";
				}
				else if (typeid(*reel[0]) == typeid(*reel[2])) {
					cout << "Lucky this time!\nYou don't win,you don't lose,you are safe!\n";
					cout << "You now have " + to_string(balance) + " tokens\n";
				}
				else {
					cout << "On No!\nYou lose your bet\n";
					balance = balance - bet;
					cout << "You now have " + to_string(balance) + " tokens\n";
				}

			}
			else if (reel[1]->screenArea() > (reel[0]->screenArea() + reel[2]->screenArea())) {
				cout << "Middle > Left + Right,in Screen Areas\nCongratulations! you win your bet:" + to_string(bet);
				balance = balance + bet;
				cout << "\nYou now have " + to_string(balance) + " tokens\n";
			}
			else {
				cout << "On No!\nYou lose your bet\n";
				balance = balance - bet;
				cout << "You now have " + to_string(balance) + " tokens\n";
			}
		}
		
	}
	if (balance == 0) {
		cout << "\nThank you for playing,come back soon!\n\nGame Over.";
	}
	else {
		cout << "Thank you for playing,come back soon!\n";
		cout << "Be sure you cash in your remaining " + to_string(balance) + " tokens at the bar!\nGame Over.";
	}
}