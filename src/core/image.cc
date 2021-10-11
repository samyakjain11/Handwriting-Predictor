//
// Created by Samyak Jain on 10/10/20.
//

#include "core/image.h"

#include <math.h>

#include <iostream>
#include <string>
#include <vector>

using namespace image;

Image::Image(const std::string &image, char classification, char black_space,
             char grey_space, char white_space, int image_size) {
  if (!(Image::IsImageValid(image))) {
    throw std::invalid_argument("image provided is not a square");
  }

  Image::InitializeVectorRepImage(image, black_space, grey_space, white_space);
  Image::classification_ = classification;
  image_size_ = image_size;
}

Image::Image(std::vector<std::vector<image::SpaceStates>> vector,
             const char &classification) {
  Image::vector_representation_of_image_ = vector;
  Image::classification_ = classification;
}

bool Image::IsPixelShaded(int row, int col) {
  if (Image::vector_representation_of_image_[row][col] ==
          image::SpaceStates::kBlackSpace ||
      Image::vector_representation_of_image_[row][col] ==
          image::SpaceStates::kGreySpace)
    return true;
  return false;
}

char Image::GetClassification() {
  return Image::classification_;
}

int Image::GetImageSize() {
  return image_size_;
}

char Image::GetGreySpace() const {
  return grey_space_;
}

char Image::GetWhiteSpace() const {
  return white_space_;
}
char Image::GetBlackSpace() const {
  return black_space_;
}

std::vector<std::vector<image::SpaceStates>> Image::GetVectorRep() {
  return Image::vector_representation_of_image_;
}

void Image::InitializeVectorRepImage(const std::string &image, char black_space,
                                     char grey_space, char white_space) {
  std::vector<image::SpaceStates> imageRow;
  for (int index = 0; index < image.size(); index++) {
    if (image.at(index) == black_space)
      imageRow.push_back(image::SpaceStates::kBlackSpace);
    else if (image.at(index) == white_space)
      imageRow.push_back(image::SpaceStates::kWhiteSpace);
    else if (image.at(index) == grey_space)
      imageRow.push_back(image::SpaceStates::kGreySpace);
    else if (image.at(index) == '\n') {
      Image::vector_representation_of_image_.push_back(imageRow);
      imageRow.clear();
    } else {
      throw std::invalid_argument("character in string not of type given");
    }
  }
  Image::vector_representation_of_image_.push_back(imageRow);
}

bool Image::IsImageValid(const std::string &image) {
  int numberOfNewLines = 0;
  if (image.size() == 0) {
    return false;
  }

  for (char c : image) {
    if (c == '\n')
      numberOfNewLines++;
  }

  if (fmod(sqrt(image.length() - numberOfNewLines), 1) != 0.0) {
    int length = image.length();
    std::cout << length;
    return false;
  } else {
    image_size_ = sqrt(image.length());
    return true;
  }
}

std::istream &image::operator>>(std::istream &input, Image &image) {
  std::string row;
  std::string image_string;

  for (int iterate = 0; iterate < image.GetImageSize(); iterate++) {
    std::getline(input, row);
    image_string += row + "\n";
  }

  //image_string.pop_back();

  image =
      Image(image_string, image.GetClassification(), image.GetBlackSpace(),
            image.GetGreySpace(), image.GetWhiteSpace(), image.GetImageSize());

  return input;
}

Image::Image(char classification, char black_space, char grey_space,
             char white_space, int image_size) {
  classification_ = classification;
  image_size_ = image_size;
  grey_space_ = grey_space;
  white_space_ = white_space;
  black_space_ = black_space;
}

Image::Image() {
  classification_ = 'x';
  image_size_ = 0;
  grey_space_ = '+';
  white_space_ = ' ';
  black_space_ = '#';
}

void Image::setPixel(int row, int col, image::SpaceStates spaceState) {
  vector_representation_of_image_[row][col] = spaceState;
}

void Image::Clear() {
  for(int row = 0; row < image_size_; row++)
  {
    for(int col = 0; col < image_size_; col++)
    {
      vector_representation_of_image_[row][col] = SpaceStates::kWhiteSpace;
    }

  }

}