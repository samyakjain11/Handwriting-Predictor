//
// Created by Samyak Jain on 10/10/20.
//

#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H
#include <string>
#include <vector>

namespace image {

/**
 * represents the states a space can have
 */

enum class SpaceStates { kBlackSpace, kGreySpace, kWhiteSpace };

class Image {
 public:
  /**
   * to create an image object
   * @param image a string representation of the image
   * @param classification the given classification of the image
   * @param black_space the character used to identify a black space
   * @param grey_space the character used to identify a grey space
   * @param white_space the character used to identify a white space
   * @param image_size the size of the image
   */
  Image(const std::string &image, char classification, char black_space,
        char grey_space, char white_space, int image_size);

  /**
   * default constructor
   */
  Image();

  /**
   *creates an image object
   * @param classification the given classification of the image
   * @param black_space the character used to identify a black space
   * @param grey_space the character used to identify a grey space
   * @param white_space the character used to identify a white space
   * @param image_size the size of the image
   */
  Image(char classification, char black_space, char grey_space,
        char white_space, int image_size);

  /**
   *
   * @param vector the 2d vector representation of the image
   * @param classification char that represents the classification_ of the image
   */
  Image(std::vector<std::vector<image::SpaceStates>> vector,
        const char &classification);

  /**
   * @return returns the classification_ of this image
   */
  char GetClassification();

  /**
   * @return returns the dimension of the image
   */
  int GetImageSize();

  /**
   * tells you whether a specific pixel is shaded or not
   * @param row the row coordinate of the specific pixel
   * @param col the column coordinate of the specific pixel
   * @return represents a boolean that tells whether a specific pixel is shaded
   *         or not
   */
  bool IsPixelShaded(int row, int col) const;

  /**
   * sets a specific pixel to the specified space state
   * @param row of the specific pixel
   * @param col of the specific pixel
   * @param spaceState the state you want to change the pixel to
   */
  void SetPixel(int row, int col, image::SpaceStates spaceState);

  /**
   * clears the vector, making all spaces white
   */
  void Clear();

  /**
   * @return returns the vector representation of the image
   */
  std::vector<std::vector<image::SpaceStates>> GetVectorRep();

  char GetWhiteSpace() const;
  char GetGreySpace() const;
  char GetBlackSpace() const;

  friend std::istream &operator>>(std::istream &input, Image &image);

 private:
  std::vector<std::vector<image::SpaceStates>> vector_representation_of_image_;
  char classification_;
  int image_size_;
  char grey_space_;
  char white_space_;
  char black_space_;

  /**
   * initializes the 2d vector representation of the image
   * @param image the string within which the image is stored
   */
  void InitializeVectorRepImage(const std::string &image, char black_space,
                                char grey_space, char white_space);

  /**
   * checks if a string image is valid
   * @param image the string that will be checked for validity
   * @return true if the image is valid, false if not
   */
  bool IsImageValid(const std::string &image);
};

};      // namespace image
#endif  // NAIVE_BAYES_IMAGE_H
