//
// Created by Samyak Jain on 10/20/20.
//

#include "core/image.h"
#include "core/ModelInterpretor.h"

ModelInterpretor::ModelInterpretor(std::istream &saved_model) {
  bool initializing_class_likelihoods = true;

  while (saved_model.good()) {
    std::string line;
    std::getline(saved_model, line);

    if (line == "") {
      initializing_class_likelihoods = false;
      continue;
    }

    if (initializing_class_likelihoods) {
      class_likelihood_scores.push_back(std::stod(line));
    } else {
      std::vector<double> probabilities;

      std::string shadedProb = (line.substr(0, line.find(' ') - 1));
      probabilities.push_back(std::stod(shadedProb));

      std::string unshadedProb = (line.substr(line.find(' ') + 1));
      probabilities.push_back(std::stod(unshadedProb));

      pixel_likelihood_scores_by_class.push_back(probabilities);
    }
  }
}

int ModelInterpretor::ComputeClassification(image::Image image) {
  std::vector<double> likelihood_scores;
  for (int classification = 0; classification < 10; classification++) {
    likelihood_scores.push_back(CalculateLikelihood(classification, image));
  }

  return FindIndexOfMaxOfVector(likelihood_scores);
}

double ModelInterpretor::CalculateLikelihood(int classification, image::Image image) {
  if(image.GetVectorRep()[0].size() == 0)
  {
    return -100000;
  }

  int number_of_pixels_per_image = image.GetImageSize() * image.GetImageSize();
  double likelihood_score = class_likelihood_scores[classification];
  for (int row = 0; row < image.GetImageSize(); row++) {
    for (int col = 0; col < image.GetImageSize(); col++) {
      if (image.IsPixelShaded(row, col)) {
        double smth =
            pixel_likelihood_scores_by_class[(classification *
                                              (number_of_pixels_per_image)) +
                                             (row * image.GetImageSize() + col)]
                                            [0];
        likelihood_score += smth;
      } else {
        double smth =
            pixel_likelihood_scores_by_class[(classification *
                                              (number_of_pixels_per_image)) +
                                             (row * image.GetImageSize() + col)]
                                            [1];
        likelihood_score += smth;
      }
    }
  }
  return likelihood_score;
}

int ModelInterpretor::FindIndexOfMaxOfVector(std::vector<double> vect) {
  int max_element_index =
      std::max_element(vect.begin(), vect.end()) - vect.begin();
  return max_element_index;
}
