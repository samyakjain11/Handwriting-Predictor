

#include <catch2/catch.hpp>

//
// Created by Samyak Jain on 10/20/20.
//

#include <core/ModelInterpretor.h>
#include <core/file_interactor.h>

#include <iostream>
#include <vector>

TEST_CASE("happy paths") {
  std::ifstream generated_model = std::ifstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "models/testGeneratedModel");
  ModelInterpretor m = ModelInterpretor(generated_model);
  SECTION("testing likelihood values") {
    SECTION("testing likelihood values for image 0") {
      image::Image i = image::Image("###\n# #\n###", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(0, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 1") {
      image::Image i = image::Image(" # \n # \n # ", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(1, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 2") {
      image::Image i = image::Image("###\n # \n###", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(2, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 3") {
      image::Image i = image::Image("###\n ##\n###", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(3, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 4") {
      image::Image i = image::Image("# #\n###\n  #", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(4, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 5") {
      image::Image i = image::Image("###\n## \n## ", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(5, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 6") {
      image::Image i = image::Image("#  \n## \n## ", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(6, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 7") {
      image::Image i = image::Image("###\n # \n#  ", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(7, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 8") {
      image::Image i = image::Image("###\n # \n###", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(8, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
    SECTION("testing likelihood values for image 9") {
      image::Image i = image::Image(" ##\n ##\n  #", '0', '#', '+', ' ', 3);
      double calculated_likelihood = m.CalculateLikelihood(9, i);
      REQUIRE(abs(calculated_likelihood - (-3.376578)) < .001);
    }
  }
  SECTION("testing classifications") {
    SECTION("image 0") {
      image::Image i = image::Image("###\n# #\n###", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 0);
    }
    SECTION("image 1") {
      image::Image i = image::Image(" # \n # \n # ", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 1);
    }
    SECTION("image 2") {
      image::Image i = image::Image("###\n # \n###", '0', '#', '+', ' ', 3);
      bool require =
          m.ComputeClassification(i) == 8 || m.ComputeClassification(i) == 2;
      REQUIRE(require);
    }
    SECTION("image 3") {
      image::Image i = image::Image("###\n ##\n###", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 3);
    }
    SECTION("image 4") {
      image::Image i = image::Image("# #\n###\n  #", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 4);
    }
    SECTION("image 5") {
      image::Image i = image::Image("###\n## \n## ", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 5);
    }
    SECTION("image 6") {
      image::Image i = image::Image("#  \n## \n## ", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 6);
    }
    SECTION("image 7") {
      image::Image i = image::Image("###\n # \n#  ", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 7);
    }
    SECTION("image 8") {
      image::Image i = image::Image("###\n # \n###", '0', '#', '+', ' ', 3);
      bool require =
          m.ComputeClassification(i) == 8 || m.ComputeClassification(i) == 2;
      REQUIRE(require);
    }
    SECTION("image 9") {
      image::Image i = image::Image(" ##\n ##\n  #", '0', '#', '+', ' ', 3);
      REQUIRE(m.ComputeClassification(i) == 9);
    }
  }
}