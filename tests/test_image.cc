//
// Created by Samyak Jain on 10/11/20.
//

#include <catch2/catch.hpp>
#include <vector>

#include "core/image.h"

TEST_CASE("checks image constructor") {
  SECTION("checks happy path") {
    image::Image testImage =
        image::Image("+ #\n+++\n+++", '1', '#', '+', ' ', 3);

    std::vector<std::vector<image::SpaceStates>> checkVector = {
        {image::SpaceStates::kGreySpace, image::SpaceStates::kWhiteSpace,
         image::SpaceStates::kBlackSpace},
        {image::SpaceStates::kGreySpace, image::SpaceStates::kGreySpace,
         image::SpaceStates::kGreySpace},
        {image::SpaceStates::kGreySpace, image::SpaceStates::kGreySpace,
         image::SpaceStates::kGreySpace}};

    REQUIRE(testImage.GetClassification() == '1');
    REQUIRE(testImage.GetImageSize() == 3);
    REQUIRE(testImage.GetVectorRep() == checkVector);
  }
  SECTION("check invalid image constructor") {
    SECTION("checks non square image") {
      REQUIRE_THROWS_AS(image::Image("+ #\n++++\n+++", '1', '#', '+', ' ', 3),
                        std::invalid_argument);
    }
    SECTION("checks image string with characters that are not classified") {
      REQUIRE_THROWS_AS(image::Image("+ #\nz++\n+++", '1', '#', '+', ' ', 3),
                        std::invalid_argument);
    }
    SECTION("checks blank image") {
      REQUIRE_THROWS_AS(image::Image("", '1', '#', '+', ' ', 3),
                        std::invalid_argument);
    }
  }
}

TEST_CASE("checks image pixel shaded method") {
  image::Image testImage = image::Image("+ #\n   \n   ", '1', '#', '+', ' ', 3);
  SECTION("check if black space returns true") {
    REQUIRE(testImage.IsPixelShaded(0, 2));
  }
  SECTION("check if grey space returns true") {
    REQUIRE(testImage.IsPixelShaded(0, 0));
  }
  SECTION("checks if white space returns false") {
    REQUIRE_FALSE(testImage.IsPixelShaded(0, 1));
  }
}
