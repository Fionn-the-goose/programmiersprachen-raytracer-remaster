#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>

#include "../framework/sphere.hpp"
#include "../framework/box.hpp"

TEST_CASE("Sphere -> area test", "[aufgabe 5.2]"){
  Sphere s1{};
  Sphere s2{{0,0,0}, 10};
  Sphere s3{{0,0,0}, 0};
  Sphere s4{{0,0,0}, 0.015};
  Sphere s5{{0,0,0}, 1.913};
  
  REQUIRE(s1.area() == Approx(12.57));
  REQUIRE(s2.area() == Approx(1256.64));
  REQUIRE(s3.area() == Approx(0));
  REQUIRE(s4.area() == Approx(0.00283));
  REQUIRE(s5.area() == Approx(45.99));
}

TEST_CASE("Sphere -> volume test", "[aufgabe 5.2]"){}
TEST_CASE("Box -> area test", "[aufgabe 5.2]"){}
TEST_CASE("Box -> volume test", "[aufgabe 5.2]"){}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
