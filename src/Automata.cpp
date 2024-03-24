#include "Automata.h"

	 Automata::Automata()
	{
		 cash = 0;
		 menu = new string[3]{"Чай", "Кофе","Молоко"};
		 prices = new unsigned int[3]{5,15,8};
		 state = Off;
	}

	 void Automata::on() //1
	 {
		 if (state == Off) { state = Wait; cout << "Автомат включился." << endl; }
		 else cout << "Автомат уже включён." << endl;

	 }

	 void Automata::off()//2
	 {
		 if (state == Wait){ state = Off; cout << "Автомат выключился." << endl;}
		 else if (state == Off) cout << "Автомат уже выключён." << endl;
		 else cout << "Автомат не завершил свою работу." << endl;
	 }
	 void Automata::coin(unsigned int sum)//3
	 {
		 if (state == Wait || state == Accept) { state = Accept; cash += sum; cout << "Деньги внесены: "<< sum << endl; }
		
		 else cout << "Дождитесь завершения работы автомата." << endl;
	 }
	 void Automata::GetMenu()//4
	 {
		 cout << " Меню:--------------------------------------- " << endl;
		 for (int i = 0; i < 3; i++) { cout << menu[i]<<" - "<< prices[i] << endl; }
		 cout << " ---------------------------------------V0.1- " << endl;
	 }
	 States Automata::GetState()//5
	 {
		 return state;
	 }
	 void Automata::choice(int num)//6
	 {
		 if (state == Accept) {state = Check; cout << "Выбор сделан: " << num << endl;}
		 
		 else cout << "Внесите деньги и выберите напиток." << endl;
	 }
	 void Automata::check(int num)//7
	 {
		 if (state == Check) 
		 {
			 if (prices[num-1] <= cash) { state = Check; cout << "Все деньги успешно внесены." << endl;  }
		 
			 else { cout << "Недостаточно денег на счете, внесите до нужной суммы." << " ( "<<cash<<"из"<<prices[num-1]<< " )"<< endl; }
		 }
		 else cout << "Внесите деньги и выберите напиток." << endl;
	 }
	 void Automata::cancel()//8
	 {
		 if (state == Accept || state ==Check) {state = Wait; cout << "Операция прервана." << endl;}
		 else cout << "Дождитесь завершения работы автомата." << endl;
	 }
	 void Automata::cook(int num)//9
	 {
		 if (state == Check && cash>=prices[num-1]) { state = Cook;  cout << "Приготовление напитка..." << menu[num-1] << endl;cash -= prices[num-1];}
		 else cout << "Внесите деньги и выберите напиток." << endl;
	 }
	 void Automata::finish()//10
	 {
		 if (state == Cook) { state = Wait;  cout << "Напиток готов. Приятного аппетита." << endl;}
	 
		 else cout << "Дождитесь завершения работы автомата." << endl;
	 }