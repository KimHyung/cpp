#include <iostream>

class Marine{
    private:
        int hp;
        int coord_x, coord_y;
        int damage;
        bool is_dead;
    
    public:
        Marine();
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);
        void show_status();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y){
    
}