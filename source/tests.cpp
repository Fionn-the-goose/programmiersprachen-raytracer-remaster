#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

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
  
  REQUIRE(s1.area() == Approx(12.5663));
  REQUIRE(s2.area() == Approx(1256.64));
  REQUIRE(s3.area() == Approx(0));
  REQUIRE(s4.area() == Approx(0.002827433));
  REQUIRE(s5.area() == Approx(45.9875));
  REQUIRE(s6.area() == Approx(1256.64));
  REQUIRE(s7.area() == Approx(0));
  REQUIRE(s8.area() == Approx(0.0028274));
  REQUIRE(s9.area() == Approx(45.9875));
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
  
  REQUIRE(s1.volume() == Approx(4.18879));
  REQUIRE(s2.volume() == Approx(4188.79));
  REQUIRE(s3.volume() == Approx(0));
  REQUIRE(s4.volume() == Approx(0.014137166));
  REQUIRE(s5.volume() == Approx(29.3247));
  REQUIRE(s6.volume() == Approx(4188.79));
  REQUIRE(s7.volume() == Approx(0));
  REQUIRE(s8.volume() == Approx(0.0000141372));
  REQUIRE(s9.volume() == Approx(29.3247));
}

TEST_CASE("Box -> area test", "[aufgabe 5.2]"){
  Box b1{};
  Box b2{{0,0,0}, {0,0,0}};
  Box b3{{0,0,0}, {0,0,10}};
  Box b3_b{{0,0,0}, {0,10,10}};
  Box b4{{0,0,0}, {-1, -1, -1}};
  Box b5{{0,0,0}, {-0.1, -0.1, -0.1}};
  Box b6{{1,1,1}, {-0.1, -0.1, -0.1}};
  Box b7{{1,1,1}, {-1, -1, -1}};
  Box b8{{-100,-100,-100}, {-10, -30, -90}};
  
  REQUIRE(b1.area() == Approx(6));
  REQUIRE(b2.area() == Approx(0));
  REQUIRE(b3.area() == Approx(0));
  REQUIRE(b3_b.area() == Approx(200));
  REQUIRE(b4.area() == Approx(6));
  REQUIRE(b5.area() == Approx(0.06));
  REQUIRE(b6.area() == Approx(7.26));
  REQUIRE(b7.area() == Approx(24));
  REQUIRE(b8.area() == Approx(15800));
}

TEST_CASE("Box -> volume test", "[aufgabe 5.2]"){
  Box b1{};
  Box b2{{0,0,0}, {0,0,0}};
  Box b3{{0,0,0}, {0,0,10}};
  Box b3_b{{0,0,0}, {0,10,10}};
  Box b4{{0,0,0}, {-1, -1, -1}};
  Box b5{{0,0,0}, {-0.1, -0.1, -0.1}};
  Box b6{{1,1,1}, {-0.1, -0.1, -0.1}};
  Box b7{{1,1,1}, {-1, -1, -1}};
  Box b8{{-100,-100,-100}, {-10, -30, -90}};
  
  REQUIRE(b1.volume() == Approx(1));
  REQUIRE(b2.volume() == Approx(0));
  REQUIRE(b3.volume() == Approx(0));
  REQUIRE(b3_b.volume() == Approx(0));
  REQUIRE(b4.volume() == Approx(1));
  REQUIRE(b5.volume() == Approx(0.001));
  REQUIRE(b6.volume() == Approx(1.331));
  REQUIRE(b7.volume() == Approx(8));
  REQUIRE(b8.volume() == Approx(63000));
}

TEST_CASE("intersect_ray_sphere", "[intersect]"){
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use:
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
  // Sphere
  glm::vec3 sphere_center{0.0f ,0.0f, 5.0f};
  float sphere_radius{1.0f};
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
  ray_origin, ray_direction,
  sphere_center,
  sphere_radius * sphere_radius, // squared radius !!!
  distance);
  REQUIRE(distance == Approx(4.0f));
}

int main(int argc, char *argv[]){
  Sphere test_sphere{{0.0, 0.0, 0.0}, 7.0, "Printing Sphere", {1.0, 1.0, 1.0}};
	Box test_box{ {0.0, 0.0, 0.0}, {10.0, 10.0, 20.0}, "Printing Box", {.5, .5, .5} };
	std::cout << test_sphere << std::endl;
	std::cout << test_box << std::endl;
  return Catch::Session().run(argc, argv);
}
