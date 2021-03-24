#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    float volume;

public:
    Shape() { volume = 0; }
    virtual void computeVolume() = 0;
    void printVolume()
    {
        cout << volume << endl;
    }
};
class Cuboid : public Shape
{
    // Add code here
private:
    float length, width, height;

public:
    Cuboid(float l, float w, float h): length(l), width(w), height(h) {}
    
    void computeVolume() {
        volume = length * width * height;
    }
};

class Pyramid : public Shape
{
    // Add code here
private:
    float baseArea, height;

public:
    Pyramid(float bA, float h): baseArea(bA), height(h) {}
    
    void computeVolume() {
        volume = baseArea * height / 3;
    }
};
class Sphere : public Shape
{
    // Add code here
private:
    float radius;

public:
    Sphere(float r): radius(r) {}
    
    void computeVolume() {
        volume = 4.0 / 3.0 * radius * radius * radius * PI;
    }
};

int main()
{
    float a, b, c;
    Shape *shape;

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub;
    shape->computeVolume();
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}