#include <iostream>
//객체 예제
int month_arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};

class Date {
	private:
		int year;
		int month;
		int day;
		bool yoon_year;

	public:
		bool set_date(int _year, int _month, int _day){}
		bool add_day(int inc){}
		bool add_month(int inc){}
		bool add_year(int inc){}
		void get_date(){}

		Date() {
			std::cout << "기본 생성자 호출" <<std::endl;
			year = 2019;
			month = 11;
			day = 24;
		}
};

bool Date::set_date(int _year, int _month, int _day){
	if(_month > 12 || _month < 1 || _day > 31 || _day < 1){
		return false;
	}
	else{
		year = _year;
		month = _month;
		day = _day;
		if((year%4 == 0 && year%100 != 0) || year%400 == 0){
			yoon_year = true;
			month_arr[1] = 29;
		}
		else{
			month_arr[1] = 28;
			false;
		}
		return true;
	}
}
bool Date::add_day(int inc){
	if(day == NULL){
		return false;
	}
	else{
		day+=inc;
		while(day > month_arr[month-1]){
			if(day < month_arr[month-1])break;
			day -= month_arr[month-1];
			add_month(1);
		}
		return true;
	}
}
bool Date::add_month(int inc){
	if(month == NULL){
		return false;
	}
	month += inc;
	while(month > 12){
		if(month < 12)break;
		add_year(1);
		month -= 12;
	}
	return true;
}
bool Date::add_year(int inc){
	if(year == NULL){
		return false;
	}
	year +=inc;
	if((year%4 == 0 && year%100 != 0) || year%400 == 0){
		yoon_year = true;
		month_arr[1] = 29;
	}
	else{
		false;
		month_arr[1] = 28;
	}
	return true;
}
void Date::get_date(){
	std::cout <<"Date : "<<year <<"-"<<month<<"-"<<day<<std::endl;
}

int main(){
	Date _date;
	while(1){
		int input_stat;
		int _year,_month,_day,inc;
		std::cout<<"\n\n1: set_date\n2: add_day\n3: add_month\n4: add_year\n5: show_date"<<std::endl;
		std::cin>>input_stat;
		if(input_stat == 1){
			std::cout<<"year : ";
			std::cin>>_year;
			std::cout<<"month : ";
			std::cin>>_month;
			std::cout<<"day : ";
			std::cin>>_day;
			if(_date.set_date(_year,_month,_day)){
				std::cout<<"날짜가 설정 되었습니다."<<std::endl;
			}
			else{
				std::cout<<"날자까 설정 되지 않았습니다."<<std::endl;
			}
		}
		else if(input_stat == 2){
			std::cout<<"+day : ";
			std::cin>>inc;
			if(_date.add_day(inc)){
				std::cout<<"날짜가 설정 되었습니다."<<std::endl;	
			}
			else{
				std::cout<<"날자까 설정 되지 않았습니다."<<std::endl;
			}

		}
		else if(input_stat == 3){
			std::cout<<"+month : ";
			std::cin>>inc;
			if(_date.add_month(inc)){
				std::cout<<"날짜가 설정 되었습니다."<<std::endl;	
			}
			else{
				std::cout<<"날자까 설정 되지 않았습니다."<<std::endl;
			}
		}
		else if(input_stat == 4){
			std::cout<<"+year : ";
			std::cin>>inc;
			if(_date.add_year(inc)){
				std::cout<<"날짜가 설정 되었습니다."<<std::endl;	
			}
			else{
				std::cout<<"날자까 설정 되지 않았습니다."<<std::endl;
			}
		}
		else if(input_stat == 5){
			_date.get_date();
		}
		else{
			std::cout<<"wrong input! retry..."<<std::endl;
		}
	}
}