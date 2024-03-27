#pragma once
#include <raylib.h>
#include <vector>

using namespace std;

class Explosions {
    public:
        Vector2 position;

        Explosions();
        ~Explosions();

        void AddExplosion(Vector2 position);
        void Update();
        void Draw();
        void ClearExplosions();

    private:
        struct Explosion {
            Vector2 position;
            bool active;
        };
        vector<Explosion> explosion;
        int explosionCount = 0;
};
