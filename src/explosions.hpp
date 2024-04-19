#pragma once
#include <raylib.h>
#include <vector>

using namespace std;

class Explosions
{
public:
    // Variables
    Vector2 position;

    // Con-/Destructor
    Explosions();
    ~Explosions();

    // Functions
    void AddExplosion(Vector2 position);
    void Update();
    void Draw();
    void ClearExplosions();
    void CleanUp();

private:
    // Variables
    struct Explosion
    {
        Vector2 position;
        bool active;
    };
    vector<Explosion> explosion;
};
