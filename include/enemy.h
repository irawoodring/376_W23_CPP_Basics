#include <iostream>
#include <string>

class Enemy {
	public:
		Enemy();
		Enemy(std::string, int, float);
		inline bool operator<(const Enemy& r) const{
			return hp < r.hp;
		}
		inline bool operator> (const Enemy& rhs) const { return rhs < *this; }
		inline bool operator<=(const Enemy& rhs) const { return !(*this > rhs); }
		inline bool operator>=(const Enemy& rhs) const { return !(*this < rhs); }
		inline bool operator==(const Enemy& rhs) const { return !(*this<rhs) && !(*this>rhs); }

		std::string getName(){ return this->name; }
		int getHp(){ return this->hp; }
		float getSpeed(){ return this->speed; }

		void setName(std::string name) {
			if(name == "" || name.length() == 0 || name.length() > 25){
				throw std::invalid_argument("Invalid name.");
			}
			this->name = name;
		}

		void setHp(int hp){
			if(hp < 0){
				throw std::invalid_argument("Invalid HP.");
			}
			this->hp = hp;
		}

		void setSpeed(float speed){
			if(speed < 0 || speed > 1.0f){
				throw std::invalid_argument("Invalid speed.");
			}
			this->speed = speed;
		}

		friend std::ostream& operator<<(std::ostream& os, const Enemy& obj){
			os << obj.name << ", " << obj.hp << ", " << obj.speed;
			return os;
		}

	private:
		std::string name;
		int hp;
		float speed;
};
