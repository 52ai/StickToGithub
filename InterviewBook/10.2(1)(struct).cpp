#include <iostream>
using namespace std;

enum BREED {GOLDEN,CAIRN,DANDIE,SHETLAND,DOBERMAN,LAB};

struct Mammal
{
	public:
		Mammal():itsAge(2),itsWeight(5){}
		~Mammal(){};

		int GetAge() const {return itsAge;}
		void SetAge(int age){itsAge = age;}

		int GetWeight() const {return itsWeight;}
		void SetWeight(int weight) {itsWeight = weight;}

		void Speak() const { cout << " Mammal sound!\n";}
		void Sleep() const { cout << "Shhhh. I am sleeping.\n";}
	protected:
		int itsAge;
		int itsWeight;
};

struct Dog : public Mammal
{
	public:
		Dog():itsBreed(GOLDEN){}
		~Dog(){};

		BREED GetBreed() const {return itsBreed;}
		void SetBreed(BREED breed){itsBreed = breed;}

		void WagTail() const {cout << "Tail wagging...\n";}
		void BegForFood() const {cout << "Begging for food...\n";}

	private:
		BREED itsBreed;

};

int main(int argc, char const *argv[])
{
	Dog fido;

	fido.Speak();
	fido.WagTail();
	cout << "Fido is "<< fido.GetAge() << "years old\n";
	fido.SetAge(3);
	cout << "Fido is "<< fido.GetAge() << "years old\n";

	return 0;
}