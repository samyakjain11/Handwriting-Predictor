//
// Created by Samyak Jain on 10/10/20.
//

#include "core/file_interactor.h"

std::vector<char> FileInteractor::labels;
std::vector<image::Image> FileInteractor::images;

std::istream& operator>>(std::istream& input, FileInteractor& fileInteractor) {
  FileInteractor::InitializeImagesVector(input);
  fileInteractor.setModelGenerator(
      ModelGenerator(FileInteractor::images, FileInteractor::kImageSize));

  return input;
}

std::ostream& operator<<(std::ostream& input, FileInteractor& fileInteractor) {
  input << fileInteractor.GetModelGenerator().GenerateModelAsString();
  return input;
}

void FileInteractor::InitializeImagesVector(std::istream& images_file) {
  images.clear();
  std::string image;
  std::string row;

  int image_iterator = 0;

  while (images_file.good()) {
    image::Image im = image::Image(labels[image_iterator], '#', '+', ' ',
                                   FileInteractor::kImageSize);
    images_file >> im;
    image_iterator++;
    images.push_back(im);
  }

  std::vector<std::vector<image::SpaceStates>> empty;

  if (images.empty())
    throw std::invalid_argument("no images found");

  // if the image vector has images but the images are empty
  if (images[0].GetVectorRep()[0].size() == 0)
    throw std::invalid_argument("no images found");
}

void FileInteractor::InitializeLabelVector(std::string labels_file_path) {
  labels.clear();
  std::string line;
  std::ifstream file_stream(labels_file_path);

  while (std::getline(file_stream, line)) {
    labels.push_back(line.at(0));
  }

  if (labels.empty())
    throw std::invalid_argument("no labels found");
}

std::vector<image::Image> FileInteractor::getImages() {
  return images;
}

ModelGenerator FileInteractor::GetModelGenerator() {
  return modelGenerator;
}

void FileInteractor::setModelGenerator(ModelGenerator generator) {
  modelGenerator = generator;
}
