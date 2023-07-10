#include "sleepAnalyzer.h"
#include "defns.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring> 
#include <cstdlib>
/*
Person ID,Gender,Age,Occupation,Sleep Duration,Quality of Sleep,
Physical Activity Level,Stress Level,BMI Category,Blood Pressure,
Heart Rate,Daily Steps,Sleep Disorder
*/

//parse and store data
void parseCSV(std::vector<Person> &p, std::string fileName){
	std::string myline;
	std::ifstream myfile;
	
	
	myfile.open(fileName);
	

	if( myfile.is_open()) {
		while( myfile) {
			std::getline(myfile, myline);
			std::stringstream ss(myline);
			std::string cell;

			Person person;
			std::getline(ss,cell, ',');
			person.id = std::stoi(cell);

			std::getline(ss,cell, ',');
			person.gender = cell;

			std::getline(ss,cell, ',');
			person.age = std::stoi(cell);

			std::getline(ss,cell, ',');
			person.occupation = cell;

			std::getline(ss,cell, ',');
			person.sleep_duration = std::stof(cell);

			std::getline(ss,cell, ',');
			person.sleep_quality = std::stoi(cell);

			std::getline(ss,cell, ',');
			person.physical_activity_level = std::stoi(cell);

			std::getline(ss,cell, ',');
			person.stress_level = std::stoi(cell);

			std::getline(ss,cell, ',');
			person.BMI = cell;

			std::getline(ss,cell, ',');
			person.heart_rate = cell;

			std::getline(ss,cell, ',');
			person.daily_steps = std::stoi(cell);

			std::getline(ss,cell, ',');
			person.sleep_disorder = cell;

			p.push_back(person);

		}
	}
}


void printPerson(std::vector<Person> p){
	for(auto person: p){
		std::cout << person.id<<" " << person.gender << 
		" " << person.age << " " << person.occupation<< " " <<
		person.sleep_duration<< " " << person.sleep_quality<< " " << 
		person.physical_activity_level<< " " << person.stress_level<< " " <<
		person.BMI << " " << person.heart_rate << " " << person.daily_steps << " "
		<< person.sleep_disorder << " "  <<std::endl;
	}
	std::cout<<std::endl;
}



int main(int argc, char const *argv[])
{
	if (argc < 2) {
        std::cout << "No command-line arguments provided." << std::endl;
        return 1;
    }
    std::string argument = argv[1];

	if(argument == "find"){
		std::cout << " finding:::::::: 0\n";
	} else{
		std::cout << argv[1] << "  no argument given\n" ;
	}
	

	std::vector<Person> people;
	parseCSV(people, "Sleep_health_and_lifestyle_dataset.csv");
	//printPerson(people);


	return 0;
}