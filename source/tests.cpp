#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>

#include "../framework/shape.hpp" 
#include "../framework/sphere.hpp"
#include "../framework/box.hpp"

TEST_CASE("Sphere -> area test", "[aufgabe 5.2]"){
  Sphere s1{};
  Sphere s2{{0,0,0}, 10};
  Sphere s3{{0,0,0}, 0};
  Sphere s4{{0,0,0}, 0.015};
  Sphere s5{{0,0,0}, 1.913};
  Sphere s6{{0,0,0}, -10};
  Sphere s7{{0,0,0}, -0};
  Sphere s8{{0,0,0}, -0.015};
  Sphere s9{{0,0,0}, -1.913};
  
  REQUIRE(s1.area() == Approx(12.57));
  REQUIRE(s2.area() == Approx(1256.64));
  REQUIRE(s3.area() == Approx(0));
  REQUIRE(s4.area() == Approx(0.00283));
  REQUIRE(s5.area() == Approx(45.99));
  REQUIRE(s6.area() == Approx(1256.64));
  REQUIRE(s7.area() == Approx(0));
  REQUIRE(s8.area() == Approx(0.00283));
  REQUIRE(s9.area() == Approx(45.99));
}

TEST_CASE("Sphere -> volume test", "[aufgabe 5.2]"){
  Sphere s1{};
  Sphere s2{{0,0,0}, 10};
  Sphere s3{{0,0,0}, 0};
  Sphere s4{{0,0,0}, 0.15};
  Sphere s5{{0,0,0}, 1.913};
  Sphere s6{{0,0,0}, -10};
  Sphere s7{{0,0,0}, -0};
  Sphere s8{{0,0,0}, -0.015};
  Sphere s9{{0,0,0}, -1.913};
  
  REQUIRE(s1.area() == Approx(4.18879));
  REQUIRE(s2.area() == Approx(4188.79));
  REQUIRE(s3.area() == Approx(0));
  REQUIRE(s4.area() == Approx(0.01413));
  REQUIRE(s5.area() == Approx(29.3247));
  REQUIRE(s6.area() == Approx(4188.79));
  REQUIRE(s7.area() == Approx(0));
  REQUIRE(s8.area() == Approx(0.01413));
  REQUIRE(s9.area() == Approx(29.3247));
}

TEST_CASE("Box -> area test", "[aufgabe 5.2]"){
  Box b1{};
  Box b2{{0,0,0}, {0,0,0}};
  Box b3{{0,0,0}, {0,0,10}};
  Box b4{{0,0,0}, {-1, -1, -1}};
  Box b5{{0,0,0}, {-0.1, -0.1, -0.1}};
  Box b6{{1,1,1}, {-0.1, -0.1, -0.1}};
  Box b7{{1,1,1}, {-1, -1, -1}};
  Box b8{{-100,-100,-100}, {-10, -30, -90}};
  
  REQUIRE(b1.area() == Approx(1));
  REQUIRE(b2.area() == Approx(0));
  REQUIRE(b3.area() == Approx(0));
  REQUIRE(b4.area() == Approx(1));
  REQUIRE(b5.area() == Approx(0.001));
  REQUIRE(b6.area() == Approx(1.331));
  REQUIRE(b7.area() == Approx(8));
  REQUIRE(b8.area() == Approx(63000));
}

TEST_CASE("Box -> volume test", "[aufgabe 5.2]"){
  Box b1{};
  Box b2{{0,0,0}, {0,0,0}};
  Box b3{{0,0,0}, {0,0,10}};
  Box b4{{0,0,0}, {-1, -1, -1}};
  Box b5{{0,0,0}, {-0.1, -0.1, -0.1}};
  Box b6{{1,1,1}, {-0.1, -0.1, -0.1}};
  Box b7{{1,1,1}, {-1, -1, -1}};
  Box b8{{-100,-100,-100}, {-10, -30, -90}};
  
  REQUIRE(b1.area() == Approx(6));
  REQUIRE(b2.area() == Approx(0));
  REQUIRE(b3.area() == Approx(0));
  REQUIRE(b4.area() == Approx(6));
  REQUIRE(b5.area() == Approx(0.06));
  REQUIRE(b6.area() == Approx(7.26));
  REQUIRE(b7.area() == Approx(24));
  REQUIRE(b8.area() == Approx(15800));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
